#ifndef WEAPON_MAGIC_H_
#define WEAPON_MAGIC_H_

#include "Magic.h"
#include "PosibilityCounter.h"

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration, 
		int propability);
	virtual void ShowFullInfo()const = 0;
	virtual ~WeaponMagic();
protected:
	virtual bool IsCasted()const final;
	virtual void Data()const = 0;
	int propability;
};

class Degenerate : virtual public WeaponMagic
{
public:
	Degenerate(std::string name, int duration,
		int degeneratin, int propability = 20);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
protected:
	int degeneration;
};

class Crush : virtual public WeaponMagic
{
public:
	Crush(std::string name, int damage,
		int propability = 20);
	virtual void Effect(Unit& unit);
	virtual void Uneffect(Unit& unit)const;
	virtual MagicPtr Clone()const override;
	virtual bool IsBuff()const;
	virtual bool Equal(const MagicPtr& magic)const;
	virtual void ShowFullInfo()const;
protected:
	virtual void Data()const;
	virtual void PutOn(Unit& unit)const;
protected:
	int damage;
};

#endif