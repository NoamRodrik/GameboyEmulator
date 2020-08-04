/**
 * @file		GameLoader.h
 * @author		Noam Rodrik
 * @description Serves as a service to load games from the hard-disk.
 */
#ifndef __GAME_LOADER_H__
#define __GAME_LOADER_H__

#include <Core/Loader/BinaryLoader.h>
#include <Core/Memory/Device/CartridgeRAM.h>
#include <Core/Processor/Processor.h>
#include <Core/LR35902/Boot.h>
#include <Tools/not_null.h>
#include <string>

namespace Core
{
class GameLoader : public BinaryLoader
{
public:
	GameLoader(const std::string& game_path) : BinaryLoader{game_path,
															Processor::GetInstance().GetMemory().GetDeviceAtAddress(CartridgeRAM::START_ADDRESS)->GetMemoryPointer() + SYSTEM_BOOT_CODE.size(),
															CartridgeRAM::SIZE - static_cast<long>(SYSTEM_BOOT_CODE.size())}
	{}

	virtual ~GameLoader() = default;
};
} // Core

#endif // __GAME_LOADER_H__