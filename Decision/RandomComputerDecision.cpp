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
	return decidingUnit.m_magicBook[randomNumber
	(decidingUnit.m_magicBook.size() - 1)]->clone();
}

UnitPtr RandomComputerDecision::chooseUnitToCast(const Unit& decidingUnit, 
	const MagicPtr& magicToCast, const Gladiators& arena)const
{
	index unitToCast = randomNumber(arena.size() - 1);
	while (isWrongSpellToCast(decidingUnit, *arena[unitToCast],magicToCast))
		unitToCast = randomNumber(arena.size() - 1);
	return arena[unitToCast];
}