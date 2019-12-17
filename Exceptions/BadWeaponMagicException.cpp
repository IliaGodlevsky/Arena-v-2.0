#include <typeinfo>

#include "../Magic/Magic.h"
#include "BadWeaponMagicException.h"

BadWeaponMagicException::BadWeaponMagicException(const std::string& message,
	const MagicPtr& magic)
	: m_message(message)
{
	m_message += (std::string(" was accured. Base type of "
		"magic must be WeaponMagic. Current magic type is ") + typeid(magic.get()).name());
}

const char* BadWeaponMagicException::what()const
{
	return m_message.c_str();
}