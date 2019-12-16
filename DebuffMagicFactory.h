#pragma once

#ifndef DEBUFF_MAGIC_FACTORIES_H_
#define DEBUFF_MAGIC_FACTORIES_H_

#include "Factory.h"

class DamageDebuffFactory : public Factory<Magic>
{
public:
	DamageDebuffFactory();
	int getChanceOfCreation()const;
private:
	enum DamageDebuffs
	{
		WEAKNESS_MANA_COST = 10, WEAKNESS_DURATION = 2, WEAKNESS_DAMAGE_REDUCE = 7,
		TIREDNESS_MANA_COST = 15, TIREDNESS_DURATION = 2,TIREDNESS_DAMAGE_REDUCE = 11
	};
};

class ArmorDebuffFactory : public Factory<Magic>
{
public:
	ArmorDebuffFactory();
	int getChanceOfCreation()const;
private:
	enum ArmorDebuffs
	{
		CORRUPTION_MANA_COST = 14, CORRUPTION_DURATION = 2, CORRUPTION_ARMOR_REDUCE = 5,
		CORROSION_MANA_COST = 20, CORROSION_DURATION = 2, CORROSION_ARMOR_REDUCE = 7
	};
};

class ArmorAndDamageDebuffFactory : public Factory<Magic>
{
public:
	ArmorAndDamageDebuffFactory();
	int getChanceOfCreation()const;
private:
	enum
	{
		CURSE_MANA_COST = 25,CURSE_DURATION = 2, CURSE_ARMOR_REDUCE= 4,CURSE_DAMAGE_REDUCE = 6,
		MUTILATION_MANA_COST = 30, MUTILATION_DURATION = 2,MUTILATION_ARMOR_REDUCE = 5, MUTILATION_DAMAGE_REDUCE = 5
	};
};

class SilenceFactory : public Factory<Magic>
{
public:
	SilenceFactory();
	int getChanceOfCreation()const;
private:
	enum
	{
		SILENCE_MANA_COST = 25, SILENCE_DURATION = 2,
		HOLLOW_SILENCE_MANA_COST = 45, HOLLOW_SILENCE_DURATION = 3
	};
};

#endif