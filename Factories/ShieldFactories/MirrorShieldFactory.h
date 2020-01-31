#ifndef MIRROR_SHIELD_FACTORY_H_
#define MIRROR_SHIELD_FACTORY_H_

#include "../Factory.h"

class MirrorShieldFactory : public Factory<Shield>
{
public:
	MirrorShieldFactory();
private:
	enum
	{
		CRYSTAL_SHIELD_ARMOR = 2, CRYSTAL_SHIELD_CHANCE = 8,
		SPIRIT_SHIELD_ARMOR = 1, SPIRIT_SHIELD_CHANCE = 10
	};
};

#endif