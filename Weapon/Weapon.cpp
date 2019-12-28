#include "Weapon.h"

#include "../Unit/Unit.h"
#include "../PossibilityCounter/PosibilityCounter.h"

Weapon::Weapon(std::string name, int damage, int criticalStrikePropability)
	: m_name(name),m_damage(damage),m_CriticalStrikePropability(criticalStrikePropability)
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
	std::cout << "<" << m_name << ": " << m_damage << ">";
}

void Weapon::injureUnit(Unit& unit, int damage)const
{
	unit.takeDamage(multiplyDamage(m_damage + damage));
}

WeaponPtr Weapon::clone()const
{
	return WeaponPtr(new Weapon(m_name, m_damage, m_CriticalStrikePropability));
}

int Weapon::multiplyDamage(int damage)const
{
	const double DAMAGE_MULTIPLY = 1.5;
	if (PosibilityCounter(m_CriticalStrikePropability))
		return static_cast<int>(std::round(damage * DAMAGE_MULTIPLY));
	else
		return damage;
}

int Weapon::getDamage()const
{
	return m_damage;
}

WeaponPtr Weapon::getPureWeapon()const
{
	return WeaponPtr(new Weapon(m_name, m_damage, ZERO_CRITIAL_PROBABILITY));
}
