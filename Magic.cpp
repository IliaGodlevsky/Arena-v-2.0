#include "Magic.h"
#include "Arena.h"

Magic::Magic(std::string name, int mana_cost, int duration)
	: name(name),mana_cost(mana_cost), duration(duration)
{

}

Magic::~Magic() {}

bool Magic::IsExpired(int round)const
{
	return round - start_time == duration;
}

void Magic::SetStartTime(int round)
{
	start_time = round;
}

bool Magic::EnoughMana(int current_mana)const
{
	return current_mana >= mana_cost;
}

std::string Magic::ShowName()const
{
	return name;
}

bool operator==(const Magic& first, const Magic& second)
{
	const bool equal_name = first.name == second.name;
	const bool equal_mana_cost = first.mana_cost == second.mana_cost;
	const bool equal_duration = first.duration == second.duration;
	return equal_name && equal_mana_cost && equal_duration;
}

bool operator!=(const Magic& first, const Magic& second)
{
	return !(first == second);
}





DamageBuff::DamageBuff(std::string name, int mana_cost,
	int duration, int damage_amplify)
	: Magic(name, mana_cost, duration),
	damage_amplify(damage_amplify)
{

}

void DamageBuff::Effect(UnitPtr unit)
{
	PutOn(unit);
	SetStartTime(Arena::CurrentRound());
	unit->on_me.push_back(MagicPtr(Clone()));
}

void DamageBuff::Uneffect(UnitPtr unit)const
{
	unit->damage.ChangeValue(-damage_amplify);
}

MagicPtr DamageBuff::Clone()const
{
	return MagicPtr(new DamageBuff(name, mana_cost, duration, damage_amplify));
}

void DamageBuff::PutOn(UnitPtr unit)const
{
	unit->damage.ChangeValue(damage_amplify);
}

bool operator==(const DamageBuff& first, const DamageBuff& second)
{
	return (const Magic&)first == (const Magic&)second
		&& first.damage_amplify == second.damage_amplify;
}

bool operator!=(const DamageBuff& first, const DamageBuff& second)
{
	return !(first == second);
}




ArmorBuff::ArmorBuff(std::string name, int mana_cost,
	int duration, int armor_amplify)
	: Magic(name, mana_cost, duration),
	armor_amplify(armor_amplify)
{

}

void ArmorBuff::Effect(UnitPtr unit)
{
	PutOn(unit);
	SetStartTime(Arena::CurrentRound());
	unit->on_me.push_back(MagicPtr(Clone()));
}

void ArmorBuff::Uneffect(UnitPtr unit)const
{
	unit->armor.ChangeValue(-armor_amplify);
}

MagicPtr ArmorBuff::Clone()const
{
	return MagicPtr(new ArmorBuff(name, mana_cost, duration, armor_amplify));
}

void ArmorBuff::PutOn(UnitPtr unit)const
{
	unit->armor.ChangeValue(armor_amplify);
}

bool operator==(const ArmorBuff& first, const ArmorBuff& second)
{
	return (const Magic&)first == (const Magic&)second
		&& first.armor_amplify == second.armor_amplify;
}

bool operator!=(const ArmorBuff& first, const ArmorBuff& second)
{
	return !(first == second);
}


ArmorAndDamageBuff::ArmorAndDamageBuff(std::string name,
	int mana_cost, int duration, int armor_amplify,
	int damage_amplify)
	: Magic(name, mana_cost, duration),
	ArmorBuff(name, mana_cost, duration, armor_amplify),
	DamageBuff(name, mana_cost, duration,damage_amplify)
{

}

void ArmorAndDamageBuff::Effect(UnitPtr unit)
{
	DamageBuff::PutOn(unit);
	ArmorBuff::PutOn(unit);
	SetStartTime(Arena::CurrentRound());
	unit->on_me.push_back(MagicPtr(Clone()));
}

void ArmorAndDamageBuff::Uneffect(UnitPtr unit)const 
{
	DamageBuff::Uneffect(unit);
	ArmorBuff::Uneffect(unit);
}

MagicPtr ArmorAndDamageBuff::Clone()const
{
	return MagicPtr(new ArmorAndDamageBuff(name, mana_cost, duration, 
		armor_amplify, damage_amplify));
}

bool operator==(const ArmorAndDamageBuff& first, const ArmorAndDamageBuff& second)
{
	return (const ArmorBuff&)first == (const ArmorBuff&)second
		&& (const DamageBuff&)first == (const DamageBuff&)second;
}

bool operator!=(const ArmorAndDamageBuff& first, const ArmorAndDamageBuff& second)
{
	return !(first == second);
}



SpellsOnMe::SpellsOnMe(UnitPtr unit)
{
	this->unit = unit;
}

void SpellsOnMe::TakeOfExpired(int round)
{
	for (size_t i = 0; i < size(); i++)
	{
		if (operator[](i)->IsExpired(round))
		{
			operator[](i)->Uneffect(unit);
			erase(begin() + i);
		}
	}
}

bool SpellsOnMe::HaveSpell(const MagicPtr& spell)const
{
	for (size_t i = 0; i < size(); i++)
		if (*operator[](i) == *spell)
			return true;
	return false;
}