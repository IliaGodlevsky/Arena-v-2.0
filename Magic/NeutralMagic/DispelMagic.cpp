#include "../../Unit/Unit.h"

#include "DispelMagic.h"


DispelMagic::DispelMagic(std::string name, int manaCost)
	: Magic(name, manaCost, Timer(ZERO_DURATION))
{

}

void DispelMagic::effectUnit(Unit& unit)
{
	unit.m_magicOnMe.expireAllMagic();
	unit.m_stateHolder.expireAllStates();
}

void DispelMagic::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr DispelMagic::clone()const
{
	return MagicPtr(new DispelMagic(m_name, m_manaCost));
}

bool DispelMagic::isBuff()const
{
	return false;
}

bool DispelMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DispelMagic* temp = DYNAMIC(DispelMagic*, magic);
	if (nullptr == temp)
		return false;
	return Magic::isEqual(magic);
}

bool DispelMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void DispelMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void DispelMagic::showData()const
{
	std::cout << "Dispels all magic on unit\n";
}

void DispelMagic::putOn(Unit& unit)const
{
	return;
}