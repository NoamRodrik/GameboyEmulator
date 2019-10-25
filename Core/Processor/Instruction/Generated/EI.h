/**
 * @file        EI.h
 * @author      Noam Rodrik
 * @description Implementation to the EI instruction(s).
 */
#ifndef __LR35902_EI_H__
#define __LR35902_EI_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
// 0xFB EI
// - - - -
auto EI_0xFB = []()
{
	memory.Write(ON, InterruptSwitch::START_ADDRESS);
};
} // Core

#endif // __LR35902_EI_H__