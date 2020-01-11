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
		SHADOW_MAIL_DEF = 2,
		GHOST_MAIL_DEF = 4
	};

	enum MailBonuses
	{
		SHADOW_MAIL_HEALTH = 20,
		GHOST_MAIL_HEALTH = 15
	};
};

#endif