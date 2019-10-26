/**
 * @file		PrefixLookupTable.h
 * @author		Noam Rodrik
 * @description A lookup table for all prefix instruction sequences.
 */
#ifndef __PREFIX_LOOKUP_TABLE_H__
#define __PREFIX_LOOKUP_TABLE_H__

#include <Core/Processor/Instruction/Instruction.h>
#include <Tools/Tools.h>
#include <array>

 /* Instruction includes */
#include <Core/Processor/Prefix/Generated/RLC.h>
#include <Core/Processor/Prefix/Generated/RRC.h>
#include <Core/Processor/Prefix/Generated/RL.h>
#include <Core/Processor/Prefix/Generated/RR.h>
#include <Core/Processor/Prefix/Generated/SLA.h>
#include <Core/Processor/Prefix/Generated/SRA.h>
#include <Core/Processor/Prefix/Generated/SWAP.h>
#include <Core/Processor/Prefix/Generated/SRL.h>
#include <Core/Processor/Prefix/Generated/BIT.h>
#include <Core/Processor/Prefix/Generated/RES.h>
#include <Core/Processor/Prefix/Generated/SET.h>

namespace Core
{
	Message("Complete the prefix table!");
	static const std::array<Instruction, 0x10 * 0x10> PREFIX_LOOKUP_TABLE =
	{
		// 0x00 RLC B
		// Z 0 0 C
		Instruction{RLC_0x00, 2, 8, 0, "RLC B"},

		// 0x01 RLC C
		// Z 0 0 C
		Instruction{RLC_0x01, 2, 8, 0, "RLC C"},

		// 0x02 RLC D
		// Z 0 0 C
		Instruction{RLC_0x02, 2, 8, 0, "RLC D"},

		// 0x03 RLC E
		// Z 0 0 C
		Instruction{RLC_0x03, 2, 8, 0, "RLC E"},

		// 0x04 RLC H
		// Z 0 0 C
		Instruction{RLC_0x04, 2, 8, 0, "RLC H"},

		// 0x05 RLC L
		// Z 0 0 C
		Instruction{RLC_0x05, 2, 8, 0, "RLC L"},

		// 0x06 RLC (HL)
		// Z 0 0 C
		Instruction{RLC_0x06, 2, 16, 0, "RLC (HL)"},

		// 0x07 RLC A
		// Z 0 0 C
		Instruction{RLC_0x07, 2, 8, 0, "RLC A"},

		// 0x08 RRC B
		// Z 0 0 C
		Instruction{RRC_0x08, 2, 8, 0, "RRC B"},

		// 0x09 RRC C
		// Z 0 0 C
		Instruction{RRC_0x09, 2, 8, 0, "RRC C"},

		// 0x0A RRC D
		// Z 0 0 C
		Instruction{RRC_0x0A, 2, 8, 0, "RRC D"},

		// 0x0B RRC E
		// Z 0 0 C
		Instruction{RRC_0x0B, 2, 8, 0, "RRC E"},

		// 0x0C RRC H
		// Z 0 0 C
		Instruction{RRC_0x0C, 2, 8, 0, "RRC H"},

		// 0x0D RRC L
		// Z 0 0 C
		Instruction{RRC_0x0D, 2, 8, 0, "RRC L"},

		// 0x0E RRC (HL)
		// Z 0 0 C
		Instruction{RRC_0x0E, 2, 16, 0, "RRC (HL)"},

		// 0x0F RRC A
		// Z 0 0 C
		Instruction{RRC_0x0F, 2, 8, 0, "RRC A"},

		// 0x10 RL B
		// Z 0 0 C
		Instruction{RL_0x10, 2, 8, 0, "RL B"},

		// 0x11 RL C
		// Z 0 0 C
		Instruction{RL_0x11, 2, 8, 0, "RL C"},

		// 0x12 RL D
		// Z 0 0 C
		Instruction{RL_0x12, 2, 8, 0, "RL D"},

		// 0x13 RL E
		// Z 0 0 C
		Instruction{RL_0x13, 2, 8, 0, "RL E"},

		// 0x14 RL H
		// Z 0 0 C
		Instruction{RL_0x14, 2, 8, 0, "RL H"},

		// 0x15 RL L
		// Z 0 0 C
		Instruction{RL_0x15, 2, 8, 0, "RL L"},

		// 0x16 RL (HL)
		// Z 0 0 C
		Instruction{RL_0x16, 2, 16, 0, "RL (HL)"},

		// 0x17 RL A
		// Z 0 0 C
		Instruction{RL_0x17, 2, 8, 0, "RL A"},

		// 0x18 RR B
		// Z 0 0 C
		Instruction{RR_0x18, 2, 8, 0, "RR B"},

		// 0x19 RR C
		// Z 0 0 C
		Instruction{RR_0x19, 2, 8, 0, "RR C"},

		// 0x1A RR D
		// Z 0 0 C
		Instruction{RR_0x1A, 2, 8, 0, "RR D"},

		// 0x1B RR E
		// Z 0 0 C
		Instruction{RR_0x1B, 2, 8, 0, "RR E"},

		// 0x1C RR H
		// Z 0 0 C
		Instruction{RR_0x1C, 2, 8, 0, "RR H"},

		// 0x1D RR L
		// Z 0 0 C
		Instruction{RR_0x1D, 2, 8, 0, "RR L"},

		// 0x1E RR (HL)
		// Z 0 0 C
		Instruction{RR_0x1E, 2, 16, 0, "RR (HL)"},

		// 0x1F RR A
		// Z 0 0 C
		Instruction{RR_0x1F, 2, 8, 0, "RR A"},

		// 0x20 SLA B
		// Z 0 0 C
		Instruction{SLA_0x20, 2, 8, 0, "SLA B"},

		// 0x21 SLA C
		// Z 0 0 C
		Instruction{SLA_0x21, 2, 8, 0, "SLA C"},

		// 0x22 SLA D
		// Z 0 0 C
		Instruction{SLA_0x22, 2, 8, 0, "SLA D"},

		// 0x23 SLA E
		// Z 0 0 C
		Instruction{SLA_0x23, 2, 8, 0, "SLA E"},

		// 0x24 SLA H
		// Z 0 0 C
		Instruction{SLA_0x24, 2, 8, 0, "SLA H"},

		// 0x25 SLA L
		// Z 0 0 C
		Instruction{SLA_0x25, 2, 8, 0, "SLA L"},

		// 0x26 SLA (HL)
		// Z 0 0 C
		Instruction{SLA_0x26, 2, 16, 0, "SLA (HL)"},

		// 0x27 SLA A
		// Z 0 0 C
		Instruction{SLA_0x27, 2, 8, 0, "SLA A"},

		// 0x28 SRA B
		// Z 0 0 0
		Instruction{SRA_0x28, 2, 8, 0, "SRA B"},

		// 0x29 SRA C
		// Z 0 0 0
		Instruction{SRA_0x29, 2, 8, 0, "SRA C"},

		// 0x2A SRA D
		// Z 0 0 0
		Instruction{SRA_0x2A, 2, 8, 0, "SRA D"},

		// 0x2B SRA E
		// Z 0 0 0
		Instruction{SRA_0x2B, 2, 8, 0, "SRA E"},

		// 0x2C SRA H
		// Z 0 0 0
		Instruction{SRA_0x2C, 2, 8, 0, "SRA H"},

		// 0x2D SRA L
		// Z 0 0 0
		Instruction{SRA_0x2D, 2, 8, 0, "SRA L"},

		// 0x2E SRA (HL)
		// Z 0 0 0
		Instruction{SRA_0x2E, 2, 16, 0, "SRA (HL)"},

		// 0x2F SRA A
		// Z 0 0 0
		Instruction{SRA_0x2F, 2, 8, 0, "SRA A"},

		// 0x30 SWAP B
		// Z 0 0 0
		Instruction{SWAP_0x30, 2, 8, 0, "SWAP B"},

		// 0x31 SWAP C
		// Z 0 0 0
		Instruction{SWAP_0x31, 2, 8, 0, "SWAP C"},

		// 0x32 SWAP D
		// Z 0 0 0
		Instruction{SWAP_0x32, 2, 8, 0, "SWAP D"},

		// 0x33 SWAP E
		// Z 0 0 0
		Instruction{SWAP_0x33, 2, 8, 0, "SWAP E"},

		// 0x34 SWAP H
		// Z 0 0 0
		Instruction{SWAP_0x34, 2, 8, 0, "SWAP H"},

		// 0x35 SWAP L
		// Z 0 0 0
		Instruction{SWAP_0x35, 2, 8, 0, "SWAP L"},

		// 0x36 SWAP (HL)
		// Z 0 0 0
		Instruction{SWAP_0x36, 2, 16, 0, "SWAP (HL)"},

		// 0x37 SWAP A
		// Z 0 0 0
		Instruction{SWAP_0x37, 2, 8, 0, "SWAP A"},

		// 0x38 SRL B
		// Z 0 0 C
		Instruction{SRL_0x38, 2, 8, 0, "SRL B"},

		// 0x39 SRL C
		// Z 0 0 C
		Instruction{SRL_0x39, 2, 8, 0, "SRL C"},

		// 0x3A SRL D
		// Z 0 0 C
		Instruction{SRL_0x3A, 2, 8, 0, "SRL D"},

		// 0x3B SRL E
		// Z 0 0 C
		Instruction{SRL_0x3B, 2, 8, 0, "SRL E"},

		// 0x3C SRL H
		// Z 0 0 C
		Instruction{SRL_0x3C, 2, 8, 0, "SRL H"},

		// 0x3D SRL L
		// Z 0 0 C
		Instruction{SRL_0x3D, 2, 8, 0, "SRL L"},

		// 0x3E SRL (HL)
		// Z 0 0 C
		Instruction{SRL_0x3E, 2, 16, 0, "SRL (HL)"},

		// 0x3F SRL A
		// Z 0 0 C
		Instruction{SRL_0x3F, 2, 8, 0, "SRL A"},

		// 0x40 BIT 0,B
		// Z 0 1 -
		Instruction{BIT_0x40, 2, 8, 0, "BIT 0,B"},

		// 0x41 BIT 0,C
		// Z 0 1 -
		Instruction{BIT_0x41, 2, 8, 0, "BIT 0,C"},

		// 0x42 BIT 0,D
		// Z 0 1 -
		Instruction{BIT_0x42, 2, 8, 0, "BIT 0,D"},

		// 0x43 BIT 0,E
		// Z 0 1 -
		Instruction{BIT_0x43, 2, 8, 0, "BIT 0,E"},

		// 0x44 BIT 0,H
		// Z 0 1 -
		Instruction{BIT_0x44, 2, 8, 0, "BIT 0,H"},

		// 0x45 BIT 0,L
		// Z 0 1 -
		Instruction{BIT_0x45, 2, 8, 0, "BIT 0,L"},

		// 0x46 BIT 0,(HL)
		// Z 0 1 -
		Instruction{BIT_0x46, 2, 16, 0, "BIT 0,(HL)"},

		// 0x47 BIT 0,A
		// Z 0 1 -
		Instruction{BIT_0x47, 2, 8, 0, "BIT 0,A"},

		// 0x48 BIT 1,B
		// Z 0 1 -
		Instruction{BIT_0x48, 2, 8, 0, "BIT 1,B"},

		// 0x49 BIT 1,C
		// Z 0 1 -
		Instruction{BIT_0x49, 2, 8, 0, "BIT 1,C"},

		// 0x4A BIT 1,D
		// Z 0 1 -
		Instruction{BIT_0x4A, 2, 8, 0, "BIT 1,D"},

		// 0x4B BIT 1,E
		// Z 0 1 -
		Instruction{BIT_0x4B, 2, 8, 0, "BIT 1,E"},

		// 0x4C BIT 1,H
		// Z 0 1 -
		Instruction{BIT_0x4C, 2, 8, 0, "BIT 1,H"},

		// 0x4D BIT 1,L
		// Z 0 1 -
		Instruction{BIT_0x4D, 2, 8, 0, "BIT 1,L"},

		// 0x4E BIT 1,(HL)
		// Z 0 1 -
		Instruction{BIT_0x4E, 2, 16, 0, "BIT 1,(HL)"},

		// 0x4F BIT 1,A
		// Z 0 1 -
		Instruction{BIT_0x4F, 2, 8, 0, "BIT 1,A"},

		// 0x50 BIT 2,B
		// Z 0 1 -
		Instruction{BIT_0x50, 2, 8, 0, "BIT 2,B"},

		// 0x51 BIT 2,C
		// Z 0 1 -
		Instruction{BIT_0x51, 2, 8, 0, "BIT 2,C"},

		// 0x52 BIT 2,D
		// Z 0 1 -
		Instruction{BIT_0x52, 2, 8, 0, "BIT 2,D"},

		// 0x53 BIT 2,E
		// Z 0 1 -
		Instruction{BIT_0x53, 2, 8, 0, "BIT 2,E"},

		// 0x54 BIT 2,H
		// Z 0 1 -
		Instruction{BIT_0x54, 2, 8, 0, "BIT 2,H"},

		// 0x55 BIT 2,L
		// Z 0 1 -
		Instruction{BIT_0x55, 2, 8, 0, "BIT 2,L"},

		// 0x56 BIT 2,(HL)
		// Z 0 1 -
		Instruction{BIT_0x56, 2, 16, 0, "BIT 2,(HL)"},

		// 0x57 BIT 2,A
		// Z 0 1 -
		Instruction{BIT_0x57, 2, 8, 0, "BIT 2,A"},

		// 0x58 BIT 3,B
		// Z 0 1 -
		Instruction{BIT_0x58, 2, 8, 0, "BIT 3,B"},

		// 0x59 BIT 3,C
		// Z 0 1 -
		Instruction{BIT_0x59, 2, 8, 0, "BIT 3,C"},

		// 0x5A BIT 3,D
		// Z 0 1 -
		Instruction{BIT_0x5A, 2, 8, 0, "BIT 3,D"},

		// 0x5B BIT 3,E
		// Z 0 1 -
		Instruction{BIT_0x5B, 2, 8, 0, "BIT 3,E"},

		// 0x5C BIT 3,H
		// Z 0 1 -
		Instruction{BIT_0x5C, 2, 8, 0, "BIT 3,H"},

		// 0x5D BIT 3,L
		// Z 0 1 -
		Instruction{BIT_0x5D, 2, 8, 0, "BIT 3,L"},

		// 0x5E BIT 3,(HL)
		// Z 0 1 -
		Instruction{BIT_0x5E, 2, 16, 0, "BIT 3,(HL)"},

		// 0x5F BIT 3,A
		// Z 0 1 -
		Instruction{BIT_0x5F, 2, 8, 0, "BIT 3,A"},

		// 0x60 BIT 4,B
		// Z 0 1 -
		Instruction{BIT_0x60, 2, 8, 0, "BIT 4,B"},

		// 0x61 BIT 4,C
		// Z 0 1 -
		Instruction{BIT_0x61, 2, 8, 0, "BIT 4,C"},

		// 0x62 BIT 4,D
		// Z 0 1 -
		Instruction{BIT_0x62, 2, 8, 0, "BIT 4,D"},

		// 0x63 BIT 4,E
		// Z 0 1 -
		Instruction{BIT_0x63, 2, 8, 0, "BIT 4,E"},

		// 0x64 BIT 4,H
		// Z 0 1 -
		Instruction{BIT_0x64, 2, 8, 0, "BIT 4,H"},

		// 0x65 BIT 4,L
		// Z 0 1 -
		Instruction{BIT_0x65, 2, 8, 0, "BIT 4,L"},

		// 0x66 BIT 4,(HL)
		// Z 0 1 -
		Instruction{BIT_0x66, 2, 16, 0, "BIT 4,(HL)"},

		// 0x67 BIT 4,A
		// Z 0 1 -
		Instruction{BIT_0x67, 2, 8, 0, "BIT 4,A"},

		// 0x68 BIT 5,B
		// Z 0 1 -
		Instruction{BIT_0x68, 2, 8, 0, "BIT 5,B"},

		// 0x69 BIT 5,C
		// Z 0 1 -
		Instruction{BIT_0x69, 2, 8, 0, "BIT 5,C"},

		// 0x6A BIT 5,D
		// Z 0 1 -
		Instruction{BIT_0x6A, 2, 8, 0, "BIT 5,D"},

		// 0x6B BIT 5,E
		// Z 0 1 -
		Instruction{BIT_0x6B, 2, 8, 0, "BIT 5,E"},

		// 0x6C BIT 5,H
		// Z 0 1 -
		Instruction{BIT_0x6C, 2, 8, 0, "BIT 5,H"},

		// 0x6D BIT 5,L
		// Z 0 1 -
		Instruction{BIT_0x6D, 2, 8, 0, "BIT 5,L"},

		// 0x6E BIT 5,(HL)
		// Z 0 1 -
		Instruction{BIT_0x6E, 2, 16, 0, "BIT 5,(HL)"},

		// 0x6F BIT 5,A
		// Z 0 1 -
		Instruction{BIT_0x6F, 2, 8, 0, "BIT 5,A"},

		// 0x70 BIT 6,B
		// Z 0 1 -
		Instruction{BIT_0x70, 2, 8, 0, "BIT 6,B"},

		// 0x71 BIT 6,C
		// Z 0 1 -
		Instruction{BIT_0x71, 2, 8, 0, "BIT 6,C"},

		// 0x72 BIT 6,D
		// Z 0 1 -
		Instruction{BIT_0x72, 2, 8, 0, "BIT 6,D"},

		// 0x73 BIT 6,E
		// Z 0 1 -
		Instruction{BIT_0x73, 2, 8, 0, "BIT 6,E"},

		// 0x74 BIT 6,H
		// Z 0 1 -
		Instruction{BIT_0x74, 2, 8, 0, "BIT 6,H"},

		// 0x75 BIT 6,L
		// Z 0 1 -
		Instruction{BIT_0x75, 2, 8, 0, "BIT 6,L"},

		// 0x76 BIT 6,(HL)
		// Z 0 1 -
		Instruction{BIT_0x76, 2, 16, 0, "BIT 6,(HL)"},

		// 0x77 BIT 6,A
		// Z 0 1 -
		Instruction{BIT_0x77, 2, 8, 0, "BIT 6,A"},

		// 0x78 BIT 7,B
		// Z 0 1 -
		Instruction{BIT_0x78, 2, 8, 0, "BIT 7,B"},

		// 0x79 BIT 7,C
		// Z 0 1 -
		Instruction{BIT_0x79, 2, 8, 0, "BIT 7,C"},

		// 0x7A BIT 7,D
		// Z 0 1 -
		Instruction{BIT_0x7A, 2, 8, 0, "BIT 7,D"},

		// 0x7B BIT 7,E
		// Z 0 1 -
		Instruction{BIT_0x7B, 2, 8, 0, "BIT 7,E"},

		// 0x7C BIT 7,H
		// Z 0 1 -
		Instruction{BIT_0x7C, 2, 8, 0, "BIT 7,H"},

		// 0x7D BIT 7,L
		// Z 0 1 -
		Instruction{BIT_0x7D, 2, 8, 0, "BIT 7,L"},

		// 0x7E BIT 7,(HL)
		// Z 0 1 -
		Instruction{BIT_0x7E, 2, 16, 0, "BIT 7,(HL)"},

		// 0x7F BIT 7,A
		// Z 0 1 -
		Instruction{BIT_0x7F, 2, 8, 0, "BIT 7,A"},

		// 0x80 RES 0,B
		// - - - -
		Instruction{RES_0x80, 2, 8, 0, "RES 0,B"},

		// 0x81 RES 0,C
		// - - - -
		Instruction{RES_0x81, 2, 8, 0, "RES 0,C"},

		// 0x82 RES 0,D
		// - - - -
		Instruction{RES_0x82, 2, 8, 0, "RES 0,D"},

		// 0x83 RES 0,E
		// - - - -
		Instruction{RES_0x83, 2, 8, 0, "RES 0,E"},

		// 0x84 RES 0,H
		// - - - -
		Instruction{RES_0x84, 2, 8, 0, "RES 0,H"},

		// 0x85 RES 0,L
		// - - - -
		Instruction{RES_0x85, 2, 8, 0, "RES 0,L"},

		// 0x86 RES 0,(HL)
		// - - - -
		Instruction{RES_0x86, 2, 16, 0, "RES 0,(HL)"},

		// 0x87 RES 0,A
		// - - - -
		Instruction{RES_0x87, 2, 8, 0, "RES 0,A"},

		// 0x88 RES 1,B
		// - - - -
		Instruction{RES_0x88, 2, 8, 0, "RES 1,B"},

		// 0x89 RES 1,C
		// - - - -
		Instruction{RES_0x89, 2, 8, 0, "RES 1,C"},

		// 0x8A RES 1,D
		// - - - -
		Instruction{RES_0x8A, 2, 8, 0, "RES 1,D"},

		// 0x8B RES 1,E
		// - - - -
		Instruction{RES_0x8B, 2, 8, 0, "RES 1,E"},

		// 0x8C RES 1,H
		// - - - -
		Instruction{RES_0x8C, 2, 8, 0, "RES 1,H"},

		// 0x8D RES 1,L
		// - - - -
		Instruction{RES_0x8D, 2, 8, 0, "RES 1,L"},

		// 0x8E RES 1,(HL)
		// - - - -
		Instruction{RES_0x8E, 2, 16, 0, "RES 1,(HL)"},

		// 0x8F RES 1,A
		// - - - -
		Instruction{RES_0x8F, 2, 8, 0, "RES 1,A"},

		// 0x90 RES 2,B
		// - - - -
		Instruction{RES_0x90, 2, 8, 0, "RES 2,B"},

		// 0x91 RES 2,C
		// - - - -
		Instruction{RES_0x91, 2, 8, 0, "RES 2,C"},

		// 0x92 RES 2,D
		// - - - -
		Instruction{RES_0x92, 2, 8, 0, "RES 2,D"},

		// 0x93 RES 2,E
		// - - - -
		Instruction{RES_0x93, 2, 8, 0, "RES 2,E"},

		// 0x94 RES 2,H
		// - - - -
		Instruction{RES_0x94, 2, 8, 0, "RES 2,H"},

		// 0x95 RES 2,L
		// - - - -
		Instruction{RES_0x95, 2, 8, 0, "RES 2,L"},

		// 0x96 RES 2,(HL)
		// - - - -
		Instruction{RES_0x96, 2, 16, 0, "RES 2,(HL)"},

		// 0x97 RES 2,A
		// - - - -
		Instruction{RES_0x97, 2, 8, 0, "RES 2,A"},

		// 0x98 RES 3,B
		// - - - -
		Instruction{RES_0x98, 2, 8, 0, "RES 3,B"},

		// 0x99 RES 3,C
		// - - - -
		Instruction{RES_0x99, 2, 8, 0, "RES 3,C"},

		// 0x9A RES 3,D
		// - - - -
		Instruction{RES_0x9A, 2, 8, 0, "RES 3,D"},

		// 0x9B RES 3,E
		// - - - -
		Instruction{RES_0x9B, 2, 8, 0, "RES 3,E"},

		// 0x9C RES 3,H
		// - - - -
		Instruction{RES_0x9C, 2, 8, 0, "RES 3,H"},

		// 0x9D RES 3,L
		// - - - -
		Instruction{RES_0x9D, 2, 8, 0, "RES 3,L"},

		// 0x9E RES 3,(HL)
		// - - - -
		Instruction{RES_0x9E, 2, 16, 0, "RES 3,(HL)"},

		// 0x9F RES 3,A
		// - - - -
		Instruction{RES_0x9F, 2, 8, 0, "RES 3,A"},

		// 0xA0 RES 4,B
		// - - - -
		Instruction{RES_0xA0, 2, 8, 0, "RES 4,B"},

		// 0xA1 RES 4,C
		// - - - -
		Instruction{RES_0xA1, 2, 8, 0, "RES 4,C"},

		// 0xA2 RES 4,D
		// - - - -
		Instruction{RES_0xA2, 2, 8, 0, "RES 4,D"},

		// 0xA3 RES 4,E
		// - - - -
		Instruction{RES_0xA3, 2, 8, 0, "RES 4,E"},

		// 0xA4 RES 4,H
		// - - - -
		Instruction{RES_0xA4, 2, 8, 0, "RES 4,H"},

		// 0xA5 RES 4,L
		// - - - -
		Instruction{RES_0xA5, 2, 8, 0, "RES 4,L"},

		// 0xA6 RES 4,(HL)
		// - - - -
		Instruction{RES_0xA6, 2, 16, 0, "RES 4,(HL)"},

		// 0xA7 RES 4,A
		// - - - -
		Instruction{RES_0xA7, 2, 8, 0, "RES 4,A"},

		// 0xA8 RES 5,B
		// - - - -
		Instruction{RES_0xA8, 2, 8, 0, "RES 5,B"},

		// 0xA9 RES 5,C
		// - - - -
		Instruction{RES_0xA9, 2, 8, 0, "RES 5,C"},

		// 0xAA RES 5,D
		// - - - -
		Instruction{RES_0xAA, 2, 8, 0, "RES 5,D"},

		// 0xAB RES 5,E
		// - - - -
		Instruction{RES_0xAB, 2, 8, 0, "RES 5,E"},

		// 0xAC RES 5,H
		// - - - -
		Instruction{RES_0xAC, 2, 8, 0, "RES 5,H"},

		// 0xAD RES 5,L
		// - - - -
		Instruction{RES_0xAD, 2, 8, 0, "RES 5,L"},

		// 0xAE RES 5,(HL)
		// - - - -
		Instruction{RES_0xAE, 2, 16, 0, "RES 5,(HL)"},

		// 0xAF RES 5,A
		// - - - -
		Instruction{RES_0xAF, 2, 8, 0, "RES 5,A"},

		// 0xB0 RES 6,B
		// - - - -
		Instruction{RES_0xB0, 2, 8, 0, "RES 6,B"},

		// 0xB1 RES 6,C
		// - - - -
		Instruction{RES_0xB1, 2, 8, 0, "RES 6,C"},

		// 0xB2 RES 6,D
		// - - - -
		Instruction{RES_0xB2, 2, 8, 0, "RES 6,D"},

		// 0xB3 RES 6,E
		// - - - -
		Instruction{RES_0xB3, 2, 8, 0, "RES 6,E"},

		// 0xB4 RES 6,H
		// - - - -
		Instruction{RES_0xB4, 2, 8, 0, "RES 6,H"},

		// 0xB5 RES 6,L
		// - - - -
		Instruction{RES_0xB5, 2, 8, 0, "RES 6,L"},

		// 0xB6 RES 6,(HL)
		// - - - -
		Instruction{RES_0xB6, 2, 16, 0, "RES 6,(HL)"},

		// 0xB7 RES 6,A
		// - - - -
		Instruction{RES_0xB7, 2, 8, 0, "RES 6,A"},

		// 0xB8 RES 7,B
		// - - - -
		Instruction{RES_0xB8, 2, 8, 0, "RES 7,B"},

		// 0xB9 RES 7,C
		// - - - -
		Instruction{RES_0xB9, 2, 8, 0, "RES 7,C"},

		// 0xBA RES 7,D
		// - - - -
		Instruction{RES_0xBA, 2, 8, 0, "RES 7,D"},

		// 0xBB RES 7,E
		// - - - -
		Instruction{RES_0xBB, 2, 8, 0, "RES 7,E"},

		// 0xBC RES 7,H
		// - - - -
		Instruction{RES_0xBC, 2, 8, 0, "RES 7,H"},

		// 0xBD RES 7,L
		// - - - -
		Instruction{RES_0xBD, 2, 8, 0, "RES 7,L"},

		// 0xBE RES 7,(HL)
		// - - - -
		Instruction{RES_0xBE, 2, 16, 0, "RES 7,(HL)"},

		// 0xBF RES 7,A
		// - - - -
		Instruction{RES_0xBF, 2, 8, 0, "RES 7,A"},

		// 0xC0 SET 0,B
		// - - - -
		Instruction{SET_0xC0, 2, 8, 0, "SET 0,B"},

		// 0xC1 SET 0,C
		// - - - -
		Instruction{SET_0xC1, 2, 8, 0, "SET 0,C"},

		// 0xC2 SET 0,D
		// - - - -
		Instruction{SET_0xC2, 2, 8, 0, "SET 0,D"},

		// 0xC3 SET 0,E
		// - - - -
		Instruction{SET_0xC3, 2, 8, 0, "SET 0,E"},

		// 0xC4 SET 0,H
		// - - - -
		Instruction{SET_0xC4, 2, 8, 0, "SET 0,H"},

		// 0xC5 SET 0,L
		// - - - -
		Instruction{SET_0xC5, 2, 8, 0, "SET 0,L"},

		// 0xC6 SET 0,(HL)
		// - - - -
		Instruction{SET_0xC6, 2, 16, 0, "SET 0,(HL)"},

		// 0xC7 SET 0,A
		// - - - -
		Instruction{SET_0xC7, 2, 8, 0, "SET 0,A"},

		// 0xC8 SET 1,B
		// - - - -
		Instruction{SET_0xC8, 2, 8, 0, "SET 1,B"},

		// 0xC9 SET 1,C
		// - - - -
		Instruction{SET_0xC9, 2, 8, 0, "SET 1,C"},

		// 0xCA SET 1,D
		// - - - -
		Instruction{SET_0xCA, 2, 8, 0, "SET 1,D"},

		// 0xCB SET 1,E
		// - - - -
		Instruction{SET_0xCB, 2, 8, 0, "SET 1,E"},

		// 0xCC SET 1,H
		// - - - -
		Instruction{SET_0xCC, 2, 8, 0, "SET 1,H"},

		// 0xCD SET 1,L
		// - - - -
		Instruction{SET_0xCD, 2, 8, 0, "SET 1,L"},

		// 0xCE SET 1,(HL)
		// - - - -
		Instruction{SET_0xCE, 2, 16, 0, "SET 1,(HL)"},

		// 0xCF SET 1,A
		// - - - -
		Instruction{SET_0xCF, 2, 8, 0, "SET 1,A"},

		// 0xD0 SET 2,B
		// - - - -
		Instruction{SET_0xD0, 2, 8, 0, "SET 2,B"},

		// 0xD1 SET 2,C
		// - - - -
		Instruction{SET_0xD1, 2, 8, 0, "SET 2,C"},

		// 0xD2 SET 2,D
		// - - - -
		Instruction{SET_0xD2, 2, 8, 0, "SET 2,D"},

		// 0xD3 SET 2,E
		// - - - -
		Instruction{SET_0xD3, 2, 8, 0, "SET 2,E"},

		// 0xD4 SET 2,H
		// - - - -
		Instruction{SET_0xD4, 2, 8, 0, "SET 2,H"},

		// 0xD5 SET 2,L
		// - - - -
		Instruction{SET_0xD5, 2, 8, 0, "SET 2,L"},

		// 0xD6 SET 2,(HL)
		// - - - -
		Instruction{SET_0xD6, 2, 16, 0, "SET 2,(HL)"},

		// 0xD7 SET 2,A
		// - - - -
		Instruction{SET_0xD7, 2, 8, 0, "SET 2,A"},

		// 0xD8 SET 3,B
		// - - - -
		Instruction{SET_0xD8, 2, 8, 0, "SET 3,B"},

		// 0xD9 SET 3,C
		// - - - -
		Instruction{SET_0xD9, 2, 8, 0, "SET 3,C"},

		// 0xDA SET 3,D
		// - - - -
		Instruction{SET_0xDA, 2, 8, 0, "SET 3,D"},

		// 0xDB SET 3,E
		// - - - -
		Instruction{SET_0xDB, 2, 8, 0, "SET 3,E"},

		// 0xDC SET 3,H
		// - - - -
		Instruction{SET_0xDC, 2, 8, 0, "SET 3,H"},

		// 0xDD SET 3,L
		// - - - -
		Instruction{SET_0xDD, 2, 8, 0, "SET 3,L"},

		// 0xDE SET 3,(HL)
		// - - - -
		Instruction{SET_0xDE, 2, 16, 0, "SET 3,(HL)"},

		// 0xDF SET 3,A
		// - - - -
		Instruction{SET_0xDF, 2, 8, 0, "SET 3,A"},

		// 0xE0 SET 4,B
		// - - - -
		Instruction{SET_0xE0, 2, 8, 0, "SET 4,B"},

		// 0xE1 SET 4,C
		// - - - -
		Instruction{SET_0xE1, 2, 8, 0, "SET 4,C"},

		// 0xE2 SET 4,D
		// - - - -
		Instruction{SET_0xE2, 2, 8, 0, "SET 4,D"},

		// 0xE3 SET 4,E
		// - - - -
		Instruction{SET_0xE3, 2, 8, 0, "SET 4,E"},

		// 0xE4 SET 4,H
		// - - - -
		Instruction{SET_0xE4, 2, 8, 0, "SET 4,H"},

		// 0xE5 SET 4,L
		// - - - -
		Instruction{SET_0xE5, 2, 8, 0, "SET 4,L"},

		// 0xE6 SET 4,(HL)
		// - - - -
		Instruction{SET_0xE6, 2, 16, 0, "SET 4,(HL)"},

		// 0xE7 SET 4,A
		// - - - -
		Instruction{SET_0xE7, 2, 8, 0, "SET 4,A"},

		// 0xE8 SET 5,B
		// - - - -
		Instruction{SET_0xE8, 2, 8, 0, "SET 5,B"},

		// 0xE9 SET 5,C
		// - - - -
		Instruction{SET_0xE9, 2, 8, 0, "SET 5,C"},

		// 0xEA SET 5,D
		// - - - -
		Instruction{SET_0xEA, 2, 8, 0, "SET 5,D"},

		// 0xEB SET 5,E
		// - - - -
		Instruction{SET_0xEB, 2, 8, 0, "SET 5,E"},

		// 0xEC SET 5,H
		// - - - -
		Instruction{SET_0xEC, 2, 8, 0, "SET 5,H"},

		// 0xED SET 5,L
		// - - - -
		Instruction{SET_0xED, 2, 8, 0, "SET 5,L"},

		// 0xEE SET 5,(HL)
		// - - - -
		Instruction{SET_0xEE, 2, 16, 0, "SET 5,(HL)"},

		// 0xEF SET 5,A
		// - - - -
		Instruction{SET_0xEF, 2, 8, 0, "SET 5,A"},

		// 0xF0 SET 6,B
		// - - - -
		Instruction{SET_0xF0, 2, 8, 0, "SET 6,B"},

		// 0xF1 SET 6,C
		// - - - -
		Instruction{SET_0xF1, 2, 8, 0, "SET 6,C"},

		// 0xF2 SET 6,D
		// - - - -
		Instruction{SET_0xF2, 2, 8, 0, "SET 6,D"},

		// 0xF3 SET 6,E
		// - - - -
		Instruction{SET_0xF3, 2, 8, 0, "SET 6,E"},

		// 0xF4 SET 6,H
		// - - - -
		Instruction{SET_0xF4, 2, 8, 0, "SET 6,H"},

		// 0xF5 SET 6,L
		// - - - -
		Instruction{SET_0xF5, 2, 8, 0, "SET 6,L"},

		// 0xF6 SET 6,(HL)
		// - - - -
		Instruction{SET_0xF6, 2, 16, 0, "SET 6,(HL)"},

		// 0xF7 SET 6,A
		// - - - -
		Instruction{SET_0xF7, 2, 8, 0, "SET 6,A"},

		// 0xF8 SET 7,B
		// - - - -
		Instruction{SET_0xF8, 2, 8, 0, "SET 7,B"},

		// 0xF9 SET 7,C
		// - - - -
		Instruction{SET_0xF9, 2, 8, 0, "SET 7,C"},

		// 0xFA SET 7,D
		// - - - -
		Instruction{SET_0xFA, 2, 8, 0, "SET 7,D"},

		// 0xFB SET 7,E
		// - - - -
		Instruction{SET_0xFB, 2, 8, 0, "SET 7,E"},

		// 0xFC SET 7,H
		// - - - -
		Instruction{SET_0xFC, 2, 8, 0, "SET 7,H"},

		// 0xFD SET 7,L
		// - - - -
		Instruction{SET_0xFD, 2, 8, 0, "SET 7,L"},

		// 0xFE SET 7,(HL)
		// - - - -
		Instruction{SET_0xFE, 2, 16, 0, "SET 7,(HL)"},

		// 0xFF SET 7,A
		// - - - -
		Instruction{SET_0xFF, 2, 8, 0, "SET 7,A"}
	};
} // Core

#endif // __PREFIX_LOOKUP_TABLE_H__