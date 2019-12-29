#ifndef WEAPON_H_
#define WEAPON_H_

#include "../Battles/Battles.h"
#include "../Globals/Globals.h"

class Weapon;
using WeaponPtr = std::unique_ptr<Weapon>;

class Weapon
{
public:
	Weapon(std::string name, int damage);
	Weapon(const Weapon& weapon);
	Weapon& operator=(const Weapon& weapon);
	virtual ~Weapon() = default;
public:
	virtual void injureUnit(Unit& unit, int damage)const;
	virtual void showFullInfo()const;
	virtual void showShortInfo()const final;
	virtual WeaponPtr clone()const;
	virtual WeaponPtr getPureWeapon()const final;
	virtual int getDamage()const final;
protected:
	Battles m_damage;
	std::string m_name;
};
#endif