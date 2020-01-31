#ifndef DAMAGE_BUFF_FACTORY_H_
#define DAMAGE_BUFF_FACTORY_H_

#include "../../Factory.h"

class DamageBuffFactory : public Factory<Magic>
{
public:
	DamageBuffFactory();
private:
	enum DamageBuffs
	{
		STRENGTH_AMPLIFY_DAMAGE = 6, STRENGTH_MANA_COST = 10, STRENGTH_DURATION = 2,
		POWER_AMPLFY_DAMAGE = 8, POWER_MANA_COST = 25, POWER_DURATION = 2
	};
};

#endif