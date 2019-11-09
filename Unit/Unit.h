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
		void Decide(Decision* decision);
		void SetState(UnitState* state);
	private:
		Vitals mana;
		Vitals health;
		Battles damage;
		Battles armor;
	private:
		using SpellBook = std::vector<Magic*>;
	private:
		UnitState* state;
		std::vector<Magic*> spells_on_me;
		SpellBook spell_book;
		Weapon* weapon;
		Armor* armor;
	};
}
#endif