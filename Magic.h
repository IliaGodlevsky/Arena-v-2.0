#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include <string>

#include "Unit.h"

// abstract base class (could't create an instance of this class)
class Magic
{
public:
	Magic(std::string name,
		int mana_cost, int duration);
	virtual ~Magic();
public:
	virtual void Effect(Unit* unit)const = 0;
	virtual void Uneffect(Unit* unit)const = 0;
	virtual Magic* Clone()const = 0;
public:
	virtual bool IsExpired(int round)const final;
	virtual void SetStartTime(int round) final;
	virtual bool EnoughMana(int current_mana)const final;
	virtual std::string ShowName()const final;
protected:
	std::string name;
	int mana_cost;
	int duration;
	int start_time;
};

class DamageBuff : virtual public Magic
{
public:
	DamageBuff(std::string name, int mana_cost,
		int duration, int damage_amplify);
	void Effect(Unit* unit)const override;
	void Uneffect(Unit* unit)const override;
	DamageBuff* Clone()const override;
protected:
	int damage_amplify;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify);
	void Effect(Unit* unit)const override;
	void Uneffect(Unit* unit)const override;
	ArmorBuff* Clone()const override;
protected:
	int armor_amplify;
};

class ArmorAndDamageBuff 
	: public ArmorBuff, public DamageBuff
{
public:
	ArmorAndDamageBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify, int damage_amplify);
	void Effect(Unit* unit)const override;
	void Uneffect(Unit* unit)const override;
	ArmorAndDamageBuff* Clone()const override;
};

#endif