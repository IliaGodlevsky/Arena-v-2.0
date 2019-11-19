#include "WeaponMagic.h"
#include "Arena.h"

#include <random>

WeaponMagic::WeaponMagic(std::string name, int duration, int propability)
	: Magic(name, 0, duration), propability(propability)
{

}

WeaponMagic::~WeaponMagic() {}

bool WeaponMagic::IsCasted()const
{
	const int MAX_PROPABILITY = 100;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, MAX_PROPABILITY);
	int currentChance = distribution(generator);

	return currentChance <= propability;
}

bool operator==(const WeaponMagic& first, const WeaponMagic& second)
{
	return (const Magic&)first == (const Magic&)second
		&& first.propability == second.propability;
}

bool operator!=(const WeaponMagic& first, const WeaponMagic& second)
{
	return !(first == second);
}

Degenerate::Degenerate(std::string name, int duration,
	int degeneration, int propability)
	: WeaponMagic(name, duration, propability),
	degeneration(degeneration)
{

}

void Degenerate::Effect(UnitPtr unit)
{
	if (IsCasted())
	{
		SetStartTime(Arena::CurrentRound());
		unit->health.ChangeRegeneration(-degeneration);
		unit->on_me.push_back(MagicPtr(Clone()));
	}
}

void Degenerate::Uneffect(UnitPtr unit)const
{
	unit->health.ChangeRegeneration(degeneration);
}

MagicPtr Degenerate::Clone()const
{
	return MagicPtr(new Degenerate(name, duration, degeneration, propability));
}

bool operator==(const Degenerate& first, const Degenerate& second)
{
	return (const WeaponMagic&)first == (const WeaponMagic&)second
		&& first.degeneration == second.degeneration;
}

bool operator!=(const Degenerate& first, const Degenerate& second)
{
	return !(first == second);
}



Crush::Crush(std::string name, int damage,
	int propability)
	: WeaponMagic(name, 0, propability), damage(damage)
{
	
}

void Crush::Effect(UnitPtr unit)
{
	if (IsCasted())
		unit->health = unit->health - damage;
}

void Crush::Uneffect(UnitPtr unit)const
{
	return;
}

MagicPtr Crush::Clone()const
{
	return MagicPtr(new Crush(name, damage, propability));
}

bool operator==(const Crush& first, const Crush& second)
{
	return (const WeaponMagic&)first == (const WeaponMagic&)second
		&& first.damage == second.damage;
}

bool operator!=(const Crush& first, const Crush& second)
{
	return false;
}