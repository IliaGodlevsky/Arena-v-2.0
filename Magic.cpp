#include <iostream>

#include "Magic.h"
#include "Arena.h"

Magic::Magic(std::string name, int mana_cost, int duration)
	: name(name),mana_cost(mana_cost), duration(duration)
{

}

Magic::~Magic() {}

void Magic::Effect(UnitPtr unit)
{
	SetStartTime(Arena::CurrentRound());
}

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

void Magic::ShowMagic()const
{
	std::cout << "<" << name << ": " << mana_cost << ">\n";
}

bool Magic::Equal(const MagicPtr& magic)const
{
	return name == magic->name
		&& mana_cost == magic->mana_cost
		&& duration == magic->duration;
}

int Magic::Cost()const
{
	return mana_cost;
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
	Magic::Effect(unit);
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

bool DamageBuff::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		DamageBuff* temp = dynamic_cast<DamageBuff*>(magic.get());
		return Magic::Equal(magic) && damage_amplify == temp->damage_amplify;
	}
	return false;
}

bool DamageBuff::IsBuff()const
{
	return true;
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
	Magic::Effect(unit);
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

bool ArmorBuff::IsBuff()const
{
	return true;
}

bool ArmorBuff::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		ArmorBuff* temp = dynamic_cast<ArmorBuff*>(magic.get());
		return Magic::Equal(magic) && armor_amplify == temp->armor_amplify;
	}
	return false;
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
	PutOn(unit);
	Magic::Effect(unit);
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

bool ArmorAndDamageBuff::IsBuff()const
{
	return true;
}

bool ArmorAndDamageBuff::Equal(const MagicPtr& magic)const
{
	return DamageBuff::Equal(magic) && ArmorBuff::Equal(magic);
}

void ArmorAndDamageBuff::PutOn(UnitPtr unit)const
{
	DamageBuff::PutOn(unit);
	ArmorBuff::PutOn(unit);
}




DamageDebuff::DamageDebuff(std::string name,
	int mana_cost, int duration, int damage_reduce)
	: Magic(name, mana_cost, duration), damage_reduce(damage_reduce)
{

}

void DamageDebuff::Effect(UnitPtr unit)
{
	PutOn(unit);
	Magic::Effect(unit);
	unit->on_me.push_back(MagicPtr(Clone()));
}

void DamageDebuff::Uneffect(UnitPtr unit)const
{
	unit->damage.ChangeValue(damage_reduce);
}

MagicPtr DamageDebuff::Clone()const
{
	return MagicPtr(new DamageDebuff(name, mana_cost, duration, damage_reduce));
}

bool DamageDebuff::IsBuff()const
{
	return false;
}

bool DamageDebuff::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		DamageDebuff* temp = dynamic_cast<DamageDebuff*>(magic.get());
		return Magic::Equal(magic) && damage_reduce == temp->damage_reduce;
	}
	return false;
}

void DamageDebuff::PutOn(UnitPtr unit)const
{
	unit->damage.ChangeValue(-damage_reduce);
}





ArmorDebuff::ArmorDebuff(std::string name, int mana_cost,
	int duration, int armor_reduce)
	: Magic(name, mana_cost, duration), armor_reduce(armor_reduce)
{

}

void ArmorDebuff::Effect(UnitPtr unit)
{
	PutOn(unit);
	Magic::Effect(unit);
	unit->on_me.push_back(MagicPtr(Clone()));
}

void ArmorDebuff::Uneffect(UnitPtr unit)const
{
	unit->armor.ChangeValue(armor_reduce);
}

MagicPtr ArmorDebuff::Clone()const
{
	return MagicPtr(new ArmorDebuff(name, mana_cost, 
		duration, armor_reduce));
}

bool ArmorDebuff::IsBuff()const
{
	return false;
}

bool ArmorDebuff::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		ArmorDebuff* temp = dynamic_cast<ArmorDebuff*>(magic.get());
		return Magic::Equal(magic) && armor_reduce == temp->armor_reduce;
	}
	return false;
}

void ArmorDebuff::PutOn(UnitPtr unit)const
{
	unit->armor.ChangeValue(-armor_reduce);
}


ArmorAndDamageDebuff::ArmorAndDamageDebuff(std::string name,
	int mana_cost, int duration, int armor_reduce, int damage_reduce)
	: Magic(name, mana_cost, duration),
	ArmorDebuff(name, mana_cost, duration, armor_reduce),
	DamageDebuff(name, mana_cost, duration, damage_reduce)
{

}

void ArmorAndDamageDebuff::Effect(UnitPtr unit)
{
	PutOn(unit);
	Magic::Effect(unit);
	unit->on_me.push_back(MagicPtr(Clone()));
}

void ArmorAndDamageDebuff::Uneffect(UnitPtr unit)const
{
	DamageDebuff::Uneffect(unit);
	ArmorDebuff::Uneffect(unit);
}

MagicPtr ArmorAndDamageDebuff::Clone()const
{
	return MagicPtr(new ArmorAndDamageDebuff(name, mana_cost, 
		duration, armor_reduce, damage_reduce));
}
bool ArmorAndDamageDebuff::IsBuff()const
{
	return false;
}

bool ArmorAndDamageDebuff::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		ArmorAndDamageDebuff* temp = 
			dynamic_cast<ArmorAndDamageDebuff*>(magic.get());
		return Magic::Equal(magic) && armor_reduce == temp->armor_reduce
			&& damage_reduce == temp->damage_reduce;
	}
	return false;
}

void ArmorAndDamageDebuff::PutOn(UnitPtr unit)const
{
	DamageDebuff::PutOn(unit);
	ArmorDebuff::PutOn(unit);
}



OffsetDamageBuff::OffsetDamageBuff(std::string name, int mana_cost,
	int duration, int armor_reduce, int damage_amplify)
	: Magic(name, mana_cost, duration),
	DamageBuff(name, mana_cost, duration, damage_amplify),
	ArmorDebuff(name, mana_cost, duration, armor_reduce)
{

}

void OffsetDamageBuff::Effect(UnitPtr unit)
{
	PutOn(unit);
	Magic::Effect(unit);
	unit->on_me.push_back(MagicPtr(Clone()));
}

void OffsetDamageBuff::Uneffect(UnitPtr unit)const
{
	DamageBuff::Uneffect(unit);
	ArmorDebuff::Uneffect(unit);
}

MagicPtr OffsetDamageBuff::Clone()const
{
	return MagicPtr(new OffsetDamageBuff(name, mana_cost, duration, 
		armor_reduce, damage_amplify));
}

bool OffsetDamageBuff::IsBuff()const
{
	return true;
}

bool OffsetDamageBuff::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		OffsetDamageBuff* temp =
			dynamic_cast<OffsetDamageBuff*>(magic.get());
		return Magic::Equal(magic) && armor_reduce == temp->armor_reduce
			&& damage_amplify == temp->damage_amplify;
	}
	return false;
}

void OffsetDamageBuff::PutOn(UnitPtr unit)const
{
	DamageBuff::PutOn(unit);
	ArmorDebuff::PutOn(unit);
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
			i--;
		}
	}
}

bool SpellsOnMe::HaveSpell(const MagicPtr& spell)const
{
	for (size_t i = 0; i < size(); i++)
		if (operator[](i)->Equal(spell))
			return true;
	return false;
}