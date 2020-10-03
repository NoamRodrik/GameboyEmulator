/**
 * @file		LCDRender.h
 * @author		Noam Rodrik
 * @description LR35902 pixel lcd render
 */
#ifndef __LR35902_LCD_RENDER_H__
#define __LR35902_LCD_RENDER_H__

#include <Core/GPU/Registers/LCDC_Status.h>
#include <Core/GPU/Mechanics/PixelFIFO.h>
#include <Core/GPU/Mechanics/Fetcher.h>
#include <Core/GPU/Registers/SCX.h>
#include <Core/GPU/Registers/LYC.h>
#include <Core/GPU/Registers/LY.h>
#include <API/Definitions.h>
#include <Tools/Tools.h>

namespace Core
{
class LCDRender
{
public:
	LCDRender(API::IMemoryDeviceAccess& memory, IPPU& ppu) :
		_memory{memory}, _ppu{ppu} {}
	~LCDRender() = default;

public:
	/**
	 * Executes next batch of instructions.
	 */
	bool Execute(std::size_t clocks)
	{
		this->_clocks += clocks;

		while (this->_clocks != 0)
		{
			switch (this->_state)
			{
				case (PPUState::OAM_SEARCH):
				{
					if (!this->OAMSearch())
					{
						return true;
					}

					break;
				}

				case (PPUState::PIXEL_RENDER):
				{
					if (!this->PixelRender())
					{
						return true;
					}

					break;
				}

				case (PPUState::H_BLANK):
				{
					if (!this->HBlank())
					{
						return true;
					}

					break;
				}

				case (PPUState::V_BLANK):
				{
					if (!this->VBlank())
					{
						return true;
					}

					break;
				}

				default:
				{
					MAIN_LOG("Got into an impossible state in the lcd renderer!");
					return false;
				}
			}
		}

		return true;
	}

	const auto& GetScreen() const
	{
		return this->_fifo.GetScreen();
	}

	void ResetLCD()
	{
		this->_fifo.WhiteScreen();

		this->_fifo.ResetNewLine();
		this->_fifo.ResetNewFrame();
		this->_fetcher.Reset();
		this->_fetcher.ResetNewFrame();

		if (static_cast<LCDC_Status::Status>(LCDC_Status{}).mode_0 == LCDC_Status::Status::MODE_SELECTION)
		{
			InterruptHandler::IRQ(EInterrupts::LCDC);
		}

		this->_fifo.SetY(this->_fifo.GetSCY());
		this->ChangeState(PPUState::H_BLANK);
	}

	void Start()
	{
		this->_fifo.WhiteScreen();
	}

private:
	const bool OAMSearch()
	{
		if (this->_clocks >= OAM_SEARCH_MAXIMUM_CYCLES)
		{
			this->_clocks -= OAM_SEARCH_MAXIMUM_CYCLES;
			this->ChangeState(PPUState::PIXEL_RENDER);

			return true;
		}

		return false;
	}

	const bool HBlank()
	{		
		if (this->_clocks >= HBLANK_CLOCK_MAXIMUM_CYCLES)
		{
			// If we need VBlank.
			if (this->_fifo.YPassedThreshold())
			{
				InterruptHandler::IRQ(EInterrupts::VBLANK);

				if (static_cast<LCDC_Status::Status>(LCDC_Status{}).mode_1 == LCDC_Status::Status::MODE_SELECTION)
				{
					InterruptHandler::IRQ(EInterrupts::LCDC);
				}

				// We need to go back to the beginning.
				this->ChangeState(PPUState::V_BLANK);
			}
			else
			{
				if (static_cast<LCDC_Status::Status>(LCDC_Status{}).mode_2 == LCDC_Status::Status::MODE_SELECTION)
				{
					InterruptHandler::IRQ(EInterrupts::LCDC);
				}

				// We need to return to OAM search.
				this->ChangeState(PPUState::OAM_SEARCH);

				// Check LYC
				this->CompareLYC();

				// Fetcher must be after fifo.
				this->_fifo.ResetNewLine();
				this->_fifo.IncrementY();
				this->_fetcher.ResetNewLine();
				this->_fetcher.Reset();
			}

			this->_clocks -= HBLANK_CLOCK_MAXIMUM_CYCLES;

			return true;
		}

		return false;
	}

	bool VBlank()
	{
		if (this->_clocks >= VBLANK_CLOCKS)
		{
			this->CompareLYC();
			this->_fifo.IncrementY();
			this->_clocks -= VBLANK_CLOCKS;

			if (static_cast<API::data_t>(LY{}) == VBLANK_LY_END)
			{
				// Going back to the beginning.
				// FIRST FIFO and then FETCHER!
				this->_fifo.ResetNewLine();
				this->_fifo.ResetNewFrame();
				this->_fetcher.Reset();
				this->_fetcher.ResetNewFrame();
				
				if (static_cast<LCDC_Status::Status>(LCDC_Status{}).mode_2 == LCDC_Status::Status::MODE_SELECTION)
				{
					InterruptHandler::IRQ(EInterrupts::LCDC);
				}

				this->ChangeState(PPUState::OAM_SEARCH);
			}

			return true;
		}

		return false;
	}

	bool PixelRender()
	{
		if (this->_clocks >= PIXEL_RENDER_MAXIMUM_CYCLES)
		{
			std::size_t clocks{PIXEL_RENDER_MAXIMUM_CYCLES};

			while (!this->_fifo.XPassedThreshold())
			{
				SANITY(this->InnerExecute(clocks), "Failed executing fifo and fetcher");
			}

			if (static_cast<LCDC_Status::Status>(LCDC_Status{}).mode_0 == LCDC_Status::Status::MODE_SELECTION)
			{
				InterruptHandler::IRQ(EInterrupts::LCDC);
			}

			this->_clocks -= PIXEL_RENDER_MAXIMUM_CYCLES;
			this->ChangeState(PPUState::H_BLANK);
			return true;
		}

		return false;
	}

	/**
	 * All combinations of possibilities of running the fetcher and fifo.
	 */
	constexpr bool InnerExecute(std::size_t& io_clocks)
	{
		if (io_clocks == FIFO_PIXEL_CLOCKS)
		{
			if (this->_fifo.NeedsFill())
			{
				RET_FALSE_IF_FAIL(this->_fetcher.Execute(FIFO_PIXEL_CLOCKS), "Failed executing the fetcher!");
				RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO!");
			}
			else
			{
				RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO!");
				RET_FALSE_IF_FAIL(this->_fetcher.Execute(FIFO_PIXEL_CLOCKS), "Failed executing the fetcher!");
			}
		}
		else if (this->_fifo.NeedsFill())
		{
			RET_FALSE_IF_FAIL(this->_fetcher.Execute(FETCHER_OPERATION_CLOCKS), "Failed executing the fetcher!");
			RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO #1!");
			RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO #2!");

			io_clocks -= FETCHER_OPERATION_CLOCKS;
		}
		else
		{
			RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO #1!");

			if (this->_fifo.NeedsFill())
			{
				RET_FALSE_IF_FAIL(this->_fetcher.Execute(FETCHER_OPERATION_CLOCKS), "Failed executing the fetcher!");
				RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO #2!");
			}
			else
			{
				RET_FALSE_IF_FAIL(this->_fifo.Execute(), "Failed executing the FIFO #2!");
				RET_FALSE_IF_FAIL(this->_fetcher.Execute(FETCHER_OPERATION_CLOCKS), "Failed executing the fetcher!");
			}

			io_clocks -= FETCHER_OPERATION_CLOCKS;
		}

		return true;
	}

private:
	void ChangeState(const PPUState new_state)
	{
		SANITY(static_cast<API::data_t>(new_state) <= 0x03, "Invalid new state");

		static IORAM* io_ram_memory_ptr{static_cast<IORAM*>(this->_ppu.GetProcessor().GetMemory().GetDeviceAtAddress(LCDC_Status::LCDC_ADDRESS))};
		io_ram_memory_ptr->GetMemoryPointer()[LCDC_Status::LCDC_ADDRESS - IORAM::START_ADDRESS] &= 0xFC;
		io_ram_memory_ptr->GetMemoryPointer()[LCDC_Status::LCDC_ADDRESS - IORAM::START_ADDRESS] |= static_cast<API::data_t>(new_state);

		this->_state = new_state;
	}

	void CompareLYC() const
	{
		static IORAM* io_ram_memory_ptr{static_cast<IORAM*>(this->_ppu.GetProcessor().GetMemory().GetDeviceAtAddress(LCDC_Status::LCDC_ADDRESS))};
		Message("Not sure if + 1 or without!?");
		Tools::MutateBitByCondition(static_cast<data_t>(LY{}) == static_cast<data_t>(LYC{}),
								    io_ram_memory_ptr->GetMemoryPointer()[LCDC_Status::LCDC_ADDRESS - IORAM::START_ADDRESS], 2);

		LCDC_Status::Status lcdc_status{LCDC_Status{}};
		if (lcdc_status.mode_lyc == LCDC_Status::Status::MODE_SELECTION &&
			lcdc_status.coincidence_flag == LCDC_Status::Status::LYC_EQUAL_LCDC)
		{
			InterruptHandler::IRQ(EInterrupts::LCDC);
		}
	}

public:
	static constexpr std::size_t OAM_SEARCH_MAXIMUM_CYCLES{80};
	static constexpr std::size_t PIXEL_RENDER_MAXIMUM_CYCLES{289};
	static constexpr std::size_t HBLANK_CLOCK_MAXIMUM_CYCLES{87};
	static constexpr std::size_t VBLANK_LY_END{154};
	static constexpr std::size_t FIFO_PIXEL_CLOCKS{4};
	static constexpr std::size_t FETCHER_OPERATION_CLOCKS{8};
	static constexpr std::size_t HBLANK_CLOCKS{PIXEL_RENDER_MAXIMUM_CYCLES + HBLANK_CLOCK_MAXIMUM_CYCLES};
	static constexpr std::size_t VBLANK_CLOCKS{OAM_SEARCH_MAXIMUM_CYCLES + PIXEL_RENDER_MAXIMUM_CYCLES + HBLANK_CLOCK_MAXIMUM_CYCLES};

public:
	API::IMemoryDeviceAccess& _memory;
	IPPU&                     _ppu;
	PixelFIFO				  _fifo{this->_ppu};
	Fetcher					  _fetcher{this->_fifo, this->_ppu};
	PPUState				  _state{PPUState::OAM_SEARCH};
	std::size_t				  _clocks{0x00};
};
}

#endif // __LR35902_LCD_RENDER_H__