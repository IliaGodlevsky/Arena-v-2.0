#ifndef MAGIC_CLUB_FACTORY_H_
#define MAGIC_CLUB_FACTORY_H_

#include "../Factory.h"

class MagicClubFactory : public Factory<Weapon>
{
public:
	MagicClubFactory();
private:
	enum
	{
		OGRE_MAUL_DAMAGE = 8,
		CAVEMANA_CLUB_DAMAGE = 7
	};

	enum
	{
		STUN_DURATION = 2,
		STUN1_POSSIBILITY = 9,
		STUN2_POSSIBILITY = 13
	};
};

#endif