#ifndef UNIT_H_
#define UNIT_H_

#include "../Weapon/Weapon.h"
#include "../Decision/Decision.h"
#include "../Battles/Battles.h"
#include "../Vitals/Vitals.h"
#include "../MagicBook/MagicBook.h"
#include "../StateHolder/StateHolder.h"
#include "../Level/Level.h"
#include "../MagicOnMe/MagicOnMe.h"
#include "../Armor/Armor.h"
#include "../Shield/Shield.h"
#include "../Factories/ItemFactory/ItemFactory.h"
#include "../ParametresInitialiser/ParametresInitialiser.h"

void setStartTime(const MagicPtr& magic, int round);

class Unit
{
	friend class UnitState;
public:
	Unit() = delete;
	Unit& operator=(const Unit& unit) = delete;
	Unit& operator=(Unit&& unit) = delete;
	virtual ~Unit() = default;
	bool castMagic(Unit& unit, MagicPtr& magic);
	virtual bool injureUnit(Unit& unit);	
	virtual void setName(std::string name)final;
	virtual void payMana(int manaCost);
	virtual bool isEnoughManaFor(const MagicPtr& magic)const;
	virtual bool takeMagicEffect(Unit& caster, MagicPtr& magic);
	void levelUp();
	void takeKilledUnitMagic(const Unit& victim);
	void showFullInfo()const;	
	void setTeam(int teamNumber);
	void recieveNewState(StatePtr unitState);
	void moveIntoNewRound();
	const std::string& getName()const;
	bool isDead()const;
	bool takeDamage(int damage);
	bool isAlly(const Unit& unit)const;
	UnitPtr chooseUnitToAttack(const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const MagicPtr& magicToCast, 
		const Gladiators& units)const;
	virtual UnitPtr getPureClone()const;
	Battles m_damage;
	Battles m_armor;
	Vitals m_health;
	Vitals m_mana;
	MagicOnMe m_magicOnMe;
	MagicBook m_magicBook;
	StateHolder m_stateHolder;
protected:
	Unit(DecisionPtr decision);
	Unit(const Unit& unit);
	Unit(Unit&& unit);
	Unit(DecisionPtr decision, ItemFactoryPtr factory,
		LevelPtr level, ParamInitPtr initialiser);
	LevelPtr m_level = nullptr;
	WeaponPtr m_weapon = nullptr;
	ArmPtr m_mail = nullptr;
	ShieldPtr m_shield = nullptr;
	DecisionPtr m_decision = nullptr;
	std::string m_name;
private:
	virtual void prepareMagic(MagicPtr& magic)const;
	int m_teamNumber = 0;
};

#endif