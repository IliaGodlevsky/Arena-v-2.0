#include "UnitState.h"

#include "../Unit/Unit.h"
#include "../Magic/Magic.h"
#include "../Arena/Arena.h"

UnitState::UnitState(const Timer& timer)
	: m_timer(timer)
{

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

void UnitState::setStartTime(int round)
{
	m_timer.setStartTime(round);
}

bool UnitState::isExpired(int round)const
{
	return m_timer.isExpired(round);
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







