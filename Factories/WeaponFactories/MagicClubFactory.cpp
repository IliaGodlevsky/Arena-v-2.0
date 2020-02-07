#include "MagicClubFactory.h"

#include "../../Weapon/MagicClub.h"
#include "../../Magic/DebuffMagic/SilenceMagic.h"
#include  "../../Magic/WeaponMagic/StunMagic.h"

MagicClubFactory::MagicClubFactory()
{
	m_items.push_back(WeaponPtr(new MagicClub("Ogre maul", OGRE_MAUL_DAMAGE, 
		MagicPtr(new StunMagic("Stun", STUN_DURATION, PosibilityCounter(STUN1_POSSIBILITY))))));
	m_items.push_back(WeaponPtr(new MagicClub("Caveman club", CAVEMANA_CLUB_DAMAGE,
		MagicPtr(new StunMagic("Knock", STUN_DURATION, PosibilityCounter(STUN2_POSSIBILITY))))));
}