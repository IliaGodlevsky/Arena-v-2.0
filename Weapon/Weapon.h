#ifndef WEAPON_H_
#define WEAPON_H_

#include "WeaponMagic.h"
#include "Battles.h"

class Weapon;
using WeaponPtr = std::unique_ptr<Weapon>;

class Weapon
{
public:
	Weapon(std::string name, int damage, int criticalStrikeProbability);
	Weapon(const Weapon& weapon);
	Weapon& operator=(const Weapon& weapon);
	virtual ~Weapon() = default;
public:
	virtual void injureUnit(Unit& unit, int damage)const;
	virtual void showFullInfo()const;
	virtual void showShortInfo()const final;
	virtual WeaponPtr clone()const;
	virtual bool canSmashUnit(const Unit& unit)const final;
protected:
	virtual int multiplyDamage(int damage)const;
protected:
	int m_CriticalStrikePropability;
	Battles m_damage;
	std::string m_name;
};

class MagicWeapon : public Weapon
{
public:
	MagicWeapon(std::string name, int damage, MagicPtr magic);
	MagicWeapon(const MagicWeapon& weapon);
	MagicWeapon& operator=(const MagicWeapon& weapon);
	virtual ~MagicWeapon() = 0;
public:
	virtual void injureUnit(Unit& unit, int dmg)const override final;
	virtual void showFullInfo()const override final;
	virtual WeaponPtr clone()const = 0;
protected:
	MagicPtr m_magic;
};

class MagicSword : public MagicWeapon
{
public:
	MagicSword(std::string name, int damage, MagicPtr magic);
	MagicSword(const MagicSword& sword);
	MagicSword& operator=(const MagicSword& sword);
	~MagicSword() = default;
public:
	WeaponPtr clone()const override;
};

class MagicAxe : public MagicWeapon
{
public:
	MagicAxe(std::string name, int damage, MagicPtr magic);
	MagicAxe(const MagicAxe& axe);
	MagicAxe& operator=(const MagicAxe& axe);
	~MagicAxe() = default;
public:
	WeaponPtr clone()const override;
};

class MagicSpear : public MagicWeapon
{
public:
	MagicSpear(std::string name, int damage, MagicPtr magic);
	MagicSpear(const MagicSpear& spear);
	MagicSpear& operator=(const MagicSpear& spear);
	~MagicSpear() = default;
public:
	WeaponPtr clone()const override;
};

class MagicClub : public MagicWeapon
{
public:
	MagicClub(std::string name, int damage, MagicPtr magic);
	MagicClub(const MagicClub& club);
	MagicClub& operator=(const MagicClub& club);
	~MagicClub() = default;
public:
	WeaponPtr clone()const override;
};
#endif