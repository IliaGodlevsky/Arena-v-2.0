#include "../../../Magic/DebuffMagic/ArmorDebuffMagic.h"

#include "ArmorDebuffFactory.h"

ArmorDebuffFactory::ArmorDebuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorDebuffMagic("Corruption", CORRUPTION_MANA_COST,
		CORRUPTION_DURATION, CORRUPTION_ARMOR_REDUCE)));
	m_items.push_back(MagicPtr(new ArmorDebuffMagic("Corrosion", CORROSION_MANA_COST,
		CORROSION_DURATION, CORROSION_ARMOR_REDUCE)));
}