#ifndef SHIELD_FACTORY_H_
#define SHIELD_FACTORY_H_

#include "../Factory.h"

class ShieldFactory : public Factory<Shield>
{
public:
	ShieldFactory();
private:
	enum ShieldParametres
	{
		BUCKLER_ARM = 2, BUCKLER_REFLECTION = 15,
		SMALL_SHIELD_ARM = 3, SMALL_SHIELD_REFLECTION = 10,
		ROUND_SHEILD_ARM = 4, ROUND_SHEILD_REFLECTION = 7
	};
};

#endif