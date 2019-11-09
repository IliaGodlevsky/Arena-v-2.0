#pragma once

#ifndef MAGIC_H_
#define MAGIC_H_

#include <string>

namespace Arena
{
	class Unit;

	class Magic
	{
	public:
		Magic(std::string name, int mana_cost, int duration);
		Magic(const Magic& magic);
		Magic(Magic&& magic);
		Magic& operator=(const Magic& magic);
		Magic& operator=(Magic&& magic);
	public:
		virtual void Effect(Unit* unit) = 0;
		void SetStartTime(int round);
		bool IsExpired(int round);
	private:
		int mana_cost;
		int duration;
	};

	class DamageDebuff : virtual public Magic
	{
		
	};

	class ArmorDebuff : virtual public Magic
	{

	};

	class BattlesDebuff 
		: public DamageDebuff, public ArmorDebuff
	{

	};

	class DamageBuff : virtual public Magic
	{

	};

	class ArmorBuff : virtual public Magic
	{

	};

	class BattlesBuff 
		: public DamageBuff, public ArmorBuff
	{

	};

	class OffsetDamageBuff 
		: public DamageBuff, public ArmorDebuff
	{

	};

	class Heal : virtual public Magic
	{

	};

	
}

#endif