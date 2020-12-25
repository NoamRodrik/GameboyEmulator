/**
 * @file		NR50.h
 * @author		Noam Rodrik
 * @description LR35902's main apu NR50 definition header.
 */
#ifndef __LR35902_NR50_H__
#define __LR35902_NR50_H__

#include <Core/CPU/Registers/DeviceRegister.h>
#include <Core/APU/Definitions.h>
#include <Tools/Tools.h>

namespace Core
{
class [[nodiscard]] NR50 : public DeviceRegister<0xFF24>
{
public:
	using DeviceRegister::DeviceRegister;
	using DeviceRegister::operator=;
	using DeviceRegister::operator API::data_t;

public:
	[[nodiscard]] const bool IsVINSoundEnabled(const OutputTerminal output) const
	{
		switch (output)
		{
			case OutputTerminal::SO1:
			{
				return Tools::IsBitSet(operator API::data_t(), SO1_ENABLED_BIT_INDEX);
			}

			case OutputTerminal::SO2:
			{
				return Tools::IsBitSet(operator API::data_t(), SO2_ENABLED_BIT_INDEX);
			}

			default:
			{
				return false;
			}
		}
	}

	[[nodiscard]] const API::data_t MasterVolumeLevel(const OutputTerminal output) const
	{
		switch (output)
		{
			case OutputTerminal::SO1:
			{
				return ((operator API::data_t()) >> SO1_VOLUME_BIT_INDEX) & 0x07;
			}

			case OutputTerminal::SO2:
			{
				return ((operator API::data_t()) >> SO2_VOLUME_BIT_INDEX) & 0x07;
			}

			default:
			{
				return 0;
			}
		}
	}

private:
	static constexpr auto SO1_VOLUME_BIT_INDEX{0};
	static constexpr auto SO1_ENABLED_BIT_INDEX{3};
	static constexpr auto SO2_VOLUME_BIT_INDEX{4};
	static constexpr auto SO2_ENABLED_BIT_INDEX{7};

public:
	static constexpr API::data_t NR50_DEFAULT_VALUE{0x77};
};
} // Core

#endif // __LR35902_NR50_H__