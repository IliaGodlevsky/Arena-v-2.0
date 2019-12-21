#ifndef UNIT_FACTORY_H_
#define UNIT_FACTORY_H_

#include "../../Unit/Unit.h"
#include "../Factory.h"
#include "../ItemFactory/ItemFactory.h"

class UnitFactory
{
public:
	UnitFactory();
	UnitFactory(ItemFactory* factory);
	UnitPtr createUnit()const;
	void setFactory(ItemFactory* factory);
protected:
	mutable std::vector<DecisionPtr> m_decisions;
	ItemFactory* m_factory = nullptr;
	std::vector<std::string> m_unitsNames;
};

#endif