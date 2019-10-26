/**
 * @file        RETI.h
 * @author      Noam Rodrik
 * @description Implementation to the RETI instruction(s).
 */
#ifndef __LR35902_RETI_H__
#define __LR35902_RETI_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>
#include "EI.h"
namespace Core
{
// 0xD9 RETI
// - - - -
auto RETI_0xD9 = []()
{
	// Pop two bytes from stack & jump to that address then
	// enable interrupts
	SP.Pop(IP);
	EI_0xFB();

	// Don't want to change IP!
	return false;
};
} // Core

#endif // __LR35902_RETI_H__