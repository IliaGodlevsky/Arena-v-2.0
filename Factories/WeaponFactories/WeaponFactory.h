#ifndef WEAPON_FACTORY_H_
#define WEAPON_FACTORY_H_

#include "../Factory.h"

class WeaponFactory : public Factory<Weapon>
{
public:
	WeaponFactory();
private:
	enum Weapons
	{
		CLUB_DAMAGE = 2,
		AXE_DAMAGE = 3,
		SWORD_DAMAGE = 4,
		SPEAR_DAMAGE = 5,
	};
	enum Propabilities
	{
		CLUB_CRITICAL_PROPABILY = 15,
		AXE_CRITICAL_PROPABILITY = 14,
		SWORD_CRITICAL_PROPABILITY = 12,
		SPEAR_CRITICAL_PROPABILITY = 10
	};
};

#endif