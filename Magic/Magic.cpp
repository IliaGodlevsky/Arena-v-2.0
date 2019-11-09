#include "Magic.h"

constexpr auto START_TIME = 0;

namespace Arena
{
	// MAGIC
	Magic::Magic(const std::string& name,
		int mana_cost, int duration)
		: mana_cost(mana_cost), name(name), 
		duration(duration), start_time(START_TIME)
	{

	}

	Magic::Magic(const Magic& magic)
	{
		mana_cost = magic.mana_cost;
		duration = magic.duration;
		start_time = magic.start_time;
	}

	Magic::Magic(Magic&& magic) : Magic(magic) {}

	Magic& Magic::operator=(const Magic& magic)
	{
		if (this == &magic)
			return *this;
		mana_cost = magic.mana_cost;
		duration = magic.duration;
		start_time = magic.start_time;
		return *this;
	}

	Magic& Magic::operator=(Magic&& magic)
	{
		return operator=(magic);
	}

	Magic::~Magic() {}

	void Magic::SetStartTime(int round)
	{
		start_time = round;
	}

	bool Magic::IsExpired(int round)const
	{
		return round - start_time == duration;
	}

	bool Magic::EnougnMana(const Unit* unit)const
	{
		unit->CurrentMana() >= mana_cost;
	}

	// DamageDebuff

	DamageDebuff::DamageDebuff(const std::string& name,
		int mana_cost, int duration, int damage_reduce)
		: Magic(name, mana_cost, duration),
		damage_reduction(damage_reduce)
	{

	}

	DamageDebuff::DamageDebuff(const DamageDebuff& dd): Magic(dd)
	{
		damage_reduction = dd.damage_reduction;
	}

	DamageDebuff::DamageDebuff(DamageDebuff&& dd) : DamageDebuff(dd)
	{

	}

	DamageDebuff& DamageDebuff::operator=(const DamageDebuff& dd)
	{
		if (this == &dd)
			return *this;
		Magic::operator=(dd);
		damage_reduction = dd.damage_reduction;
		return *this;
	}

	DamageDebuff& DamageDebuff::operator=(DamageDebuff&& dd)
	{
		return operator=(dd);
	}

	void DamageDebuff::Effect(Unit* unit)const
	{
		unit->DamageChange(-damage_reduction);
	}

	void DamageDebuff::Uneffect(Unit* unit)const
	{
		unit->DamageChange(damage_reduction);
	}

	DamageDebuff* DamageDebuff::Clone()const
	{
		return new DamageDebuff(name, mana_cost, 
			duration, damage_reduction);
	}

	// ArmorDebuff

	ArmorDebuff::ArmorDebuff(const std::string& name,
		int mana_cost, int duration, int armor_reduce)
		: Magic(name, mana_cost, duration), armor_reduction(armor_reduce)
	{

	}

	ArmorDebuff::ArmorDebuff(const ArmorDebuff& ad) : Magic(ad)
	{
		armor_reduction = ad.armor_reduction;
	}

	ArmorDebuff::ArmorDebuff(ArmorDebuff&& ad) : ArmorDebuff(ad)
	{
		
	}

	ArmorDebuff& ArmorDebuff::operator=(const ArmorDebuff& ad)
	{
		if (this == &ad)
			return *this;
		Magic::operator=(ad);
		armor_reduction = ad.armor_reduction;
		return *this;
	}

	ArmorDebuff& ArmorDebuff::operator=(ArmorDebuff&& ad)
	{
		return operator=(ad);
	}

	void ArmorDebuff::Effect(Unit* unit)const
	{
		unit->ArmorChange(-armor_reduction);
	}

	void ArmorDebuff::Uneffect(Unit* unit)const
	{
		unit->ArmorChange(armor_reduction);
	}

	ArmorDebuff* ArmorDebuff::Clone()const
	{
		return new ArmorDebuff(name, mana_cost, 
			duration, armor_reduction);
	}

	// BattleDebuff

	BattlesDebuff::BattlesDebuff(const std::string& name,
		int mana_cost, int duration, int damage_reduce, int armor_reduce)
		: Magic(name, mana_cost, duration),
		DamageDebuff(name, mana_cost, duration, damage_reduce),
		ArmorDebuff(name, mana_cost, duration, armor_reduce)
	{

	}

	BattlesDebuff::BattlesDebuff(const BattlesDebuff& bd)
		: Magic(bd), DamageDebuff(bd), ArmorDebuff(bd)
	{

	}

	BattlesDebuff::BattlesDebuff(BattlesDebuff&& bd) : BattlesDebuff(bd)
	{

	}

	BattlesDebuff& BattlesDebuff::operator=(const BattlesDebuff& bd)
	{
		if (this == &bd)
			return *this;
		DamageDebuff::operator=(bd);
		ArmorDebuff::operator=(bd);
		return *this;
	}

	BattlesDebuff& BattlesDebuff::operator=(BattlesDebuff&& bd)
	{
		return operator=(bd);
	}

	void BattlesDebuff::Effect(Unit* unit)const
	{
		DamageDebuff::Effect(unit);
		ArmorDebuff::Effect(unit);
	}

	void BattlesDebuff::Uneffect(Unit* unit)const
	{
		DamageDebuff::Uneffect(unit);
		ArmorDebuff::Uneffect(unit);
	}

	BattlesDebuff* BattlesDebuff::Clone()const
	{
		return new BattlesDebuff(name, mana_cost, duration, 
			damage_reduction, armor_reduction);
	}

	// DamageBuff

	DamageBuff::DamageBuff(const std::string& name, int mana_cost,
		int duration, int damage_amplify) 
		: Magic(name, mana_cost, duration), damage_amplify(damage_amplify)
	{

	}
	DamageBuff::DamageBuff(const DamageBuff& bb)
		: Magic(bb)
	{
		damage_amplify = bb.damage_amplify;
	}

	DamageBuff::DamageBuff(DamageBuff&& bb) : DamageBuff(bb)
	{

	}

	DamageBuff& DamageBuff::operator=(const DamageBuff& bb)
	{
		if (this == &bb)
			return *this;
		Magic::operator=(bb);
		damage_amplify = bb.damage_amplify;
		return *this;
	}

	DamageBuff& DamageBuff::operator=(DamageBuff&& bb)
	{
		return operator=(bb);
	}

	void DamageBuff::Effect(Unit* unit)const
	{
		unit->DamageChange(damage_amplify);
	}

	void DamageBuff::Uneffect(Unit* unit)const
	{
		unit->DamageChange(-damage_amplify);
	}

	DamageBuff* DamageBuff::Clone()const
	{
		return new DamageBuff(name, mana_cost, duration, damage_amplify);
	}

}