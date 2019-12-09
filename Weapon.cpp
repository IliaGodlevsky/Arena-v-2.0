#include <iostream>

#include "Weapon.h"
#include "WeaponMagic.h"
#include "Unit.h"
#include "BadWeaponMagicException.h"

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

Sword::Sword(std::string name, int damage, MagicPtr magic)
	: Weapon(name,damage), m_magic(magic->clone())
{
	Degenerate* temp = dynamic_cast<Degenerate*>(m_magic.get());
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

Sword::~Sword()
{
	
}

void Sword::injureUnit(Unit& unit, int damage)const
{
	if(unit.takeDamage(multiplyDamage(damage + m_damage)))
		m_magic->effectUnit(unit);
}

Sword::Sword(const Sword& sword)
	: Weapon(sword), 
	m_magic(sword.m_magic->clone())
{

}

Sword& Sword::operator=(const Sword& sword)
{
	if (this == &sword)
		return *this;
	Weapon::operator=(sword);
	m_magic = MagicPtr(m_magic->clone());
	return *this;
}

int Sword::multiplyDamage(int damage)const
{
	return damage;
}

void Sword::showFullInfo()const
{
	Weapon::showFullInfo();
	m_magic->showFullInfo();
}

WeaponPtr Sword::clone()const
{
	return WeaponPtr(new Sword(m_name, m_damage, m_magic->clone()));
}

Axe::Axe(std::string name, int damage, MagicPtr magic)
	: Weapon(name, damage), m_magic(magic->clone())
{
	Crush* temp = dynamic_cast<Crush*>(m_magic.get());
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

Axe::~Axe()
{

}

void Axe::injureUnit(Unit& unit, int damage)const
{
	if (unit.takeDamage(multiplyDamage(m_damage + damage)))
		m_magic->effectUnit(unit);
}

Axe::Axe(const Axe& axe)
	: Weapon(axe), m_magic(axe.m_magic->clone())
{

}

Axe& Axe::operator=(const Axe& axe)
{
	if (this == &axe)
		return *this;
	Weapon::operator=(axe);
	m_magic = MagicPtr(axe.m_magic->clone());
	return *this;
}

int Axe::multiplyDamage(int dmg)const
{
	return dmg;
}

void Axe::showFullInfo()const
{
	Weapon::showFullInfo();
	m_magic->showFullInfo();
}

WeaponPtr Axe::clone()const
{
	return WeaponPtr(new Axe(m_name, m_damage, m_magic->clone()));
}