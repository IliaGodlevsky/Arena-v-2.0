#include "../../../Magic/AttackMagic/AttackAndStunMagic.h"

#include "AttackAndStunMagicFactory.h"

AttackAndStunMagicFactory::AttackAndStunMagicFactory()
{
	m_items.push_back(MagicPtr(new AttackAndStunMagic("Thunder bolt",
		THUNDER_BOLT_MANA_COST, THUNDER_BOLT_DURATION, THUNDER_BOLT_DAMAGE)));
	m_items.push_back(MagicPtr(new AttackAndStunMagic("Mental fist",
		MENTAL_FIST_MANA_COST, MENTAL_FIST_DURATION, MENTAL_FIST_DAMAGE)));
}