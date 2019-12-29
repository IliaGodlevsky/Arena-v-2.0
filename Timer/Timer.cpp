#include "Timer.h"

#include <iostream>

Timer::Timer(int duration)
	: Timer(duration, 0)
{

}

Timer::Timer(int duration, int startTime)
	: m_duration(duration), m_startTime(startTime)
{

}

void Timer::setStartTime(int round)
{
	m_startTime = round;
}

bool Timer::isExpired(int round)const
{
	return round - m_startTime > m_duration;
}

bool Timer::operator==(const Timer& durationmeter)const
{
	return m_duration == durationmeter.m_duration;
}

int Timer::getDuration()const
{
	return m_duration;
}

int Timer::getStartTime()const
{
	return m_startTime;
}
