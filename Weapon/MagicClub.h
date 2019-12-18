#ifndef MAGIC_CLUB_H_
#define MAGIC_CLUB_H_

#include "MagicWeapon.h"

class MagicClub : public MagicWeapon
{
public:
	MagicClub(std::string name, int damage, MagicPtr magic);
	MagicClub(const MagicClub& club);
	MagicClub& operator=(const MagicClub& club);
	~MagicClub() = default;
public:
	WeaponPtr clone()const override;
};

#endif