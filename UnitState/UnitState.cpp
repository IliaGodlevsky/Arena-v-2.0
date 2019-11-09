#include <iostream>

#include "UnitState.h"

namespace Arena
{
	UnitState::UnitState(Unit* unit, int duration)
	{
		this->unit = unit;
		this->duration = duration;
	}

	void UnitState::SetStart(int round)
	{
		start_time = round;
	}

	bool UnitState::IsExpired(int round)
	{
		return round - start_time == duration;
	}




	IsDead::IsDead(Unit* unit)
		: UnitState(unit, INT_MAX)
	{

	}

	bool IsDead::Injure(Unit* unit)
	{
		std::cout << "\aUnit is dead\n";
		return false;
	}

	bool IsDead::Spell(Unit* unit)
	{
		return Injure(unit);
	}




	IsMuted::IsMuted(Unit* unit, int duration)
		: UnitState(unit, duration)
	{

	}

	bool IsMuted::Injure(Unit* unit)
	{
		return this->unit->Injure(unit);
	}

	bool IsMuted::Spell(Unit* unit)
	{
		std::cout << "\aYou are muted. You can't cast spells\n";
		return false;
	}




	IsStunned::IsStunned(Unit* unit, int duration)
		: IsMuted(unit, duration)
	{

	}
	bool IsStunned::Injure(Unit* unit)
	{
		std::cout << "You are stunned! You can't attack\n";
		return false;
	}

	bool IsStunned::Spell(Unit* unit)
	{
		return IsMuted::Spell(unit);
	}


}