#include "../Unit/Unit.h"

#include "SimpleComputerDecision.h"

SimpleComputerDecision::SimpleComputerDecision()
{

}

UnitPtr SimpleComputerDecision::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& arena)const
{
	return RandomComputerDecision::chooseUnitToAttack(decidingUnit, arena);
}

MagicPtr SimpleComputerDecision::chooseMagicToCast(const Unit& decideingUnit,
	const Gladiators& arena)const
{
	return RandomComputerDecision::chooseMagicToCast(decideingUnit, arena);
}

UnitPtr SimpleComputerDecision::chooseUnitToCast(const Unit& decidingUnit, 
	const MagicPtr& magicToCast, const Gladiators& arena)const
{
	return findUnitWithOutChosenMagic(decidingUnit, magicToCast, arena);
}

UnitPtr SimpleComputerDecision::findUnitWithOutChosenMagic(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& arena)const
{
	size_t i = randomNumber(arena.size() - 1);
	size_t count = 0;
	while (count < arena.size())
	{
		if (!isWrongSpellToCast(decidingUnit, *arena[i], magicToCast)
			&& !arena[i]->m_magicOnMe.hasItem(magicToCast)
			&& decidingUnit.isEnoughManaFor(magicToCast))
			return arena[i];
		i++;
		count++;
		if (i >= arena.size())
			i = 0;
	}
	return nullptr;
}

DecisionPtr SimpleComputerDecision::clone()const
{
	return DecisionPtr(new SimpleComputerDecision());
}