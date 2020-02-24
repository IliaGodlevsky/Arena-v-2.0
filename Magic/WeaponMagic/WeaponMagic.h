#ifndef WEAPON_MAGIC_H_
#define WEAPON_MAGIC_H_

#include "../FreeParamChangeMagic.h"
#include "../../PossibilityCounter/PosibilityCounter.h"

class WeaponMagic : public FreeParamChangeMagic
{
public:
	WeaponMagic(std::string name, Time time,
		const ElementHolder& elements, PosibilityCounter propability);
	void effectUnit(Unit& unit) override;
	virtual MagicPtr clone()const = 0;
	virtual bool isEqual(const MagicPtr& magic)const override;
	~WeaponMagic() = default;
protected:
	PosibilityCounter m_posibility;
};
#endif
