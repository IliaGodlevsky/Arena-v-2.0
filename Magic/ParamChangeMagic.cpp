#include "ParamChangeMagic.h"
#include "../Unit/Unit.h"

ParamChangeMagic::ParamChangeMagic(std::string name, int manaCost,
	Timer timer)
	: FreeParamChangeMagic(name, timer), m_manaCost(manaCost)
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

int ParamChangeMagic::getCost()const
{
	return m_manaCost;
}

int ParamChangeMagic::getDuration()const
{
	return m_timer.getDuration();
}

int ParamChangeMagic::getStartTime()const
{
	return m_timer.getStartTime();
}

void ParamChangeMagic::setStartTime(int round)
{
	m_timer.setStartTime(round);
}

bool ParamChangeMagic::isExpired()const
{
	return m_timer.isExpired(Arena::getCurrentRound());
}