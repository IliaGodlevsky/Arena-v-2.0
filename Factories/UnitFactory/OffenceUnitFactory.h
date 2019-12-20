#ifndef OFFENCE_UNIT_FACTORY_H_
#define OFFENCE_UNIT_FACTORY_H_

#include "UnitFactory.h"

class OffenceUnitFactory : public UnitFactory
{
public:
	OffenceUnitFactory();
	UnitPtr createUnit()const override;
	~OffenceUnitFactory();
};

#endif