#include "Timer.h"

#include <iostream>

Timer::Timer(int duration)
	: m_duration(duration), m_startTime(0)
{

}

void Timer::setStartTime(int round)
{
	m_startTime = round;
}

bool Timer::isExpired(int round)const
{
	std::cout << "Round: " << round << std::endl;
	std::cout << "Start time: " << m_startTime << std::endl;
	std::cout << "Duration: " << m_duration << std::endl;
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
