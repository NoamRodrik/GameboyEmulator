/**
 * @file        PUSH.h
 * @author      Noam Rodrik
 * @description Implementation to the PUSH instruction(s).
 */
#ifndef __LR35902_PUSH_H__
#define __LR35902_PUSH_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
// 0xC5 PUSH BC
// - - - -
auto PUSH_0xC5 = []()
{
	SP.Push(B_const);
	SP.Push(C_const);
	return true;
};

// 0xD5 PUSH DE
// - - - -
auto PUSH_0xD5 = []()
{
	SP.Push(D_const);
	SP.Push(E_const);
	return true;
};

// 0xE5 PUSH HL
// - - - -
auto PUSH_0xE5 = []()
{
	SP.Push(H_const);
	SP.Push(L_const);
	return true;
};

// 0xF5 PUSH AF
// - - - -
auto PUSH_0xF5 = []()
{
	SP.Push(A_const);
	SP.Push(F_const);
	return true;
};
} // Core

#endif // __LR35902_PUSH_H__