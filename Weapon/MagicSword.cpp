#include "../Unit/Unit.h"
#include "../Magic/WeaponMagic/DegenerateMagic.h"

#include "MagicSword.h"

MagicSword::MagicSword(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
		if (!canCast<DegenerateMagic*>(magic))
			throw BadWeaponMagicException("Bad class is " + std::string(typeid(*this).name())
				+ "\nTry to use other weapon magic");
}

MagicSword::MagicSword(const MagicSword& sword)
	: MagicWeapon(sword)
{

}

MagicSword& MagicSword::operator=(const MagicSword& sword)
{
	if (this == &sword)
		return *this;
	MagicWeapon::operator=(sword);
	return *this;
}

WeaponPtr MagicSword::clone()const
{
	return WeaponPtr(new MagicSword(m_name, m_damage, m_magic->clone()));
}