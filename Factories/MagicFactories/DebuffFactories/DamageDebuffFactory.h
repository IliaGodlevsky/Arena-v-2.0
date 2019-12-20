#ifndef DAMAGE_DEBUFF_FACTORY_H_
#define DAMAGE_DEBUFF_FACTORY_H_

#include "../../Factory.h"

class DamageDebuffFactory : public Factory<Magic>
{
public:
	DamageDebuffFactory();
private:
	enum DamageDebuffs
	{
		WEAKNESS_MANA_COST = 10, WEAKNESS_DURATION = 2, WEAKNESS_DAMAGE_REDUCE = 7,
		TIREDNESS_MANA_COST = 25, TIREDNESS_DURATION = 2, TIREDNESS_DAMAGE_REDUCE = 11
	};
};

#endif