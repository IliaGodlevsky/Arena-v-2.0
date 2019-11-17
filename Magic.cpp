#include "Magic.h"
#include "Arena.h"

Magic::Magic(std::string name,
	int mana_cost, int duration)
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





DamageBuff::DamageBuff(std::string name, int mana_cost,
	int duration, int damage_amplify)
	: Magic(name, mana_cost, duration),
	damage_amplify(damage_amplify)
{

}

void DamageBuff::Effect(Unit* unit)
{
	PutOn(unit);
	SetStartTime(Arena::CurrentRound());
	unit->on_me.AddMagic(std::unique_ptr<DamageBuff>(Clone()));
}

void DamageBuff::Uneffect(Unit* unit)const
{
	unit->damage.ChangeValue(-damage_amplify);
}

DamageBuff* DamageBuff::Clone()const
{
	return new DamageBuff(name, mana_cost, duration, damage_amplify);
}

void DamageBuff::PutOn(Unit* unit)const
{
	unit->damage.ChangeValue(damage_amplify);
}




ArmorBuff::ArmorBuff(std::string name, int mana_cost,
	int duration, int armor_amplify)
	: Magic(name, mana_cost, duration),
	armor_amplify(armor_amplify)
{

}

void ArmorBuff::Effect(Unit* unit)
{
	PutOn(unit);
	SetStartTime(Arena::CurrentRound());
	unit->on_me.AddMagic(spell_ptr<ArmorBuff>(Clone()));
}

void ArmorBuff::Uneffect(Unit* unit)const
{
	unit->armor.ChangeValue(-armor_amplify);
}

ArmorBuff* ArmorBuff::Clone()const
{
	return new ArmorBuff(name, mana_cost, duration, armor_amplify);
}

void ArmorBuff::PutOn(Unit* unit)const
{
	unit->armor.ChangeValue(armor_amplify);
}



ArmorAndDamageBuff::ArmorAndDamageBuff(std::string name,
	int mana_cost, int duration, int armor_amplify,
	int damage_amplify)
	: Magic(name, mana_cost, duration),
	ArmorBuff(name, mana_cost, duration, armor_amplify),
	DamageBuff(name, mana_cost, duration,damage_amplify)
{

}

void ArmorAndDamageBuff::Effect(Unit* unit)
{
	DamageBuff::PutOn(unit);
	ArmorBuff::PutOn(unit);
	SetStartTime(Arena::CurrentRound());
	unit->on_me.AddMagic(spell_ptr< ArmorAndDamageBuff>(Clone()));
}

void ArmorAndDamageBuff::Uneffect(Unit* unit)const 
{
	DamageBuff::Uneffect(unit);
	ArmorBuff::Uneffect(unit);
}

ArmorAndDamageBuff* ArmorAndDamageBuff::Clone()const
{
	return new ArmorAndDamageBuff(name, mana_cost, duration, 
		armor_amplify, damage_amplify);
}



void SpellBook::AddMagic(spell_ptr<Magic> magic)
{
	spells.push_back(magic);
}

const spell_ptr<Magic>& SpellBook::operator[](int i)const
{
	return spells[i];
}

spell_ptr<Magic>& SpellBook::operator[](int i)
{
	return spells[i];
}

SpellsOnMe::SpellsOnMe(Unit* unit)
{
	this->unit = unit;
}

void SpellsOnMe::AddMagic(spell_ptr<Magic> magic)
{
	spells.push_back(magic);
}

void SpellsOnMe::TakeOfExpired(int round)
{
	for (size_t i = 0; i < spells.size(); i++)
	{
		if (spells[i]->IsExpired(round))
		{
			spells[i]->Uneffect(unit);
			spells.erase(spells.begin() + i);
		}
	}
}