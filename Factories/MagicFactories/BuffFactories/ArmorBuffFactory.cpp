#include "ArmorBuffFactory.h"

#include "../../../Magic/BuffMagic/ArmorBuffMagic.h"

ArmorBuffFactory::ArmorBuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorBuffMagic("Stone skin", STONE_SKIN_MANA_COST,
		STONE_SKIN_DURATION, STONE_SKIN_AMPLIFY_ARMOR)));
	m_items.push_back(MagicPtr(new ArmorBuffMagic("Holy shield", HOLY_SHIELD_MANA_COST,
		HOLY_SHIELD_DURATION, HOLY_SHIELD_AMPLIFY_ARMOR)));
}