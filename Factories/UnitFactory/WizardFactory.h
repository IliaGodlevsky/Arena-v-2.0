#ifndef WIZARD_FACTORY_H_
#define WIZARD_FACTORY_H_

#include "UnitFactory.h"

class WizardFactory : public UnitFactory
{
public:
	WizardFactory();
	UnitPtr createUnit()const;
};

#endif