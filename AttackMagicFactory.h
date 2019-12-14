#pragma once

#ifndef ATTACK_MAGIC_FACTORY_H_
#define ATTACK_MAGIC_FACTORY_H_

#include "Factory.h"

class AttackMagicFactory : public Factory<Magic>
{
public:
	AttackMagicFactory();
	int getChanceOfCreation()const;
private:
	enum
	{
		MAGIC_ARROW_MANA_COST = 10, MAGIC_ARROW_DAMAGE = 15,
		ICE_BOLT_MANA_COST = 22, ICE_BOLT_DAMAGE = 20, 
		
	};
};

class AttackAndStunMagicFactory : public Factory<Magic>
{
public:
	AttackAndStunMagicFactory();
	int getChanceOfCreation()const;
private:
	enum
	{
		THUNDER_BOLT_MANA_COST = 35, THUNDER_BOLT_DAMAGE = 25, THUNDER_BOLT_DURATION = 1,
		MENTAL_FIST_MANA_COST = 55, MENTAL_FIST_DAMAGE = 25, MENTAL_FIST_DURATION = 2
	};
};

class PoisonMagicFactory : public Factory<Magic>
{
public:
	PoisonMagicFactory();
	int getChanceOfCreation()const;
private:
	enum
	{

	};
};

class PoisonAndAttackMagicFactory : public Factory<Magic>
{
public:
	PoisonAndAttackMagicFactory();
	int getChanceOfCreation()const;
private:
	enum
	{

	};
};
#endif