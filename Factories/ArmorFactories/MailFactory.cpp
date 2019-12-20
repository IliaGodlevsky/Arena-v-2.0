#include "../../Armor/Mail.h"

#include "MailFactory.h"

MailFactory::MailFactory()
{
	m_items.push_back(ArmPtr(new Mail("Shadow mail", SHADOW_MAIL_DEF,
		Vitals(SHADOW_MAIL_HEALTH, SHADOW_MAIL_HEALTH))));
	m_items.push_back(ArmPtr(new Mail("Ghost mail", GHOST_MAIL_DEF,
		Vitals(GHOST_MAIL_HEALTH, GHOST_MAIL_HEALTH))));
}