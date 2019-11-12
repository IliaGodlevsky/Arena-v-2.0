#pragma once

#ifndef STATE_H_
#define STATE_H_

#include "..\Unit\Unit.h"

namespace Arena
{
	class UnitState
	{
	public:

	protected:

	};

	class IsDead : public UnitState
	{
	public:

	};

	class IsMuted : public UnitState
	{
	public:
	};

	class IsStunned : public UnitState
	{
	public:
	};

	class StateHolder
	{
	public:
		StateHolder(Unit* unit);
		bool Injure(Unit* unit);
		bool Spell(Unit* unit);
		void AddState(UnitState* state);
		void TakeOfExpired();
	private:
		std::vector<UnitState*> states;
	};
}

#endif