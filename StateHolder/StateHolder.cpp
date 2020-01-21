#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../UnitState/OuterUnitState/StunUnitState.h"
#include "../UnitState/OuterUnitState/MutedUnitState.h"
#include "../Magic/Magic.h"
#include "../Decision/Decision.h"
#include "../UnitState/InnerUnitState/ActiveUnitState.h"

enum { CURRENT_STATE };

inline bool isMoreImportantState(const StatePtr& st1, 
	const StatePtr& st2)
{
	return *st1 > *st2;
}

StateHolder::StateHolder(Unit* unit)
	: m_holder(unit)
{
	takeNew(StatePtr(new ActiveUnitState(m_holder)));
}

void StateHolder::expireIfFound(const StatePtr& unitState)
{
	if (hasItem(unitState))
	{
		index stateIndex = getItemIndex(unitState);
		m_items.erase(m_items.begin() + stateIndex);
	}
}

StateHolder::StateHolder(Unit* unit, const StateHolder& stateHolder)
	: StateHolder(unit)
{
	for (size_t i = 0; i < stateHolder.size(); i++)
		takeNew(stateHolder[i]);
}

bool StateHolder::itemHasPassedControl(const StatePtr& unitState)const
{
	if (nullptr == unitState)
		return false;
	else
		return true;
}

void StateHolder::takeNew(const StatePtr& unitState)
{
	if (itemHasPassedControl(unitState))
	{
		expireIfFound(unitState);
		StatePtr temp = unitState->clone();
		InnerUnitState* innerState = nullptr;
		if (innerState = DYNAMIC(InnerUnitState*, temp))
			innerState->setOwner(m_holder);
		m_items.push_back(temp);
		std::sort(m_items.begin(), m_items.end(), isMoreImportantState);
	}
}

bool StateHolder::castMagic(Unit& caster, Unit& unit, MagicPtr& magic)
{
	return m_items[CURRENT_STATE]->castMagic(caster, unit, magic);
}

bool StateHolder::injureUnit(WeaponPtr& weapon, Unit& unit, int damage)
{
	return m_items[CURRENT_STATE]->injureUnit(weapon, unit, damage);
}

bool StateHolder::takeDamage(Unit& unit, int damage)
{
	return m_items[CURRENT_STATE]->takeDamage(unit, damage);
}

bool StateHolder::takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)
{
	return m_items[CURRENT_STATE]->takeMagicEffect(unit, caster, magic);
}

UnitPtr StateHolder::chooseUnitToAttack(DecisionPtr decision, const Unit& decidingUnit,
	const Gladiators& units)const
{
	return m_items[CURRENT_STATE]->chooseUnitToAttack(decision, decidingUnit, units);
}

MagicPtr StateHolder::chooseMagicToCast(DecisionPtr decision, const Unit& decidingUnit,
	const Gladiators& units)const
{
	return m_items[CURRENT_STATE]->chooseMagicToCast(decision, decidingUnit, units);
}

UnitPtr StateHolder::chooseUnitToCast(DecisionPtr decision, const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	return m_items[CURRENT_STATE]->chooseUnitToCast(decision, decidingUnit, magicToCast, units);
}

void StateHolder::makeExpire(size_t stateIndex)
{
	OuterUnitState* state = nullptr;
	if (state = DYNAMIC(OuterUnitState*, m_items[stateIndex]))
		state->setStartTime(Arena::getCurrentRound() - 
			state->getDuration() - 1);
}

void StateHolder::takeOffExpired()
{
	for (size_t i = 0; i < m_items.size(); i++)
	{	
		if (m_items[i]->isExpired())
		{
			m_items.erase(m_items.begin() + i);
			i--;
		}
	}
}

void StateHolder::setItemColor(const StatePtr& unitState)const
{
	InnerUnitState* inner = nullptr;
	inner = DYNAMIC(InnerUnitState*, unitState);
	if (inner == nullptr)
		setColor(LIGHT_RED);
	else
		setColor(BROWN);
}

void StateHolder::showShortInfo()const
{
	std::cout << "States: ";
	TemplateContainer<StatePtr>::showShortInfo();
}

StateHolder::~StateHolder()
{

}