/**
 * @file		WorkRAM.h
 * @author		Noam Rodrik
 * @description LR35902 main work RAM device header.
 */
#ifndef __LR35902_MEMORY_DEVICE_WORK_RAM_H__
#define __LR35902_MEMORY_DEVICE_WORK_RAM_H__

#include <API/Memory/Device/IMemoryDeviceAccess.h>
#include <API/Memory/Device/IMemoryDevice.h>
#include <Core/Bus/Devices/CloneWorkRAM.h>
#include <API/Memory/Memory.h>
#include <API/Definitions.h>

namespace Core
{
class WorkRAM : public API::IMemoryDevice
{
public:
	constexpr WorkRAM(API::IMemoryDeviceAccess& memory_accessor) : API::IMemoryDevice{START_ADDRESS, END_ADDRESS, memory_accessor }, m_memory{} {}

	virtual bool Read(const API::address_t absolute_address, API::data_t& result) const override
	{
		result = this->m_memory[absolute_address - START_ADDRESS];
		return true;
	}

	virtual void Write(const API::address_t absolute_address, const API::data_t data) override
	{
		this->m_memory[absolute_address - START_ADDRESS] = data;

		API::data_t clone_data{0};

		SANITY(this->m_memory_accessor.Read(CloneWorkRAM::START_ADDRESS + absolute_address - START_ADDRESS, clone_data),
			"Failed reading from CloneWorkRAM");

		if (clone_data != data)
		{
			// Clones to the CloneWorkRAM
			this->m_memory_accessor.Write(CloneWorkRAM::START_ADDRESS + (absolute_address - START_ADDRESS), data);
		}
	}

public:
	static constexpr uint16_t START_ADDRESS = 0xC000;
	static constexpr uint16_t END_ADDRESS = 0xDFFF;
	static constexpr size_t   SIZE = END_ADDRESS - START_ADDRESS + 1;

protected:
	virtual uint8_t* GetMemoryPointer() override { return this->m_memory.GetMemoryPointer(); }

private:
	API::Memory<SIZE> m_memory;

private:
	friend class DeviceManager;
};
} // Core

#endif // __LR35902_MEMORY_DEVICE_WORK_RAM_H__
