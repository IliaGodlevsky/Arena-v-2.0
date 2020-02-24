#include "WeaponMagic.h"

WeaponMagic::WeaponMagic(std::string name, Time time,
	const ElementHolder& elements, PosibilityCounter propability)
	: FreeParamChangeMagic(name, time, elements), m_posibility(propability)
{

}

void WeaponMagic::effectUnit(Unit& unit)
{
	if (m_posibility)
		FreeParamChangeMagic::effectUnit(unit);
}

bool WeaponMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<WeaponMagic*>(magic))
		return false;
	const auto temp = dCast<WeaponMagic*>(magic);
	return FreeParamChangeMagic::isEqual(magic)
		&& m_posibility == temp->m_posibility;
}