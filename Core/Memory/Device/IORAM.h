/**
 * @file		IORAM.h
 * @author		Noam Rodrik
 * @description LR35902 main IO RAM device header.
 */
#ifndef __LR35902_MEMORY_DEVICE_IO_RAM_H__
#define __LR35902_MEMORY_DEVICE_IO_RAM_H__

#include <Core/API/Memory/Device/MemoryDeviceBase.h>
#include <Core/Memory/Memory.h>
#include <Core/API/Definitions.h>
#include <Core/Processor/Timer/Timer.h>

namespace Core
{
class DeviceManagerBase;
} // Core

namespace Core
{
class IORAM : public MemoryDeviceBase
{
public:
	constexpr IORAM(DeviceManagerBase& device_manager) : MemoryDeviceBase{START_ADDRESS, END_ADDRESS, device_manager}, m_memory{} {}

	virtual bool Read(const address_t absolute_address, data_t& result) const override
	{
		result = this->m_memory[absolute_address - START_ADDRESS];
		return true;
	}

	virtual void Write(const data_t data, const address_t absolute_address) override
	{
		if (this->ApplyChanges(data, absolute_address))
		{
			this->m_memory[absolute_address - START_ADDRESS] = data;
		}
	}

	virtual bool Read(const address_t absolute_address, address_t& result) const override
	{
		result = this->m_memory[absolute_address - START_ADDRESS] | (this->m_memory[absolute_address - START_ADDRESS + 1] << 8);
		return true;
	}

	virtual void Write(const address_t data, const address_t absolute_address) override
	{
		if (this->ApplyChanges(data & 0x00FF, absolute_address) &&
			this->ApplyChanges((data & 0xFF00) >> 8, absolute_address + 1))
		{
			this->m_memory[absolute_address - START_ADDRESS] = data & 0x00FF;
			this->m_memory[absolute_address - START_ADDRESS + 1] = (data & 0xFF00 >> 8);
		}
	}

public:
	static constexpr uint16_t START_ADDRESS = 0xFF00;
	static constexpr uint16_t END_ADDRESS = 0xFF7F;
	static constexpr size_t   SIZE = END_ADDRESS - START_ADDRESS + 1;

protected:
	virtual uint8_t* GetMemoryPointer() override { return this->m_memory.GetMemoryPointer(); }

private:
	bool ApplyChanges(const data_t data, const address_t address)
	{
		switch (address)
		{
		case (TIMER_MODULO_ADDRESS):
		{
			if (Timer::GetInstance().IsTimerLoading())
			{
				// Writing also onto the timer counter!
				this->m_memory[TIMER_COUNTER_ADDRESS - START_ADDRESS] = data;
			}

			return true;
		}

		case (TIMER_COUNTER_ADDRESS):
		{
			/* Writes to the timer counter whilst it is loading are ignored */
			if (!Timer::GetInstance().IsTimerLoading())
			{
				Timer::GetInstance().ClearOverflowing();
				return true;
			}

			return false;
		}

		case (TIMER_CONTROL_ADDRESS):
		{
			Timer::GetInstance().UpdateTimerControl(data);
			break;
		}

		case (DIVIDER_REGISTER_ADDRESS):
		{
			break;
		}
		}

		return true;
	}
	
private:
	Memory<SIZE> m_memory;

private:
	friend class DeviceManager;
};
} // Core

#endif // __LR35902_MEMORY_DEVICE_IO_RAM_H__
