/**
 * @file		MBC1_0x02.h
 * @author		Noam Rodrik
 * @description Implementation of the first mbc.
 */
#ifndef __MBC_ROM_1_RAM_H__
#define __MBC_ROM_1_RAM_H__

#include <Core/Cartridge/Implementation/MBC1_0x01.h>
#include <API/Cartridge/IMemoryBankController.h>
#include <API/Memory/Memory.h>

namespace Core
{
class [[nodiscard]] MemoryBankController_2 : public API::AMemoryBankController
{
public:
	MemoryBankController_2(IMemoryDeviceAccess& memory_device, std::shared_ptr<API::ILoader> loader) :
		API::AMemoryBankController{memory_device, loader},
		_inner_mbc{memory_device, loader} {}
	virtual ~MemoryBankController_2() = default;

public:
	[[nodiscard]] virtual API::CartridgeHeader::CartridgeType Type() const override { return API::CartridgeHeader::CartridgeType::MBC1_RAM; }
	[[nodiscard]] virtual size_t BankSize() const override;
	virtual void LoadMBC() override;
	[[nodiscard]] virtual bool Read(const API::address_t absolute_address, API::data_t& result) const override;
	[[nodiscard]] virtual bool Write(const API::address_t absolute_address, const API::data_t data) override;
	[[nodiscard]] virtual bool WriteDirectly(const API::address_t absolute_address, const API::data_t data) override;

public:
	static constexpr size_t BANK_SIZE = 125;

private:
	[[nodiscard]] const bool RamRomBankNumberAction(const API::data_t data);

private:
	static constexpr API::address_t ADDITIONAL_RAM_BANKS_OFFSET = 0xA000;
	static constexpr API::address_t RAM_ENABLE_START = 0x0000;
	static constexpr API::address_t RAM_ENABLE_END = 0x1FFF;
	static constexpr API::address_t RAM_ROM_BANK_NUMBER_START = 0x4000;
	static constexpr API::address_t RAM_ROM_BANK_NUMBER_END = 0x5FFF;

private:
	MemoryBankController_1                  _inner_mbc;
	API::Memory<Tools::BytesInRAMBanks(16)> _ram_memory;
	API::data_t							    _selected_ram_bank{0};
	bool								    _ram_enable{false};

private:
	friend class MemoryBankController_3;
};
} // Core

#endif // __MBC_ROM_1_RAM_H__