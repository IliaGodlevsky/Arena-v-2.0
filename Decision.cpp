#include <iostream>
#include <random>

#include "Decision.h"
#include "Unit.h"

int input(const std::string& message,
	int upper, int lower)
{
	int choice;
	std::cout << message;
	std::cin >> choice;
	while (error(choice, upper, lower))
	{
		eatline();
		std::cout << message;
		std::cin >> choice;
	}
	return choice;
}

bool error(int choice, int upper, int lower)
{
	return !std::cin 
		|| choice > upper 
		|| choice < lower;
}

void eatline()
{
	std::cin.clear();
	while (!iscntrl(std::cin.get()))
		continue;
}

size_t RandInd(size_t max_index)
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<size_t> distributor(0, max_index);
	return distributor(generator);
}

Decision::Decision(const std::vector<Unit*>& arena)
	: arena(arena)
{

}

bool Decision::SameUnit(const Unit& unit1, const Unit& unit2)const
{
	return &unit1 == &unit2;
}

bool Decision::CanCastBuff(const Unit& caster, const Unit& aim,
	const MagicPtr& spell)const
{
	return spell->IsBuff() && SameUnit(caster, aim);
}
bool Decision::CanCastDebuff(const Unit& caster, const Unit& aim,
	const MagicPtr& spell)const
{
	return !spell->IsBuff() && !SameUnit(caster, aim);
}

HumanDecision::HumanDecision(const std::vector<Unit*>& arena)
	: Decision(arena)
{

}

Unit* HumanDecision::ChooseUnitToAttack(const Unit& deciding_unit)const
{
	int unit_number = input(UNIT_TO_ATTACK_CHOOSE, arena.size() - 1, 0);
	while (SameUnit(*arena[unit_number], deciding_unit))
	{
		std::cout << "You can't attack yourselt\n";
		unit_number = input(UNIT_TO_ATTACK_CHOOSE, arena.size() - 1, 0);
	}
	return arena[unit_number];
}

MagicPtr HumanDecision::ChooseMagicToCast(const Unit& deciding_unit)const
{
	int magic_to_spell = input(MAGIC_CHOOSE, 
		deciding_unit.spell_book.size(), 0);
	return MagicPtr(deciding_unit.
		spell_book[magic_to_spell]->Clone());
}

Unit* HumanDecision::ChooseUnitToCast(const Unit& deciding_unit, 
	const MagicPtr& magic_to_spell)const
{
	int unit_to_cast = input(UNIT_TO_CAST_CHOOSE, arena.size() - 1, 0);
	while (WrongSpellToCast(deciding_unit, *arena[unit_to_cast], magic_to_spell))
	{
		std::cout << "You can't use this spell on this unit\n";
		unit_to_cast = input(UNIT_TO_CAST_CHOOSE, arena.size() - 1, 0);
	}
	return arena[unit_to_cast];
}

bool HumanDecision::WrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& spell)const
{
	return !CanCastBuff(caster, aim, spell) || !CanCastDebuff(caster, aim, spell);
}


//ComputerDecision::ComputerDecision(const std::vector<Unit*>& arena)
//	: Decision(arena)
//{
//
//}