#include <random>

#include "WeaponMagic.h"
#include "Arena.h"

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
		PutOn(unit);
		Magic::Effect(unit);
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

bool Degenerate::IsBuff()const
{
	return false;
}

void Degenerate::PutOn(UnitPtr unit)const
{
	unit->health.ChangeRegeneration(-degeneration);
}

bool Degenerate::Equal(const MagicPtr& magic)const
{
	try
	{
		Degenerate& temp = dynamic_cast<Degenerate&>(*magic);
		return Magic::Equal(magic)
			&& degeneration == temp.degeneration;
	}
	catch (std::bad_cast& cast) { return false; }
}



Crush::Crush(std::string name, int damage,
	int propability)
	: WeaponMagic(name, 0, propability), damage(damage)
{
	
}

void Crush::Effect(UnitPtr unit)
{
	if (IsCasted())
		PutOn(unit);
}

void Crush::Uneffect(UnitPtr unit)const
{
	return;
}

MagicPtr Crush::Clone()const
{
	return MagicPtr(new Crush(name, damage, propability));
}

bool Crush::IsBuff()const
{
	return false;
}

void Crush::PutOn(UnitPtr unit)const
{
	unit->health = unit->health - damage;
}

bool Crush::Equal(const MagicPtr& magic)const
{
	try
	{
		Crush& temp = dynamic_cast<Crush&>(*magic);
		return Magic::Equal(magic)
			&& damage == temp.damage;
	}
	catch (std::bad_cast& cast) { return false; }
}