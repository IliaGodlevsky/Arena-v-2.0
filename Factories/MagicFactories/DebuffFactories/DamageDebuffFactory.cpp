#include "../../../Magic/DebuffMagic/DamageDebuffMagic.h"

#include "DamageDebuffFactory.h"

DamageDebuffFactory::DamageDebuffFactory()
{
	m_items.push_back(MagicPtr(new DamageDebuffMagic("Weakness", WEAKNESS_MANA_COST,
		WEAKNESS_DURATION, WEAKNESS_DAMAGE_REDUCE)));
	m_items.push_back(MagicPtr(new DamageDebuffMagic("Tiredness", TIREDNESS_MANA_COST,
		TIREDNESS_DURATION, TIREDNESS_DAMAGE_REDUCE)));
}