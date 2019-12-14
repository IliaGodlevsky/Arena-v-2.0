#include "ArmorFactory.h"

ArmorFactory::ArmorFactory()
{
	m_items.push_back(ArmPtr(new Armor("Lether armor", LETHER_ARMOR_DEF)));
	m_items.push_back(ArmPtr(new Armor("Chain mail", CHAIN_MAIL_DEF)));
}

int ArmorFactory::getChanceOfCreation()const
{
	return 60;
}

MailFactory::MailFactory()
{
	m_items.push_back(ArmPtr(new Mail("Shadow mail", SHADOW_MAIL_DEF,
		Vitals(SHADOW_MAIL_HEALTH, SHADOW_MAIL_HEALTH))));
	m_items.push_back(ArmPtr(new Mail("Ghost mail", GHOST_MAIL_DEF,
		Vitals(GHOST_MAIL_HEALTH, GHOST_MAIL_HEALTH))));
}

int MailFactory::getChanceOfCreation()const
{
	return 20;
}

WizardCloakFactory::WizardCloakFactory()
{
	m_items.push_back(ArmPtr(new WizardCloak("Mantle", MANTLE_DEF,
		Vitals(MANTLE_MANA, MANTLE_MANA))));
	m_items.push_back(ArmPtr(new WizardCloak("Cape", CAPE_DEF,
		Vitals(CAPE_MANA, CAPE_MANA))));
}

int WizardCloakFactory::getChanceOfCreation()const
{
	return 20;
}

LegionerChainsFactory::LegionerChainsFactory()
{
	m_items.push_back(ArmPtr(new LegionerChains("Full plate",FULL_MAIL_DEF,
		Vitals(FULL_MAIL_HEALTH,FULL_MAIL_HEALTH),
		Vitals(FULL_MAIL_MANA, FULL_MAIL_MANA))));
	m_items.push_back(ArmPtr(new LegionerChains("Plate mail",PLATE_MAIL_DEF,
		Vitals(PLATE_MAIL_HEALTH, PLATE_MAIL_HEALTH), 
		Vitals(PLATE_MAIL_MANA, PLATE_MAIL_MANA))));
}

int LegionerChainsFactory::getChanceOfCreation()const
{
	return 10;
}