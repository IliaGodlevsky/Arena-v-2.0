#include "Interface.h"
#include "../Arena/Arena.h"

int IDuration::getDurationRemained()const
{
	return getStartTime() + getDuration() -
		Arena::getCurrentRound();
}