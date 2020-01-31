#ifndef SILENCE_FACTORY_H_
#define SILENCE_FACTORY_H_

#include "../../Factory.h"

class SilenceFactory : public Factory<Magic>
{
public:
	SilenceFactory();
private:
	enum { SILENCE_MANA_COST = 20, SILENCE_DURATION = 2 };
};

#endif