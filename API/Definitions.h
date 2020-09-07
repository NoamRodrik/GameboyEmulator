/**
 * @file		Definitions.h
 * @author		Noam Rodrik
 * @description API main definition header.
 */
#ifndef __API_DEFINITIONS_H__
#define __API_DEFINITIONS_H__

#include <Tools/Tools.h>
#include <stdint.h>
#include <limits>
#include <array>

namespace API
{
	/* Necessary types for the CPU */
	using address_t = uint16_t;
	using data_t = uint8_t;
	using r8_t = int8_t;

	/* RAM */
	static constexpr size_t MEMORY_SIZE{Tools::SlotsToBytes(std::numeric_limits<address_t>::digits)};
	static constexpr size_t MEMORY_ROM_BANK_SIZE{0x4000};
	static constexpr size_t MEMORY_RAM_BANK_SIZE{0x2000};

	/* Main memory */
	static constexpr address_t ROM_BEGIN_ADDRESS{0x0100};
	static constexpr address_t ZERO_PAGE_ADDRESS{0xFF00};

	/* Devices on BUS */
	static constexpr uint8_t DEVICES_ON_BUS{10};

	/* Memory bank controllers */
	static constexpr uint8_t MEMORY_BANK_CONTROLLERS_AMOUNT{28};

	/* Serial */
	static constexpr address_t SERIAL_TRANSFER_DATA{0xFF01};
	static constexpr address_t SERIAL_TRANSFER_CONTROL{0xFF02};
	static constexpr data_t SERIAL_TRANSFER_START{0x01};
	static constexpr data_t SERIAL_TRANSFER_CLOCK_SOURCE{0x80};

	/* Audio Processing and Graphics Processing */
	static constexpr address_t NR10_ADDRESS{0xFF10};
	static constexpr address_t NR11_ADDRESS{0xFF11};
	static constexpr address_t NR12_ADDRESS{0xFF12};
	static constexpr address_t NR14_ADDRESS{0xFF14};
	static constexpr address_t NR21_ADDRESS{0xFF16};
	static constexpr address_t NR22_ADDRESS{0xFF17};
	static constexpr address_t NR24_ADDRESS{0xFF19};
	static constexpr address_t NR30_ADDRESS{0xFF1A};
	static constexpr address_t NR31_ADDRESS{0xFF1B};
	static constexpr address_t NR32_ADDRESS{0xFF1C};
	static constexpr address_t NR33_ADDRESS{0xFF1E};
	static constexpr address_t NR41_ADDRESS{0xFF20};
	static constexpr address_t NR42_ADDRESS{0xFF21};
	static constexpr address_t NR43_ADDRESS{0xFF22};
	static constexpr address_t NR44_ADDRESS{0xFF23};
	static constexpr address_t NR50_ADDRESS{0xFF24};
	static constexpr address_t NR51_ADDRESS{0xFF25};
	static constexpr address_t NR52_ADDRESS{0xFF26};
	static constexpr address_t KEY1_ADDRESS{0xFF4D};
	static constexpr address_t RP_ADDRESS  {0xFF56};
	static constexpr address_t NR10_DEFAULT_VALUE{0x80};
	static constexpr address_t NR11_DEFAULT_VALUE{0xBF};
	static constexpr address_t NR12_DEFAULT_VALUE{0xF3};
	static constexpr address_t NR14_DEFAULT_VALUE{0xBF};
	static constexpr address_t NR21_DEFAULT_VALUE{0x3F};
	static constexpr address_t NR22_DEFAULT_VALUE{0x00};
	static constexpr address_t NR24_DEFAULT_VALUE{0xBF};
	static constexpr address_t NR30_DEFAULT_VALUE{0x7F};
	static constexpr address_t NR31_DEFAULT_VALUE{0xFF};
	static constexpr address_t NR32_DEFAULT_VALUE{0x9F};
	static constexpr address_t NR33_DEFAULT_VALUE{0xBF};
	static constexpr address_t NR41_DEFAULT_VALUE{0xFF};
	static constexpr address_t NR42_DEFAULT_VALUE{0x00};
	static constexpr address_t NR43_DEFAULT_VALUE{0x00};
	static constexpr address_t NR44_DEFAULT_VALUE{0xBF};
	static constexpr address_t NR50_DEFAULT_VALUE{0x77};
	static constexpr address_t NR51_DEFAULT_VALUE{0xF3};
	static constexpr address_t NR52_DEFAULT_VALUE{0xF1};

	/* Special Registers */
	static constexpr address_t OVERRIDE_BOOTROM_ADDRESS{0xFF50};

	/* Timer Definitions */
	static constexpr auto LR35902_HZ_CLOCK = 4'194'304;

	/* Boot Definitions */
#ifdef SKIP_BOOT
#undef SKIP_BOOT
#endif

	Message("Cancel this if you don't want to skip the Boot");
	//#define SKIP_BOOT 1
	#define SKIP_BOOT 0

	// Extracted from DMG_boot.bin.
	static constexpr std::array<data_t, 0x100> SYSTEM_BOOT_CODE =
	{
		0x31, 0xFE, 0xFF, 0xAF, 0x21, 0xFF,
		0x9F, 0x32, 0xCB, 0x7C, 0x20, 0xFB,
		0x21, 0x26, 0xFF, 0x0E, 0x11, 0x3E,
		0x80, 0x32, 0xE2, 0x0C, 0x3E, 0xF3,
		0xE2, 0x32, 0x3E, 0x77, 0x77, 0x3E,
		0xFC, 0xE0, 0x47, 0x11, 0x04, 0x01,
		0x21, 0x10, 0x80, 0x1A, 0xCD, 0x95,
		0x00, 0xCD, 0x96, 0x00, 0x13, 0x7B,
		0xFE, 0x34, 0x20, 0xF3, 0x11, 0xD8,
		0x00, 0x06, 0x08, 0x1A, 0x13, 0x22,
		0x23, 0x05, 0x20, 0xF9, 0x3E, 0x19,
		0xEA, 0x10, 0x99, 0x21, 0x2F, 0x99,
		0x0E, 0x0C, 0x3D, 0x28, 0x08, 0x32,
		0x0D, 0x20, 0xF9, 0x2E, 0x0F, 0x18,
		0xF3, 0x67, 0x3E, 0x64, 0x57, 0xE0,
		0x42, 0x3E, 0x91, 0xE0, 0x40, 0x04,
		0x1E, 0x02, 0x0E, 0x0C, 0xF0, 0x44,
		0xFE, 0x90, 0x20, 0xFA, 0x0D, 0x20,
		0xF7, 0x1D, 0x20, 0xF2, 0x0E, 0x13,
		0x24, 0x7C, 0x1E, 0x83, 0xFE, 0x62,
		0x28, 0x06, 0x1E, 0xC1, 0xFE, 0x64,
		0x20, 0x06, 0x7B, 0xE2, 0x0C, 0x3E,
		0x87, 0xE2, 0xF0, 0x42, 0x90, 0xE0,
		0x42, 0x15, 0x20, 0xD2, 0x05, 0x20,
		0x4F, 0x16, 0x20, 0x18, 0xCB, 0x4F,
		0x06, 0x04, 0xC5, 0xCB, 0x11, 0x17,
		0xC1, 0xCB, 0x11, 0x17, 0x05, 0x20,
		0xF5, 0x22, 0x23, 0x22, 0x23, 0xC9,
		0xCE, 0xED, 0x66, 0x66, 0xCC, 0x0D,
		0x00, 0x0B, 0x03, 0x73, 0x00, 0x83,
		0x00, 0x0C, 0x00, 0x0D, 0x00, 0x08,
		0x11, 0x1F, 0x88, 0x89, 0x00, 0x0E,
		0xDC, 0xCC, 0x6E, 0xE6, 0xDD, 0xDD,
		0xD9, 0x99, 0xBB, 0xBB, 0x67, 0x63,
		0x6E, 0x0E, 0xEC, 0xCC, 0xDD, 0xDC,
		0x99, 0x9F, 0xBB, 0xB9, 0x33, 0x3E,
		0x3C, 0x42, 0xB9, 0xA5, 0xB9, 0xA5,
		0x42, 0x3C, 0x21, 0x04, 0x01, 0x11,
		0xA8, 0x00, 0x1A, 0x13, 0xBE, 0x20,
		0xFE, 0x23, 0x7D, 0xFE, 0x34, 0x20,
		0xF5, 0x06, 0x19, 0x78, 0x86, 0x23,
		0x05, 0x20, 0xFB, 0x86, 0x20, 0xFE,
		0x3E, 0x01, 0xE0, 0x50
	};
} // API

#endif // __API_DEFINITIONS_H__