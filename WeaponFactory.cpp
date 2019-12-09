#include "WeaponFactory.h"
#include "Weapon.h"

SwordFactory::SwordFactory()
{
	m_items.push_back(WeaponPtr(new Sword("Gladius", GLADIUS_DAMAGE,
		MagicPtr(new Degenerate("Open wounds", OPEN_WOUNDS_DURATION, 
			OPEN_WOUNDS_DMG_PER_ROUND, OPEN_WOUNDS_POSIBILITY)))));
	m_items.push_back(WeaponPtr(new Sword("Palache",PALACHE_DAMAGE,
		MagicPtr(new Degenerate("Poison", POISON_DURATION, 
			POISON_DMP_PER_ROUND, POISON_POSIBILITY)))));
	m_items.push_back(WeaponPtr(new Sword("Knife", KNIFE_DAMAGE,
		MagicPtr(new Degenerate("Plague", PLAGUE_DURATION, 
			PLAGUE_DMG_PER_ROUND, PLAGUE_POSIBILITY)))));
}

int SwordFactory::getChanceOfCreation()const
{
	return 50;
}

AxeFactory::AxeFactory()
{
	m_items.push_back(WeaponPtr(new Axe("Hatchet", HATCHET_DAMAGE,
		MagicPtr(new Crush("Smash", SMASH_DAMAGE, SMASH_CHANCE)))));
	m_items.push_back(WeaponPtr(new Axe("Axe", AXE_DAMAGE,
		MagicPtr(new Crush("Clap", CLAP_DAMAGE, CLAP_CHANCE)))));
	printf("%s", "AxeFactory\n");
	system("pause");
}

int AxeFactory::getChanceOfCreation()const
{
	return 50;
}