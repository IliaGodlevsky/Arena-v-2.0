#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include <vector>
#include <string>
#include <algorithm>

#include "Vitals.h"
#include "Decision.h"
#include "Armor.h"
#include "Weapon.h"
#include "UnitState.h"

template<class Pointer>
void ReleaseMemory(std::vector<Pointer>& container);

template <class Pointer>
bool PushStuff(std::vector<Pointer>& container, 
	Pointer stuff);

template <class Pointer>
void CopyStuff(std::vector<Pointer>& container1, 
	const std::vector<Pointer>& container2);

// abstract class Unit
class Unit
{
public:
	Unit(const std::string& name, 
		const Vital& health, 
		const Vital& mana, 
		UnitState* state);
	Unit(const Unit& unit);
	Unit(Unit&& unit);
	Unit& operator=(const Unit& unit);
	Unit& operator=(Unit&& unit);
	virtual ~Unit();
public:
	bool TakeArm(Weapon* weapon);
	bool TakeMagic(Magic* magic);
	bool TakeMagicOnMe(Magic* magic);
	bool TakeArmor(Armor* armor);
	virtual void Act(Decision* decision) = 0;
	virtual bool Injure(const Weapon* weapon, Unit* unit) = 0;
	virtual bool Spell(const Magic* magic, Unit* unit) = 0;
	void Show()const;
	void SetState(UnitState* state);
public:
	void ChangeArmor(int armor);
	void ChangeDamage(int damage);
	int Damage()const;
	int Arm()const;
protected:
	void CopyMagicOnMe(const Unit& unit);
	void CopyArmor(const Unit& unit);
	void CopyWeapon(const Unit& unit);
	void CopyMagic(const Unit& unit);
	void CopyUnitsStuff(const Unit& unit);
protected:
	std::vector<Magic*> on_me;
	std::vector<Armor*> armors;
	std::vector<Weapon*> weapons;
	std::vector<Magic*> magic;
protected:
	std::string name;
	UnitState* current_state;
	Vital health;
	Vital mana;
};

class Warrior : virtual public Unit
{

};

class Wizard : virtual public Unit
{

};

class BattleWizard : 
	public Warrior, public Wizard
{

};

template<class Pointer>
void ReleaseMemory(std::vector<Pointer>& container)
{
	for (auto i : container)
		delete i;
}

template <class Pointer>
bool PushStuff(std::vector<Pointer>& container, Pointer stuff)
{
	if (stuff == nullptr)
		return false;
	container.push_back(stuff);
	return true;
}

template <class Pointer>
void CopyStuff(std::vector<Pointer>& container1,
	const std::vector<Pointer>& container2)
{
	container1.clear();
	container1.resize(container2.size());
	for (size_t i = 0; i < container2.size(); i++)
		container1[i] = new Pointer(*container2[i]);
}
#endif