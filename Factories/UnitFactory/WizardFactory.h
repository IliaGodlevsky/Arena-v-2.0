#ifndef WIZARD_FACTORY_H_
#define WIZARD_FACTORY_H_

#include "UnitFactory.h"

class WizardFactory : public UnitFactory
{
public:
	WizardFactory();
	UnitPtr createUnit()const;
	UnitPtr operator()()override;
	~WizardFactory();
private:
	std::vector <Factory<Magic>*> m_secondMagics;
};

#endif