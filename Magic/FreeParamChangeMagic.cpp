#include "FreeParamChangeMagic.h"
#include "../Unit/Unit.h"

FreeParamChangeMagic::FreeParamChangeMagic(std::string name, Time time)
	: Magic(name), Expiring(time)
{

}

void FreeParamChangeMagic::effectUnit(Unit& unit)
{
	setStartTime(Arena::getCurrentRound());
	unit.m_magicOnMe.takeNew(clone());
}

bool FreeParamChangeMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<FreeParamChangeMagic*>(magic))
		return false;
	FreeParamChangeMagic* temp = DYNAMIC(FreeParamChangeMagic*, magic);
	return Magic::isEqual(magic)
		&& Expiring::operator==(*temp);
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