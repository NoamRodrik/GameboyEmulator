/**
 * @file		LCDC_Status.h
 * @author		Noam Rodrik
 * @description LR35902's main gpu lcdc status definition header.
 */
#ifndef __LR35902_LCDC_STATUS_H__
#define __LR35902_LCDC_STATUS_H__

#include <Core/CPU/Registers/MemoryRegister.h>

namespace Core
{
class LCDC_Status : public MemoryRegister<API::data_t>
{
public:
	constexpr LCDC_Status() : MemoryRegister{LCDC_ADDRESS} {}
	LCDC_Status(const API::data_t value) : MemoryRegister{LCDC_ADDRESS} { *this = value; }

public:
	using MemoryRegister::operator=;
	using MemoryRegister::operator API::data_t;

public:
	struct Status
	{
		// LCD_MODE
		// 00: During H-Blank
		static constexpr API::data_t DURING_H_BLANK{0x00};
		// 01: During V - Blank
		static constexpr API::data_t DURING_V_BLANK{0x01};
		// 10 : During Searching OAM - RAM
		static constexpr API::data_t DURING_SEARCH_OAM_RAM{0x02};
		// 11 : During Transfering Data to LCD driver
		static constexpr API::data_t DURING_DATA_TRANSFER_LCD{0x03};
		API::data_t lcd_enable : 2;

		// LYC_STAT
		// 0: LYC not equal to LCDC LY
		static constexpr API::data_t LYC_NOT_EQUAL_LCDC{0x00};
		// 1: LYC = LCDC LY
		static constexpr API::data_t LYC_EQUAL_LCDC{0x01};
		API::data_t coincidence_flag : 1;

		// INTR_M0
		// 0: No Selection
		static constexpr API::data_t MODE_NO_SELECTION{0x00};
		// 1: Selection
		static constexpr API::data_t MODE_SELECTION{0x01};
		API::data_t mode_0 : 1;

		// INTR_M1
		// 0: No Selection
		// 1: Selection
		API::data_t mode_1 : 1;

		// INTR_M2
		// 0: No Selection
		// 1: Selection
		API::data_t mode_2 : 1;

		// INTR_LYC
		// LYC=LY Coincidence (Selectable)
		// 0: No Selection
		// 1: Selection
		API::data_t mode_lyc : 1;

		constexpr operator API::data_t() const
		{
			const API::data_t DATA = mode_lyc << 6 |
									 mode_2 << 5 |
									 mode_1 << 4 |
									 mode_0 << 3 |
									 coincidence_flag << 2 |
									 lcd_enable;
			return DATA;
		}
	};

	static_assert(sizeof(Status) == sizeof(API::data_t),
				  "Status too big! Supposed to of size data_t!");

public:
	/**
	 * Mutate/Access the LCDC via a bit field structure.
	 */
	operator Status()
	{
		return {this->operator API::data_t()};
	}

	MemoryRegister& operator=(const Status other)
	{
		return this->operator=(static_cast<const API::data_t>(other));
	}

public:
	static constexpr API::address_t LCDC_ADDRESS{0xFF41};
	static constexpr API::address_t LCDC_DEFAULT_VALUE{0x00};
};
}

#endif // __LR35902_LCDC_STATUS_H__