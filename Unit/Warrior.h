#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "Unit.h"

class Warrior : public Unit
{
public:
	Warrior(DecisionPtr decision, ItemFactoryPtr factory);
	Warrior(const Warrior& unit);
	bool injureUnit(Unit& unit);
	~Warrior() = default;
};

#endif
