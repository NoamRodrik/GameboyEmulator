/**
 * @file        LDH.h
 * @author      Noam Rodrik
 * @description Implementation to the LDH instruction(s).
 */
#ifndef __LR35902_LDH_H__
#define __LR35902_LDH_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
// 0xE0 LDH (a8),A
// - - - -
auto LDH_0xE0 = []()
{
	memory.Write(A8() + ZERO_PAGE_ADDRESS, A_const);
	return true;
};

// 0xF0 LDH A,(a8)
// - - - -
auto LDH_0xF0 = []()
{
	return memory.Read(A8() + ZERO_PAGE_ADDRESS, A);
};
} // Core

#endif // __LR35902_LDH_H__