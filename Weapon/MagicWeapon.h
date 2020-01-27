#ifndef MAGIC_WEAPON_H_
#define MAGIC_WEAPON_H_

#include "Weapon.h"

class MagicWeapon : public Weapon
{
public:
	MagicWeapon(std::string name, int damage, MagicPtr magic);
	MagicWeapon(const MagicWeapon& weapon);
	MagicWeapon& operator=(const MagicWeapon& weapon);
	virtual ~MagicWeapon() = default;
	virtual void injureUnit(Unit& unit, int dmg)const override final;
	virtual void showFullInfo()const override final;
	virtual WeaponPtr clone()const = 0;
protected:
	MagicPtr m_magic = nullptr;
};

#endif