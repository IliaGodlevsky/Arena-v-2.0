#include "FreeParamChangeMagic.h"
#include "../Unit/Unit.h"

FreeParamChangeMagic::FreeParamChangeMagic(std::string name, Time time,
	const ElementsInit& holder)
	: Magic(name), Expiring(time), m_elemHolder(holder)
{

}

FreeParamChangeMagic::FreeParamChangeMagic(std::string name, Time time,
	const ElementHolder& holder)
	: Magic(name), Expiring(time), m_elemHolder(holder)
{

}

void FreeParamChangeMagic::effectUnit(Unit& unit)
{
	m_elemHolder.effectUnit(unit);
	unit.m_magicOnMe.takeNew(clone());
}

void FreeParamChangeMagic::uneffectUnit(Unit& unit)
{
	m_elemHolder.uneffectUnit(unit);
}

bool FreeParamChangeMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<FreeParamChangeMagic*>(magic))
		return false;
	const auto temp = dCast<FreeParamChangeMagic*>(magic);
	return Magic::isEqual(magic)
		&& Expiring::operator==(*temp)
		&& m_elemHolder.isEqual(temp->m_elemHolder);
}

void FreeParamChangeMagic::showFullInfo()const
{
	setColor(YELLOW);
	Magic::showFullInfo();
	setColor();
}

void FreeParamChangeMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << "> ";
}