#include <typeinfo>
#include <iostream>

#include "Magic.h"
#include "BadWeaponMagicException.h"

BadWeaponMagicException::BadWeaponMagicException(const std::string& message,
	const MagicPtr& magic)
	: m_message(message), m_magic(magic)
{

}

const char* BadWeaponMagicException::what()const
{
	std::string message = message + " was accured. Base type of "
		"magic must be WeaponMagic. Current magic type is " + typeid(m_magic.get()).name();
	return message.c_str();
}