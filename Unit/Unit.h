#ifndef UNIT_H_
#define UNIT_H_

#include "../Weapon/Weapon.h"
#include "../Decision/Decision.h"
#include "../UnitState/UnitState.h"
#include "../Battles/Battles.h"
#include "../Vitals/Vitals.h"
#include "../MagicBook/MagicBook.h"
#include "../StateHolder/StateHolder.h"
#include "../Level/Level.h"
#include "../MagicOnMe/MagicOnMe.h"
#include "../Armor/Armor.h"
#include "../Shield/Shield.h"
#include "../Factories/ItemFactory/ItemFactory.h"

class Unit
{
public:
	friend bool Weapon::canSmashUnit(const Unit& unit)const;
	friend class ComputerDecision;
public:
	Unit(std::string name, DecisionPtr decision, ItemFactory* factory);
	virtual ~Unit();
public:
	bool isEnoughManaFor(const MagicPtr& magic)const;
	bool takeDamage(int damage);
	bool injureUnit(Unit& unit);
	bool castMagic(Unit& unit, MagicPtr& magic);
	bool isAlive()const;
public:
	void payMana(int manaCost);
	void showFullInfo()const;
	void levelUp();
	void recieveNewState(StatePtr unitState);
	void moveIntoNewRound();
	const std::string& getName()const;
public:
	UnitPtr chooseUnitToAttack(const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const MagicPtr& magicToCast_ptr, 
		const Gladiators& units)const;
public:
	Battles m_damage = Battles(4);
	Battles m_armor = Battles(2);
	Vitals m_health = { 100,100,2 };
	Vitals m_mana = { 40,40,1 };
	MagicOnMe m_magicOnMe;
	MagicBook m_magicBook;
	Level m_level;
	StateHolder m_stateHolder;
private:
	std::string m_name;
	DecisionPtr m_decision;
private:
	WeaponPtr m_weapon;
	ArmPtr m_mail;
	ShieldPtr m_shield;
private:
	int calculateDamageAbsorb(int damage)const;
};

#endif