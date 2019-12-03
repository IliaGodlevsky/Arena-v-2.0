#pragma once

#ifndef ARMOR_FACTORY_H_
#define ARMOR_FACTORY_H_

#include "Factory.h"
#include "Armor.h"

class ArmorFactory : public Factory<Armor*>
{
public:
	ArmorFactory();
	int chance()const;
private:
	static const int CHANCE = 60;
private:
	enum ArmorParametres
	{
		LETHER_ARMOR_DEF = 3,
		CHAIN_MAIL_DEF = 4,
	};
};

class MailFactory : public Factory<Armor*>
{
public:
	MailFactory();
	int chance()const;
private:
	static const int CHANCE = 20;
private:
	enum MailParametres
	{
		SHADOW_MAIL_DEF = 4,
		GHOST_MAIL_DEF = 6
	};

	enum MailBonuses
	{
		SHADOW_MAIL_HEALTH = 25,
		GHOST_MAIL_HEALTH = 35
	};
};

class WizardCloakFactory : public Factory<Armor*>
{
public:
	WizardCloakFactory();
	int chance()const;
private:
	static const int CHANCE = 20;
private:
	enum WizardCloakParametres
	{
		MANTLE_DEF = 3,
		CAPE_DEF = 2
	};

	enum WizardCloakBonuses
	{
		MANTLE_MANA = 25,
		CAPE_MANA = 20
	};
};

class LegionerChainsFactory : public Factory<Armor*>
{
public:
	LegionerChainsFactory();
	int chance()const;
private:
	static const int CHANCE = 10;
private:
	enum LegionerChainsParametres
	{
		FULL_MAIL_DEF = 5,
		PLATE_MAIL_DEF = 6
	};

	enum LegionerChainsBonuses
	{
		FULL_MAIL_HEALTH = 20, FULL_MAIL_MANA = 10,
		PLATE_MAIL_HEALTH = 20, PLATE_MAIL_MANA = 15
	};
};
#endif