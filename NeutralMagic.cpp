#include "NeutralMagic.h"
#include "Unit.h"

Dispel::Dispel(std::string name, int manaCost)
	: Magic(name, manaCost, ZERO_DURATION)
{

}

void Dispel::effectUnit(Unit& unit)
{
	unit.m_magicOnMe.expireAllMagic();
	unit.m_stateHolder.expireAllStates();
}

void Dispel::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr Dispel::clone()const
{
	return MagicPtr(new Dispel(m_name, m_manaCost));
}

bool Dispel::isBuff()const
{
	return false;
}

bool Dispel::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Dispel* temp = DYNAMIC(Dispel*, magic);
	if (nullptr == temp)
		return false;
	return Magic::isEqual(magic);
}

bool Dispel::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Dispel::showFullInfo()const
{
	Magic::showData();
	showData();
}

void Dispel::showData()const
{
	std::cout << "Dispels all magic on unit\n";
}

void Dispel::putOn(Unit& unit)const
{
	return;
}