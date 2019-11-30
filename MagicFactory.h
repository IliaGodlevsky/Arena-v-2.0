#pragma once

#ifndef MAGIC_FACTORY
#define MAGIC_FACTORY

#include <initializer_list>
#include <valarray>

#include "Globals.h"

class MagicFactory
{
public:
	MagicFactory();
	virtual MagicPtr createMagic()final;
	virtual int chance()const = 0;
	virtual ~MagicFactory() = default;
protected:
	std::vector<MagicPtr> spells;
	int buffsGaved = 0;
};

class DamageBuffFactory : public MagicFactory
{
public:
	DamageBuffFactory();
	int chance()const;
private:
	static const int CHANCE = 35;
private:
	enum DamageBuffs
	{
		STRENGTH_AMPLIFY_DAMAGE = 4, STRENGTH_MANA_COST = 10, STRENGTH_DURATION = 2,
		POWER_AMPLFY_DAMAGE = 7, POWER_MANA_COST = 20, POWER_DURATION = 2
	};
};

class ArmorBuffFactory : public MagicFactory
{
public:
	ArmorBuffFactory();
	int chance()const;
private:
	static const int CHANCE = 35;
private:
	enum ArmorBuffs
	{
		STONE_SKIN_AMPLIFY_ARMOR = 3, STONE_SKIN_MANA_COST = 10, STONE_SKIN_DURATION = 2,
		HOLY_SHIELD_AMPLIFY_ARMOR = 6, HOLY_SHIELD_MANA_COST = 22, HOLY_SHIELD_DURATION = 2
	};
};

class ArmorAndDamageBuffFactory : public MagicFactory
{
public:
	ArmorAndDamageBuffFactory();
	int chance()const;
private:
	static const int CHANCE = 10;
private:
	enum DamageAndArmorBuffs
	{
		GODS_ARMOR_AMPLIFY_ARMOR = 3, GODS_ARMOR_AMPLIFY_DAMAGE = 5, GOD_ARMOR_MANA_COST = 25, GODS_ARMOR_DURATION = 2,
		BLESS_AMPLIFY_ARMOR = 1, BLESS_AMPLIFY_DAMAGE = 4, BLESS_MANA_COST = 20, BLESS_DURATION = 2
	};
};

class OffsetDamageBuffFactory : public MagicFactory
{
public:
	OffsetDamageBuffFactory();
	int chance()const;
private:
	static const int CHANCE = 20;
private:
	enum OffsetDamageBuffs
	{
		BERSERK_AMPLIFY_DAMAGE = 8, BERSERK_REDUCE_ARMOR = 2, BERSERK_MANA_COST = 15, BERSERK_DURATION = 2,
		RAGE_AMPLIFY_DAMAGE = 11, RAGE_REDUCE_ARMOR = 4, RAGE_MANA_COST = 25, RAGE_DURATION = 2
	};
};

class BuffFactory
{
public:
	BuffFactory(std::initializer_list<MagicFactory*> factList);
	MagicPtr createMagic();
	~BuffFactory();
private:
	int transformChanceToIndex(int chance)const;
	bool inBounds(int lower, int upper, int chance)const;
	int chance(int lowerBound, int upperBound)const;
private:
	int totalChances_ = 0;
	std::vector<int> chances_;
	std::vector<MagicFactory*> factories_;
};
#endif