#include <iostream>

#include "Weapon.h"
#include "WeaponMagic.h"
#include "Unit.h"

Weapon::Weapon(std::string name, int damage)
	: name(name),damage(damage)
{

}

Weapon::Weapon(const Weapon& weapon)
	: damage(weapon.damage)
{

}

Weapon& Weapon::operator=(const Weapon& weapon)
{
	if (this == &weapon)
		return *this;
	damage = weapon.damage;
	return *this;
}

bool Weapon::CanSmash(const Unit& unit)const
{
	return unit.health <= unit.AbsorbCalc(damage);
}

void Weapon::ShowFullInfo()const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Damage: " << damage << std::endl;
}

void Weapon::ShowShortInfo()const
{
	std::cout << "<" << name << ">";
}

Sword::Sword(std::string name, int damage, Degenerate* spell)
	: Weapon(name,damage), spell(spell)
{
	
}

Sword::~Sword()
{
	
}

void Sword::Injure(Unit& unit, int dmg)const
{
	if(unit.TakeDamage(Multiply(damage + dmg)))
		spell->Effect(unit);
}

Sword::Sword(const Sword& sword)
	: Weapon(sword), 
	spell(sword.spell->Clone())
{

}

Sword& Sword::operator=(const Sword& sword)
{
	if (this == &sword)
		return *this;
	Weapon::operator=(sword);
	spell = MagicPtr(spell->Clone());
	return *this;
}

int Sword::Multiply(int dmg)const
{
	return dmg;
}

void Sword::ShowFullInfo()const
{
	Weapon::ShowFullInfo();
	spell->ShowFullInfo();
}

Axe::Axe(std::string name, int damage, Crush* spell)
	: Weapon(name, damage), spell(spell)
{
	
}

Axe::~Axe()
{

}

void Axe::Injure(Unit& unit, int dmg)const
{
	if (unit.TakeDamage(Multiply(damage + dmg)))
		spell->Effect(unit);
}

Axe::Axe(const Axe& axe)
	: Weapon(axe), spell(axe.spell->Clone())
{

}

Axe& Axe::operator=(const Axe& axe)
{
	if (this == &axe)
		return *this;
	Weapon::operator=(axe);
	spell = MagicPtr(axe.spell->Clone());
	return *this;
}

int Axe::Multiply(int dmg)const
{
	return dmg;
}

void Axe::ShowFullInfo()const
{
	Weapon::ShowFullInfo();
	spell->ShowFullInfo();
}