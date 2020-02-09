#ifndef SHIELD_H_
#define SHIELD_H_

#include "../Globals/Globals.h"
#include "../Armor/Armor.h"

class Shield;
using ShieldPtr = std::unique_ptr<Shield>;

class Shield
{
public:
	Shield(std::string name, int armor,int reflectChance = 0);
	void showFullInfo()const;
	virtual void showShortInfo()const;
	virtual bool takeDamage(Unit& unit, int damage)const;
	virtual bool takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const;
	void putOn(Unit& unit)const;
	virtual bool isReflected()const;
	void putOff(Unit& unit)const;
	virtual ShieldPtr clone()const;
	virtual ShieldPtr getPureShield()const final;
	virtual ~Shield() = default;
protected:
	Armor m_armor;
	std::string m_name;
	int m_reflectChance = 0;
};

#endif