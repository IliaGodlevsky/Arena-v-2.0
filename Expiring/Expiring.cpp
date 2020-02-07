#include <utility>

#include "Expiring.h"
#include "../Arena/Arena.h"

Time::Time(int duration, int startTime)
	: duration(duration), startTime(startTime)
{

}

Expiring::Expiring(int duration, int startTime)
	: m_time(duration, startTime)
{

}

Expiring::Expiring(Time time)
	: m_time(time)
{

}

void Expiring::setStartTime(int round)
{
	m_time.startTime = round;
}

bool Expiring::isExpired()const
{
	return Arena::getCurrentRound() - m_time.startTime >= m_time.duration;
}

bool Expiring::operator==(const Expiring& expiring)const
{
	return m_time.duration == expiring.m_time.duration;
}

int Expiring::getDuration()const
{
	return m_time.duration;
}

int Expiring::getStartTime()const
{
	return m_time.startTime;
}

int Expiring::getDurationRemained()const
{
	return getStartTime() + getDuration() -
		Arena::getCurrentRound();
}

void Expiring::makeExpire()
{
	setStartTime(Arena::getCurrentRound() - getDuration() - 1);
}
