#include <random>

#include "WeaponMagic.h"
#include "Arena.h"

WeaponMagic::WeaponMagic(std::string name,
	int duration, int propability = 20)
	: Magic(name, 0, duration), propability(propability)
{

}

WeaponMagic::~WeaponMagic() {}

bool WeaponMagic::IsCasted()const
{
	const int MAX_PROPABILITY = 100;
	std::random_device seed();
	std::mt19937 engine(seed);
	std::uniform_int_distribution<int> rand(0, MAX_PROPABILITY);
	return rand(engine) <= propability;
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