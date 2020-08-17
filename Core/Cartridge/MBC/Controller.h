/**
 * @file		MBCController.h
 * @author		Noam Rodrik
 * @description Decides which MBC the game should use.
 */
#ifndef __MBC_CONTROLLER_H__
#define __MBC_CONTROLLER_H__

#include <API/Memory/Device/IMemoryDeviceAccess.h>
#include <API/Cartridge/IMemoryBankController.h>
#include <API/Definitions.h>
#include <utility>
#include <array>

namespace Core
{
/**
 * Serves as an abstraction between the MBC type and the MBC operations.
 * Must call UpdateMBC before usage (otherwise will use the wrong MBC).
 */
class MBCController : public API::AMemoryBankController
{
public:
	MBCController(API::IMemoryDeviceAccess& memory_accessor, API::ILoader& loader);
	~MBCController() = default;

public:
	/**
	 * Checks if the MBC has changed. If it has, changes the currently
	 * used MBC.
	 *
	 * Returns true if exists such MBC.
	 */
	bool UpdateMBC();

public:
	virtual API::CartridgeHeader::CartridgeType Type() const override;
	virtual void LoadROMBankZero() override;

private:
	void Setup();

private:
	std::array<std::unique_ptr<API::IMemoryBankController>, API::MEMORY_BANK_CONTROLLERS_AMOUNT> m_mbcs{};
	std::size_t m_chosen_mbc{0};
};
}

#endif // __MBC_CONTROLLER_H__