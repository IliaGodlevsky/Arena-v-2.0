#pragma once

#ifndef STATE_H_
#define STATE_H_

#include "..\Unit\Unit.h"

namespace Arena
{
	class UnitState
	{
	public:
		UnitState(Unit* unit, int duration);
		virtual bool Injure(Unit* unit) = 0;
		virtual bool Spell(Unit* unit) = 0;
		void SetStart(int round);
		bool IsExpired(int round);
	protected:
		Unit* unit;
		int duration;
		int start_time;
	};

	class IsDead : public UnitState
	{
	public:
		IsDead(Unit* unit, int duration);
		bool Injure(Unit* unit);
		bool Spell(Unit* unit);
	};

	class IsMuted : public UnitState
	{
	public:
		IsMuted(Unit* unit, int duration);
		bool Injure(Unit* unit);
		bool Spell(Unit* unit);
	};

	class IsStunned : public IsMuted
	{
	public:
		IsStunned(Unit* unit, int duration);
		bool Injure(Unit* unit);
		bool Spell(Unit* unit);
	};


}

#endif