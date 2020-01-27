#ifndef STAFF_H_
#define STAFF_H_

#include "Weapon.h"

class Staff : public Weapon
{
public:
	Staff(std::string name, int damage);
	Staff(const Staff& weapon);
	Staff& operator=(const Staff& weapon);
	virtual void injureUnit(Unit& unit, int damage)const;
};

#endif
