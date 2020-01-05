#include "../Unit/Unit.h"
#include "../Magic/WeaponMagic/CorruptionMagic.h"

#include "MagicSpear.h"

MagicSpear::MagicSpear(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
	try {
		if (!canCast<CorruptionMagic*>(magic))
			throw BadWeaponMagicException("Bad class is " + std::string(typeid(*this).name())
				+ "\n Try to use other weapon magic");
	}
	catch (BadWeaponMagicException& ex) { exceptionMessage(ex); }
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