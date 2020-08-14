/**
 * @file		InterruptFlag.h
 * @author		Noam Rodrik
 * @description LR35902 main interrupt flag definition header.
 */
#ifndef __LR35902_INTERRUPT_FLAG_H__
#define __LR35902_INTERRUPT_FLAG_H__

#include <Core/CPU/Registers/MemoryRegister.h>

namespace Core
{
class InterruptFlag : public MemoryRegister<API::data_t>
{
public:
	InterruptFlag() : MemoryRegister{INTERRUPT_FLAG_ADDRESS} {}
	InterruptFlag(const API::data_t value) : MemoryRegister{INTERRUPT_FLAG_ADDRESS} {*this = value;}

public:
	using MemoryRegister::operator=;
	using MemoryRegister::operator API::data_t;

public:
	static constexpr API::address_t INTERRUPT_FLAG_ADDRESS{0xFF0F};
	static constexpr API::data_t	INTERRUPT_FLAG_DEFAULT_VALUE{0x00};
};
} // Core

#endif // __LR35902_INTERRUPT_FLAG_H__