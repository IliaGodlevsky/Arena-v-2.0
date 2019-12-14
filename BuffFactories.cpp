#include "BuffFactories.h"
#include "BuffMagic.h"

DamageBuffFactory::DamageBuffFactory()
{
	m_items.push_back(MagicPtr(new DamageBuff("Strength",
		STRENGTH_MANA_COST, STRENGTH_DURATION, STRENGTH_AMPLIFY_DAMAGE)));
	m_items.push_back(MagicPtr(new DamageBuff("Power", POWER_MANA_COST,
		POWER_DURATION, POWER_AMPLFY_DAMAGE)));
}

int DamageBuffFactory::getChanceOfCreation()const
{
	return 35;
}

ArmorBuffFactory::ArmorBuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorBuff("Stone skin", STONE_SKIN_MANA_COST,
		STONE_SKIN_DURATION, STONE_SKIN_AMPLIFY_ARMOR)));
	m_items.push_back(MagicPtr(new ArmorBuff("Holy shield", HOLY_SHIELD_MANA_COST,
		HOLY_SHIELD_DURATION, HOLY_SHIELD_AMPLIFY_ARMOR)));
}

int ArmorBuffFactory::getChanceOfCreation()const
{
	return 35;
}

ArmorAndDamageBuffFactory::ArmorAndDamageBuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorAndDamageBuff("God armor",
		GOD_ARMOR_MANA_COST, GODS_ARMOR_DURATION,
		GODS_ARMOR_AMPLIFY_ARMOR, GODS_ARMOR_AMPLIFY_DAMAGE)));
	m_items.push_back(MagicPtr(new ArmorAndDamageBuff("Bless", BLESS_MANA_COST,
		BLESS_DURATION, BLESS_AMPLIFY_ARMOR, BLESS_AMPLIFY_DAMAGE)));
}

int ArmorAndDamageBuffFactory::getChanceOfCreation()const
{
	return 10;
}

OffsetDamageBuffFactory::OffsetDamageBuffFactory()
{
	m_items.push_back(MagicPtr(new OffsetDamageBuff("Berserk", BERSERK_MANA_COST,
		BERSERK_DURATION, BERSERK_REDUCE_ARMOR, BERSERK_AMPLIFY_DAMAGE)));
	m_items.push_back(MagicPtr(new OffsetDamageBuff("Rage", RAGE_MANA_COST,
		RAGE_DURATION, RAGE_REDUCE_ARMOR, RAGE_AMPLIFY_DAMAGE)));
}

int OffsetDamageBuffFactory::getChanceOfCreation()const
{
	return 20;
}