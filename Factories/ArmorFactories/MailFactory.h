#ifndef MAIL_FACTORY_H_
#define MAIL_FACTORY_H_

#include "../Factory.h"

class MailFactory : public Factory<Armor>
{
public:
	MailFactory();
private:
	enum MailParametres
	{
		SHADOW_MAIL_DEF = 3,
		GHOST_MAIL_DEF = 5
	};

	enum MailBonuses
	{
		SHADOW_MAIL_HEALTH = 35,
		GHOST_MAIL_HEALTH = 25
	};
};

#endif