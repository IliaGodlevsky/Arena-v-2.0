#include "StateHolder.h"
#include "Unit.h"
#include "Arena.h"

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

UnitPtr StateHolder::chooseUnitToAttack(const Unit& decidingUnit)const
{
	if (m_unitStates.empty())
		return m_activeState->chooseUnitToAttack(decidingUnit);
	return m_unitStates[0]->chooseUnitToAttack(decidingUnit);
}

MagicPtr StateHolder::chooseMagicToCast(const Unit& decidingUnit)const
{
	if (m_unitStates.empty())
		return m_activeState->chooseMagicToCast(decidingUnit);
	return m_unitStates[0]->chooseMagicToCast(decidingUnit);
}

UnitPtr StateHolder::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast)const
{
	if (m_unitStates.empty())
		return m_activeState->chooseUnitToCast(decidingUnit, magicToCast);
	return m_unitStates[0]->chooseUnitToCast(decidingUnit, magicToCast);
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

StateHolder::~StateHolder()
{

}