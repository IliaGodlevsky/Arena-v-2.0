#include <cmath>

#include "Unit.h"
#include "Arena.h"

bool Unit::Injure(UnitPtr unit)
{
	if (nullptr == weapon)
		return false;
	weapon->Injure(unit, damage.Value());
	return true;
}

bool Unit::Spell(UnitPtr unit, MagicPtr& magic)
{
	if (nullptr == magic)
		return false;
	magic->Effect(unit);
	mana = mana - magic->Cost();
	return true;
}

void Unit::Act(Decision* decision)
{
	UnitPtr unit_to_attack = decision->ChooseUnitToAttack(UnitPtr(this));
	MagicPtr magic_to_cast = decision->ChooseMagicToCast(UnitPtr(this));
	UnitPtr unit_to_cast = decision->ChooseUnitToCast(UnitPtr(this), magic_to_cast);

}

void Unit::TakeDamage(int damage)
{
	if (!sheild->Reflect())
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