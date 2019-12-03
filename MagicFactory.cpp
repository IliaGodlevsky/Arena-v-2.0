#include "MagicFactory.h"
#include "Magic.h"

int randomIndex(int arraySize) { return std::rand() % arraySize; }

DamageBuffFactory::DamageBuffFactory()
{
	items.push_back(MagicPtr(new DamageBuff("Strength",
		STRENGTH_MANA_COST, STRENGTH_DURATION, STRENGTH_AMPLIFY_DAMAGE)));
	items.push_back(MagicPtr(new DamageBuff("Power", POWER_MANA_COST,
		POWER_DURATION, POWER_AMPLFY_DAMAGE)));
}

int DamageBuffFactory::chance()const
{
	return CHANCE;
}

ArmorBuffFactory::ArmorBuffFactory()
{
	items.push_back(MagicPtr(new ArmorBuff("Stone skin", STONE_SKIN_MANA_COST,
		STONE_SKIN_DURATION, STONE_SKIN_AMPLIFY_ARMOR)));
	items.push_back(MagicPtr(new ArmorBuff("Holy shield", HOLY_SHIELD_MANA_COST,
		HOLY_SHIELD_DURATION, HOLY_SHIELD_AMPLIFY_ARMOR)));
}

int ArmorBuffFactory::chance()const
{
	return CHANCE;
}

ArmorAndDamageBuffFactory::ArmorAndDamageBuffFactory()
{
	items.push_back(MagicPtr(new ArmorAndDamageBuff("God armor",
		GOD_ARMOR_MANA_COST, GODS_ARMOR_DURATION,
		GODS_ARMOR_AMPLIFY_ARMOR, GODS_ARMOR_AMPLIFY_DAMAGE)));
	items.push_back(MagicPtr(new ArmorAndDamageBuff("Bless", BLESS_MANA_COST,
		BLESS_DURATION, BLESS_AMPLIFY_ARMOR, BLESS_AMPLIFY_DAMAGE)));
}

int ArmorAndDamageBuffFactory::chance()const
{
	return CHANCE;
}

OffsetDamageBuffFactory::OffsetDamageBuffFactory()
{
	items.push_back(MagicPtr(new OffsetDamageBuff("Berserk", BERSERK_MANA_COST,
		BERSERK_DURATION, BERSERK_REDUCE_ARMOR, BERSERK_AMPLIFY_DAMAGE)));
	items.push_back(MagicPtr(new OffsetDamageBuff("Rage", RAGE_MANA_COST,
		RAGE_DURATION, RAGE_REDUCE_ARMOR, RAGE_AMPLIFY_DAMAGE)));
}

int OffsetDamageBuffFactory::chance()const
{
	return CHANCE;
}