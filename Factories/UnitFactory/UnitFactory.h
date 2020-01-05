#ifndef UNIT_FACTORY_H_
#define UNIT_FACTORY_H_

#include "../../Globals/Globals.h"
#include "../Factory.h"
#include "../ItemFactory/ItemFactory.h"

class UnitFactory;
using UnitFactoryPtr = std::shared_ptr<UnitFactory>;

class UnitFactory
{
public:
	UnitFactory();
	virtual UnitPtr createUnit()const = 0;
	virtual UnitPtr operator()() = 0;
	virtual ~UnitFactory() = default;
protected:
	ItemFactoryPtr m_itemFactory = nullptr;
	std::vector<DecisionPtr> m_decisions;
protected:
	virtual index chooseDecsion()const final;
};

#endif