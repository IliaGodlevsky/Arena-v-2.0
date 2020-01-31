#ifndef ARMOR_AND_DAMAGE_DEBUFF_FACTORY_H_
#define ARMOR_AND_DAMAGE_DEBUFF_FACTORY_H_

#include "../../Factory.h"

class ArmorAndDamageDebuffFactory : public Factory<Magic>
{
public:
	ArmorAndDamageDebuffFactory();
private:
	enum
	{
		CURSE_MANA_COST = 15, CURSE_DURATION = 2, CURSE_ARMOR_REDUCE = 2, CURSE_DAMAGE_REDUCE = 6,
		MUTILATION_MANA_COST = 25, MUTILATION_DURATION = 2, MUTILATION_ARMOR_REDUCE = 3, MUTILATION_DAMAGE_REDUCE = 7
	};
};

#endif