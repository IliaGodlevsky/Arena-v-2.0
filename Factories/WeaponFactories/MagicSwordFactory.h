#ifndef MAGIC_SWORD_FACTORY_H_
#define MAGIC_SWORD_FACTORY_H_

#include "../Factory.h"

class MagicSwordFactory : public Factory<Weapon>
{
public:
	MagicSwordFactory();
private:
	enum Weapons
	{
		HELL_SWORD_DAMAGE = 7,
		GLADIATOR_SWORD_DAMAGE = 9
	};
	enum Magics
	{
		SOUL_BURN_DEGENERATE = 12, SOUL_BURN_DURATION = 2, SOUL_BURN_PROPABILITY = 15,
		OPEN_WOUNDS_DEGENERATE = 8, OPEN_WOUNDS_DURATION = 2, OPEN_WOUNDS_PROPABILITY = 20
	};
};

#endif