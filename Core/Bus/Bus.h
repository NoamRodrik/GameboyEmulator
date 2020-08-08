/**
 * @file		Bus.h
 * @author		Noam Rodrik
 * @description LR35902 main bus definition header.
 */
#ifndef __LR35902_BUS_H__
#define __LR35902_BUS_H__

#include <Core/Bus/Devices/DeviceManagerBase.h>
#include <Core/Bus/Devices/DeviceManager.h>

namespace Core
{
class Bus : public IMemoryDeviceAccess
{
public:
	virtual void Write(const address_t absolute_address, const data_t data) override
	{
		this->m_device_manager.Write(absolute_address, data);
	}

	virtual bool Read(const address_t absolute_address, data_t& result) const override
	{
		return this->m_device_manager.Read(absolute_address, result);
	}

	MemoryDeviceBase* GetDeviceAtAddress(const address_t absolute_address)
	{
		return this->m_device_manager.GetDeviceAtAddress(absolute_address);
	}

private:
	DeviceManager m_device_manager;

private:
	friend class Timer;
};
} // Core

#endif // __LR35902_BUS_H__
