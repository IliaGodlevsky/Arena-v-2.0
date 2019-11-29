#include <iostream>
#include <typeinfo>

#include "Magic.h"
#include "Arena.h"
#include "State.h"

#define SHOW_DATA	Magic::Data(); Data();
#define CHARM_UNIT	PutOn(unit); Magic::Effect(unit);



Magic::Magic(std::string name, int mana_cost, int duration)
	: name(name), mana_cost(mana_cost), durationmeter(duration)
{

}

Magic::~Magic() {}

void Magic::Effect(Unit& unit)
{
	SetStartTime(Arena::CurrentRound());
	unit.on_me.TakeSpell(Clone());
}

bool Magic::IsExpired(int round)const
{
	return durationmeter.IsExpired(round);
}

void Magic::SetStartTime(int round)
{
	durationmeter.SetStartTime(round);
}

bool Magic::EnoughMana(int current_mana)const
{
	return current_mana >= mana_cost;
}

bool Magic::Equal(const MagicPtr& magic)const
{
	return name == magic->name
		&& mana_cost == magic->mana_cost
		&& durationmeter == magic->durationmeter;
}

int Magic::Cost()const
{
	return mana_cost;
}

void Magic::Data()const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Mana cost: " << mana_cost << std::endl;
	std::cout << "Duration: " << durationmeter << std::endl;
}

void Magic::ShowFullInfo()const
{
	Data();
}

void Magic::ShowShortInfo()const
{
	std::cout << "<" << name << " : " << mana_cost << ">";
}



DamageBuff::DamageBuff(std::string name, int mana_cost,
	int duration, int damage_amplify)
	: Magic(name, mana_cost, duration),
	damage_amplify(damage_amplify)
{

}

void DamageBuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void DamageBuff::Uneffect(Unit& unit)const
{
	unit.damage.ChangeValue(-damage_amplify);
}

MagicPtr DamageBuff::Clone()const
{
	return MagicPtr(new DamageBuff(name, mana_cost, durationmeter, damage_amplify));
}

void DamageBuff::PutOn(Unit& unit)const
{
	unit.damage.ChangeValue(damage_amplify);
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

void DamageBuff::Data()const
{
	std::cout << "Damage add: " << damage_amplify << std::endl;
}

void DamageBuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}


ArmorBuff::ArmorBuff(std::string name, int mana_cost,
	int duration, int armor_amplify)
	: Magic(name, mana_cost, duration),
	armor_amplify(armor_amplify)
{

}

void ArmorBuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void ArmorBuff::Uneffect(Unit& unit)const
{
	unit.armor.ChangeValue(-armor_amplify);
}

MagicPtr ArmorBuff::Clone()const
{
	return MagicPtr(new ArmorBuff(name, mana_cost, durationmeter, armor_amplify));
}

void ArmorBuff::PutOn(Unit& unit)const
{
	unit.armor.ChangeValue(armor_amplify);
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

void ArmorBuff::Data()const
{
	std::cout << "Armor add: " << armor_amplify << std::endl;
}

void ArmorBuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}




ArmorAndDamageBuff::ArmorAndDamageBuff(std::string name,
	int mana_cost, int duration, int armor_amplify,
	int damage_amplify)
	: Magic(name, mana_cost, duration),
	ArmorBuff(name, mana_cost, duration, armor_amplify),
	DamageBuff(name, mana_cost, duration,damage_amplify)
{

}

void ArmorAndDamageBuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void ArmorAndDamageBuff::Uneffect(Unit& unit)const 
{
	DamageBuff::Uneffect(unit);
	ArmorBuff::Uneffect(unit);
}

MagicPtr ArmorAndDamageBuff::Clone()const
{
	return MagicPtr(new ArmorAndDamageBuff(name, mana_cost, durationmeter, 
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

void ArmorAndDamageBuff::PutOn(Unit& unit)const
{
	DamageBuff::PutOn(unit);
	ArmorBuff::PutOn(unit);
}

void ArmorAndDamageBuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void ArmorAndDamageBuff::Data()const
{
	ArmorBuff::Data();
	DamageBuff::Data();
}




DamageDebuff::DamageDebuff(std::string name,
	int mana_cost, int duration, int damage_reduce)
	: Magic(name, mana_cost, duration), damage_reduce(damage_reduce)
{

}

void DamageDebuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void DamageDebuff::Uneffect(Unit& unit)const
{
	unit.damage.ChangeValue(damage_reduce);
}

MagicPtr DamageDebuff::Clone()const
{
	return MagicPtr(new DamageDebuff(name, mana_cost, durationmeter, damage_reduce));
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

void DamageDebuff::PutOn(Unit& unit)const
{
	unit.damage.ChangeValue(-damage_reduce);
}

void DamageDebuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void DamageDebuff::Data()const
{
	std::cout << "Damage reduce: " << damage_reduce << std::endl;
}





ArmorDebuff::ArmorDebuff(std::string name, int mana_cost,
	int duration, int armor_reduce)
	: Magic(name, mana_cost, duration), armor_reduce(armor_reduce)
{

}

void ArmorDebuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void ArmorDebuff::Uneffect(Unit& unit)const
{
	unit.armor.ChangeValue(armor_reduce);
}

MagicPtr ArmorDebuff::Clone()const
{
	return MagicPtr(new ArmorDebuff(name, mana_cost, 
		durationmeter, armor_reduce));
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

void ArmorDebuff::PutOn(Unit& unit)const
{
	unit.armor.ChangeValue(-armor_reduce);
}

void ArmorDebuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void ArmorDebuff::Data()const
{
	std::cout << "Armor reduce: " << armor_reduce << std::endl;
}





ArmorAndDamageDebuff::ArmorAndDamageDebuff(std::string name,
	int mana_cost, int duration, int armor_reduce, int damage_reduce)
	: Magic(name, mana_cost, duration),
	ArmorDebuff(name, mana_cost, duration, armor_reduce),
	DamageDebuff(name, mana_cost, duration, damage_reduce)
{

}

void ArmorAndDamageDebuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void ArmorAndDamageDebuff::Uneffect(Unit& unit)const
{
	DamageDebuff::Uneffect(unit);
	ArmorDebuff::Uneffect(unit);
}

MagicPtr ArmorAndDamageDebuff::Clone()const
{
	return MagicPtr(new ArmorAndDamageDebuff(name, mana_cost, 
		durationmeter, armor_reduce, damage_reduce));
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

void ArmorAndDamageDebuff::PutOn(Unit& unit)const
{
	DamageDebuff::PutOn(unit);
	ArmorDebuff::PutOn(unit);
}

void ArmorAndDamageDebuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void ArmorAndDamageDebuff::Data()const
{
	ArmorDebuff::Data();
	DamageDebuff::Data();
}



OffsetDamageBuff::OffsetDamageBuff(std::string name, int mana_cost,
	int duration, int armor_reduce, int damage_amplify)
	: Magic(name, mana_cost, duration),
	DamageBuff(name, mana_cost, duration, damage_amplify),
	ArmorDebuff(name, mana_cost, duration, armor_reduce)
{

}

void OffsetDamageBuff::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void OffsetDamageBuff::Uneffect(Unit& unit)const
{
	DamageBuff::Uneffect(unit);
	ArmorDebuff::Uneffect(unit);
}

MagicPtr OffsetDamageBuff::Clone()const
{
	return MagicPtr(new OffsetDamageBuff(name, mana_cost, durationmeter, 
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

void OffsetDamageBuff::PutOn(Unit& unit)const
{
	DamageBuff::PutOn(unit);
	ArmorDebuff::PutOn(unit);
}

void OffsetDamageBuff::ShowFullInfo()const
{
	Magic::Data();
	Data();
}


void OffsetDamageBuff::Data()const
{
	DamageBuff::Data();
	ArmorDebuff::Data();
}




Attack::Attack(std::string name, int mana_cost, int damage)
	: Magic(name, mana_cost, 0), damage(damage)
{

}

void Attack::Effect(Unit& unit)
{
	unit.health = unit.health - damage;
}

void Attack::Uneffect(Unit& unit)const
{
	return;
}

MagicPtr Attack::Clone()const
{
	return MagicPtr(new Attack(name, mana_cost, damage));
}

bool Attack::IsBuff()const
{
	return false;
}

bool Attack::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		Attack* temp = dynamic_cast<Attack*>(magic.get());
		return Magic::Equal(magic) && damage == temp->damage;
	}
	return false;
}

void Attack::PutOn(Unit& unit)const
{
	return;
}

void Attack::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void Attack::Data()const
{
	std::cout << "Deals " << damage << std::endl;
}





Poison::Poison(std::string name, int mana_cost, int duration,
	int regen_reduce)
	: Magic(name, mana_cost, duration), regen_reduce(regen_reduce)
{

}

void Poison::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void Poison::Uneffect(Unit& unit)const
{
	unit.health.ChangeRegeneration(regen_reduce);
}

MagicPtr Poison::Clone()const
{
	return MagicPtr(new Poison(name, mana_cost, durationmeter, regen_reduce));
}

bool Poison::IsBuff()const
{
	return false;
}

bool Poison::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		Poison* temp = dynamic_cast<Poison*>(magic.get());
		return Magic::Equal(magic) && regen_reduce == temp->regen_reduce;
	}
	return false;
}

void Poison::PutOn(Unit& unit)const
{
	unit.health.ChangeRegeneration(-regen_reduce);
}

void Poison::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void Poison::Data()const
{
	std::cout << "Deals " << regen_reduce << " per round\n";
}




PoisonAndAttack::PoisonAndAttack(std::string name, int mana_cost,
	int duration, int damage, int regen_reduce)
	: Magic(name, mana_cost, duration),
	Poison(name, mana_cost, duration, regen_reduce),
	Attack(name, mana_cost, damage)
{

}

void PoisonAndAttack::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
}

void PoisonAndAttack::Uneffect(Unit& unit)const
{
	Poison::Uneffect(unit);
	Attack::Uneffect(unit);
}

MagicPtr PoisonAndAttack::Clone()const
{
	return MagicPtr(new PoisonAndAttack(name, mana_cost, 
		durationmeter, damage, regen_reduce));
}

bool PoisonAndAttack::IsBuff()const
{
	return false;
}

bool PoisonAndAttack::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
	{
		PoisonAndAttack* temp = dynamic_cast<PoisonAndAttack*>(magic.get());
		return Magic::Equal(magic) && regen_reduce == temp->regen_reduce
			&& damage == temp->damage;
	}
	return false;
}

void PoisonAndAttack::PutOn(Unit& unit)const
{
	Attack::PutOn(unit);
	Poison::PutOn(unit);
}

void PoisonAndAttack::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void PoisonAndAttack::Data()const
{
	Attack::Data();
	Poison::Data();
}



Silence::Silence(std::string name, int mana_cost,
	int duration)
	: Magic(name, mana_cost, duration)
{

}

void Silence::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
	unit.RecieveNewState(new MutedState(durationmeter));
}

void Silence::Uneffect(Unit& unit)const
{
	return;
}

MagicPtr Silence::Clone()const
{
	return MagicPtr(new Silence(name, mana_cost, durationmeter));
}

bool Silence::IsBuff()const
{
	return false;
}

bool Silence::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
		return Magic::Equal(magic);
	return false;
}

void Silence::PutOn(Unit& unit)const
{
	return;
}

void Silence::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void Silence::Data()const
{
	std::cout << "Enemy can't cast spells\n";
}


Dispel::Dispel(std::string name, int mana_cost)
	: Magic(name, mana_cost, 0)
{

}

void Dispel::Effect(Unit& unit)
{
	unit.on_me.ExpireAllSpells();
}

void Dispel::Uneffect(Unit& unit)const
{
	return;
}

MagicPtr Dispel::Clone()const
{
	return MagicPtr(new Dispel(name, mana_cost));
}

bool Dispel::IsBuff()const
{
	return false;
}

bool Dispel::Equal(const MagicPtr& magic)const
{

}

void Dispel::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void Dispel::Data()const
{
	std::cout << "Dispels all spells on unit\n";
}

void Dispel::PutOn(Unit& unit)const
{
	return;
}
