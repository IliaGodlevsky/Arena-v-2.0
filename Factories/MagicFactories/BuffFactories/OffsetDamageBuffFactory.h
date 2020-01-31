#ifndef OFFSET_DAMAGE_BUFF_FACTORY_H_
#define OFFSET_DAMAGE_BUFF_FACTORY_H_

#include "../../Factory.h"

class OffsetDamageBuffFactory : public Factory<Magic>
{
public:
	OffsetDamageBuffFactory();
private:
	enum OffsetDamageBuffs
	{
		BERSERK_AMPLIFY_DAMAGE = 8, BERSERK_REDUCE_ARMOR = 2, BERSERK_MANA_COST = 10, BERSERK_DURATION = 2,
		RAGE_AMPLIFY_DAMAGE = 11, RAGE_REDUCE_ARMOR = 3, RAGE_MANA_COST = 25, RAGE_DURATION = 2
	};
};

#endif