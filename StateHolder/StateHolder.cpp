#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../UnitState/ActiveUnitState.h"
#include "../Magic/Magic.h"

StateHolder::StateHolder(DecisionPtr decision)
	: m_decision(decision), m_activeState(new ActiveUnitState())
{
	m_activeState->setDecision(decision);
}

void StateHolder::recieveNewState(StatePtr unitState)
{
	unitState->setDecision(m_decision);
	m_unitStates.push_back(unitState);
	std::sort(m_unitStates.begin(), m_unitStates.end(),
		[](const StatePtr& st1, const StatePtr& st2) {return *st1 < *st2; });
}

size_t StateHolder::getStateIndex(const StatePtr& state)const
{

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
	std::cout << std::endl;
}

StateHolder::~StateHolder()
{

}