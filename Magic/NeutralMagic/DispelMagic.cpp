#include "../../Unit/Unit.h"

#include "DispelMagic.h"


DispelMagic::DispelMagic(std::string name, int manaCost)
	: Magic(name), m_manaCost(manaCost)
{

}

void DispelMagic::effectUnit(Unit& unit)
{
	unit.m_magicOnMe.expireAll();
	unit.m_stateHolder.expireAll();
}

int DispelMagic::getCost()const
{
	return m_manaCost;
}

MagicPtr DispelMagic::clone()const
{
	return MagicPtr(new DispelMagic(m_name, m_manaCost));
}

bool DispelMagic::isBuff()const
{
	return true;
}

bool DispelMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<DispelMagic*>(magic))
		return false;
	return Magic::isEqual(magic);
}

void DispelMagic::showFullInfo()const
{
	Magic::showFullInfo();

	std::cout << "Dispels all magic on unit\n";
}

void  DispelMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}