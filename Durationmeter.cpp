#include "Durationmeter.h"

Durationmeter::Durationmeter(int duration)
	: m_duration(duration), m_startTime(0)
{

}

void Durationmeter::setStartTime(int round)
{
	m_startTime = round;
}

bool Durationmeter::isExpired(int round)const
{
	return m_startTime - round == m_duration;
}

bool Durationmeter::operator==(const Durationmeter& durationmeter)const
{
	return m_duration == durationmeter.m_duration;
}

Durationmeter::operator int()const
{
	return m_duration;
}
