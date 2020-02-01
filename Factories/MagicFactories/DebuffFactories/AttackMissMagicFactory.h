#ifndef ATTACK_MISS_MAGIC_FACTORY_H_
#define ATTACK_MISS_MAGIC_FACTORY_H_

#include "../../Factory.h"

class AttackMissMagicFactory : public Factory<Magic>
{
public:
	AttackMissMagicFactory();
private:
	enum
	{
		DISORIENTATION_MANA_COST = 25, DISORIENTATION_DURATION = 3, DISORIENTATION_CHANCE = 20,
		OBLIVION_MANA_COST = 35, OBLIVION_DURATION = 3, OBLIVION_CHANCE = 30
	};
};
#endif
