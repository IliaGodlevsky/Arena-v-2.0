#ifndef ATTACK_MAGIC_FACTORY_H_
#define ATTACK_MAGIC_FACTORY_H_

#include "../../Factory.h"

class AttackMagicFactory : public Factory<Magic>
{
public:
	AttackMagicFactory();
private:
	enum
	{
		MAGIC_ARROW_MANA_COST = 10, MAGIC_ARROW_DAMAGE = 15,
		MAGIC_HUMMER_MANA_COST = 20, MAGIC_HUMMER_DAMAGE = 20,
		SILENCE_FIST_MANA_COST = 30, SILENCE_FIST_DAMAGE = 15, SILENCE_FIST_DURATION = 2,
		FEAR_MANA_COST = 40, FEAR_DAMAGE = 20, FEAR_DURATION = 2
	};
};
#endif