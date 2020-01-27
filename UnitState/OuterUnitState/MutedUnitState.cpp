#include "MutedUnitState.h"

#include "../../Magic/Magic.h"
#include "../../Decision/Decision.h"
#include "../../Unit/Unit.h"

MutedUnitState::MutedUnitState(const Timer& timer)
	: OuterUnitState(timer)
{

}

bool MutedUnitState::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return false;
}

bool MutedUnitState::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return UnitState::injureUnit(weapon, unit, damage);
}

UnitPtr MutedUnitState::chooseUnitToAttack(DecisionPtr decision,const Unit& decidingUnit,
	const Gladiators& units)const
{
	return decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr MutedUnitState::chooseMagicToCast(DecisionPtr decision, const Unit& decidingUnit,
	const Gladiators& units)const
{
	return nullptr;
}

UnitPtr MutedUnitState::chooseUnitToCast(DecisionPtr decision, const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
}

int MutedUnitState::getValue()const
{
	return MUTED_UNIT_STATE;
}

void MutedUnitState::showShortInfo()const
{
	std::cout << "<Muted: " << m_timer.getStartTime()
		+ m_timer.getDuration() - Arena::getCurrentRound() << "> ";
}

StatePtr MutedUnitState::clone()const
{
	return StatePtr(new MutedUnitState(m_timer));
}