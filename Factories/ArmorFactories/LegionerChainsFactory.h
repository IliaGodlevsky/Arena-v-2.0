#ifndef LEGIONER_CHAIN_FACTORY_H_
#define LEGIONER_CHAIN_FACTORY_H_

#include "../Factory.h"

class LegionerChainsFactory : public Factory<Armor>
{
public:
	LegionerChainsFactory();
private:
	enum LegionerChainsParametres
	{
		FULL_MAIL_DEF = 4,
		PLATE_MAIL_DEF = 2
	};

	enum LegionerChainsBonuses
	{
		FULL_MAIL_HEALTH = 10, FULL_MAIL_MANA = 5,
		PLATE_MAIL_HEALTH = 10, PLATE_MAIL_MANA = 10
	};
};
#endif