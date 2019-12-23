#include "../../../Magic/BuffMagic/ArmorAndDamageBuffMagic.h"

#include "ArmorAndDamageBuffFactory.h"

ArmorAndDamageBuffFactory::ArmorAndDamageBuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorAndDamageBuffMagic("God armor",
		GOD_ARMOR_MANA_COST, Timer(GODS_ARMOR_DURATION),
		GODS_ARMOR_AMPLIFY_ARMOR, GODS_ARMOR_AMPLIFY_DAMAGE)));
	m_items.push_back(MagicPtr(new ArmorAndDamageBuffMagic("Bless", BLESS_MANA_COST,
		Timer(BLESS_DURATION), BLESS_AMPLIFY_ARMOR, BLESS_AMPLIFY_DAMAGE)));
}