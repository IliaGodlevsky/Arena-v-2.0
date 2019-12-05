#include <algorithm>

#include "State.h"
#include "Unit.h"
#include "Arena.h"

UnitState::UnitState(int duration)
	: m_durationmeter(duration)
{

}

UnitPtr UnitState::chooseUnitToAttack(const Unit& decidingUnit)const
{
	return nullptr;
}

MagicPtr UnitState::chooseMagicToCast(const Unit& decidingUnit)const
{
	return nullptr;
}

UnitPtr UnitState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast)const
{
	return nullptr;
}

void UnitState::setDecision(std::shared_ptr<Decision> decision)
{
	if (nullptr != decision)
		this->m_decision_ptr = decision;
}

void UnitState::setStartTime(int round)
{
	m_durationmeter.SetStartTime(round);
}

bool UnitState::isExpired(int round)const
{
	return m_durationmeter.IsExpired(round);
}

bool UnitState::operator < (const UnitState& unitState)const
{
	return getValue() < unitState.getValue();
}

bool UnitState::operator>(const UnitState& state)const
{
	return getValue() > state.getValue();
}


ActiveState::ActiveState()
	: UnitState(INT_MAX)
{

}

UnitPtr ActiveState::chooseUnitToAttack(const Unit& decidingUnit)const
{
	return m_decision_ptr->chooseUnitToAttack(decidingUnit);
}

MagicPtr ActiveState::chooseMagicToCast(const Unit& decidingUnit)const
{
	return m_decision_ptr->chooseMagicToCast(decidingUnit);
}

UnitPtr ActiveState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast)const
{
	return m_decision_ptr->chooseUnitToCast(decidingUnit, magicToCast);
}

UnitState::StateValue ActiveState::getValue()const
{
	return UnitState::ALIVE_STATE;
}


MutedState::MutedState(int duration)
	: UnitState(duration)
{

}

UnitPtr MutedState::chooseUnitToAttack(const Unit& decidingUnit)const
{
	return m_decision_ptr->ChooseUnitToAttack(decidingUnit);
}

MagicPtr MutedState::chooseMagicToCast(const Unit& decidingUnit)const
{
	return nullptr;
}

UnitPtr MutedState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast)const
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


UnitPtr StunState::chooseUnitToAttack(const Unit& decidingUnit)const
{
	return UnitState::chooseUnitToAttack(decidingUnit);
}

MagicPtr StunState::chooseMagicToCast(const Unit& decidingUnit)const
{
	return UnitState::chooseMagicToCast(decidingUnit);
}

UnitPtr StunState::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast)const
{
	return UnitState::chooseUnitToCast(decidingUnit, magicToCast);
}

StunState::StateValue StunState::getValue()const
{
	return UnitState::STUNNED_STATE;
}