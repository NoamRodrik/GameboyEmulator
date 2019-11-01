/**
 * @file        RST.h
 * @author      Noam Rodrik
 * @description Implementation to the RST instruction(s).
 */
#ifndef __LR35902_RST_H__
#define __LR35902_RST_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
auto RST_OFFSET = [](const address_t offset)
{
	Message("ADDED +1 to RST because we need to skip RST size.");
	SP.Push(static_cast<const address_t>(PC_const + 1 + 1));
	PC = offset;

	return false;
};

// 0xC7 RST 00H
// - - - -
auto RST_0xC7 = []()
{
	return RST_OFFSET(0x00);
};

// 0xCF RST 08H
// - - - -
auto RST_0xCF = []()
{
	return RST_OFFSET(0x08);
};

// 0xD7 RST 10H
// - - - -
auto RST_0xD7 = []()
{
	return RST_OFFSET(0x10);
};

// 0xDF RST 18H
// - - - -
auto RST_0xDF = []()
{
	return RST_OFFSET(0x18);
};

// 0xE7 RST 20H
// - - - -
auto RST_0xE7 = []()
{
	return RST_OFFSET(0x20);
};

// 0xEF RST 28H
// - - - -
auto RST_0xEF = []()
{
	return RST_OFFSET(0x28);
};

// 0xF7 RST 30H
// - - - -
auto RST_0xF7 = []()
{
	return RST_OFFSET(0x30);
};

// 0xFF RST 38H
// - - - -
auto RST_0xFF = []()
{
	return RST_OFFSET(0x38);
};
} // Core

#endif // __LR35902_RST_H__