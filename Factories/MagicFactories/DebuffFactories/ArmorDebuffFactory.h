#ifndef ARMOR_DEBUFF_FACTORY_H_
#define ARMOR_DEBUFF_FACTORY_H_

#include "../../Factory.h"

class ArmorDebuffFactory : public Factory<Magic>
{
public:
	ArmorDebuffFactory();
private:
	enum ArmorDebuffs
	{
		CORRUPTION_MANA_COST = 10, CORRUPTION_DURATION = 2, CORRUPTION_ARMOR_REDUCE = 3,
		CORROSION_MANA_COST = 25, CORROSION_DURATION = 2, CORROSION_ARMOR_REDUCE = 5
	};
};


#endif