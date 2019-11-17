#include "Weapon.h"
#include "WeaponMagic.h"

Weapon::Weapon(int damage): damage(damage)
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

Sword::Sword(int damage)
	: Weapon(damage), open_wounds(new Degenerate("Open wounds", 2, 4))
{
	
}

Sword::~Sword()
{
	
}

void Sword::Injure(Unit* unit)const
{
	qq
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
	open_wounds = spell_ptr<Magic>(open_wounds->Clone());
	return *this;
}

Axe::Axe(int damage)
	: Weapon(damage), crush(new Crush("Crush", 10))
{
	
}

Axe::~Axe()
{

}

void Axe::Injure(Unit* unit)const
{
	unit->health = unit->health - damage.Value();
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
	crush = spell_ptr<Magic>(axe.crush->Clone());
	return *this;
}