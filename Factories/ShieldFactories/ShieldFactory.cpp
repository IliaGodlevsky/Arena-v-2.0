#include "../../Shield/Shield.h"

#include "ShieldFactory.h"

ShieldFactory::ShieldFactory()
{
	m_items.push_back(ShieldPtr(new Shield("Buckler",
		BUCKLER_ARM, BUCKLER_REFLECTION)));
	m_items.push_back(ShieldPtr(new Shield("Small shield",
		SMALL_SHIELD_ARM, SMALL_SHIELD_REFLECTION)));
	m_items.push_back(ShieldPtr(new Shield("Round shield",
		ROUND_SHEILD_ARM, ROUND_SHEILD_REFLECTION)));
}