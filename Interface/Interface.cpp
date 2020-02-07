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

void IDuration::expire()
{
	setStartTime(Arena::getCurrentRound() - getDuration() - 1);
}

IManaCost::IManaCost(int manaCost)
	: m_manaCost(manaCost)
{

}

int IManaCost::getCost()const
{
	return m_manaCost;
}