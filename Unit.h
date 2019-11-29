#ifndef UNIT_H_
#define UNIT_H_

#include "Level.h"
#include "Vitals.h"
#include "Magic.h"
#include "Sheild.h"
#include "Armor.h"
#include "Sheild.h"
#include "Weapon.h"
#include "Decision.h"
#include "SpellBook.h"
#include "SpellsOnMe.h"
#include "State.h"

#include "Globals.h"

class Unit
{
	friend bool Weapon::CanSmash(const Unit& unit)const;
	friend class ComputerDecision;
public:
	Unit(std::string name, Decision* decision);
	virtual ~Unit();
public:
	bool EnoughManaFor(const MagicPtr& magic)const;
	bool TakeDamage(int damage);
	bool Injure(Unit& unit);
	bool Spell(Unit& unit, MagicPtr& magic);
	bool IsAlive()const;
public:
	void PayMana(int mana_cost);
	void ShowFullInfo()const;
	void LevelUp();
	void RecieveNewState(UnitState* state);
	void Scan();
public:
	const std::string& Name()const;
	Unit* ChooseUnitToAttack()const;
	MagicPtr ChooseMagicToCast()const;
	Unit* ChooseUnitToCast(const MagicPtr& magic_to_spell)const;
public:
	Battles damage;
	Battles armor;
	Vitals health;
	Vitals mana;
	SpellsOnMe on_me;
	SpellBook spell_book;
	Level level;
	StateHolder state;
private:
	std::string name;
	Decision* decision;
private:
	std::unique_ptr<Weapon> weapon;
	std::unique_ptr<Armor> mail;
	std::unique_ptr<Shield> sheild;
private:
	int AbsorbCalc(int damage)const;
};

#endif