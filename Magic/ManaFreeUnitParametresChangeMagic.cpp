#include "ManaFreeUnitParametresChangeMagic.h"
#include "../Unit/Unit.h"

ManaFreeUnitParametresChangeMagic::ManaFreeUnitParametresChangeMagic(std::string name, Time time,
	const ElementsInitializerList& holder)
	: Magic(name), Expiring(time), m_elemHolder(holder)
{

}

ManaFreeUnitParametresChangeMagic::ManaFreeUnitParametresChangeMagic(std::string name, Time time,
	const ElementHolder& holder)
	: Magic(name), Expiring(time), m_elemHolder(holder)
{

}

void ManaFreeUnitParametresChangeMagic::effectUnit(Unit& unit)
{
	m_elemHolder.effectUnit(unit);
	unit.m_magicOnMe.takeNew(clone());
}

void ManaFreeUnitParametresChangeMagic::uneffectUnit(Unit& unit)
{
	m_elemHolder.uneffectUnit(unit);
}

bool ManaFreeUnitParametresChangeMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ManaFreeUnitParametresChangeMagic*>(magic))
		return false;
	const auto temp = dCast<ManaFreeUnitParametresChangeMagic*>(magic);
	return Magic::isEqual(magic)
		&& Expiring::operator==(*temp)
		&& m_elemHolder.isEqual(temp->m_elemHolder);
}

void ManaFreeUnitParametresChangeMagic::showFullInfo()const
{
	setColor(YELLOW);
	Magic::showFullInfo();
	setColor();
}

void ManaFreeUnitParametresChangeMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << "> ";
}