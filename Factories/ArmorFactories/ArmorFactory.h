#ifndef ARMOR_FACTORY_H_
#define ARMOR_FACTORY_H_

#include "../Factory.h"

class ArmorFactory : public Factory<Armor>
{
public:
	ArmorFactory();
private:
	enum ArmorParametres
	{
		LETHER_ARMOR_DEF = 2,
		CHAIN_MAIL_DEF = 3,
	};
};

#endif