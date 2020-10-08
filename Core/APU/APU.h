/**
 * @file		APU.h
 * @author		Noam Rodrik
 * @description The implementation for LR35902's APU.
 */
#ifndef __CORE_APU_H__
#define __CORE_APU_H__

#include <Core/APU/Waves/WaveController.h>
#include <Core/APU/Definitions.h>
#include <API/StaticInstance.h>
#include <API/Definitions.h>
#include <cstddef>

namespace Core
{
class APU : public API::StaticInstance<APU>
{
public:
	APU() = default;
	~APU() = default;

public:
	void Clock(std::size_t clocks);

	// The type of function pointer needed for the pixel engine's sound manipulator.
	static float_t SoundDemultiplexer(int32_t channel, float_t global_time, float_t time_step);

	WaveController& GetOscillator()
	{
		return APU::GetInstance()._wave_controller;
	}

private:
	static const float_t Play(const OutputTerminal output, const float_t global_time, const float_t time_step);
	static const float_t Sample(const OutputTerminal output, const float_t global_time, const float_t time_step, const API::data_t volume);
	static const float_t VolumeWaveManipulator(const API::data_t volume);

public:
	// Sample rate at 44.1kHZ
	static constexpr auto SAMPLE_RATE{44100};

	// SO2 goes to the left headphone, and SO1 goes to the right
	static constexpr auto CHANNEL_AMOUNT{2};
	static constexpr auto BLOCKS_AMOUNT{8};
	static constexpr auto BLOCKS_SAMPLE_SIZE{512};

	static constexpr auto MAX_VOLUME{7.0f};
	static constexpr auto MIN_VOLUME{0.0f};

private:
	WaveController _wave_controller{};
};
} // Core

#endif // __CORE_APU_H__