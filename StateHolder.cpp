#include "StateHolder.h"
#include "Unit.h"
#include "Arena.h"

#include <iostream>

StateHolder::StateHolder(std::shared_ptr<Decision> decision)
	: m_decision(decision), m_activeState(new ActiveState())
{
	m_activeState->setDecision(decision);
}

void StateHolder::recieveNewState(std::shared_ptr<UnitState>& unitState)
{
	unitState->setDecision(m_decision);
	m_unitStates.push_back(unitState);
	std::sort(m_unitStates.begin(), m_unitStates.end(),
		[&](const std::shared_ptr<UnitState>& st1, 
			const std::shared_ptr<UnitState>& st2) {return *st1 < *st2; });
}

UnitPtr StateHolder::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	if (m_unitStates.empty())
		return m_activeState->chooseUnitToAttack(decidingUnit, units);
	return m_unitStates[0]->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StateHolder::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	if (m_unitStates.empty())
		return m_activeState->chooseMagicToCast(decidingUnit, units);
	return m_unitStates[0]->chooseMagicToCast(decidingUnit, units);
}

UnitPtr StateHolder::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (m_unitStates.empty())
		return m_activeState->chooseUnitToCast(decidingUnit, magicToCast, units);
	return m_unitStates[0]->chooseUnitToCast(decidingUnit, magicToCast, units);
}

void StateHolder::takeOfExpiredStates(int round)
{
	for (size_t i = 0; i < m_unitStates.size(); i++)
	{
		if (m_unitStates[i]->isExpired(Arena::getCurrentRound()))
		{
			m_unitStates.erase(m_unitStates.begin() + i);
			i--;
		}
	}
}

void StateHolder::expireAllStates()
{
	m_unitStates.clear();
}

void StateHolder::showShortInfo()const
{
	std::cout << "States: ";
	for (size_t i = 0; i < m_unitStates.size(); i++)
	{
		std::cout << "<";
		m_unitStates[i]->showShortInfo();
		std::cout << "> ";
	}
}

StateHolder::~StateHolder()
{

}