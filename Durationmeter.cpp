#include "Durationmeter.h"

Durationmeter::Durationmeter(int duration)
	: duration(duration), start_time(0)
{

}

void Durationmeter::SetStartTime(int round)
{
	start_time = round;
}

bool Durationmeter::IsExpired(int round)const
{
	return start_time - round == duration;
}

bool Durationmeter::operator==(const Durationmeter& d)const
{
	return duration == d.duration;
}

Durationmeter::operator int()const
{
	return duration;
}
