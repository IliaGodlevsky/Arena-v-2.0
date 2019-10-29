#include "Unit.h"

Unit::Unit(const std::string& name,
	const Vital& health,
	const Vital& mana,
	UnitState* state) :
	name(name),
	health(health),
	mana(mana),
	current_state(state), on_me(0), armors(0), magic(0), weapons(0)
{

}

Unit::Unit(const Unit& unit) :
	Unit(unit.name, unit.health,
		unit.mana, current_state)
{
	CopyUnitsStuff(unit);
}

Unit::Unit(Unit&& unit) : Unit(unit)
{

}

Unit& Unit::operator=(const Unit& unit)
{
	if (this == &unit)
		return *this;
	delete current_state;
	current_state = unit.current_state->Clone();
	health = unit.health;
	mana = unit.mana;
	CopyUnitsStuff(unit);
	return *this;
}

Unit& Unit::operator=(Unit&& unit)
{
	return operator=(unit);
}

Unit::~Unit()
{
	ReleaseMemory(on_me);
	ReleaseMemory(magic);
	ReleaseMemory(weapons);
	ReleaseMemory(armors);
	delete current_state;
}

bool Unit::TakeArm(Weapon* weapon)
{
	return PushStuff(weapons, weapon);
}

bool Unit::TakeMagic(Magic* magic)
{
	return PushStuff(this->magic, magic);
}

bool Unit::TakeMagicOnMe(Magic* magic)
{
	return PushStuff(on_me, magic);
}

bool Unit::TakeArmor(Armor* armor)
{
	return PushStuff(armors, armor);
}

void Unit::SetState(UnitState* state) // take care
{
	if (state != nullptr)
	{
		delete current_state;
		current_state = state->Clone();
	}
}

void Unit::CopyMagicOnMe(const Unit& unit)
{
	ReleaseMemory(on_me);
	CopyStuff(on_me, unit.on_me);
}

void Unit::CopyArmor(const Unit& unit)
{
	ReleaseMemory(armors);
	CopyStuff(armors, unit.armors);
}

void Unit::CopyWeapon(const Unit& unit)
{
	ReleaseMemory(weapons);
	CopyStuff(weapons, unit.weapons);
}

void Unit::CopyMagic(const Unit& unit)
{
	ReleaseMemory(magic);
	CopyStuff(magic, unit.magic);
}

void Unit::CopyUnitsStuff(const Unit& unit)
{
	CopyArmor(unit);
	CopyWeapon(unit);
	CopyMagic(unit);
	CopyMagicOnMe(unit);
}