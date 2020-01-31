#ifndef ATTACK_AND_STUN_MAGIC_FACTORY_H_
#define ATTACK_AND_STUN_MAGIC_FACTORY_H_

#include "../../Factory.h"

class AttackAndStunMagicFactory : public Factory<Magic>
{
public:
	AttackAndStunMagicFactory();
private:
	enum
	{
		THUNDER_BOLT_MANA_COST = 35, THUNDER_BOLT_DAMAGE = 25, THUNDER_BOLT_DURATION = 1,
		MENTAL_FIST_MANA_COST = 50, MENTAL_FIST_DAMAGE = 25, MENTAL_FIST_DURATION = 2
	};
};

#endif
