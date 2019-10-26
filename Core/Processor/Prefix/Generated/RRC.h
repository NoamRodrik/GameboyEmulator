/**
 * @file        RRC.h
 * @author      Noam Rodrik
 * @description Implementation to the RRC instruction(s).
 */
#ifndef __LR35902_RRC_H__
#define __LR35902_RRC_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
// RRC reg
// Z 0 0 C
auto RRC_REG = [](auto& reg)
{
	F.Clear(Flag::SUB);
	F.Clear(Flag::HALF_CARRY);

	// Fetching the utmost left bit.
	uint8_t shifted_bit = reg & 0x01;
	F.MutateByCondition(shifted_bit == 0x01, Flag::CARRY);

	// Rotate right A.
	// Restore shifted_bit's position.
	reg >>= 1;
	shifted_bit <<= 7;
	reg |= shifted_bit;
	F.MutateByCondition(reg == 0, Flag::ZERO);
	return true;
};

// 0x08 RRC B
// Z 0 0 C
auto RRC_0x08 = []()
{
	return RRC_REG(B);
};

// 0x09 RRC C
// Z 0 0 C
auto RRC_0x09 = []()
{
	return RRC_REG(C);
};

// 0x0A RRC D
// Z 0 0 C
auto RRC_0x0A = []()
{
	return RRC_REG(D);
};

// 0x0B RRC E
// Z 0 0 C
auto RRC_0x0B = []()
{
	return RRC_REG(E);
};

// 0x0C RRC H
// Z 0 0 C
auto RRC_0x0C = []()
{
	return RRC_REG(H);
};

// 0x0D RRC L
// Z 0 0 C
auto RRC_0x0D = []()
{
	return RRC_REG(L);
};

// 0x0E RRC (HL)
// Z 0 0 C
auto RRC_0x0E = []()
{
	return RunCommandAtAddress(HL_const, RRC_REG);
};

// 0x0F RRC A
// Z 0 0 C
auto RRC_0x0F = []()
{
	return RRC_REG(A);
};
} // Core

#endif // __LR35902_RRC_H__