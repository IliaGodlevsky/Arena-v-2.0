#include <iostream>

#include "Decision.h"

#include "Unit.h"

Decision::Decision(std::vector<UnitPtr>& arena)
	: arena(arena)
{

}

HumanDecision::HumanDecision(std::vector<UnitPtr>& arena)
	: Decision(arena)
{

}

UnitPtr HumanDecision::ChooseUnitToAttack(UnitPtr deciding_unit)
{
	int unit_number = Input(UNIT_TO_ATTACK_CHOOSE, 
		arena.size(), 0);
	ShowUnits();
	while (arena[unit_number] == deciding_unit)
		unit_number = Input(UNIT_TO_ATTACK_CHOOSE, 
			arena.size(), 0);
	return arena[unit_number];
}

MagicPtr HumanDecision::ChooseMagicToCast(UnitPtr deciding_unit)
{
	int magic_to_spell = Input(MAGIC_CHOOSE, 
		deciding_unit->NumberOfSpells(), 0);
	return MagicPtr(deciding_unit->
		GetMagic(magic_to_spell)->Clone());
}

UnitPtr HumanDecision::ChooseUnitToCast(UnitPtr deciding_unit, const MagicPtr& magic_to_spell)
{
	int unit_to_cast = 0;
	std::cout << "Choose unit to attack: ";
	std::cin >> unit_to_cast;
	while (( magic_to_spell->IsBuff() && arena[unit_to_cast] != deciding_unit)
		|| (!magic_to_spell->IsBuff() && arena[unit_to_cast] == deciding_unit))
	{
		std::cout << "Choose unit to attack: ";
		std::cin >> unit_to_cast;
	}
	return arena[unit_to_cast];
}

void HumanDecision::EatLine()const
{

}

int HumanDecision::Input(const std::string& message, int upper, int lower)const
{

}