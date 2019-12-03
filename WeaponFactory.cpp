#include "WeaponFactory.h"

SwordFactory::SwordFactory()
{
	items.push_back(new Sword("Gladius", GLADIUS_DAMAGE, 
		new Degenerate("Open wounds", OPEN_WOUNDS_DURATION, 
			OPEN_WOUNDS_DMG_PER_ROUND, OPEN_WOUNDS_POSIBILITY)));
	items.push_back(new Sword("Palache",PALACHE_DAMAGE, 
		new Degenerate("Poison", POISON_DURATION, 
			POISON_DMP_PER_ROUND, POISON_POSIBILITY)));
	items.push_back(new Sword("Knife", KNIFE_DAMAGE, 
		new Degenerate("Plague", PLAGUE_DURATION, 
			PLAGUE_DMG_PER_ROUND, PLAGUE_POSIBILITY)));
}

int SwordFactory::chance()const
{
	return CHANCE;
}

AxeFactory::AxeFactory()
{
	items.push_back(new Axe("Hatchet", HATCHET_DAMAGE,
		new Crush("Smash", SMASH_DAMAGE, SMASH_CHANCE)));
	items.push_back(new Axe("Axe", AXE_DAMAGE, 
		new Crush("Clap", CLAP_DAMAGE, CLAP_CHANCE)));
}

int AxeFactory::chance()const
{
	return CHANCE;
}