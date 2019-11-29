#include <algorithm>

#include "State.h"
#include "Unit.h"
#include "Arena.h"

UnitState::UnitState(int duration)
	: durationmeter(duration)
{

}

Unit* UnitState::ChooseUnitToAttack(const Unit& deciding_unit)const
{
	return nullptr;
}

MagicPtr UnitState::ChooseMagicToCast(const Unit& deciding_unit)const
{
	return nullptr;
}

Unit* UnitState::ChooseUnitToCast(const Unit& deciding_unit,
	const MagicPtr& magic_to_spell)const
{
	return nullptr;
}

void UnitState::RecieveDecision(Decision* decision)
{
	if (nullptr != decision)
		this->decision = decision;
}

void UnitState::SetStartTime(int round)
{
	durationmeter.SetStartTime(round);
}

bool UnitState::IsExpired(int round)const
{
	return durationmeter.IsExpired(round);
}

bool UnitState::operator < (const UnitState& state)const
{
	return Value() < state.Value();
}

bool UnitState::operator>(const UnitState& state)const
{
	return Value() > state.Value();
}


ActiveState::ActiveState()
	: UnitState(INT_MAX)
{

}

Unit* ActiveState::ChooseUnitToAttack(const Unit& deciding_unit)const
{
	return decision->ChooseUnitToAttack(deciding_unit);
}

MagicPtr ActiveState::ChooseMagicToCast(const Unit& deciding_unit)const
{
	return decision->ChooseMagicToCast(deciding_unit);
}

Unit* ActiveState::ChooseUnitToCast(const Unit& deciding_unit,
	const MagicPtr& magic_to_spell)const
{
	return decision->ChooseUnitToCast(deciding_unit, magic_to_spell);
}

UnitState::StateValue ActiveState::Value()const
{
	return UnitState::ALIVE_STATE;
}


MutedState::MutedState(int duration)
	: UnitState(duration)
{

}

Unit* MutedState::ChooseUnitToAttack(const Unit& deciding_unit)const
{
	return decision->ChooseUnitToAttack(deciding_unit);
}

MagicPtr MutedState::ChooseMagicToCast(const Unit& deciding_unit)const
{
	return nullptr;
}

Unit* MutedState::ChooseUnitToCast(const Unit& deciding_unit,
	const MagicPtr& magic_to_spell)const
{
	return nullptr;
}


Unit* StunState::ChooseUnitToAttack(const Unit& deciding_unit)const
{
	return UnitState::ChooseUnitToAttack(deciding_unit);
}

MagicPtr StunState::ChooseMagicToCast(const Unit& deciding_unit)const
{
	return UnitState::ChooseMagicToCast(deciding_unit);
}

Unit* StunState::ChooseUnitToCast(const Unit& deciding_unit,
	const MagicPtr& magic_to_spell)const
{
	return UnitState::ChooseUnitToCast(deciding_unit, magic_to_spell);
}







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
		if (unit_states[i]->IsExpired(Arena::CurrentRound()))
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