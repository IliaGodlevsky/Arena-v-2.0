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
	public:
		Unit(std::string name);
		Unit(const Unit& unit);
		Unit(Unit&& unit);
		Unit& operator=(const Unit& unit);
		Unit& operator=(Unit&& unit);
	public:
		bool Injure(Unit* unit);
		bool Spell(Unit* unit);
	public:
		void Decide(Decision* decision); // todo: make return value of decision
		void AddState(UnitState* state);
		void TakeSpellOnMe(const Magic* magic);
		void ReloadStatus();
	public:
		void DamageChange(int damage);
		void ArmorChange(int armor);
		void HealthChange(int health);
		void RegenerationChange(int regeneration);
		void PayMana(int mana_cost);
		int CurrentMana()const;
		bool IsDead()const;
	private:
		void TakeOffExpiredSpells();
		void TakeOffExpiredStates();
	private:
		Vitals mana;
		Vitals health;
		Battles damage;
		Battles armor;
	private:
		using SpellBook = std::vector<Magic*>;
		using SpellsUnder = SpellBook;
	private:
		std::vector<UnitState*> states;
		UnitBattleState* battle_state;
		SpellsUnder spells_on_me;
		SpellBook spell_book;
		Weapon* weapon;
		Armor* armor;
	};
}
#endif