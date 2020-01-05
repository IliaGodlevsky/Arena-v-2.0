#include "UnitFactory.h"
#include "../../Decision/HumanDecision.h"
#include "../../Decision/RandomComputerDecision.h"
#include "../../Decision/SimpleComputerDecision.h"

UnitFactory::UnitFactory():
	m_decisions(0)
{
	m_decisions.push_back(DecisionPtr(new HumanDecision()));
	m_decisions.push_back(DecisionPtr(new RandomComputerDecision()));
	m_decisions.push_back(DecisionPtr(new SimpleComputerDecision())); 
}

index UnitFactory::chooseDecsion()const
{
	try {
		if (m_decisions.empty())
			throw BadEquipmentException("No actual desicions for gamers. Bad class is "
				+ std::string(typeid(*this).name()));
		if(nullptr == m_itemFactory)
			throw BadEquipmentException("No actual item factory for units. Bad class is "
				+ std::string(typeid(*this).name()));
	}
	catch (BadEquipmentException& ex) { exceptionMessage(ex); }
	return inputNumber("1. Human\n2. \"Dump\"comp\n"
		"3. \"Clever\" comp\nChoose decision: ", m_decisions.size(), 1);
}