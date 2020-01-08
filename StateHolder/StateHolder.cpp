#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../UnitState/ActiveUnitState.h"
#include "../UnitState/StunUnitState.h"
#include "../UnitState/MutedUnitState.h"
#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../UnitState/DisableUnitState.h"

bool isMoreImportantState(const StatePtr& st1, 
	const StatePtr& st2)
{
	return *st1 > *st2;
}

StateHolder::StateHolder(DecisionPtr decision)
	: m_decision(decision)
{
	m_items.push_back(StatePtr(new ActiveUnitState()));
	m_items[0]->setDecision(m_decision);
}

void StateHolder::expireIfFound(const StatePtr& unitState)
{
	if (hasItem(unitState))
	{
		index stateIndex = getItemIndex(unitState);
		m_items.erase(m_items.begin() + stateIndex);
	}
}

StateHolder::StateHolder(Unit* unit, DecisionPtr decision, const StateHolder& stateHolder)
	: StateHolder(m_decision)
{
	m_unit = unit;
	for (size_t i = 0; i < stateHolder.size(); i++)
			takeNew(stateHolder[i]);
	InnerUnitState* is = nullptr;
	for (size_t i = 0; i < size(); i++)
		if (is = DYNAMIC(InnerUnitState*, m_items[i]))
			is->setOwner(m_unit);
	std::sort(m_items.begin(), m_items.end(), isMoreImportantState);
}

void StateHolder::takeNew(const StatePtr& unitState)
{
	if (nullptr == unitState)
		return;
	expireIfFound(unitState);
	unitState->setDecision(m_decision);
	m_items.push_back(unitState);
	if (hasItem(StatePtr(new NotEnoughManaUnitState())) &&
		hasItem(StatePtr(new NotEnoughDamageUnitState())) &&
		!hasItem(StatePtr(new DisableUnitState())))
	{
		StatePtr newState(new DisableUnitState(m_unit));
		newState->setDecision(m_decision);
		takeNew(newState);
	}
	std::sort(m_items.begin(), m_items.end(), isMoreImportantState);
}

bool StateHolder::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return m_items[0]->castMagic(caster, unit, magic);
}

bool StateHolder::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return m_items[0]->injureUnit(weapon, unit, damage);
}

UnitPtr StateHolder::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return m_items[0]->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StateHolder::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	return m_items[0]->chooseMagicToCast(decidingUnit, units);
}

UnitPtr StateHolder::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return m_items[0]->chooseUnitToCast(decidingUnit, magicToCast, units);
}

void StateHolder::makeExpire(size_t stateIndex)
{
	OuterUnitState* state = nullptr;
	if (state = DYNAMIC(OuterUnitState*, m_items[stateIndex]))
		state->setStartTime(Arena::getCurrentRound() - 
			state->getDuration() - 1);
}

void StateHolder::takeOffExpired(int round)
{
	InnerUnitState* is = nullptr;
	OuterUnitState* os = nullptr;
	for (size_t i = 0; i < m_items.size(); i++)
	{	
		if (is = DYNAMIC(InnerUnitState*, m_items[i]))
		{
			if (is->isExpired())
			{
				m_items.erase(m_items.begin() + i);
				i--;
			}
		}
		else if (os = DYNAMIC(OuterUnitState*, m_items[i]))
		{
			if (os->isExpired(Arena::getCurrentRound()))
			{
				m_items.erase(m_items.begin() + i);
				i--;
			}
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