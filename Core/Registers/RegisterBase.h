/**
 * @file		RegisterBase.h
 * @author		Noam Rodrik
 * @description Class definitions for register types
 */
#ifndef __REGISTER_BASE_H__
#define __REGISTER_BASE_H__

#include <API/Definitions.h>
#include <type_traits>
#include <stdint.h>
#include <atomic>

namespace Core
{
/**
 * A base class made for registers.
 */
template <typename T>
class RegisterBase
{
public:
	static_assert(std::is_integral<T>::value, "Got a non-integral register-base data type.");

public:
	constexpr RegisterBase(T&& data) : m_data{data} {};

	operator T&()
	{
		return this->m_data;
	}

	operator T() const
	{
		return this->m_data;
	}

protected:
	using RegisterType = T;
	T m_data;
};

/**
 * All addressing registers use 16 bits.
 */
class AddressRegisterBase : public RegisterBase<API::address_t>
{
public:
	using RegisterBase::RegisterBase;
	using RegisterBase::operator API::address_t&;
	using RegisterBase::operator API::address_t;

	AddressRegisterBase& operator=(const API::address_t data)
	{
		this->m_data = data;
		return *this;
	}
};

/**
 * In use for stack arithmetic
 */
class StackRegisterBase : public AddressRegisterBase
{
public:
	using AddressRegisterBase::AddressRegisterBase;
	using AddressRegisterBase::operator=;
	using RegisterBase::operator API::address_t&;
	using RegisterBase::operator API::address_t;

public:
	virtual void Push(const API::address_t data) = 0;
	virtual void Push(const API::data_t data) = 0;
	virtual void Pop(API::address_t& data) = 0;
	virtual void Pop(API::data_t& data) = 0;
};

/**
 * The stack registers hold 8 bit data segments that maintain their position in the stack.
 */
class FlagsRegisterBase : public RegisterBase<API::data_t>
{
public:
	using RegisterBase::RegisterBase;
	using RegisterBase::operator API::data_t&;
	using RegisterBase::operator API::data_t;

protected:
	constexpr bool GetFlag(const API::data_t bit_index) const
	{
		return (this->m_data >> bit_index) & 0x01;
	}

	inline void SetFlag(const API::data_t flag)
	{
		this->m_data |= (0x1 << flag);
	}

	inline void ClearFlag(const API::data_t flag)
	{
		this->m_data &= ((0x1 << flag) ^ 0b11111111);
	}
};

/**
 * The arithmetic registers hold 8 bit data segments, that maintain their logic.
 */
class ArithmeticRegisterBase : public RegisterBase<API::data_t>
{
public:
	using RegisterBase::RegisterBase;
	using RegisterBase::operator API::data_t&;
	using RegisterBase::operator API::data_t;
};
} // Core

#endif // __REGISTER_BASE_H__