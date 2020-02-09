#include "MagicShieldFactory.h"
#include "../../Shield/MagicShield.h"

MagicShieldFactory::MagicShieldFactory()
{
	m_items.push_back(ShieldPtr(new MagicShield("Ruby shield",
		RUBY_SHIELD_ARMOR, RUBY_SHIELD_REFLECT_CHANCE*10)));
	m_items.push_back(ShieldPtr(new MagicShield("Sapphire shield", 
		SAPPHIRE_SHIELD_ARMOR, SAPPHIRE_SHIELD_REFLECT_CHANCE*10)));
}