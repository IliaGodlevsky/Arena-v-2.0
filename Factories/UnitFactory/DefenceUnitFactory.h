#ifndef DEFENCE_UNIT_FACTORY_H_
#define DEFENCE_UNIT_FACTORY_H_

#include "UnitFactory.h"

class DefenceUnitFactory : public UnitFactory
{
public:
	DefenceUnitFactory();
	UnitPtr createUnit()const override;
	~DefenceUnitFactory();
};
#endif