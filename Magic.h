#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include <string>
#include <vector>
#include <memory>

#include "Unit.h"

class Magic;
using MagicPtr = std::unique_ptr<Magic>;

// abstract base class (could't create an instance of this class)
class Magic
{
public:
	Magic(std::string name,
		int mana_cost, int duration);
	virtual ~Magic();
public:
	virtual void Effect(UnitPtr unit) = 0;
	virtual void Uneffect(UnitPtr unit)const = 0;
	virtual MagicPtr Clone()const = 0; // Prototype
public:
	virtual bool IsExpired(int round)const final;
	virtual void SetStartTime(int round) final;
	virtual bool EnoughMana(int current_mana)const final;
	virtual std::string ShowName()const final;
public:
	friend bool operator==(const Magic& first, const Magic& second);
	friend bool operator!=(const Magic& first, const Magic& second);
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
	void Effect(UnitPtr unit) override;
	void Uneffect(UnitPtr unit)const override;
	MagicPtr Clone()const override;
public:
	friend bool operator==(const DamageBuff& first, const DamageBuff& second);
	friend bool operator!=(const DamageBuff& first, const DamageBuff& second);
protected:
	int damage_amplify;
protected:
	void PutOn(UnitPtr unit)const;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify);
	void Effect(UnitPtr unit) override;
	void Uneffect(UnitPtr unit)const override;
	MagicPtr Clone()const override;
public:
	friend bool operator==(const ArmorBuff& first, const ArmorBuff& second);
	friend bool operator!=(const ArmorBuff& first, const ArmorBuff& second);
protected:
	int armor_amplify;
protected:
	void PutOn(UnitPtr unit)const;
};

class ArmorAndDamageBuff 
	: public ArmorBuff, public DamageBuff
{
public:
	ArmorAndDamageBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify, int damage_amplify);
	void Effect(UnitPtr unit)override;
	void Uneffect(UnitPtr unit)const override;
	MagicPtr Clone()const override;
public:
	friend bool operator==(const ArmorAndDamageBuff& first, const ArmorAndDamageBuff& second);
	friend bool operator!=(const ArmorAndDamageBuff& first, const ArmorAndDamageBuff& second);
};

using Spells = std::vector<MagicPtr>;

class SpellsOnMe : public Spells
{
public:
	SpellsOnMe(UnitPtr unit);
	void TakeOfExpired(int round);
	bool HaveSpell(const MagicPtr& spell)const;
private:
	UnitPtr unit;
};

#endif