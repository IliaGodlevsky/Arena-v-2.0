#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/StunUnitState.h"

#include "StunMagic.h"

StunMagic::StunMagic(std::string name, int duration, int propability)
	: WeaponMagic(name, duration, propability)
{

}

void StunMagic::effectUnit(Unit& unit)
{
	if (isCastChance())
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void StunMagic::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr StunMagic::clone()const
{
	return MagicPtr(new StunMagic(m_name,
		m_timer, m_propability));
}

bool StunMagic::isBuff()const
{
	return false;
}

bool StunMagic::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void StunMagic::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

bool StunMagic::hasEqualParametres(const MagicPtr& magic)const
{
	return WeaponMagic::hasEqualParametres(magic);
}

void StunMagic::showData()const
{
	std::cout << "Stuns unit\n";
}

void StunMagic::putOn(Unit& unit)const
{
	unit.recieveNewState(StatePtr(new StunUnitState(m_timer)));
}