#ifndef BAD_WEAPON_MAGIC_H_
#define BAD_WEAPON_MAGIC_H_

#include <exception>

#include "../Globals/Globals.h"

class BadWeaponMagicException : public std::exception
{
public:
	BadWeaponMagicException(const std::string& message,
		const MagicPtr& magic);
	const char* what()const override;
private:
	std::string m_message;
};
#endif