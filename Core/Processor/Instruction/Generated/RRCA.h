/**
 * @file        RRCA.h
 * @author      Noam Rodrik
 * @description Implementation to the RRCA instruction(s).
 */
#ifndef __LR35902_RRCA_H__
#define __LR35902_RRCA_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>
#include <Core/Processor/Prefix/Generated/RRC.h>

namespace Core
{
// 0x0F RRCA
// 0 0 0 C
auto RRCA_0x0F = []()
{
	const bool result = RRC_0x0F();
	F.Clear(Flag::ZERO);
	return result;
};
} // Core

#endif // __LR35902_RRCA_H__