#include "HumanDecision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Arena/Arena.h"

HumanDecision::HumanDecision()
{

}

UnitPtr HumanDecision::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	std::cout << decidingUnit.getName() << ", ";
	index unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE,
		units.size(), 1);
	while (units[unitIndex - 1]->isAlly(decidingUnit) ||
		!units[unitIndex - 1]->isAlive())
	{
		std::cout << "You can't attack this unit\n";
		unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE,
			units.size(), 1);
	}
	return units[unitIndex - 1];
}

bool HumanDecision::wantToCastMagic(const Unit& decidingUnit)const
{
	std::cout << decidingUnit.getName() << ", ";
	m_wantToCastMagic = static_cast<bool>(inputNumber(
		WANT_TO_CAST_QUESTION, YES, NO));
	return m_wantToCastMagic;
}

MagicPtr HumanDecision::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	if (!wantToCastMagic(decidingUnit))
		return nullptr;
	std::cout << "Choose magic to cast\n";
	decidingUnit.m_magicBook.magicList();
	std::cout << decidingUnit.m_magicBook.size() + 1 
		<< ". Show more info about magic\n";
	index magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE,
		decidingUnit.m_magicBook.size() + 1, 1);
	if (decidingUnit.m_magicBook.size() + 1 == magicToCastIndex)
	{
		decidingUnit.m_magicBook.showFullInfo();
		magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE,
			decidingUnit.m_magicBook.size(), 1);
	}	
	while (!decidingUnit.isEnoughManaFor(decidingUnit.m_magicBook[magicToCastIndex - 1]))
	{
		std::cout << "Not enough mana for this magic\n";
		magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE,
			decidingUnit.m_magicBook.size(), 1);
	}
	return MagicPtr(decidingUnit.m_magicBook[magicToCastIndex - 1]->clone());
}

UnitPtr HumanDecision::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (!m_wantToCastMagic)
		return nullptr;
	auto& arena = Arena::getInstance();
	arena.showUnits();
	std::cout << decidingUnit.getName() << ", ";
	index unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
		units.size(), 1);
	while (isWrongSpellToCast(decidingUnit, *units[unitToCastIndex - 1], magicToCast))
	{
		std::cout << "You can't use this magic on this unit\n";
		unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
			units.size(), 1);
	}
	return units[unitToCastIndex - 1];
}

std::string HumanDecision::setName(std::string name)const
{
	const int NAME_SIZE = 70;
	char unitName[NAME_SIZE];
	eatLine();
	std::cout << "Enter your name: ";
	std::cin.get(unitName, NAME_SIZE);
	name = unitName;
	while ("\n" == name || name.empty())
	{
		eatLine();
		std::cout << "Enter your name: ";
		std::cin.get(unitName, NAME_SIZE);
		name = unitName;
	}
	return name;
}

std::string HumanDecision::getDecisionType()const
{
	return "Human";
}

void HumanDecision::takeMagic(Unit& decidingUnit, const Unit& victim)
{
	const std::string CHOOSE_MAGIC_TO_TAKE_MSG = decidingUnit.getName() + 
		", choose units spell you want to take: ";
	const std::string YOU_HAVE_MAGIC_MSG = "You have such a magic. "
		"Do you really want to take it?: ";
	victim.m_magicBook.magicList();
	index magicToTake = inputNumber(CHOOSE_MAGIC_TO_TAKE_MSG, victim.m_magicBook.size(), 1);
	bool wantToTakeMagic;
	while (decidingUnit.m_magicBook.hasItem(victim.m_magicBook[magicToTake - 1]))
	{
		wantToTakeMagic = static_cast<bool>(inputNumber(YOU_HAVE_MAGIC_MSG, YES, NO));
		if (NO == wantToTakeMagic)
			magicToTake = inputNumber(CHOOSE_MAGIC_TO_TAKE_MSG, victim.m_magicBook.size(), 1);
		else
			break;
	}
	decidingUnit.m_magicBook.takeNew(victim.m_magicBook[magicToTake - 1]);
}

DecisionPtr HumanDecision::clone()const
{
	return DecisionPtr(new HumanDecision(*this));
}