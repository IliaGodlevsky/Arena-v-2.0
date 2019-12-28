#ifndef MAGIC_STAFF_H_
#define MAGIC_STAFF_H_

#include "Staff.h"

class MagicStaff : public Staff
{
public:
	MagicStaff(std::string name, int damage, MagicPtr magic);
	MagicStaff(const MagicStaff& weapon);
	MagicStaff& operator=(const MagicStaff& weapon);
public:
	void injureUnit(Unit& unit, int damage)const;
	WeaponPtr clone()const;
private:
	MagicPtr m_magic;
};

#endif
