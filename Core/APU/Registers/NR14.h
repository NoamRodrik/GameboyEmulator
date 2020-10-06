/**
 * @file		NR14.h
 * @author		Noam Rodrik
 * @description LR35902's main apu NR14 definition header.
 */
#ifndef __LR35902_NR14_H__
#define __LR35902_NR14_H__

#include <Core/CPU/Registers/MemoryRegister.h>

namespace Core
{
class NR14 : public MemoryRegister<API::data_t>
{
public:
	constexpr NR14() : MemoryRegister{NR14_ADDRESS} {}
	NR14(const API::data_t value) : MemoryRegister{NR14_ADDRESS} { *this = value; }

public:
	using MemoryRegister::operator=;
	using MemoryRegister::operator API::data_t;

public:
	static constexpr API::address_t NR14_ADDRESS{0xFF14};
	static constexpr API::address_t NR14_DEFAULT_VALUE{0xBF};
};
} // Core

#endif // __LR35902_NR14_H__