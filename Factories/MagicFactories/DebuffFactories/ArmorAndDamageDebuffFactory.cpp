#include "../../../Magic/DebuffMagic/ArmorAndDamageDebuffMagic.h"

#include "ArmorAndDamageDebuffFactory.h"

ArmorAndDamageDebuffFactory::ArmorAndDamageDebuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorAndDamageDebuffMagic("Curse", CURSE_MANA_COST,
		CURSE_DURATION, CURSE_ARMOR_REDUCE, CURSE_DAMAGE_REDUCE)));
	m_items.push_back(MagicPtr(new ArmorAndDamageDebuffMagic("Mutilation", MUTILATION_MANA_COST,
		MUTILATION_DURATION, MUTILATION_ARMOR_REDUCE, MUTILATION_DAMAGE_REDUCE)));
}