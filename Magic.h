#ifndef MAGIC_H_
#define MAGIC_H_

#include "Globals.h"

// abstract base class (couldn't create an instance of this class)
class Magic
{
public:
	Magic(std::string name,
		int mana_cost, int duration);
	virtual ~Magic();
public:
	virtual void Effect(UnitPtr unit) = 0;
	virtual void Uneffect(UnitPtr unit)const = 0;
	virtual MagicPtr Clone()const = 0; // Prototype
	virtual bool IsBuff()const = 0;
public:
	virtual bool IsExpired(int round)const final;
	virtual void SetStartTime(int round) final;
	virtual bool EnoughMana(int current_mana)const final;
	virtual int Cost()const final;
	virtual void ShowMagic()const final;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	virtual void PutOn(UnitPtr unit)const = 0;
protected:
	std::string name;
	int mana_cost;
	int duration;
	int start_time;
};

class DamageBuff : virtual public Magic
{
public:
	DamageBuff(std::string name, int mana_cost,
		int duration, int damage_amplify);
	virtual void Effect(UnitPtr unit) override;
	virtual void Uneffect(UnitPtr unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual bool IsBuff()const;
protected:
	int damage_amplify;
protected:
	virtual void PutOn(UnitPtr unit)const;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	int armor_amplify;
protected:
	virtual void PutOn(UnitPtr unit)const;
};

class ArmorAndDamageBuff 
	: public ArmorBuff, public DamageBuff
{
public:
	ArmorAndDamageBuff(std::string name, int mana_cost, 
		int duration, int armor_amplify, int damage_amplify);
	void Effect(UnitPtr unit);
	void Uneffect(UnitPtr unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
protected:
	void PutOn(UnitPtr unit)const;
};

class DamageDebuff : virtual public Magic
{
public:
	DamageDebuff(std::string name, int mana_cost, int duration,
		int damage_reduce);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	int damage_reduce;
protected:
	virtual void PutOn(UnitPtr unit)const;
};

class ArmorDebuff : virtual public Magic
{
public:
	ArmorDebuff(std::string name, int mana_cost, int duration,
		int armor_reduce);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	int armor_reduce;
protected:
	virtual void PutOn(UnitPtr unit)const;
};

class ArmorAndDamageDebuff
	: public DamageDebuff, public ArmorDebuff
{
public:
	ArmorAndDamageDebuff(std::string name, int mana_cost,
		int duration, int armor_reduce, int damage_reduce);
	void Effect(UnitPtr unit);
	void Uneffect(UnitPtr unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
protected:
	void PutOn(UnitPtr unit)const;
};

class OffsetDamageBuff
	: public DamageBuff, public ArmorDebuff
{
public:
	OffsetDamageBuff(std::string name, int mana_cost,
		int duration, int armor_reduce, int damage_amplify);
	void Effect(UnitPtr unit);
	void Uneffect(UnitPtr unit)const;
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
protected:
	void PutOn(UnitPtr unit)const;
};

class Attack : virtual public Magic
{
public:
	Attack(std::string name, int mana_cost, int damage);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit);
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	virtual void PutOn(UnitPtr unit)const;
protected:
	int damage;
};

class Poison : virtual public Magic
{
public:
	Poison(std::string name, int mana_cost, int duration,
		int regen_reduce);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit);
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	virtual void PutOn(UnitPtr unit)const;
protected:
	int regen_reduce;
};

class PoisonAndAttack
	: public Poison, public Attack
{
public:
	PoisonAndAttack(std::string name, int mana_cost, int duration,
		int damage, int regen_reduce);
	void Effect(UnitPtr unit);
	void Uneffect(UnitPtr unit);
	MagicPtr Clone()const override;
	bool IsBuff()const;
	bool Equal(const MagicPtr& magic)const;
protected:
	void PutOn(UnitPtr unit)const;
};



using Spells = std::vector<MagicPtr>;

class SpellsOnMe : public Spells
{
public:
	SpellsOnMe(UnitPtr unit);
	void TakeOfExpired(int round);
	bool HaveSpell(const MagicPtr& spell)const;
	void ShowSpells()const;
private:
	UnitPtr unit;
};

class SpellBook : public Spells
{
public:
	SpellBook(UnitPtr unit);
	bool CanCastAnySpell()const;
	void ShowSpells();
};

#endif