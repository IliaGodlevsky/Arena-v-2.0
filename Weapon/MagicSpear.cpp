#include "../Unit/Unit.h"
#include "../Magic/WeaponMagic/CorruptionMagic.h"
#include "../Exceptions/BadWeaponMagicException.h"

#include "MagicSpear.h"

MagicSpear::MagicSpear(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
	if (!canCast<CorruptionMagic*>(magic))
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

MagicSpear::MagicSpear(const MagicSpear& spear)
	: MagicWeapon(spear)
{

}

MagicSpear& MagicSpear::operator=(const MagicSpear& spear)
{
	if (this == &spear)
		return *this;
	MagicWeapon::operator=(spear);
	return *this;
}

WeaponPtr MagicSpear::clone()const
{
	return WeaponPtr(new MagicSpear(m_name, m_damage, m_magic->clone()));
}