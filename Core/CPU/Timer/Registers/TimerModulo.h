/**
 * @file		TimerModulo.h
 * @author		Noam Rodrik
 * @description LR35902 main timer modulo register definition header.
 */
#ifndef __LR35902_TIMER_MODULO_REGISTER_H__
#define __LR35902_TIMER_MODULO_REGISTER_H__

#include <Core/Registers/Memory/MemoryRegister.h>
#include "TimerCounter.h"

namespace Core
{
class TimerModulo : public MemoryRegister<API::data_t>
{
public:
	TimerModulo() : MemoryRegister{API::TIMER_MODULO_ADDRESS} {}
	TimerModulo(const API::data_t value) : MemoryRegister{API::TIMER_MODULO_ADDRESS} { *this = value; }

public:
	using MemoryRegister::operator API::data_t;
	using MemoryRegister::operator=;

public:
	static constexpr auto TIMER_MODULO_DEFAULT_VALUE = 0;
};
} // Core

#endif // __LR35902_TIMER_MODULO_REGISTER_H__