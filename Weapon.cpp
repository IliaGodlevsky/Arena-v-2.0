#include <iostream>

#include "Weapon.h"
#include "WeaponMagic.h"
#include "Unit.h"

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

bool Weapon::canSmashUnit(const Unit& unit)const
{
	return unit.m_health <= unit.calculateDamageAbsorb(m_damage);
}

void Weapon::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Damage: " << m_damage << std::endl;
}

void Weapon::showShortInfo()const
{
	std::cout << "<" << m_name << ">";
}

Sword::Sword(std::string name, int damage, Degenerate* magic) // 
	: Weapon(name,damage), m_magic_ptr(magic)
{
	
}

Sword::~Sword()
{
	
}

void Sword::injureUnit(Unit& unit, int damage)const
{
	if(unit.takeDamage(multiplyDamage(damage + m_damage)))
		m_magic_ptr->Effect(unit);
}

Sword::Sword(const Sword& sword)
	: Weapon(sword), 
	m_magic_ptr(sword.m_magic_ptr->Clone())
{

}

Sword& Sword::operator=(const Sword& sword)
{
	if (this == &sword)
		return *this;
	Weapon::operator=(sword);
	m_magic_ptr = MagicPtr(m_magic_ptr->Clone());
	return *this;
}

int Sword::multiplyDamage(int damage)const
{
	return damage;
}

void Sword::showFullInfo()const
{
	Weapon::showFullInfo();
	m_magic_ptr->ShowFullInfo();
}

Axe::Axe(std::string name, int damage, Crush* magic)
	: Weapon(name, damage), m_magic_ptr(magic)
{
	
}

Axe::~Axe()
{

}

void Axe::injureUnit(Unit& unit, int damage)const
{
	if (unit.takeDamage(multiplyDamage(m_damage + damage)))
		m_magic_ptr->Effect(unit);
}

Axe::Axe(const Axe& axe)
	: Weapon(axe), m_magic_ptr(axe.m_magic_ptr->Clone())
{

}

Axe& Axe::operator=(const Axe& axe)
{
	if (this == &axe)
		return *this;
	Weapon::operator=(axe);
	m_magic_ptr = MagicPtr(axe.m_magic_ptr->Clone());
	return *this;
}

int Axe::multiplyDamage(int dmg)const
{
	return dmg;
}

void Axe::showFullInfo()const
{
	Weapon::showFullInfo();
	m_magic_ptr->ShowFullInfo();
}