#include "../../../Magic/BuffMagic/OffsetDamageBuffMagic.h"

#include "OffsetDamageBuffFactory.h"

OffsetDamageBuffFactory::OffsetDamageBuffFactory()
{
	m_items.push_back(MagicPtr(new OffsetDamageBuffMagic("Berserk", BERSERK_MANA_COST,
		Timer(BERSERK_DURATION), BERSERK_REDUCE_ARMOR, BERSERK_AMPLIFY_DAMAGE)));
	m_items.push_back(MagicPtr(new OffsetDamageBuffMagic("Rage", RAGE_MANA_COST,
		Timer(RAGE_DURATION), RAGE_REDUCE_ARMOR, RAGE_AMPLIFY_DAMAGE)));
}