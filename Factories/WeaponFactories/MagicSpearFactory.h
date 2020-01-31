#ifndef MAGIC_SPEAR_FACTORY_H_
#define MAGIC_SPEAR_FACTORY_H_

#include "../Factory.h"

class MagicSpearFactory : public Factory<Weapon>
{
public:
	MagicSpearFactory();
private:
	enum
	{
		AMAZONE_SPEAR_DAMAGE = 5,
		GLADIATORS_SPEAR_DAMAGE = 7
	};

	enum
	{
		HOLE_ARMOR_REDUCE = 3, HOLE_POSSIBILITY = 20, HOLE_DURATION = 2,
		PIERCE_ARMOR_REDUCE = 2, PIERCE_POSSIBILTY = 20, PIERCE_DURATION = 2
	};
};

#endif
