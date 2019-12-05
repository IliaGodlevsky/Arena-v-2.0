#pragma once

#include "Magic.h"

#ifndef BUFF_H_
#define BUFF_H_

class DamageBuff : virtual public Magic
{
public:
	DamageBuff(std::string name, int manaCost,
		int duration, int damageAmplify);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual bool isBuff()const override;
	virtual void showFullInfo()const override;
	virtual ~DamageBuff() = default;
protected:
	int m_damageAmplify;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void putOn(Unit& unit)const override;
	virtual void showData()const override;
};

class ArmorBuff : virtual public Magic
{
public:
	ArmorBuff(std::string name, int manaCost,
		int duration, int armorAmplify);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~ArmorBuff() = default;
protected:
	int m_armorAmplify;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const;
	virtual void putOn(Unit& unit)const;
};

class ArmorAndDamageBuff
	: public ArmorBuff, public DamageBuff
{
public:
	ArmorAndDamageBuff(std::string name, int manaCost,
		int duration, int armorAmplify, int damageAmplify);
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

class OffsetDamageBuff
	: public DamageBuff, public ArmorDebuff
{
public:
	OffsetDamageBuff(std::string name, int manaCost,
		int duration, int armorReduce, int damageAmplify);
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
#endif