#include <cmath>
#include <iostream>

#include "Unit.h"
#include "Arena.h"

Unit::Unit()
	: on_me(*this)
{

}

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
	// TODO : if unit have this spell, this spell must be recasted
	magic->Effect(unit);
	mana = mana - magic->Cost();
	return true;
}

bool Unit::TakeDamage(int damage)
{
	if (!sheild->Reflect())
	{
		health = health - AbsorbCalc(damage);
		return true;
	}
	return false;
}

int Unit::AbsorbCalc(int damage)const
{
	// The formula is taken from WarCraft 3
	const double REDUCE_CONST = 0.06;
	const double numerator = static_cast<double>(armor.Value()) * REDUCE_CONST;
	double percent_of_reduce = numerator / (1.0 + numerator);
	return static_cast<int>(std::ceil(damage * (1.0 - percent_of_reduce)));
}