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
	UnitPtr createUnit()const;
private:
	// a new thread for downloading names from file
	mutable std::unique_ptr<std::thread> m_thread;
	std::vector<std::string> m_unitsNames;
	std::vector<ItemFactoryPtr> m_itemFactories;
	std::vector<DecisionPtr> m_decisions;
};

#endif