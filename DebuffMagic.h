#pragma once

#ifndef DEBUFF_H_
#define DEBUFF_H_

#include "Magic.h"

class DamageDebuff : virtual public Magic
{
public:
	DamageDebuff(std::string name, int manaCost, int duration,
		int damageReduce);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~DamageDebuff() = default;
protected:
	int m_damageReduce;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
};

class ArmorDebuff : virtual public Magic
{
public:
	ArmorDebuff(std::string name, int manaCost, int duration,
		int armorReduce);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~ArmorDebuff() = default;
protected:
	int m_armorReduce;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
};

class ArmorAndDamageDebuff
	: public DamageDebuff, public ArmorDebuff
{
public:
	ArmorAndDamageDebuff(std::string name, int manaCost,
		int duration, int armorReduce, int damageReduce);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit)const override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
protected:
	bool hasEqualParametres(const MagicPtr& magic)const override;
	void showData()const override;
	void putOn(Unit& unit)const override;
};

class Silence : public Magic
{
public:
	Silence(std::string name, int manaCost,
		int duration);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit)const override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
protected:
	void showData()const override;
	void putOn(Unit& unit)const override;
};
#endif