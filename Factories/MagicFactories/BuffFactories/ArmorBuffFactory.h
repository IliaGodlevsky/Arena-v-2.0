#ifndef ARMOR_BUFF_FACTORY_H_
#define ARMOR_BUFF_FACTORY_H_

#include "../../Factory.h"

class ArmorBuffFactory : public Factory<Magic>
{
public:
	ArmorBuffFactory();
private:
	enum ArmorBuffs
	{
		STONE_SKIN_AMPLIFY_ARMOR = 2, STONE_SKIN_MANA_COST = 10, STONE_SKIN_DURATION = 2,
		HOLY_SHIELD_AMPLIFY_ARMOR = 3, HOLY_SHIELD_MANA_COST = 25, HOLY_SHIELD_DURATION = 2
	};
};

#endif