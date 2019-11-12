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
		return new DamageDebuff(*this);
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
		return new ArmorDebuff(*this);
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
		return new BattlesDebuff(*this);
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
		return new DamageBuff(*this);
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
		return new ArmorBuff(*this);
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
		return new BattlesBuff(*this);
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
		return new OffsetDamageBuff(*this);
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
	}

	void AttackAndStun::Uneffect(Unit* unit)const
	{
		return;
	}

	AttackAndStun* AttackAndStun::Clone()const
	{
		return new AttackAndStun(*this);
	}

	void AttackAndStun::ToSpellsUnder(Unit* unit)const
	{
		Magic::ToSpellsUnder(unit);
		unit->AddState(new IsStunned(duration));
	}

	// Heal

	Heal::Heal(const std::string& name, int mana_cost,
		int healing) 
		: Magic(name, mana_cost, 0), healing(healing)
	{

	}

	Heal::Heal(const Heal& h) : Magic(h)
	{
		healing = h.healing;
	}

	Heal::Heal(Heal&& h) : Heal(h)
	{

	}

	Heal& Heal::operator=(const Heal& h)
	{
		if (this == &h)
			return *this;
		Magic::operator =(h);
		healing = h.healing;
		return *this;
	}

	Heal& Heal::operator=(Heal&& h)
	{
		return operator=(h);
	}

	void Heal::Effect(Unit* unit)const
	{
		unit->HealthChange(healing);
	}

	void Heal::Uneffect(Unit* unit)const
	{
		return;
	}

	Heal* Heal::Clone()const
	{
		return new Heal(*this);
	}

	Poison::Poison(const std::string& name, int mana_cost,
		int duration, int regeneration_reduce)
		: Magic(name, mana_cost,duration),
		regeneration_reduce(regeneration_reduce)
	{

	}

	Poison::Poison(const Poison& p) : Magic(p)
	{
		regeneration_reduce = p.regeneration_reduce;
	}

	Poison::Poison(Poison&& p) : Poison(p)
	{

	}

	Poison& Poison::operator=(const Poison& p)
	{
		if (this == &p)
			return *this;
		Magic::operator=(p);
		regeneration_reduce = p.regeneration_reduce;
		return *this;
	}

	Poison& Poison::operator=(Poison&& p)
	{
		return operator=(p);
	}

	void Poison::Effect(Unit* unit)const
	{
		unit->RegenerationChange(-regeneration_reduce);
	}

	void Poison::Uneffect(Unit* unit)const
	{
		unit->RegenerationChange(regeneration_reduce);
	}

	Poison* Poison::Clone()const
	{
		return new Poison(*this);
	}

	// Attack

	Attack::Attack(const std::string& name,
		int mana_cost, int damage)
		: Magic(name, mana_cost, 0),
		damage(damage)
	{

	}

	Attack::Attack(const Attack& a) : Magic(a)
	{
		damage = a.damage;
	}

	Attack::Attack(Attack&& a) : Attack(a)
	{

	}

	Attack& Attack::operator=(const Attack& a)
	{
		if (this == &a)
			return *this;
		Magic::operator=(a);
		damage = a.damage;
		return *this;
	}

	Attack& Attack::operator=(Attack&& a)
	{
		return operator=(a);
	}

	Attack::~Attack() {}

	void Attack::Effect(Unit* unit)const
	{
		unit->HealthChange(-damage);
	}

	void Attack::Uneffect(Unit* unit)const
	{
		return;
	}

	Attack* Attack::Clone()const
	{
		return new Attack(*this);
	}

	// AttackAndArmorDebuff

	AttackAndArmorDebuff::AttackAndArmorDebuff(const std::string& name,
		int duration, int mana_cost, int damage, int armor_debuff)
		: Magic(name, mana_cost, duration),
		Attack(name, mana_cost, damage),
		ArmorDebuff(name, mana_cost, duration, armor_debuff)
	{

	}

	AttackAndArmorDebuff::AttackAndArmorDebuff(const AttackAndArmorDebuff& aa)
		: Magic(aa), Attack(aa), ArmorDebuff(aa)
	{

	}

	AttackAndArmorDebuff::AttackAndArmorDebuff(AttackAndArmorDebuff&& aa)
		: AttackAndArmorDebuff(aa)
	{

	}

	AttackAndArmorDebuff& AttackAndArmorDebuff::operator=(const AttackAndArmorDebuff& aa)
	{
		if (this == &aa)
			return *this;
		Attack::operator=(aa);
		ArmorDebuff::operator=(aa);
		return *this;
	}

	AttackAndArmorDebuff& AttackAndArmorDebuff::operator=(AttackAndArmorDebuff&& aa)
	{
		return operator=(aa);
	}

	void AttackAndArmorDebuff::Effect(Unit* unit)const
	{
		Attack::Effect(unit);
		ArmorDebuff::Effect(unit);
	}

	void AttackAndArmorDebuff::Uneffect(Unit* unit)const
	{
		ArmorDebuff::Uneffect(unit);
	}

	AttackAndArmorDebuff* AttackAndArmorDebuff::Clone()const
	{
		return new AttackAndArmorDebuff(*this);
	}

	// PoisonAndAttack


	PoisonAndAttack::PoisonAndAttack(const std::string& name, int mana_cost,
		int duration, int regeneration_reduce, int damage)
		:Magic(name, mana_cost, duration),
		Poison(name, mana_cost, duration, regeneration_reduce),
		Attack(name, mana_cost, damage)
	{

	}

	PoisonAndAttack::PoisonAndAttack(const PoisonAndAttack& ap)
		: Magic(ap), Attack(ap), Poison(ap) 
	{

	}

	PoisonAndAttack::PoisonAndAttack(PoisonAndAttack&& ap) 
		: PoisonAndAttack(ap)
	{

	}

	PoisonAndAttack& PoisonAndAttack::operator=(const PoisonAndAttack& ap)
	{
		if (this == &ap)
			return *this;
		Poison::operator=(ap);
		Attack::operator=(ap);
		return *this;
	}

	PoisonAndAttack& PoisonAndAttack::operator=(PoisonAndAttack&& ap)
	{
		return operator=(ap);
	}

	void PoisonAndAttack::Effect(Unit* unit)const
	{
		Poison::Effect(unit);
		Attack::Effect(unit);
	}

	void PoisonAndAttack::Uneffect(Unit* unit)const
	{
		Poison::Uneffect(unit);
	}

	PoisonAndAttack* PoisonAndAttack::Clone()const
	{
		return new PoisonAndAttack(*this);
	}
}