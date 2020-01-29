#include "UnitState.h"

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Arena/Arena.h"

bool UnitState::canCast()const
{
	return true;
}

bool UnitState::canAttack()const
{
	return true;
}

bool UnitState::canTakeDamage(Unit& unit, int damage)const
{
	return unit.m_shield->takeDamage(unit, damage);
}

bool UnitState::canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	return unit.m_shield->takeMagicEffect(unit, caster, magic);
}

bool UnitState::operator < (const UnitState& unitState)const
{
	return getValue() < unitState.getValue();
}

bool UnitState::operator>(const UnitState& state)const
{
	return getValue() > state.getValue();
}

void UnitState::showShortInfo()const
{
	return;
}

bool UnitState::isEqual(const StatePtr& unitState)const
{
	return getValue() == unitState->getValue();
}