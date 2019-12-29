#ifndef NEUTRAL_FACTORY_H_
#define NEUTRAL_FACTORY_H_

#include "../../Factory.h"

class NeutralMagicFactory : public Factory<Magic>
{
public:
	NeutralMagicFactory();
	enum
	{
		DISPEL_MANA_COST = 50
	};
};

#endif