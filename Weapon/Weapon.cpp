#include "Weapon.h"

#include "../Unit/Unit.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"

Weapon::Weapon(std::string name, int damage)
	: m_name(name),m_damage(damage)
{

}

Weapon::Weapon(const Weapon& weapon)
	: m_damage(weapon.m_damage)
{

}

Weapon& Weapon::operator=(const Weapon& weapon)
{
	if (this == &weapon)
		return *this;
	m_damage = weapon.m_damage;
	return *this;
}

void Weapon::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Damage: " << m_damage << std::endl;
}

void Weapon::showShortInfo()const
{
	commentator.writeMessage("<", m_name, ": ", m_damage, ">\n");
}

void Weapon::injureUnit(Unit& unit, int damage)const
{
	unit.takeDamage(m_damage + damage);
}

WeaponPtr Weapon::clone()const
{
	return WeaponPtr(new Weapon(m_name, m_damage));
}

int Weapon::getDamage()const
{
	return m_damage;
}

WeaponPtr Weapon::getPureWeapon()const
{
	return WeaponPtr(new Weapon(m_name, m_damage));
}
