#ifndef POISON_AND_ATTACK_MAGIC_FACTORY_H_
#define POISON_AND_ATTACK_MAGIC_FACTORY_H_


#include "../../Factory.h"

class PoisonAndAttackMagicFactory : public Factory<Magic>
{
public:
	PoisonAndAttackMagicFactory();
private:
	enum
	{
		POISON_KNIFE_MANA_COST = 20, POISON_KNIFE_DAMAGE = 10, POISON_KNIFE_DEGENERATION = 3, POISON_KNIFE_DURATION = 2,
		POISON_BITE_MANA_COST = 30, POISON_BITE_DAMAGE = 15, POISON_BITE_DEGENERATION = 4, POISON_BITE_DURATION = 2
	};
};
#endif