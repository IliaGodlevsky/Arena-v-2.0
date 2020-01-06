#include "../Unit/Unit.h"
#include "../Magic/WeaponMagic/StunMagic.h"

#include "MagicClub.h"

MagicClub::MagicClub(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
		if (!canCast<StunMagic*>(magic))
			throw BadWeaponMagicException("Bad class is " + std::string(typeid(*this).name())
				+ "\nTry to use other weapon magic");
}

MagicClub::MagicClub(const MagicClub& club)
	: MagicWeapon(club)
{

}

MagicClub& MagicClub::operator=(const MagicClub& club)
{
	if (this == &club)
		return *this;
	MagicWeapon::operator=(club);
	return *this;
}

WeaponPtr MagicClub::clone()const
{
	return WeaponPtr(new MagicClub(m_name, m_damage, m_magic->clone()));
}