#include "FreeParamChangeMagic.h"
#include "../Unit/Unit.h"

FreeParamChangeMagic::FreeParamChangeMagic(std::string name, Timer timer)
	: Magic(name), IDuration(timer)
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
		&& m_timer == temp->m_timer;
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

int FreeParamChangeMagic::getDuration()const
{
	return m_timer.getDuration();
}

int FreeParamChangeMagic::getStartTime()const
{
	return m_timer.getStartTime();
}

void FreeParamChangeMagic::setStartTime(int round)
{
	m_timer.setStartTime(round);
}

bool FreeParamChangeMagic::isExpired()const
{
	return m_timer.isExpired(Arena::getCurrentRound());
}