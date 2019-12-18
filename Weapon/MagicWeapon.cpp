#include "../Unit/Unit.h"
#include "../Magic/WeaponMagic/WeaponMagic.h"

#include "MagicWeapon.h"

MagicWeapon::MagicWeapon(std::string name, int damage, MagicPtr magic)
	: Weapon(name, damage, ZERO_CRITIAL_PROBABILITY), m_magic(magic->clone())
{

}

MagicWeapon::MagicWeapon(const MagicWeapon& weapon)
	: Weapon(weapon), m_magic(weapon.m_magic->clone())
{

}

MagicWeapon& MagicWeapon::operator=(const MagicWeapon& weapon)
{
	if (this == &weapon)
		return *this;
	Weapon::operator=(weapon);
	m_magic = weapon.m_magic->clone();
	return *this;
}

void MagicWeapon::injureUnit(Unit& unit, int dmg)const
{
	if (unit.takeDamage(multiplyDamage(m_damage + dmg)))
		m_magic->effectUnit(unit);
}

void MagicWeapon::showFullInfo()const
{
	Weapon::showFullInfo();
	m_magic->showFullInfo();
}