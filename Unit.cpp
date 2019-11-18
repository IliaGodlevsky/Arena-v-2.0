#include <cmath>

#include "Unit.h"

bool Unit::Injure(UnitPtr unit)
{
	if (weapon == nullptr)
		return false;
	weapon->Injure(unit, damage.Value());
	return true;
}

bool Unit::Spell(UnitPtr unit, MagicPtr<>& magic)
{
	if (magic == nullptr)
		return false;
	magic->Effect(unit);
	return true;
}

void Unit::Act(Decision* decision)
{
	Unit* unit_to_attack = decision->ChooseUnitToAttack(this);
	Magic* magic_to_spell = decision->ChooseMagicToCast(this);
	Unit* unit_to_cast = decision->ChooseUnitToCast(this);
	Spell(unit_to_cast, magic_to_spell);
	Injure(unit_to_attack);
}

void Unit::TakeDamage(int damage)
{
	health = health - AbsorbCalc(damage);
}

int Unit::AbsorbCalc(int damage)const
{
	// The formula is taken from WarCraft 3
	const double REDUCE_CONST = 0.06;
	const double numerator = static_cast<double>(armor.Value()) * REDUCE_CONST;
	double percent_of_reduce = numerator / (1.0 + numerator);
	return static_cast<int>(std::ceil(damage * (1.0 - percent_of_reduce)));
}