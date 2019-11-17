#include <random>

#include "Weapon.h"

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
	return rand(engine) == propability;
}

Degenerate::Degenerate(std::string name, int duration,
	int degeneration, int propability)
	: WeaponMagic(name, duration, propability),
	degeneration(degeneration)
{

}
void Degenerate::Effect(Unit* unit)const
{
	if (IsCasted())
		unit->health.ChangeRegeneration(-degeneration);
}
void Degenerate::Uneffect(Unit* unit)const
{
	unit->health.ChangeRegeneration(degeneration);
}
Degenerate* Degenerate::Clone()const
{

}