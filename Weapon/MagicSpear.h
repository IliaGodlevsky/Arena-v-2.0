#ifndef MAGIC_SPEAR_H_
#define MAGIC_SPEAR_H_

#include "MagicWeapon.h"

class MagicSpear : public MagicWeapon
{
public:
	MagicSpear(std::string name, int damage, MagicPtr magic);
	MagicSpear(const MagicSpear& spear);
	MagicSpear& operator=(const MagicSpear& spear);
	~MagicSpear() = default;
public:
	WeaponPtr clone()const override;
};

#endif