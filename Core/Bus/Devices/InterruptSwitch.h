/**
 * @file		InterruptSwitch.h
 * @author		Noam Rodrik
 * @description LR35902 main interrupt switch header.
 */
#ifndef __LR35902_MEMORY_DEVICE_INTERRUPT_SWITCH_H__
#define __LR35902_MEMORY_DEVICE_INTERRUPT_SWITCH_H__

#include <Core/CPU/Interrupts/Registers/InterruptEnable.h>
#include <Core/Bus/RAMDevice.h>
#include <API/Definitions.h>

namespace Core
{
class InterruptSwitch : public RAMDevice<0xFFFF, 0xFFFF>
{
public:
	constexpr InterruptSwitch(API::IMemoryDeviceAccess& memory_accessor) : RAMDevice{memory_accessor}
	{
		// Default value for the interrupt flag
		this->_memory[this->RelativeAddress(InterruptEnable::INTERRUPT_ENABLE_ADDRESS)] =
					   InterruptEnable::INTERRUPT_ENABLE_DEFAULT_VALUE;
	}

private:
	friend class DeviceManager;
};
} // Core

#endif // __LR35902_MEMORY_DEVICE_INTERRUPT_SWITCH_H__
