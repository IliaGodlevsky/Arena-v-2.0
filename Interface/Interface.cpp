#include "Interface.h"
#include "../Arena/Arena.h"

IDuration::IDuration(Timer timer)
	: m_timer(timer)
{

}

int IDuration::getDurationRemained()const
{
	return getStartTime() + getDuration() -
		Arena::getCurrentRound();
}

IManaCost::IManaCost(int manaCost)
	: m_manaCost(manaCost)
{

}

int IManaCost::getCost()const
{
	return m_manaCost;
}