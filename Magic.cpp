#include "Magic.h"

Magic::Magic(int mana_cost, int duration)
	: mana_cost(mana_cost), duration(duration)
{

}

void Magic::SetTimeOfActivation(int round)
{
	activation_time = round;
}

bool Magic::Expired(int round)const
{
	return round - activation_time == duration;
}

Magic::~Magic()
{

}