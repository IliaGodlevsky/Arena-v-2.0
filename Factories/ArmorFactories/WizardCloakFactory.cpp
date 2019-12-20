#include "../../Armor/WizardCloak.h"

#include "WizardCloakFactory.h"

WizardCloakFactory::WizardCloakFactory()
{
	m_items.push_back(ArmPtr(new WizardCloak("Mantle", MANTLE_DEF,
		Vitals(MANTLE_MANA, MANTLE_MANA))));
	m_items.push_back(ArmPtr(new WizardCloak("Cape", CAPE_DEF,
		Vitals(CAPE_MANA, CAPE_MANA))));
}