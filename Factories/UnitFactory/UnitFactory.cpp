#include "UnitFactory.h"
#include "../../Decision/HumanDecision.h"
#include "../../Decision/RandomComputerDecision.h"
#include "../../Decision/SimpleComputerDecision.h"
#include "../ItemFactory/DefenceItemFactory.h"
#include "../ItemFactory/OffenceItemFactory.h"

UnitFactory::UnitFactory():
	m_decisions(0)
{
	m_thread = std::unique_ptr<std::thread>(new std::thread([&]()
	{ m_unitsNames = loadFromFile("Names.txt"); }));
	m_decisions.push_back(DecisionPtr(new HumanDecision()));
	m_decisions.push_back(DecisionPtr(new RandomComputerDecision()));
	m_decisions.push_back(DecisionPtr(new SimpleComputerDecision())); 
}

index UnitFactory::chooseDecsion()const
{
	return inputNumber("1. Human 2. RandomComputer"
		" 3.SimpleComputer\nChoose decision: ", m_decisions.size(), 1);
}

void UnitFactory::checkThread()const
{
	if (m_thread->joinable())
		m_thread->join();
}

UnitFactory::~UnitFactory()
{

}