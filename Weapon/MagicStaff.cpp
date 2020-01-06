#include "MagicStaff.h"

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Magic/WeaponMagic/DegenerateMagic.h"

MagicStaff::MagicStaff(std::string name, int damage, MagicPtr magic)
	: Staff(name, damage), m_magic(magic->clone())
{
		if (!canCast<DegenerateMagic*>(magic))
			throw BadWeaponMagicException("Bad class is " + std::string(typeid(*this).name())
				+ "\nTry to use other weapon magic");
}

MagicStaff::MagicStaff(const MagicStaff& weapon)
	: Staff(weapon), m_magic(weapon.m_magic->clone())
{

}

MagicStaff& MagicStaff::operator=(const MagicStaff& weapon)
{
	if (this == &weapon)
		return *this;
	Staff::operator=(weapon);
	m_magic = weapon.m_magic->clone();
	return *this;
}

void MagicStaff::injureUnit(Unit& unit, int damage)const
{
	Staff::injureUnit(unit, damage);
	m_magic->effectUnit(unit);
}

WeaponPtr MagicStaff::clone()const
{
	return WeaponPtr(new MagicStaff(m_name, m_damage, m_magic->clone()));
}

WeaponPtr MagicStaff::getPureWeapon()const
{
	return clone();
}