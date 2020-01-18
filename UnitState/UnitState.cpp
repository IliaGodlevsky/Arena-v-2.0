#include "UnitState.h"

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Arena/Arena.h"
#include "../Interface/Interface.h"
#include "InnerUnitState/NotEnoughManaUnitState.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"

bool UnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	IManaCost* manaCost = DYNAMIC(IManaCost*, magic);
	if (!caster.isEnoughManaFor(magic)|| nullptr == magic)
		return false;
	unit.takeMagicEffect(caster, magic);
	caster.payMana(manaCost->getCost());
	if (!caster.m_magicBook.canCastAnySpell())
		caster.m_stateHolder.takeNew(StatePtr(new NotEnoughManaUnitState(&caster)));
	return true;
}

bool UnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	if (nullptr == weapon)
		return false;
	weapon->injureUnit(unit, damage);
	if (!unit.isAlive())
		unit.m_stateHolder.takeNew(StatePtr(new DeadUnitState(&unit)));
	return true;
}

UnitPtr UnitState::chooseUnitToAttack(DecisionPtr decision, const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return nullptr;
}

MagicPtr UnitState::chooseMagicToCast(DecisionPtr decision, const Unit& decidingUnit,
	const Gladiators& units)const
{
	return nullptr;
}

UnitPtr UnitState::chooseUnitToCast(DecisionPtr decision, const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
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