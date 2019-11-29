#include <iostream>

#include "Weapon.h"
#include "WeaponMagic.h"
#include "Unit.h"

Weapon::Weapon(std::string name, int damage)
	: name(name),damage(damage)
{

}

Weapon::~Weapon() {}

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

Sword::Sword(std::string name, int damage)
	: Weapon(name,damage), open_wounds(new Degenerate("Open wounds", 2, 4))
{
	
}

Sword::~Sword()
{
	
}

void Sword::Injure(Unit& unit, int dmg)const
{
	if(unit.TakeDamage(Multiply(damage + dmg)))
		open_wounds->Effect(unit);
}

Sword::Sword(const Sword& sword)
	: Weapon(sword), 
	open_wounds(sword.open_wounds->Clone())
{

}

Sword& Sword::operator=(const Sword& sword)
{
	if (this == &sword)
		return *this;
	Weapon::operator=(sword);
	open_wounds = MagicPtr(open_wounds->Clone());
	return *this;
}

int Sword::Multiply(int dmg)const
{
	return dmg;
}

void Sword::ShowFullInfo()const
{
	Weapon::ShowFullInfo();
	open_wounds->ShowFullInfo();
}

Axe::Axe(std::string name, int damage)
	: Weapon(name, damage), crush(new Crush("Crush", 10))
{
	
}

Axe::~Axe()
{

}

void Axe::Injure(Unit& unit, int dmg)const
{
	if (unit.TakeDamage(Multiply(damage + dmg)))
		crush->Effect(unit);
}

Axe::Axe(const Axe& axe)
	: Weapon(axe), crush(axe.crush->Clone())
{

}

Axe& Axe::operator=(const Axe& axe)
{
	if (this == &axe)
		return *this;
	Weapon::operator=(axe);
	crush = MagicPtr(axe.crush->Clone());
	return *this;
}

int Axe::Multiply(int dmg)const
{
	return dmg;
}

void Axe::ShowFullInfo()const
{
	Weapon::ShowFullInfo();
	crush->ShowFullInfo();
}