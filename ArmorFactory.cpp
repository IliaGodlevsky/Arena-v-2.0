#include "ArmorFactory.h"

ArmorFactory::ArmorFactory()
{
	items.push_back(new Armor("Lether armor", LETHER_ARMOR_DEF));
	items.push_back(new Armor("Chain mail", CHAIN_MAIL_DEF));
}

int ArmorFactory::chance()const
{
	return CHANCE;
}

MailFactory::MailFactory()
{
	items.push_back(new Mail("Shadow mail", SHADOW_MAIL_DEF, 
		Vitals(SHADOW_MAIL_HEALTH, SHADOW_MAIL_HEALTH)));
	items.push_back(new Mail("Ghost mail", GHOST_MAIL_DEF, 
		Vitals(GHOST_MAIL_HEALTH, GHOST_MAIL_HEALTH)));
}

int MailFactory::chance()const
{
	return CHANCE;
}

WizardCloakFactory::WizardCloakFactory()
{
	items.push_back(new WizardCloak("Mantle", MANTLE_DEF,
		Vitals(MANTLE_MANA, MANTLE_MANA)));
	items.push_back(new WizardCloak("Cape", CAPE_DEF, 
		Vitals(CAPE_MANA, CAPE_MANA)));
}

int WizardCloakFactory::chance()const
{
	return CHANCE;
}

LegionerChainsFactory::LegionerChainsFactory()
{
	items.push_back(new LegionerChains("Full plate",FULL_MAIL_DEF,
		Vitals(FULL_MAIL_HEALTH,FULL_MAIL_HEALTH),
		Vitals(FULL_MAIL_MANA, FULL_MAIL_MANA)));
	items.push_back(new LegionerChains("Plate mail",PLATE_MAIL_DEF,
		Vitals(PLATE_MAIL_HEALTH, PLATE_MAIL_HEALTH), 
		Vitals(PLATE_MAIL_MANA, PLATE_MAIL_MANA)));
}

int LegionerChainsFactory::chance()const
{
	return CHANCE;
}