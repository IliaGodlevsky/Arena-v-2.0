#include "../Magic/Magic.h"

#include "StunUnitState.h"
#include "../Arena/Arena.h"

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

UnitPtr StunUnitState::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return UnitState::chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StunUnitState::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return UnitState::chooseMagicToCast(decidingUnit, units);
}

UnitPtr StunUnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return UnitState::chooseUnitToCast(decidingUnit, magicToCast, units);
}

int StunUnitState::getValue()const
{
	return STUN_UNIT_STATE;
}

void StunUnitState::showShortInfo()const
{
	std::cout << "<Stun: " << m_timer.getStartTime()
		+ m_timer.getDuration() - Arena::getCurrentRound() << "> ";
}