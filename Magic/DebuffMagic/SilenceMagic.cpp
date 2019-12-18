#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/MutedUnitState.h"

#include "SilenceMagic.h"

SilenceMagic::SilenceMagic(std::string name, int mana_cost,
	int duration)
	: Magic(name, mana_cost, duration)
{

}

void SilenceMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
	unit.recieveNewState(StatePtr(new MutedUnitState(m_timer)));
}

void SilenceMagic::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr SilenceMagic::clone()const
{
	return MagicPtr(new SilenceMagic(m_name, m_manaCost, m_timer));
}

bool SilenceMagic::isBuff()const
{
	return false;
}

bool SilenceMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	SilenceMagic* temp = DYNAMIC(SilenceMagic*, magic);
	if (nullptr == temp)
		return false;
	return Magic::isEqual(magic);
}

bool SilenceMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic) &&
		hasEqualParametres(magic);
}

void SilenceMagic::putOn(Unit& unit)const
{
	return;
}

void SilenceMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void SilenceMagic::showData()const
{
	std::cout << "Enemy can't cast spells\n";
}