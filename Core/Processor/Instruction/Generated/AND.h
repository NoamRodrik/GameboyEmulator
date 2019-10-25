/**
 * @file        AND.h
 * @author      Noam Rodrik
 * @description Implementation to the AND instruction(s).
 */
#ifndef __LR35902_AND_H__
#define __LR35902_AND_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
// AND data
// Z 0 1 0
auto AND_WITH_A = [](const auto data)
{
	A &= data;

	F.MutateByCondition(A == 0, Flag::ZERO);
	F.Clear(Flag::SUB);
	F.Clear(Flag::CARRY);
	F.Set(Flag::HALF_CARRY);
};

// 0xA0 AND B
// Z 0 1 0
auto AND_0xA0 = []()
{
	AND_WITH_A(B_const);
};

// 0xA1 AND C
// Z 0 1 0
auto AND_0xA1 = []()
{
	AND_WITH_A(C_const);
};

// 0xA2 AND D
// Z 0 1 0
auto AND_0xA2 = []()
{
	AND_WITH_A(D_const);
};

// 0xA3 AND E
// Z 0 1 0
auto AND_0xA3 = []()
{
	AND_WITH_A(E_const);
};

// 0xA4 AND H
// Z 0 1 0
auto AND_0xA4 = []()
{
	AND_WITH_A(H_const);
};

// 0xA5 AND L
// Z 0 1 0
auto AND_0xA5 = []()
{
	AND_WITH_A(L_const);
};

// 0xA6 AND (HL)
// Z 0 1 0
auto AND_0xA6 = []()
{
	AND_WITH_A(DataAt(HL_const));
};

// 0xA7 AND A
// Z 0 1 0
auto AND_0xA7 = []()
{
	AND_WITH_A(A_const);
};

// 0xE6 AND d8
// Z 0 1 0
auto AND_0xE6 = []()
{
	AND_WITH_A(DataAt(IP_const + 1));
};
} // Core

#endif // __LR35902_AND_H__