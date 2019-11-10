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

	void Magic::ToSpellsUnder(Unit* unit)const
	{
		unit->TakeSpellOnMe(this);
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

	// ArmorBuff

	ArmorBuff::ArmorBuff(const std::string& name, int mana_cost,
		int duration, int armor_amplify)
		: Magic(name, mana_cost, duration), armor_amplify(armor_amplify)
	{

	}

	ArmorBuff::ArmorBuff(const ArmorBuff& ab) : Magic(ab)
	{
		armor_amplify = ab.armor_amplify;
	}

	ArmorBuff::ArmorBuff(ArmorBuff&& ab) : ArmorBuff(ab)
	{

	}

	ArmorBuff& ArmorBuff::operator=(const ArmorBuff& ab)
	{
		if (this == &ab)
			return *this;
		Magic::operator=(ab);
		armor_amplify = ab.armor_amplify;
		return *this;
	}

	ArmorBuff& ArmorBuff::operator=(ArmorBuff&& ab)
	{
		return operator=(ab);
	}

	void ArmorBuff::Effect(Unit* unit)const
	{
		unit->ArmorChange(armor_amplify);
	}

	void ArmorBuff::Uneffect(Unit* unit)const
	{
		unit->ArmorChange(-armor_amplify);
	}

	ArmorBuff* ArmorBuff::Clone()const
	{
		return new ArmorBuff(name, mana_cost, duration, armor_amplify);
	}

	// BattlesBuff

	BattlesBuff::BattlesBuff(const std::string& name, int mana_cost,
		int duration, int armor_amplify, int damage_amplify)
		: Magic(name, mana_cost, duration),
		DamageBuff(name, mana_cost, duration, damage_amplify),
		ArmorBuff(name, mana_cost, duration, armor_amplify)
	{

	}

	BattlesBuff::BattlesBuff(const BattlesBuff& bb)
		: Magic(bb), DamageBuff(bb), ArmorBuff(bb)
	{

	}

	BattlesBuff::BattlesBuff(BattlesBuff&& bb) : BattlesBuff(bb)
	{

	}

	BattlesBuff& BattlesBuff::operator=(const BattlesBuff& bb)
	{
		if (this == &bb)
			return *this;
		DamageBuff::operator=(bb);
		ArmorBuff::operator=(bb);
		return *this;
	}

	BattlesBuff& BattlesBuff::operator=(BattlesBuff&& bb)
	{
		return operator=(bb);
	}

	void BattlesBuff::Effect(Unit* unit)const
	{
		DamageBuff::Effect(unit);
		ArmorBuff::Effect(unit);
	}

	void BattlesBuff::Uneffect(Unit* unit)const
	{
		DamageBuff::Uneffect(unit);
		ArmorBuff::Uneffect(unit);
	}

	BattlesBuff* BattlesBuff::Clone()const
	{
		return new BattlesBuff(name, mana_cost, duration, armor_amplify, damage_amplify);
	}

	//OffsetDamageBuff

	OffsetDamageBuff::OffsetDamageBuff(const std::string& name, int mana_cost,
		int duration, int armor_reduce, int damage_amplify)
		: Magic(name, mana_cost, duration),
		DamageBuff(name, mana_cost, duration, damage_amplify),
		ArmorDebuff(name, mana_cost, duration, armor_reduce) 
	{

	}

	OffsetDamageBuff::OffsetDamageBuff(const OffsetDamageBuff& ob)
		: Magic(ob), DamageBuff(ob), ArmorDebuff(ob)
	{

	}

	OffsetDamageBuff::OffsetDamageBuff(OffsetDamageBuff&& ob)
		: OffsetDamageBuff(ob)
	{

	}

	OffsetDamageBuff& OffsetDamageBuff::operator=(const OffsetDamageBuff& ob)
	{
		if (this == &ob)
			return *this;
		DamageBuff::operator=(ob);
		ArmorDebuff::operator=(ob);
		return *this;
	}

	OffsetDamageBuff& OffsetDamageBuff::operator=(OffsetDamageBuff&& ob)
	{
		return operator=(ob);
	}

	void OffsetDamageBuff::Effect(Unit* unit)const
	{
		DamageBuff::Effect(unit);
		ArmorDebuff::Effect(unit);
	}

	void OffsetDamageBuff::Uneffect(Unit* unit)const
	{
		DamageBuff::Uneffect(unit);
		ArmorDebuff::Uneffect(unit);
	}

	OffsetDamageBuff* OffsetDamageBuff::Clone()const
	{
		return new OffsetDamageBuff(name, mana_cost, duration, armor_reduction, damage_amplify);
	}

	// AttackAndStun


	AttackAndStun::AttackAndStun(const std::string& name, int mana_cost,
		int duration, int damage)
		: Magic(name, mana_cost, duration),
		Attack(name, mana_cost, damage)
	{
		this->duration = duration;
	}
	AttackAndStun::AttackAndStun(const AttackAndStun& as)
		: Magic(as), Attack(as)
	{

	}

	AttackAndStun::AttackAndStun(AttackAndStun&& as) : AttackAndStun(as)
	{

	}

	AttackAndStun& AttackAndStun::operator=(const AttackAndStun& as)
	{
		if (this == &as)
			return *this;
		Attack::operator=(as);
		return *this;
	}

	AttackAndStun& AttackAndStun::operator=(AttackAndStun&& as)
	{
		return operator=(as);
	}

	void AttackAndStun::Effect(Unit* unit)const
	{
		unit->HealthChange(-damage);
		unit->AddState(new IsStunned(unit, duration));
	}

	void AttackAndStun::Uneffect(Unit* unit)const
	{
		return;
	}

	AttackAndStun* AttackAndStun::Clone()const
	{
		return new AttackAndStun(name, mana_cost, duration, damage);
	}
}