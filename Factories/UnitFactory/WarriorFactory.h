#ifndef WARRIOR_FACTORY_H_
#define WARRIOR_FACTORY_H_

#include "UnitFactory.h"
#include "../../Unit/Warrior.h"

class WarriorFactory : public UnitFactory
{
public:
	WarriorFactory();
	UnitPtr createUnit()const;
	UnitPtr operator()()override;
};

#endif
