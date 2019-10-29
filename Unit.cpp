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