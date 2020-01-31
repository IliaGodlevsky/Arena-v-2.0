#ifndef WIZARD_CLOAK_FACTORY_H_
#define WIZARD_CLOAK_FACTORY_H_

#include "../Factory.h"

class WizardCloakFactory : public Factory<Armor>
{
public:
	WizardCloakFactory();
private:
	enum WizardCloakParametres
	{
		MANTLE_DEF = 1,
		CAPE_DEF = 2
	};

	enum WizardCloakBonuses
	{
		MANTLE_MANA = 25,
		CAPE_MANA = 20
	};
};

#endif