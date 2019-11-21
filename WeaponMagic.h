#ifndef WEAPON_MAGIC_H_
#define WEAPON_MAGIC_H_

#include "Magic.h"

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration, int propability = 20);
	virtual ~WeaponMagic();
protected:
	virtual bool IsCasted()const final;
	int propability;
};

class Degenerate : virtual public WeaponMagic
{
public:
	Degenerate(std::string name, int duration,
		int degeneratin, int propability = 20);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	virtual void PutOn(UnitPtr unit)const;
protected:
	int degeneration;
};

class Crush : virtual public WeaponMagic
{
public:
	Crush(std::string name, int damage,
		int propability = 20);
	virtual void Effect(UnitPtr unit);
	virtual void Uneffect(UnitPtr unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
protected:
	virtual void PutOn(UnitPtr unit)const;
protected:
	int damage;
};

class Corruption : virtual public WeaponMagic
{

};

#endif