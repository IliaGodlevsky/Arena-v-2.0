#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../UnitState/ActiveUnitState.h"
#include "../UnitState/StunUnitState.h"
#include "../UnitState/MutedUnitState.h"
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
	if (hasItem(unitState))
	{
		index stateIndex = getItemIndex(unitState);
		m_items.erase(m_items.begin() + stateIndex);
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
	if (nullptr == unitState)
		return;
	expireIfFound(unitState);
	unitState->setDecision(m_decision);
	m_items.push_back(unitState);
	std::sort(m_items.begin(), m_items.end(),
		[](const StatePtr& st1, const StatePtr& st2) {return *st1 > *st2; });
}

bool StateHolder::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	if (m_items.empty())
		return m_activeState->castMagic(caster, unit, magic);
	return m_items[0]->castMagic(caster, unit, magic);
}

bool StateHolder::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	if (m_items.empty())
		return m_activeState->injureUnit(weapon, unit, damage);
	return m_items[0]->injureUnit(weapon, unit, damage);
}

UnitPtr StateHolder::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	if (m_items.empty())
		return m_activeState->chooseUnitToAttack(decidingUnit, units);
	return m_items[0]->chooseUnitToAttack(decidingUnit, units);
}

MagicPtr StateHolder::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	if (m_items.empty())
		return m_activeState->chooseMagicToCast(decidingUnit, units);
	return m_items[0]->chooseMagicToCast(decidingUnit, units);
}

UnitPtr StateHolder::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (m_items.empty())
		return m_activeState->chooseUnitToCast(decidingUnit, magicToCast, units);
	return m_items[0]->chooseUnitToCast(decidingUnit, magicToCast, units);
}

void StateHolder::takeOffExpired(int round)
{
	for (size_t i = 0; i < m_items.size(); i++)
	{
		if (m_items[i]->isExpired(Arena::getCurrentRound()))
		{
			m_items.erase(m_items.begin() + i);
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