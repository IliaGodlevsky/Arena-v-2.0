#include "Staff.h"

#include "../Unit/Unit.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"

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
	unit.m_health = unit.m_health - damage;
	if (!unit.isAlive())
		unit.m_stateHolder.takeNew(StatePtr(new DeadUnitState(&unit)));
}