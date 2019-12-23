#ifndef MAGIC_AXE_FACTORY_H_
#define MAGIC_AXE_FACTORY_H_

#include "../Factory.h"

class MagicAxeFactory : public Factory<Weapon>
{
public:
	MagicAxeFactory();
private:
	enum Weapons
	{
		BUTCHER_AXE_DAMAGE = 6,
		CHOPPER_AXE_DAMAGE = 4
	};
	enum Magics
	{
		HEAD_STRIKE_DAMAGE = 7, HEAD_STRIKE_PROPABILITY = 15,
		KNOCK_DAMAGE = 9, KNOCK_PROPABILITY = 18
	};
};

#endif