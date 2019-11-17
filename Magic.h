#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include <string>
#include <vector>
#include <memory>

#include "Unit.h"

template <class Spell>
using spell_ptr = std::unique_ptr<Spell>;

// abstract base class (could't create an instance of this class)
class Magic
{
public:
	Magic(std::string name,
		int mana_cost, int duration);
	virtual ~Magic();
public:
	virtual void Effect(Unit* unit) = 0;
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
	void Effect(Unit* unit) override;
	void Uneffect(Unit* unit)const override;
	DamageBuff* Clone()const override;
protected:
	int damage_amplify;
protected:
	void PutOn(Unit* unit)const;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify);
	void Effect(Unit* unit) override;
	void Uneffect(Unit* unit)const override;
	ArmorBuff* Clone()const override;
protected:
	int armor_amplify;
protected:
	void PutOn(Unit* unit)const;
};

class ArmorAndDamageBuff 
	: public ArmorBuff, public DamageBuff
{
public:
	ArmorAndDamageBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify, int damage_amplify);
	void Effect(Unit* unit)override;
	void Uneffect(Unit* unit)const override;
	ArmorAndDamageBuff* Clone()const override;
};

using Spells = std::vector<spell_ptr<Magic>>;

class SpellBook
{
public:
	void AddMagic(spell_ptr<Magic> magic);
	const spell_ptr<Magic>& operator[](int i)const;
	spell_ptr<Magic>& operator[](int i);
private:
	Spells spells;
};

class SpellsOnMe
{
public:
	SpellsOnMe(Unit* unit);
	void AddMagic(spell_ptr<Magic> magic);
	void TakeOfExpired(int round);
private:
	Spells spells;
	Unit* unit;
};

#endif