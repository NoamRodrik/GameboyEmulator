/**
 * @file		ISoundChannel.h
 * @author		Noam Rodrik
 * @description An interface for any sound channel
 */
#ifndef __CORE_ISOUND_CHANNEL_H__
#define __CORE_ISOUND_CHANNEL_H__

#include <Core/APU/Definitions.h>
#include <API/Definitions.h>
#include <cstddef>

namespace Core
{
class ISoundChannel
{
public:
	virtual ~ISoundChannel() = default;

public:
	virtual const bool IsEnabled() const = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;

	virtual const bool Activated(const OutputTerminal output) const = 0;
};
} // Core

#endif // __CORE_ISOUND_CHANNEL_H__