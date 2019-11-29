#ifndef MAGIC_H_
#define MAGIC_H_

#include "Globals.h"
#include "Durationmeter.h"

// abstract base class (couldn't create an instance of this class)
class Magic
{
public:
	Magic(std::string name,
		int mana_cost, int duration);
	virtual ~Magic();
public:
	virtual void Effect(Unit& unit) = 0;
	virtual void Uneffect(Unit& unit)const = 0;
	virtual MagicPtr Clone()const = 0; // Prototype
	virtual bool IsBuff()const = 0;
	virtual void ShowFullInfo()const = 0;
	virtual void ShowShortInfo()const final;
public:
	virtual bool IsExpired(int round)const final;
	virtual void SetStartTime(int round) final;
	virtual bool EnoughMana(int current_mana)const final;
	virtual int Cost()const final;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	virtual void Data()const = 0;
	virtual void PutOn(Unit& unit)const = 0;
protected:
	std::string name;
	int mana_cost;
	Durationmeter durationmeter;
};

class DamageBuff : virtual public Magic
{
public:
	DamageBuff(std::string name, int mana_cost,
		int duration, int damage_amplify);
	virtual void Effect(Unit& unit) override;
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual bool IsBuff()const;
	virtual void ShowFullInfo()const;
	virtual ~DamageBuff() = default;
protected:
	int damage_amplify;
protected:
	virtual void PutOn(Unit& unit)const;
	virtual void Data()const;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
	virtual ~ArmorBuff() = default;
protected:
	int armor_amplify;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
};

class ArmorAndDamageBuff 
	: public ArmorBuff, public DamageBuff
{
public:
	ArmorAndDamageBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify, int damage_amplify);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

class DamageDebuff : virtual public Magic
{
public:
	DamageDebuff(std::string name, int mana_cost, int duration,
		int damage_reduce);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
	virtual ~DamageDebuff() = default;
protected:
	int damage_reduce;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
};

class ArmorDebuff : virtual public Magic
{
public:
	ArmorDebuff(std::string name, int mana_cost, int duration,
		int armor_reduce);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
	virtual ~ArmorDebuff() = default;
protected:
	int armor_reduce;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
};

class ArmorAndDamageDebuff
	: public DamageDebuff, public ArmorDebuff
{
public:
	ArmorAndDamageDebuff(std::string name, int mana_cost,
		int duration, int armor_reduce, int damage_reduce);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

class OffsetDamageBuff
	: public DamageBuff, public ArmorDebuff
{
public:
	OffsetDamageBuff(std::string name, int mana_cost,
		int duration, int armor_reduce, int damage_amplify);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

class Attack : virtual public Magic
{
public:
	Attack(std::string name, int mana_cost, int damage);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
	virtual ~Attack() = default;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
protected:
	int damage;
};

class AttackAndStun : public Attack
{
public:
	AttackAndStun(std::string name, int mana_cost, 
		int duration, int damage);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

class Poison : virtual public Magic
{
public:
	Poison(std::string name, int mana_cost, int duration,
		int regen_reduce);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
	virtual ~Poison() = default;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
protected:
	int regen_reduce;
};

class PoisonAndAttack
	: public Poison, public Attack
{
public:
	PoisonAndAttack(std::string name, 
		int mana_cost, int duration,
		int damage, int regen_reduce);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

class Silence : public Magic
{
public:
	Silence(std::string name, int mana_cost, 
		int duration);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

class Dispel : public Magic
{
public:
	Dispel(std::string name, int mana_cost);
	void Effect(Unit& unit);
	void Uneffect(Unit& unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
	void ShowFullInfo()const;
protected:
	void Data()const;
	void PutOn(Unit& unit)const;
};

#endif