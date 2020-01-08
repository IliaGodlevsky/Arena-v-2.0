#include "UnitState.h"

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Arena/Arena.h"

UnitState::UnitState(DecisionPtr decision)
	:m_decision(decision)
{

}

bool UnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	if (!caster.isEnoughManaFor(magic)
		|| nullptr == magic)
		return false;
	unit.takeMagicEffect(caster, magic);
	caster.payMana(magic->getCost());
	return true;
}

bool UnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	if (nullptr == weapon)
		return false;
	weapon->injureUnit(unit, damage);
	return true;
}

UnitPtr UnitState::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return nullptr;
}

MagicPtr UnitState::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return nullptr;
}

UnitPtr UnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
}

void UnitState::setDecision(DecisionPtr decision)
{
	if (nullptr != decision)
		this->m_decision = decision;
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