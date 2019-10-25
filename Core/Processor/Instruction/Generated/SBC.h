/**
 * @file        SBC.h
 * @author      Noam Rodrik
 * @description Implementation to the SBC instruction(s).
 */
#ifndef __LR35902_SBC_H__
#define __LR35902_SBC_H__

#include <Core/Processor/Processor.h>
#include <Core/Processor/Instruction/Shortcuts.h>

namespace Core
{
// 0x98 SBC A,B
// Z 1 H C
auto SBC_0x98 = []()
{

};

// 0x99 SBC A,C
// Z 1 H C
auto SBC_0x99 = []()
{

};

// 0x9A SBC A,D
// Z 1 H C
auto SBC_0x9A = []()
{

};

// 0x9B SBC A,E
// Z 1 H C
auto SBC_0x9B = []()
{

};

// 0x9C SBC A,H
// Z 1 H C
auto SBC_0x9C = []()
{

};

// 0x9D SBC A,L
// Z 1 H C
auto SBC_0x9D = []()
{

};

// 0x9E SBC A,(HL)
// Z 1 H C
auto SBC_0x9E = []()
{

};

// 0x9F SBC A,A
// Z 1 H C
auto SBC_0x9F = []()
{

};

// 0xDE SBC A,d8
// Z 1 H C
auto SBC_0xDE = []()
{

};
} // Core

#endif // __LR35902_SBC_H__