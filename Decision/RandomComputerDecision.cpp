#include "RandomComputerDecision.h"

#include "../Magic/Magic.h"
#include "../Unit/Unit.h"

RandomComputerDecision::RandomComputerDecision()
{
	
}

UnitPtr RandomComputerDecision::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& arena)const
{
	index unitToAttack = randomNumber(arena.size() - 1);
	while (isSameUnit(decidingUnit, *arena[unitToAttack]))
		unitToAttack = randomNumber(arena.size() - 1);
	return arena[unitToAttack];
}

MagicPtr RandomComputerDecision::chooseMagicToCast(const Unit& decidingUnit,
	const Gladiators& arena)const
{
	index magicToCastIndex = randomNumber(decidingUnit.m_magicBook.size() - 1);
	while(!decidingUnit.isEnoughManaFor(decidingUnit.m_magicBook[magicToCastIndex]))
		magicToCastIndex = randomNumber(decidingUnit.m_magicBook.size() - 1);
	return decidingUnit.m_magicBook[magicToCastIndex]->clone();
}

UnitPtr RandomComputerDecision::chooseUnitToCast(const Unit& decidingUnit, 
	const MagicPtr& magicToCast, const Gladiators& arena)const
{
	index unitToCast = randomNumber(arena.size() - 1);
	while (isWrongSpellToCast(decidingUnit, *arena[unitToCast],magicToCast))
		unitToCast = randomNumber(arena.size() - 1);
	return arena[unitToCast];
}

std::string RandomComputerDecision::setName(std::string name)const
{
	return name;
}

std::string RandomComputerDecision::getDecisionType()const
{
	return "Computer";
}

void RandomComputerDecision::takeMagic(Unit& decidingUnit, const Unit& victim)
{
	// coming soon
}

DecisionPtr RandomComputerDecision::clone()const
{
	return DecisionPtr(new RandomComputerDecision());
}