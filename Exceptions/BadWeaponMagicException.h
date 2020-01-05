#ifndef BAD_WEAPON_MAGIC_H_
#define BAD_WEAPON_MAGIC_H_

#include "ArenaException.h"

class BadWeaponMagicException : public ArenaException
{
public:
	BadWeaponMagicException(const std::string& message);
	~BadWeaponMagicException() = default;
};
#endif