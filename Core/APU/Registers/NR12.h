/**
 * @file		NR12.h
 * @author		Noam Rodrik
 * @description LR35902's main apu NR12 definition header.
 */
#ifndef __LR35902_NR12_H__
#define __LR35902_NR12_H__

#include <Core/CPU/Registers/MemoryRegister.h>

namespace Core
{
class [[nodiscard]] NR12 : public MemoryRegister<API::data_t>
{
public:
	constexpr NR12() : MemoryRegister{NR12_ADDRESS} {}
	NR12(const API::data_t value) : MemoryRegister{NR12_ADDRESS} { *this = value; }

public:
	using MemoryRegister::operator=;
	using MemoryRegister::operator API::data_t;

public:
	[[nodiscard]] const API::data_t GetEnvelopeSweep() const
	{
		return ((this->operator API::data_t()) >> ENVELOPE_SWEEP_BIT_INDEX) & 0b111;
	}

	[[nodiscard]] const bool GetEnvelopeDirection() const
	{
		return ((this->operator API::data_t()) >> ENVELOPE_DIRECTION_BIT_INDEX) & 0b01;
	}

	[[nodiscard]] const API::data_t GetEnvelopeVolume() const
	{
		return ((this->operator API::data_t()) >> ENVELOPE_VOLUME_BIT_INDEX) & 0b1111;
	}

public:
	static constexpr API::data_t    ENVELOPE_VOLUME_BIT_INDEX{0x04};
	static constexpr API::data_t    ENVELOPE_DIRECTION_BIT_INDEX{0x03};
	static constexpr API::data_t    ENVELOPE_SWEEP_BIT_INDEX{0x00};
	static constexpr API::address_t NR12_ADDRESS{0xFF12};
	static constexpr API::address_t NR12_DEFAULT_VALUE{0xF3};
};
} // Core

#endif // __LR35902_NR12_H__