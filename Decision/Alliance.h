#ifndef ALLIANCE_H_
#define ALLIANCE_H_

#include "../Globals/Globals.h"

class Alliance
{
public:
	Alliance();
	void takeAlly(const UnitPtr& ally);
	bool isAlly(const Unit& unit)const;
protected:
	std::vector<UnitPtr> m_allies;
};

#endif
