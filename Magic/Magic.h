#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include <string>

#include "../Unit/Unit.h"

namespace Arena
{

	class Magic
	{
	public:
		Magic(const std::string& name, 
			int mana_cost, int duration);
		Magic(const Magic& magic);
		Magic(Magic&& magic);
		Magic& operator=(const Magic& magic);
		Magic& operator=(Magic&& magic);
		virtual ~Magic();
	public:
		virtual void Effect(Unit* unit)const= 0;
		virtual void Uneffect(Unit* unit)const = 0;
		virtual Magic* Clone()const = 0;
		void SetStartTime(int round);
		bool IsExpired(int round)const;
		bool EnougnMana(const Unit* unit)const;
	private:
		virtual void ToSpellsUnder(Unit* unit)const;
	protected:
		std::string name;
		int mana_cost;
		int duration;
		int start_time;
	};

	class DamageDebuff : virtual public Magic
	{
	public:
		DamageDebuff(const std::string& name, int mana_cost,
			int duration, int damage_reduce);
		DamageDebuff(const DamageDebuff& dd);
		DamageDebuff(DamageDebuff&& dd);
		DamageDebuff& operator=(const DamageDebuff& dd);
		DamageDebuff& operator=(DamageDebuff&& dd);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		DamageDebuff* Clone()const;
	protected:
		int damage_reduction;
	};

	class ArmorDebuff : virtual public Magic
	{
	public:
		ArmorDebuff(const std::string& name, int mana_cost,
			int duration, int armor_reduce);
		ArmorDebuff(const ArmorDebuff& ad);
		ArmorDebuff(ArmorDebuff&& ad);
		ArmorDebuff& operator=(const ArmorDebuff& ad);
		ArmorDebuff& operator=(ArmorDebuff&& ad);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		ArmorDebuff* Clone()const;
	protected:
		int armor_reduction;
	};

	class BattlesDebuff 
		: public DamageDebuff, public ArmorDebuff
	{
		BattlesDebuff(const std::string& name, int mana_cost,
			int duration, int damage_reduce, int armor_reduce);
		BattlesDebuff(const BattlesDebuff& bd);
		BattlesDebuff(BattlesDebuff&& bd);
		BattlesDebuff& operator=(const BattlesDebuff& bd);
		BattlesDebuff& operator=(BattlesDebuff&& bd);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		BattlesDebuff* Clone()const;
	};

	class DamageBuff : virtual public Magic
	{
	public:
		DamageBuff(const std::string& name, int mana_cost,
			int duration, int damage_amplify);
		DamageBuff(const DamageBuff& db);
		DamageBuff(DamageBuff&& db);
		DamageBuff& operator=(const DamageBuff& db);
		DamageBuff& operator=(DamageBuff&& db);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		DamageBuff* Clone()const;
	protected:
		int damage_amplify;
	};

	class ArmorBuff : virtual public Magic
	{
	public:
		ArmorBuff(const std::string& name, int mana_cost,
			int duration, int armor_amplify);
		ArmorBuff(const ArmorBuff& ab);
		ArmorBuff(ArmorBuff&& ab);
		ArmorBuff& operator=(const ArmorBuff& ab);
		ArmorBuff& operator=(ArmorBuff&& ab);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		ArmorBuff* Clone()const;
	protected:
		int armor_amplify;
	};

	class BattlesBuff 
		: public DamageBuff, public ArmorBuff
	{
	public:
		BattlesBuff(const std::string& name, int mana_cost,
			int duration, int armor_amplify, int damage_amplify);
		BattlesBuff(const BattlesBuff& bb);
		BattlesBuff(BattlesBuff&& bb);
		BattlesBuff& operator=(const BattlesBuff& bb);
		BattlesBuff& operator=(BattlesBuff&& bb);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		BattlesBuff* Clone()const;
	};

	class OffsetDamageBuff 
		: public DamageBuff, public ArmorDebuff
	{
	public:
		OffsetDamageBuff(const std::string& name, int mana_cost,
			int duration, int armor_reduce, int damage_amplify);
		OffsetDamageBuff(const OffsetDamageBuff& ob);
		OffsetDamageBuff(OffsetDamageBuff&& ob);
		OffsetDamageBuff& operator=(const OffsetDamageBuff& ob);
		OffsetDamageBuff& operator=(OffsetDamageBuff&& ob);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		OffsetDamageBuff* Clone()const;
	};

	class Heal : virtual public Magic
	{

	};

	class Poison : virtual public Magic
	{

	};

	class Attack : virtual public Magic
	{
	public:
		Attack(const std::string& name, 
			int mana_cost, int damage);
		Attack(const Attack& as);
		Attack(Attack&& as);
		Attack& operator=(const Attack& as);
		Attack& operator=(Attack&& as);
		virtual ~Attack();
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		Attack* Clone()const;
	protected:
		int damage;
	};

	class AttackAndArmorDebuff 
		: public Attack, public ArmorDebuff
	{

	};

	class AttackAndStun : public Attack
	{
	public:
		AttackAndStun(const std::string& name, int mana_cost,
			int duration, int damage);
		AttackAndStun(const AttackAndStun& as);
		AttackAndStun(AttackAndStun&& as);
		AttackAndStun& operator=(const AttackAndStun& as);
		AttackAndStun& operator=(AttackAndStun&& as);
	public:
		void Effect(Unit* unit)const;
		void Uneffect(Unit* unit)const;
		AttackAndStun* Clone()const;
	};

	class PoisonAndAttack 
		: public Attack, public Poison
	{

	};

	class Dispel : public Magic
	{

	};

	class Silence : public Magic
	{

	};
}

#endif