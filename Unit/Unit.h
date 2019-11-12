#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>

#include "../Magic\Magic.h"
#include "../UnitState/UnitState.h"

namespace Arena
{
	class Unit
	{
		friend class StateHolder;
	public:
		Unit(std::string name);
		Unit(const Unit& unit);
		Unit(Unit&& unit);
		Unit& operator=(const Unit& unit);
		Unit& operator=(Unit&& unit);
	public:
		void AddState(UnitState* state);
		void TakeSpellOnMe(const Magic* magic);
		bool HaveSpell(const Magic* magic);
	public:
		void DamageChange(int damage);
		void ArmorChange(int armor);
		void HealthChange(int health);
		void RegenerationChange(int regeneration);
		void PayMana(int mana_cost);
		int CurrentMana()const;
		bool IsDead()const;
		int Damage()const;
		int Armor()const;
	private:
		StateHolder* state;

	};
}
#endif