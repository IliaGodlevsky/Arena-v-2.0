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
		FULL_MAIL_DEF = 6,
		PLATE_MAIL_DEF = 4
	};

	enum LegionerChainsBonuses
	{
		FULL_MAIL_HEALTH = 15, FULL_MAIL_MANA = 10,
		PLATE_MAIL_HEALTH = 15, PLATE_MAIL_MANA = 15
	};
};
#endif