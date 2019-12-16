#pragma once

#ifndef SHIELD_FACTORY_H_
#define SHIELD_FACTORY_H_

#include "Factory.h"
#include "Shield.h"

class ShieldFactory : public Factory<Shield>
{
public:
	ShieldFactory();
	int getChanceOfCreation()const;
private:

	enum ShieldParametres
	{
		BUCKLER_ARM = 2, BUCKLER_REFLECTION = 30,
		SMALL_SHIELD_ARM = 3, SMALL_SHIELD_REFLECTION = 25,
		ROUND_SHEILD_ARM = 5, ROUND_SHEILD_REFLECTION = 20
	};
};

#endif