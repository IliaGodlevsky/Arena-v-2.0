#ifndef ARMOR_AND_DAMAGE_BUFF_FACTORY_H_
#define ARMOR_AND_DAMAGE_BUFF_FACTORY_H_

#include "../../Factory.h"

class ArmorAndDamageBuffFactory : public Factory<Magic>
{
public:
	ArmorAndDamageBuffFactory();
private:
	enum DamageAndArmorBuffs
	{
		GODS_ARMOR_AMPLIFY_ARMOR = 2, GODS_ARMOR_AMPLIFY_DAMAGE = 6, GOD_ARMOR_MANA_COST = 25, GODS_ARMOR_DURATION = 2,
		BLESS_AMPLIFY_ARMOR = 1, BLESS_AMPLIFY_DAMAGE = 4, BLESS_MANA_COST = 15, BLESS_DURATION = 2
	};
};

#endif