#include "MirrorShieldFactory.h"

#include "../../Shield/MirrorShield.h"

MirrorShieldFactory::MirrorShieldFactory()
{
	m_items.push_back(ShieldPtr(new MirrorShield("Crystal shield",
		CRYSTAL_SHIELD_ARMOR, CRYSTAL_SHIELD_CHANCE)));
	m_items.push_back(ShieldPtr(new MirrorShield("Spirit shield",
		SPIRIT_SHIELD_ARMOR, SPIRIT_SHIELD_CHANCE)));
}