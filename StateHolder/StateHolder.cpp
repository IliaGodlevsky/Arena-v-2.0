#include <numeric>

#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../Magic/Magic.h"
#include "../UnitState/OuterUnitState/OuterUnitState.h"
#include "../UnitState/InnerUnitState/ActiveUnitState.h"

enum { CURRENT_STATE };

inline bool isMoreImportantState(const StatePtr& st1, 
	const StatePtr& st2)
{
	return *st1 > *st2;
}

inline bool castAccum(const StatePtr st1, bool accum)
{
	return st1->canCast() && accum;
}

inline bool attackAccum(const StatePtr st1, bool accum)
{
	return st1->canAttack() && accum;
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
	return nullptr != unitState;
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

bool StateHolder::canCast()const
{
	return stateAccumulator(m_items, castAccum);
}

bool StateHolder::canAttack()const
{
	return stateAccumulator(m_items, attackAccum);
}

bool StateHolder::canTakeDamage(Unit& unit, int damage)const
{
	return m_items[CURRENT_STATE]->canTakeDamage(unit, damage);
}

bool StateHolder::canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	return m_items[CURRENT_STATE]->canTakeMagicEffect(unit, caster, magic);
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
	InnerUnitState* inner = DYNAMIC(InnerUnitState*, unitState);
	if (nullptr == inner)
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