#pragma once

#ifndef NEUTRAL_MAGIC_FACTORY_H_
#define NEUTRAL_MAGIC_FACTORY_H_

#include "Factory.h"

class NeutralMagicFactory : public Factory<Magic>
{
public:
	NeutralMagicFactory();
	int getChanceOfCreation()const;
private:
	enum
	{
		DISPEL_MANA_COST = 30
	};
};
#endif