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
	friend class ComputerDecision;
public:
	Unit(std::string name, DecisionPtr decision, 
		ItemFactoryPtr factory);
	Unit(const Unit& unit);
	virtual ~Unit();
public:
	bool isEnoughManaFor(const MagicPtr& magic)const;
	bool takeDamage(int damage);
	bool injureUnit(Unit& unit);
	bool castMagic(Unit& unit, MagicPtr& magic);
	bool isAlive()const;
public:
	virtual void payMana(int manaCost);
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
	UnitPtr clone()const;
public:
	Battles m_damage;
	Battles m_armor;
	Vitals m_health;
	Vitals m_mana;
	MagicOnMe m_magicOnMe;
	MagicBook m_magicBook;
	StateHolder m_stateHolder;
protected:
	std::unique_ptr<Level> m_level;
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