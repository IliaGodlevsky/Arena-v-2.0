#ifndef MAGIC_SHIELD_FACTORY_H_
#define MAGIC_SHIELD_FACTORY_H_

#include "../Factory.h"

class MagicShieldFactory : public Factory<Shield>
{
public:
	MagicShieldFactory();
private:
	enum
	{
		RUBY_SHIELD_ARMOR = 3, RUBY_SHIELD_REFLECT_CHANCE = 8,
		SAPPHIRE_SHIELD_ARMOR = 2, SAPPHIRE_SHIELD_REFLECT_CHANCE = 10
	};
};
#endif
