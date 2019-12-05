#pragma once

#ifndef WEAPON_FACTORY_H_
#define WEAPON_FACTORY_H_

#include "Factory.h"
#include "Weapon.h"

class SwordFactory : public Factory<Weapon>
{
public:
	SwordFactory();
	int getChanceOfCreation()const;
private:
	enum SwordParametres
	{
		GLADIUS_DAMAGE = 10,
		PALACHE_DAMAGE = 12,
		KNIFE_DAMAGE = 5
	};

	enum SwordMagic
	{
		OPEN_WOUNDS_DMG_PER_ROUND = 10, OPEN_WOUNDS_DURATION = 2, OPEN_WOUNDS_POSIBILITY = 15,
		POISON_DMP_PER_ROUND = 8, POISON_DURATION = 2, POISON_POSIBILITY = 20,
		PLAGUE_DMG_PER_ROUND = 15, PLAGUE_DURATION = 2, PLAGUE_POSIBILITY = 10
	};
};

class AxeFactory : public Factory<Weapon>
{
public:
	AxeFactory();
	int getChanceOfCreation()const;
private:
	enum AxeParametres
	{
		HATCHET_DAMAGE = 7,
		AXE_DAMAGE = 5
	};
	enum AxeMagic
	{
		SMASH_DAMAGE = 15, SMASH_CHANCE = 15,
		CLAP_DAMAGE = 10, CLAP_CHANCE = 18
	};
};

#endif