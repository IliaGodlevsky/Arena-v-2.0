#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "Unit.h"

class Warrior : public Unit
{
public:
	Warrior() = delete;
	Warrior(DecisionPtr decision, ItemFactoryPtr factory);
	Warrior(const Warrior& unit);
	Warrior(Warrior&& unit);
	Warrior& operator=(const Warrior&) = delete;
	Warrior& operator=(Warrior&&) = delete;
	~Warrior() = default;
public:
	bool injureUnit(Unit& unit);
	bool takeMagicEffect(Unit& caster, MagicPtr& magic);
private:
	int damageMultiply(int damage)const;
	bool secondHit(Unit& unit);
};

#endif
