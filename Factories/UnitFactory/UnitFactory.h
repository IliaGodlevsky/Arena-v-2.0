#ifndef UNIT_FACTORY_H_
#define UNIT_FACTORY_H_

#include <thread>

#include "../../Unit/Unit.h"
#include "../Factory.h"
#include "../ItemFactory/ItemFactory.h"

class UnitFactory;
using UnitFactoryPtr = std::shared_ptr<UnitFactory>;

class UnitFactory
{
public:
	UnitFactory();
	virtual UnitPtr createUnit()const = 0;
	virtual ~UnitFactory();
protected:
	// a new thread for loading names from file
	mutable std::unique_ptr<std::thread> m_thread;
	std::vector<std::string> m_unitsNames;
	ItemFactoryPtr m_itemFactory;
	std::vector<DecisionPtr> m_decisions;
protected:
	virtual index chooseDecsion()const final;
	virtual void checkThread()const final;
};

#endif