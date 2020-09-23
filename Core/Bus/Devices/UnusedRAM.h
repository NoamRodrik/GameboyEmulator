/**
 * @file		UnusedRAM.h
 * @author		Noam Rodrik
 * @description LR35902 main unused RAM device header.
 */
#ifndef __LR35902_MEMORY_DEVICE_UNUSED_RAM_H__
#define __LR35902_MEMORY_DEVICE_UNUSED_RAM_H__

#include <API/Memory/Device/IMemoryDeviceAccess.h>
#include <API/Memory/Device/IMemoryDevice.h>
#include <API/Memory/Memory.h>
#include <API/Definitions.h>

namespace Core
{
class UnusedRAM : public API::IMemoryDevice
{
public:
	constexpr UnusedRAM(API::IMemoryDeviceAccess& memory_accessor) : API::IMemoryDevice{START_ADDRESS, END_ADDRESS, memory_accessor} {}

	virtual bool Read(const API::address_t absolute_address, API::data_t& result) const override
	{
		result = this->_memory[absolute_address - START_ADDRESS];
		return true;
	}

	virtual bool Write(const API::address_t absolute_address, const API::data_t data) override
	{
		this->_memory[absolute_address - START_ADDRESS] = data;
		return true;
	}

public:
	static constexpr API::address_t START_ADDRESS = 0xFEA0;
	static constexpr API::address_t END_ADDRESS = 0xFEFF;
	static constexpr size_t   SIZE = END_ADDRESS - START_ADDRESS + 1;

protected:
	virtual uint8_t* GetMemoryPointer() override { return this->_memory.GetMemoryPointer(); }

private:
	API::Memory<SIZE> _memory;

private:
	friend class DeviceManager;
};
} // Core

#endif // __LR35902_MEMORY_DEVICE_OAM_RAM_H__