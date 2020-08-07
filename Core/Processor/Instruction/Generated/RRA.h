/**
 * @file        RRA.h
 * @author      Noam Rodrik
 * @description Implementation to the RRA instruction(s).
 */
#ifndef __LR35902_RRA_H__
#define __LR35902_RRA_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>
#include <Core/Processor/Instruction/Prefix/Generated/RR.h>

namespace Core
{
// 0x1F RRA
// 0 0 0 C
auto RRA_0x1F = []()
{
	const bool result = RR_0x1F();
	F.Clear(Flag::ZERO);
	return result;
};
} // Core

#endif // __LR35902_RRA_H__