#include "Staff.h"

#include "../Unit/Unit.h"

Staff::Staff(std::string name, int damage)
	: Weapon(name, damage)
{

}

Staff::Staff(const Staff& weapon)
	: Weapon(weapon)
{

}

Staff& Staff::operator=(const Staff& weapon)
{
	if (this == &weapon)
		return *this;
	Weapon::operator=(weapon);
	return *this;
}

void Staff::injureUnit(Unit& unit, int damage)const
{
	unit.m_health = unit.m_health - (m_damage + damage);
}