#include "ParamChangeMagic.h"
#include "../Unit/Unit.h"

ParamChangeMagic::ParamChangeMagic(std::string name, int manaCost,
	Time time)
	: FreeParamChangeMagic(name, time), IManaCost(manaCost)
{

}

bool ParamChangeMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ParamChangeMagic*>(magic))
		return false;
	ParamChangeMagic* temp = DYNAMIC(ParamChangeMagic*, magic);
	return FreeParamChangeMagic::isEqual(magic)
		&& m_manaCost == temp->m_manaCost;
}

void ParamChangeMagic::effectUnit(Unit& unit)
{
	unit.m_magicOnMe.takeNew(clone());
}

void ParamChangeMagic::showFullInfo()const
{
	Magic::showFullInfo();
}

void ParamChangeMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}