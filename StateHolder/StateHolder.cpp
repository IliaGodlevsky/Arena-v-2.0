#include <functional>

#include "StateHolder.h"

#include "../Unit/Unit.h"
#include "../Arena/Arena.h"
#include "../Magic/Magic.h"
#include "../UnitState/OuterUnitState/OuterUnitState.h"
#include "../UnitState/InnerUnitState/ActiveUnitState.h"

enum { CURRENT_STATE };

StateHolder::StateHolder(Unit* unit)
	: m_holder(unit)
{
	takeNew(StatePtr(new ActiveUnitState(m_holder)));
}

void StateHolder::expireIfFound(const StatePtr& unitState)
{
	if (hasItem(unitState))
	{
		m_items.erase(std::find_if(m_items.begin(), m_items.end(),
			[&](const StatePtr& it) {return unitState->isEqual(it); }));
	}
}

StateHolder::StateHolder(Unit* unit, const StateHolder& stateHolder)
	: StateHolder(unit)
{
	std::for_each(stateHolder.m_items.begin(), stateHolder.m_items.end(),
		[&](const StatePtr& st) { takeNew(st); });
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
		std::sort(m_items.begin(), m_items.end(),
			[](const StatePtr& st1, const StatePtr& st2) {return *st1 > *st2; });
	}
}

bool StateHolder::canCast()const
{
	return std::all_of(m_items.begin(), m_items.end(), 
		[](const StatePtr st) {return st->canCast(); });
}

bool StateHolder::canAttack()const
{
	return std::all_of(m_items.begin(), m_items.end(),
		[](const StatePtr st) {return st->canAttack(); });
}

bool StateHolder::canTakeDamage(Unit& unit, int damage)const
{
	return m_items[CURRENT_STATE]->canTakeDamage(unit, damage);
}

bool StateHolder::canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const
{
	return m_items[CURRENT_STATE]->canTakeMagicEffect(unit, caster, magic);
}

void StateHolder::makeExpire(StatePtr& state)
{
	auto expired = std::find_if(m_items.begin(),m_items.end(),
		[&](const StatePtr& it) {return state->isEqual(it); });
	OuterUnitState* st = nullptr;
	if (st = DYNAMIC(OuterUnitState*, (*expired)))
		st->setStartTime(Arena::getCurrentRound() - 
			st->getDuration() - 1);
}

void StateHolder::takeOffExpired()
{
	m_items.erase(std::remove_if(m_items.begin(), m_items.end(),
		std::mem_fn(&UnitState::isExpired)), m_items.end());
}

void StateHolder::setItemColor(const StatePtr& unitState)const
{
	InnerUnitState* innerState = DYNAMIC(InnerUnitState*, unitState);
	if (!innerState)
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