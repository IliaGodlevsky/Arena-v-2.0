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
		OGRE_MAUL_DAMAGE = 10,
		CAVEMANA_CLUB_DAMAGE = 8
	};

	enum
	{
		STUN_DURATION = 2,
		STUN2_POSSIBILITY = 20,
		STUN1_POSSIBILITY = 15
	};
};

#endif