#include <cmath>
#include <iostream>

#include "Unit.h"
#include "Arena.h"

Unit::Unit(std::string name, Decision* decision)
	: damage(0), 
	armor(0),
	spell_book(this), 
	name(name),
	level(this),
	on_me(this), 
	decision(decision)
{

}

const std::string& Unit::Name()const
{
	return name;
}

void Unit::LevelUp()
{
	level++;
}

bool Unit::IsAlive()const
{
	return health > 0;
}

void Unit::RecieveNewState(UnitState* state)
{
	state->RecieveDecision(decision);
	this->state.RecieveNewState(state);
}

void Unit::Scan()
{
	health++;
	mana++;
	on_me.TakeOfExpired(Arena::currentRound());
	state.TakeOfExpired(Arena::currentRound());
}

bool Unit::EnoughManaFor(const MagicPtr& magic)const
{
	return mana >= magic->Cost();
}

void Unit::PayMana(int mana_cost)
{
	mana = mana - mana_cost;
}


bool Unit::Injure(Unit& unit)
{
	if (nullptr == weapon)
		return false;
	weapon->Injure(unit, damage);
	return true;
}

bool Unit::Spell(Unit& unit, MagicPtr& magic)
{
	if (nullptr == magic || !EnoughManaFor(magic))
		return false;
	magic->Effect(unit);
	PayMana(magic->Cost());
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
	const double numerator = static_cast<double>(armor * REDUCE_CONST);
	double percent_of_reduce = numerator / (1.0 + numerator);
	return static_cast<int>(std::ceil(damage * (1.0 - percent_of_reduce)));
}

Unit* Unit::ChooseUnitToAttack()const
{
	return state.ChooseUnitToAttack(*this);
}

MagicPtr Unit::ChooseMagicToCast()const
{
	return state.ChooseMagicToCast(*this);
}

Unit* Unit::ChooseUnitToCast(const MagicPtr& magic_to_spell)const
{
	return state.ChooseUnitToCast(*this, magic_to_spell);
}

void Unit::ShowFullInfo()const
{
	// must be code here!!
}

Unit::~Unit()
{
	delete decision;
}