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

void Degenerate::Effect(Unit* unit)
{
	if (IsCasted())
	{
		SetStartTime(Arena::CurrentRound());
		unit->health.ChangeRegeneration(-degeneration);
		unit->on_me.AddMagic(spell_ptr<Degenerate>(Clone()));
	}
}

void Degenerate::Uneffect(Unit* unit)const
{
	unit->health.ChangeRegeneration(degeneration);
}

Degenerate* Degenerate::Clone()const
{
	return new Degenerate(name, duration, degeneration, propability);
}



Crush::Crush(std::string name, int damage,
	int propability)
	: WeaponMagic(name, 0, propability), damage(damage)
{

}

void Crush::Effect(Unit* unit)
{
	if (IsCasted())
		unit->health = unit->health - damage;
}

void Crush::Uneffect(Unit* unit)const
{
	return;
}

Crush* Crush::Clone()const
{
	return new Crush(name, damage, propability);
}