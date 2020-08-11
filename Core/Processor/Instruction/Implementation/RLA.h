/**
 * @file        RLA.h
 * @author      Noam Rodrik
 * @description Implementation to the RLA instruction(s).
 */
#ifndef __LR35902_RLA_H__
#define __LR35902_RLA_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>
#include <Core/Processor/Instruction/Prefix/Implementation/RL.h>

namespace Core
{
// 0x17 RLA
// 0 0 0 C
static constexpr auto RLA_0x17 = []()
{
	const bool RESULT = RL_0x17();
	F.Clear(Flag::ZERO);
	return RESULT;
};
} // Core

#endif // __LR35902_RLA_H__