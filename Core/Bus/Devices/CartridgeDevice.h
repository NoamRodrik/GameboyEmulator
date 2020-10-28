/**
 * @file		CartridgeDevice.h
 * @author		Noam Rodrik
 * @description LR35902 main cartridge RAM device header.
 */
#ifndef __LR35902_MEMORY_DEVICE_CARTRIDGE_DEVICE_H__
#define __LR35902_MEMORY_DEVICE_CARTRIDGE_DEVICE_H__

#include <Core/Bus/MemoryDevice.h>
#include <API/Memory/Memory.h>
#include <API/Definitions.h>
#include <algorithm>

namespace Core
{
class [[nodiscard]] CartridgeDevice : public MemoryDevice<0x0000, 0x7FFF>
{
public:
	explicit CartridgeDevice(API::IMemoryDeviceAccess& memory_accessor) : MemoryDevice{memory_accessor} {}
	virtual ~CartridgeDevice() override = default;

public:
	[[nodiscard]] virtual bool Read(const API::address_t absolute_address, API::data_t& result) const override
	{
		// While 0xFF50 isn't 0x1, we still return the system_boot code.
		if (!this->_covered_system_boot && this->RelativeAddress(absolute_address) < BOOT_END_ADDRESS)
		{
			result = API::SYSTEM_BOOT_CODE[this->RelativeAddress(absolute_address)];
		}
		else
		{
			return MemoryDevice::Read(absolute_address, result);
		}

		return true;
	}

public:
	/**
	 * Will be called when the system boot code will be swapped with the cartridge code.
	 */
	inline void CoverSystemBoot() { this->_covered_system_boot = true; }
	[[nodiscard]] const bool IsBootCovered() const { return this->_covered_system_boot; }

public:
	// Public for all the MBCS
	[[nodiscard]] virtual uint8_t* GetMemoryPointer() override { return MemoryDevice::GetMemoryPointer(); }

public:
	static constexpr API::address_t BOOT_END_ADDRESS{0x0100};

private:
	bool _covered_system_boot{SKIP_BOOT ? true : false};

private:
	friend class DeviceManager;
};
} // Core

#endif // __LR35902_MEMORY_DEVICE_CARTRIDGE_RAM_H__
