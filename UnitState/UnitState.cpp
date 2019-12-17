#include "State.h"
#include "Unit.h"
#include "Arena.h"

UnitState::UnitState(int duration)
	: m_durationmeter(duration)
{

}

UnitPtr UnitState::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	return nullptr;
}

MagicPtr UnitState::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
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

void UnitState::setStartTime(int round)
{
	m_durationmeter.setStartTime(round);
}

bool UnitState::isExpired(int round)const
{
	return m_durationmeter.isExpired(round);
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
	std::cout << typeid(*this).name() + 6;
}


ActiveState::ActiveState()
	: UnitState(INT_MAX)
{

}

UnitPtr ActiveState::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	return m_decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr ActiveState::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	return m_decision->chooseMagicToCast(decidingUnit, units);
}

UnitPtr ActiveState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return m_decision->chooseUnitToCast(decidingUnit, magicToCast, units);
}

UnitState::StateValue ActiveState::getValue()const
{
	return UnitState::ALIVE_STATE;
}


MutedState::MutedState(int duration)
	: UnitState(duration)
{

}

UnitPtr MutedState::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	return m_decision->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr MutedState::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	return nullptr;
}

UnitPtr MutedState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return nullptr;
}

MutedState::StateValue MutedState::getValue()const
{
	return UnitState::MUTED_STATE;
}

StunState::StunState(int duration)
	: UnitState(duration)
{

}


UnitPtr StunState::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	return UnitState::chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StunState::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	return UnitState::chooseMagicToCast(decidingUnit, units);
}

UnitPtr StunState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return UnitState::chooseUnitToCast(decidingUnit, magicToCast, units);
}

StunState::StateValue StunState::getValue()const
{
	return UnitState::STUNNED_STATE;
}