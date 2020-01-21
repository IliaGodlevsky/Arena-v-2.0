#ifndef MIRROR_SHIELD_H_
#define MIRROR_SHIELD_H_

#include "MagicShield.h"

class MirrorShield : public MagicShield
{
public:
	MirrorShield(std::string name, int armor, int reflectChance);
	virtual bool takeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const;
	virtual ShieldPtr clone()const;
};
#endif
