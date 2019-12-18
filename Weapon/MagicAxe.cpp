#include "../Unit/Unit.h"
#include "../Magic/WeaponMagic/WeaponMagic.h"
#include "../Magic/WeaponMagic/CrushMagic.h"
#include "../Exceptions/BadWeaponMagicException.h"

#include "MagicAxe.h"

MagicAxe::MagicAxe(std::string name, int damage, MagicPtr magic)
	:MagicWeapon(name, damage, magic->clone())
{
	CrushMagic* temp = DYNAMIC(CrushMagic*, magic);
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

MagicAxe::MagicAxe(const MagicAxe& axe)
	: MagicWeapon(axe)
{

}

MagicAxe& MagicAxe::operator=(const MagicAxe& axe)
{
	if (this == &axe)
		return *this;
	MagicWeapon::operator=(axe);
	return *this;
}

WeaponPtr MagicAxe::clone()const
{
	return WeaponPtr(new MagicAxe(m_name, m_damage, m_magic->clone()));
}