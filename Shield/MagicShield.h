#ifndef MAGIC_SHIELD_H_
#define MAGIC_SHIELD_H_

#include "Shield.h"

class MagicShield : public Shield
{
public:
	MagicShield(std::string name, int armor, int reflectChance);
	virtual bool takeMagicEffect(Unit& unit, Unit& caster,
		MagicPtr& magic)const override;
	virtual bool takeDamage(Unit& unit, int damage)const;
	virtual ShieldPtr clone()const;
	virtual ~MagicShield() = default;
};
#endif
