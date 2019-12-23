#include "DamageBuffFactory.h"

#include "../../../Magic/BuffMagic/DamageBuffMagic.h"

DamageBuffFactory::DamageBuffFactory()
{
	m_items.push_back(MagicPtr(new DamageBuffMagic("Strength",
		STRENGTH_MANA_COST, Timer(STRENGTH_DURATION), STRENGTH_AMPLIFY_DAMAGE)));
	m_items.push_back(MagicPtr(new DamageBuffMagic("Power", POWER_MANA_COST,
		Timer(POWER_DURATION), POWER_AMPLFY_DAMAGE)));
}