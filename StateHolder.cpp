#include "StateHolder.h"
#include "Unit.h"
#include "Arena.h"

StateHolder::StateHolder()
{
	active_state = new ActiveState();
}

void StateHolder::RecieveNewState(UnitState* state)
{
	unit_states.push_back(state);
	std::sort(unit_states.begin(), unit_states.end(),
		[&](const UnitState* st1, const UnitState* st2) {return *st1 > *st2; });
}

Unit* StateHolder::ChooseUnitToAttack(const Unit& deciding_unit)const
{
	if (unit_states.empty())
		return active_state->ChooseUnitToAttack(deciding_unit);
	return unit_states[0]->ChooseUnitToAttack(deciding_unit);
}

MagicPtr StateHolder::ChooseMagicToCast(const Unit& deciding_unit)const
{
	if (unit_states.empty())
		return active_state->ChooseMagicToCast(deciding_unit);
	return unit_states[0]->ChooseMagicToCast(deciding_unit);
}

Unit* StateHolder::ChooseUnitToCast(const Unit& deciding_unit,
	const MagicPtr& magic_to_spell)const
{
	if (unit_states.empty())
		return active_state->ChooseUnitToCast(deciding_unit, magic_to_spell);
	return unit_states[0]->ChooseUnitToCast(deciding_unit, magic_to_spell);
}

void StateHolder::TakeOfExpired(int round)
{
	for (size_t i = 0; i < unit_states.size(); i++)
	{
		if (unit_states[i]->IsExpired(Arena::currentRound()))
		{
			delete unit_states[i];
			unit_states.erase(unit_states.begin() + i);
			i--;
		}
	}
}

void StateHolder::ExpireAllStates()
{
	for (size_t i = 0; i < unit_states.size(); i++)
		delete unit_states[i];
	unit_states.clear();
}

StateHolder::~StateHolder()
{
	delete active_state;
	if (!unit_states.empty())
	{
		for (size_t i = 0; i < unit_states.size(); i++)
			delete unit_states[i];
	}
}