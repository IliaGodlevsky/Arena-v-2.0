#include "WizardItemFactory.h"

#include "../WeaponFactories/MagicStaffFactory.h"
#include "../ArmorFactories/WizardCloakFactory.h"
#include "../MagicFactories/DebuffFactories/SilenceFactory.h"
#include "../MagicFactories/DebuffFactories/ArmorAndDamageDebuffFactory.h"
#include "../ShieldFactories/ShieldFactory.h"
#include "../MagicFactories/DebuffFactories/ArmorDebuffFactory.h"
#include "../MagicFactories/DebuffFactories/DamageDebuffFactory.h"


WizardItemFactory::WizardItemFactory()
{
	m_armorFactories.push_back(new WizardCloakFactory());
	m_weaponFactories.push_back(new MagicStaffFactory());
	m_magicFactories.push_back(new SilenceFactory());
	m_magicFactories.push_back(new ArmorAndDamageDebuffFactory());
	m_magicFactories.push_back(new ArmorDebuffFactory());
	m_magicFactories.push_back(new DamageDebuffFactory());
	m_shieldFactories.push_back(new ShieldFactory());
}