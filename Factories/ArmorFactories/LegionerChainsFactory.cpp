#include "../../Armor/LegionerChains.h"

#include "LegionerChainsFactory.h"

LegionerChainsFactory::LegionerChainsFactory()
{
	m_items.push_back(ArmPtr(new LegionerChains("Full plate", FULL_MAIL_DEF,
		Vitals(FULL_MAIL_HEALTH, FULL_MAIL_HEALTH),
		Vitals(FULL_MAIL_MANA, FULL_MAIL_MANA))));
	m_items.push_back(ArmPtr(new LegionerChains("Plate mail", PLATE_MAIL_DEF,
		Vitals(PLATE_MAIL_HEALTH, PLATE_MAIL_HEALTH),
		Vitals(PLATE_MAIL_MANA, PLATE_MAIL_MANA))));
}