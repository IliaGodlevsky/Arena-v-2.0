#pragma once

#ifndef ATTACK_H_
#define ATTACK_H_

#include "Magic.h"

class Attack : virtual public Magic
{
public:
	Attack(std::string name, int manaCost, int damage);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~Attack() = default;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_damage;
};

class AttackAndStun : public Attack
{
public:
	AttackAndStun(std::string name, int manaCost,
		int duration, int damage);
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

class Poison : virtual public Magic
{
public:
	Poison(std::string name, int manaCost, int duration,
		int regenReduce);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~Poison() = default;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_regenReduce;
};

class PoisonAndAttack
	: public Poison, public Attack
{
public:
	PoisonAndAttack(std::string name,
		int manaCost, int duration,
		int damage, int regenReduce);
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