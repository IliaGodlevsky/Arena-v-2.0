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
		ILLNESS_MANA_COST = 20, ILLNESS_DEGENERATION = 4, ILLNESS_DURATION = 2,
		BLEEDING_MANA_COST = 25, BLEEDING_DEGENERATION = 5,BLEEDING_DURATION = 2,
		PARASITE_MANA_COST = 15, PARASITE_DEGENERATION = 3, PARASITE_DURATION = 2
	};
};

#endif