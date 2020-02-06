#include "HumanDecision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Arena/Arena.h"

index chooseMagicIndex(const std::string& message, 
	const MagicBook& magicBook)
{
	magicBook.magicList();
	std::cout << magicBook.size() + 1 
		<< ". Show more info about magic\n";
	index magicToCastIndex = inputNumber(message, 
		(int)magicBook.size() + 1, 1);
	if ((int)magicBook.size() + 1 == magicToCastIndex)
	{
		magicBook.showFullInfo();
		magicToCastIndex = inputNumber(message, 
			(int)magicBook.size(), 1);
	}
	return magicToCastIndex;
}

HumanDecision::HumanDecision()
{

}

UnitPtr HumanDecision::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	std::cout << decidingUnit.getName() << ", ";
	index unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE,
		(int)units.size(), 1);
	while (isWrongUnitToAttack(decidingUnit, units[unitIndex - 1]))
	{
		std::cout << "You can't attack this unit\n";
		unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE,
			(int)units.size(), 1);
	}
	return units[unitIndex - 1];
}

bool HumanDecision::wantToCastMagic(const Unit& decidingUnit)const
{
	std::cout << decidingUnit.getName() << ", ";
	return m_wantToCastMagic = static_cast<bool>(inputNumber(
		WANT_TO_CAST_QUESTION, YES, NO));
}

MagicPtr HumanDecision::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	if (!wantToCastMagic(decidingUnit))
		return nullptr;
	std::cout << "Choose magic to cast\n";
	index magicToCastIndex = chooseMagicIndex(MAGIC_TO_CAST_CHOOSE_MESSAGE,
		decidingUnit.m_magicBook);
	while (!decidingUnit.isEnoughManaFor(decidingUnit.m_magicBook[magicToCastIndex - 1]))
	{
		std::cout << "Not enough mana for this magic\n";
		magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE,
			(int)decidingUnit.m_magicBook.size(), 1);
	}
	return MagicPtr(decidingUnit.m_magicBook[magicToCastIndex - 1]->clone());
}

UnitPtr HumanDecision::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (!m_wantToCastMagic)
		return nullptr;
	Arena::getInstance().showUnits();
	std::cout << decidingUnit.getName() << ", ";
	index unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE, 
		(int)units.size(), 1);
	while (isWrongSpellToCast(decidingUnit, 
		*units[unitToCastIndex - 1], magicToCast))
	{
		std::cout << "You can't use this magic on this unit\n";
		unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
			(int)units.size(), 1);
	}
	return units[unitToCastIndex - 1];
}

std::string HumanDecision::setName(std::string name)const
{
	const int NAME_SIZE = 70;
	char unitName[NAME_SIZE];
	eatLine();
	std::cout << "\t\t\tEnter your name: ";
	std::cin.get(unitName, NAME_SIZE);
	name = unitName;
	while ("\n" == name || name.empty())
	{
		eatLine();
		std::cout << "\t\t\tEnter your name: ";
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
	std::cout << decidingUnit.getName() << ", ";
	index magicToTake = chooseMagicIndex(CHOOSE_MAGIC_TO_TAKE_MSG, 
		victim.m_magicBook);
	bool wantsToTakeMagic;
	while (decidingUnit.m_magicBook.hasItem(victim.m_magicBook[magicToTake - 1]))
	{
		wantsToTakeMagic = static_cast<bool>(inputNumber(YOU_HAVE_MAGIC_MSG, YES, NO));
		if (!wantsToTakeMagic)
			magicToTake = inputNumber(CHOOSE_MAGIC_TO_TAKE_MSG, 
			(int)victim.m_magicBook.size(), 1);
		else
			break;
	}
	decidingUnit.m_magicBook.takeNew(victim.m_magicBook[magicToTake - 1]);
}

DecisionPtr HumanDecision::clone()const
{
	return DecisionPtr(new HumanDecision(*this));
}