#pragma once

#ifndef WEAPON_MAGIC_H_
#define WEAPON_MAGIC_H_

#include "Magic.h"
#include "PosibilityCounter.h"

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration, 
		int propability);
	virtual void showFullInfo()const = 0;
	virtual ~WeaponMagic();
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override= 0;
	virtual bool isEqual(const MagicPtr& magic)const override = 0;
	virtual bool isCastChance()const final;
	virtual void showData()const = 0;
protected:
	int m_propability; // chance to be casted
};

class Degenerate : virtual public WeaponMagic
{
public:
	Degenerate(std::string name, int duration,
		int degeneration, int propability);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_degeneration;
};

class Crush : virtual public WeaponMagic
{
public:
	Crush(std::string name, int damage,
		int propability);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_damage;
};

class Corruption : public WeaponMagic
{
public:
	Corruption(std::string name, int duration,
		int armorReduce, int propability);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_armorReduce;
};

class Stun : public WeaponMagic
{
public:
	Stun(std::string name, int duration, int propability);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
};
#endif