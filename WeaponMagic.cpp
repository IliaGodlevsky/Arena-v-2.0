#include <random>
#include <iostream>

#include "WeaponMagic.h"
#include "Arena.h"

int randomNumber(int maxRange, int minRange)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(minRange, maxRange);
	return distribution(generator);
}
WeaponMagic::WeaponMagic(std::string name, int duration, int propability)
	: Magic(name, 0, duration), propability(propability)
{

}

WeaponMagic::~WeaponMagic() {}

bool WeaponMagic::IsCasted()const
{
	const int MAX_PROPABILITY = 100;
	return randomNumber(MAX_PROPABILITY) <= propability;
}

void WeaponMagic::ShowFullInfo()const
{
	Data();
}

void WeaponMagic::Data()const
{
	
}


Degenerate::Degenerate(std::string name, int duration,
	int degeneration, int propability)
	: WeaponMagic(name, duration, propability),
	degeneration(degeneration)
{

}

void Degenerate::Effect(Unit& unit)
{
	if (IsCasted())
	{
		Magic::Effect(unit);
		PutOn(unit);
		unit.on_me.push_back(MagicPtr(Clone()));
	}
}

void Degenerate::Uneffect(Unit& unit)const
{
	unit.health.ChangeRegeneration(degeneration);
}

MagicPtr Degenerate::Clone()const
{
	return MagicPtr(new Degenerate(name, durationmeter, degeneration, propability));
}

bool Degenerate::IsBuff()const
{
	return false;
}

void Degenerate::PutOn(Unit& unit)const
{
	unit.health.ChangeRegeneration(-degeneration);
}

bool Degenerate::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		Degenerate* temp = dynamic_cast<Degenerate*>(magic.get());
		return Magic::Equal(magic) && degeneration == temp->degeneration;
	}
	return false;
}



Crush::Crush(std::string name, int damage,
	int propability)
	: WeaponMagic(name, 0, propability), damage(damage)
{
	
}

void Crush::Effect(Unit& unit)
{
	if (IsCasted())
		PutOn(unit);
}

void Crush::Uneffect(Unit& unit)const
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

void Crush::PutOn(Unit& unit)const
{
	unit.health = unit.health - damage;
}

bool Crush::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		Crush* temp = dynamic_cast<Crush*>(magic.get());
		return Magic::Equal(magic) && damage == temp->damage;
	}
	return false;
}