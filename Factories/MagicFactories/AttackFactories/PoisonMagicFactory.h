#ifndef POISION_MAGIC_FACTORY_H_
#define POISION_MAGIC_FACTORY_H_

#include "../../Factory.h"

class PoisonMagicFactory : public Factory<Magic>
{
public:
	PoisonMagicFactory();
private:
	enum
	{
		ILLNESS_MANA_COST = 15, ILLNESS_DEGENERATION = 6, ILLNESS_DURATION = 2,
		BLEEDING_MANA_COST = 30, BLEEDING_DEGENERATION = 10,BLEEDING_DURATION = 2,
		PARASITE_MANA_COST = 10, PARASITE_DEGENERATION = 3, PARASITE_DURATION = 3
	};
};

#endif