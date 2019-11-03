#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include "Unit.h"

class Magic
{
public:
	Magic(int mana_cost, int duration);
	virtual void Effect(Unit* unit)const = 0;
	virtual Magic* Clone() const = 0;
	void SetTimeOfActivation(int round);
	bool Expired(int round)const;
	virtual ~Magic();
protected:
	int mana_cost;
	int duration;
	int activation_time;
};

class DamageBuff : virtual public Magic
{
public:
	DamageBuff(int mana_cost, int duration, 
		int amplify_damage);
	virtual void Effect(Unit* unit)const;
	virtual DamageBuff* Clone()const;
	virtual ~DamageBuff();
private:
	int amplify_damage;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(int mana_cost, int duration,
		int amplify_armor);
	virtual void Effect(Unit* unit)const;
	virtual ArmorBuff* Clone()const;
	virtual ~ArmorBuff();
private:
	int amplify_armor;
};

class DamageArmorBuff : 
	public DamageBuff, public ArmorBuff
{
public:
	DamageArmorBuff(int mana_cost, int duration,
		int amplify_armor, int amplify_damage);
	void Effect(Unit* unit)const;
	DamageArmorBuff* Clone()const;
	~DamageArmorBuff();
};

class HealMagic : public Magic
{
public:
	HealMagic(int mana_cost, int duration, int heal);
	void Effect(Unit* unit)const;
	HealMagic* Clone()const;
private:
	int heal;
};

class NegativeMagicDispel : public Magic
{
public:
	
};
#endif