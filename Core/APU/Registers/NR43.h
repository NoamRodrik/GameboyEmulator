/**
 * @file		NR43.h
 * @author		Noam Rodrik
 * @description LR35902's main apu NR43 definition header.
 */
#ifndef __LR35902_NR43_H__
#define __LR35902_NR43_H__

#include <Core/CPU/Registers/DeviceRegister.h>

namespace Core
{
class [[nodiscard]] NR43 : public DeviceRegister<0xFF22>
{
public:
	using DeviceRegister::DeviceRegister;
	using DeviceRegister::operator=;
	using DeviceRegister::operator API::data_t;

public:
	[[nodiscard]] const API::data_t GetRatioOfFrequencies() const
	{
		return (static_cast<API::data_t>(*this) >> NR43_RATIO_BIT) & 0b111;
	}

	[[nodiscard]] const API::data_t GetShiftClockFrequency() const
	{
		return (static_cast<API::data_t>(*this) >> NR43_SHIFT_BIT) & 0b1111;
	}

	[[nodiscard]] const bool IsCounterStep7Bits() const
	{
		return (static_cast<API::data_t>(*this) >> NR43_COUNTER_STEP_BITS) & 0b01;
	}

public:
	static constexpr API::data_t NR43_SHIFT_BIT{0x04};
	static constexpr API::data_t NR43_COUNTER_STEP_BITS{0x03};
	static constexpr API::data_t NR43_RATIO_BIT{0x00};
	static constexpr API::data_t NR43_DEFAULT_VALUE{0x00};
};
} // Core

#endif // __LR35902_NR43_H__