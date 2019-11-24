#include <iostream>
#include <random>

#include "Decision.h"

#include "Unit.h"

size_t RandInd(size_t max_index)
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<size_t> distributor(0, max_index);
	return distributor(generator);
}

Decision::Decision(const std::vector<UnitPtr>& arena)
	: arena(arena)
{

}

bool Decision::SameUnit(const UnitPtr& unit1, const UnitPtr& unit2)const
{
	return unit1 == unit2;
}

bool Decision::CanCastBuff(UnitPtr caster, UnitPtr aim,
	const MagicPtr& spell)const
{
	return spell->IsBuff() && SameUnit(caster, aim);
}
bool Decision::CanCastDebuff(UnitPtr caster, UnitPtr aim,
	const MagicPtr& spell)const
{
	return !spell->IsBuff() && !SameUnit(caster, aim);
}

HumanDecision::HumanDecision(const std::vector<UnitPtr>& arena)
	: Decision(arena)
{

}

UnitPtr HumanDecision::ChooseUnitToAttack(const UnitPtr& deciding_unit)const
{
	int unit_number = Input(UNIT_TO_ATTACK_CHOOSE, arena.size(), 0);
	ShowUnits();
	while (SameUnit(arena[unit_number], deciding_unit))
		unit_number = Input(UNIT_TO_ATTACK_CHOOSE, arena.size(), 0);
	return arena[unit_number];
}

MagicPtr HumanDecision::ChooseMagicToCast(const UnitPtr& deciding_unit)const
{
	int magic_to_spell = Input(MAGIC_CHOOSE, 
		deciding_unit->spell_book.size(), 0);
	return MagicPtr(deciding_unit->
		spell_book[magic_to_spell]->Clone());
}

UnitPtr HumanDecision::ChooseUnitToCast(const UnitPtr& deciding_unit, 
	const MagicPtr& magic_to_spell)const
{
	int unit_to_cast = Input(UNIT_TO_CAST_CHOOSE, arena.size(), 0);
	while (WrongSpellToCast(deciding_unit, arena[unit_to_cast], magic_to_spell))
		unit_to_cast = Input(UNIT_TO_CAST_CHOOSE, arena.size(), 0);
	return arena[unit_to_cast];
}

void HumanDecision::EatLine()const
{

}

int HumanDecision::Input(const std::string& message, int upper, int lower)const
{
	// TODO: do input
	return 0;
}

bool HumanDecision::WrongSpellToCast(const UnitPtr& caster, const UnitPtr& aim,
	const MagicPtr& spell)const
{
	return !CanCastBuff(caster, aim, spell) || !CanCastDebuff(caster, aim, spell);
}


ComputerDecision::ComputerDecision(const std::vector<UnitPtr>& arena)
	: Decision(arena)
{

}

UnitPtr ComputerDecision::ChooseUnitToAttack(const UnitPtr& deciding_unit)const
{
	UnitPtr unit_to_attack = nullptr;
	if (unit_to_attack = FindUnitToSmash(deciding_unit))
		return unit_to_attack;
	unit_to_attack = ChooseRandomUnit(deciding_unit);
	return unit_to_attack;
}

MagicPtr ComputerDecision::ChooseMagicToCast(const UnitPtr& deciding_unit)const
{
	if (!deciding_unit->spell_book.CanCastAnySpell())
		return nullptr;
	return MagicPtr(deciding_unit->spell_book[RandInd(arena.size() - 1)]->Clone());
}

UnitPtr ComputerDecision::ChooseUnitToCast(const UnitPtr& deciding_unit, 
	const MagicPtr& magic_to_spell)const
{
	if (!magic_to_spell)
		return nullptr;
	size_t i = RandInd(arena.size() - 1);
	size_t iter = 0;
	while (iter <= arena.size())
	{
		if (CanCastBuff(deciding_unit, arena[i], magic_to_spell))
			return arena[i];
		else if (CanCastDebuff(deciding_unit, arena[i], magic_to_spell))
			return arena[i];
		i++;
		if (i >= arena.size())
			i = 0;
		iter++;
	}
}

UnitPtr ComputerDecision::FindUnitToSmash(const UnitPtr& attacker)const
{
	for (size_t i = 0; i < arena.size(); i++)
		if (CanSmash(attacker, arena[i]) 
			&& !SameUnit(attacker, arena[i]))
			return arena[i];
	return nullptr;
}

bool ComputerDecision::CanSmash(const UnitPtr& attacker, const UnitPtr& unit)const
{
	return unit->health <= unit->AbsorbCalc(attacker->damage.Value());
}

UnitPtr ComputerDecision::ChooseRandomUnit(const UnitPtr& attacker)const
{
	UnitPtr unit_to_attack = arena[std::rand() % arena.size()];
	while (SameUnit(attacker, unit_to_attack))
		unit_to_attack = arena[RandInd(arena.size() - 1)];
	return unit_to_attack;
}

bool ComputerDecision::CanCastBuff(const UnitPtr& caster, const UnitPtr& aim,
	const MagicPtr& spell)const
{
	return spell->IsBuff() && SameUnit(caster, aim)
		&& !caster->on_me.HaveSpell(spell);
}

bool ComputerDecision::CanCastDebuff(const UnitPtr& caster, const UnitPtr& aim,
	const MagicPtr& spell)const
{
	return !spell->IsBuff() && !SameUnit(caster, aim)
		&& !aim->on_me.HaveSpell(spell);
}