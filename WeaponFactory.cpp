#include "WeaponFactory.h"
#include "Weapon.h"

SwordFactory::SwordFactory()
{
	m_items.push_back(WeaponPtr(new Sword("Gladius", GLADIUS_DAMAGE,
		new Degenerate("Open wounds", OPEN_WOUNDS_DURATION, 
			OPEN_WOUNDS_DMG_PER_ROUND, OPEN_WOUNDS_POSIBILITY))));
	m_items.push_back(WeaponPtr(new Sword("Palache",PALACHE_DAMAGE,
		new Degenerate("Poison", POISON_DURATION, 
			POISON_DMP_PER_ROUND, POISON_POSIBILITY))));
	m_items.push_back(WeaponPtr(new Sword("Knife", KNIFE_DAMAGE,
		new Degenerate("Plague", PLAGUE_DURATION, 
			PLAGUE_DMG_PER_ROUND, PLAGUE_POSIBILITY))));
}

int SwordFactory::getChanceOfCreation()const
{
	return 50;
}

AxeFactory::AxeFactory()
{
	m_items.push_back(WeaponPtr(new Axe("Hatchet", HATCHET_DAMAGE,
		new Crush("Smash", SMASH_DAMAGE, SMASH_CHANCE))));
	m_items.push_back(WeaponPtr(new Axe("Axe", AXE_DAMAGE,
		new Crush("Clap", CLAP_DAMAGE, CLAP_CHANCE))));
}

int AxeFactory::getChanceOfCreation()const
{
	return 50;
}