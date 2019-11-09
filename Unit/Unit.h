#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>

#include "..\Magic\Magic.h"

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
		void Decide(Decision* decision); // todo: make return value
		void SetState(UnitState* state);
		void CheckStatus();
	public:
		void DamageChange(int damage);
		void ArmorChange(int armor);
		void RegenerationChange(int regeneration);
		void PayMana(int mana_cost);
		int CurrentMana()const;
	private:
		void TakeOffExpiredSpells();
	private:
		Vitals mana;
		Vitals health;
		Battles damage;
		Battles armor;
	private:
		using SpellBook = std::vector<Magic*>;
	private:
		UnitState* state;
		UnitBattleState* battle_state;
		std::vector<Magic*> spells_on_me;
		SpellBook spell_book;
		Weapon* weapon;
		Armor* armor;
	};
}
#endif