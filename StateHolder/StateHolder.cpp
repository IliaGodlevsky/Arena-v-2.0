#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../UnitState/ActiveUnitState.h"
#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../UnitState/NotEnoughManaUnitState.h"

StateHolder::StateHolder(DecisionPtr decision)
	: m_decision(decision), m_activeState(new ActiveUnitState())
{
	m_activeState->setDecision(decision);
}

void StateHolder::expireIfFound(const StatePtr& unitState)
{
	if (TemplateContainer<StatePtr>::hasItem(unitState))
	{
		index stateIndex = getItemIndex(unitState);
		TemplateContainer<StatePtr>::m_items.erase(
			TemplateContainer<StatePtr>::m_items.begin() + stateIndex);
	}
}

StateHolder::StateHolder(DecisionPtr decision, const StateHolder& stateHolder)
	: StateHolder(m_decision)
{
	for (size_t i = 0; i < stateHolder.size(); i++)
	{
		if (!stateHolder[i]->isEqual(StatePtr(new NotEnoughManaUnitState())))
			takeNew(stateHolder[i]);
	}
}

void StateHolder::takeNew(const StatePtr& unitState)
{
	expireIfFound(unitState);
	unitState->setDecision(m_decision);
	TemplateContainer<StatePtr>::m_items.push_back(unitState);
	std::sort(TemplateContainer<StatePtr>::m_items.begin(), 
		TemplateContainer<StatePtr>::m_items.end(),
		[](const StatePtr& st1, const StatePtr& st2) {return *st1 > *st2; });
}

UnitPtr StateHolder::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	if (TemplateContainer<StatePtr>::m_items.empty())
		return m_activeState->chooseUnitToAttack(decidingUnit, units);
	return TemplateContainer<StatePtr>::m_items[0]->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StateHolder::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	if (TemplateContainer<StatePtr>::m_items.empty())
		return m_activeState->chooseMagicToCast(decidingUnit, units);
	return TemplateContainer<StatePtr>::m_items[0]->chooseMagicToCast(decidingUnit, units);
}

UnitPtr StateHolder::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (TemplateContainer<StatePtr>::m_items.empty())
		return m_activeState->chooseUnitToCast(decidingUnit, magicToCast, units);
	return TemplateContainer<StatePtr>::m_items[0]->chooseUnitToCast(decidingUnit, magicToCast, units);
}

void StateHolder::takeOffExpired(int round)
{
	for (size_t i = 0; i < TemplateContainer<StatePtr>::m_items.size(); i++)
	{
		if (TemplateContainer<StatePtr>::m_items[i]->isExpired(Arena::getCurrentRound()))
		{
			TemplateContainer<StatePtr>::m_items.erase(TemplateContainer<StatePtr>::m_items.begin() + i);
			i--;
		}
	}
}

void StateHolder::showShortInfo()const
{
	std::cout << "States: ";
	TemplateContainer<StatePtr>::showShortInfo();
}

StateHolder::~StateHolder()
{

}