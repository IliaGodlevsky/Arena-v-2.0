#pragma once

#ifndef WEAPON_FACTORY_H_
#define WEAPON_FACTORY_H_

#include "Factory.h"
#include "Weapon.h"

class WeaponFactory : public Factory<Weapon>
{
public:
	WeaponFactory();
	int getChanceOfCreation()const;
private:
	enum Weapons
	{
		CLUB_DAMAGE = 2,
		AXE_DAMAGE = 3,
		SWORD_DAMAGE = 4,
		SPEAR_DAMAGE = 5,
	};
	enum Propabilities
	{
		CLUB_CRITICAL_PROPABILY = 23,
		AXE_CRITICAL_PROPABILITY = 19,
		SWORD_CRITICAL_PROPABILITY = 16,
		SPEAR_CRITICAL_PROPABILITY = 13
	};
};

class MagicSwordFactory : public Factory<Weapon>
{
public:
	MagicSwordFactory();
	int getChanceOfCreation()const;
private:
	enum Weapons
	{
		HELL_SWORD_DAMAGE = 4,
		GLADIATOR_SWORD_DAMAGE = 5
	};
	enum Magics
	{
		SOUL_BURN_DEGENERATE = 12, SOUL_BURN_DURATION = 2, SOUL_BURN_PROPABILITY = 15,
		OPEN_WOUNDS_DEGENERATE = 10, OPEN_WOUNDS_DURATION = 2, OPEN_WOUNDS_PROPABILITY = 20
	};
};

class MagicAxeFactory : public Factory<Weapon>
{
public:
	MagicAxeFactory();
	int getChanceOfCreation()const;
private:
	enum
	{

	};
};

class MagicSpearFactory : public Factory<Weapon>
{
public:
	MagicSpearFactory();
	int getChanceOfCreation()const;
private:
	enum
	{

	};
};

class MagicClubFactory : public Factory<Weapon>
{
public:
	MagicClubFactory();
	int getChanceOfCreation()const;
private:
	enum
	{

	};
};

#endif