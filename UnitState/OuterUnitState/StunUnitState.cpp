#include "../../Magic/Magic.h"

#include "StunUnitState.h"
#include "../../Arena/Arena.h"
#include "../../Unit/Unit.h"
#include "../InnerUnitState/DeadUnitState.h"

StunUnitState::StunUnitState(const Timer& timer)
	: OuterUnitState(timer)
{

}

bool StunUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return false;
}

bool StunUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return false;
}

UnitPtr StunUnitState::chooseUnitToAttack(DecisionPtr decision, const Unit& decidingUnit,
	const Gladiators& units)const
{
	return UnitState::chooseUnitToAttack(decision, decidingUnit, units);
}

MagicPtr StunUnitState::chooseMagicToCast(DecisionPtr decision, const Unit& decidingUnit,
	const Gladiators& units)const
{
	return UnitState::chooseMagicToCast(decision, decidingUnit, units);
}

UnitPtr StunUnitState::chooseUnitToCast(DecisionPtr decision, const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return UnitState::chooseUnitToCast(decision, decidingUnit, magicToCast, units);
}

int StunUnitState::getValue()const
{
	return STUN_UNIT_STATE;
}

void StunUnitState::showShortInfo()const
{
	commentator.writeMessage("<Stun: ", m_timer.getStartTime()
		+ m_timer.getDuration() - Arena::getCurrentRound(), "> ");
}

bool StunUnitState::takeDamage(Unit& unit, int damage)
{
	UnitState::reduceUnitHp(unit, damage);
	return true;
}

bool StunUnitState::takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)
{
	magic->effectUnit(unit);
	return true;
}

StatePtr StunUnitState::clone()const
{
	return StatePtr(new StunUnitState(m_timer));
}