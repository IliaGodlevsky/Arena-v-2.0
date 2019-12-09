#ifndef WEAPON_H_
#define WEAPON_H_

#include "Globals.h"
#include "WeaponMagic.h"
#include "Battles.h"

class Weapon;
using WeaponPtr = std::unique_ptr<Weapon>;

class Weapon
{
public:
	Weapon(std::string name, int damage);
	Weapon(const Weapon& weapon);
	Weapon& operator=(const Weapon& weapon);
	virtual ~Weapon() = default;
public:
	virtual void injureUnit(Unit& unit, int damage)const = 0;
	virtual void showFullInfo()const = 0;
	virtual void showShortInfo()const final;
	virtual WeaponPtr clone()const = 0;
	virtual bool canSmashUnit(const Unit& unit)const final;
protected:
	virtual int multiplyDamage(int damage)const = 0;
protected:
	Battles m_damage;
	std::string m_name;
};



class Sword : public Weapon
{
public:
	Sword(std::string name, int damage, MagicPtr magic);
	Sword(const Sword& sword);
	Sword& operator=(const Sword& sword);
	~Sword();
	void injureUnit(Unit& unit, int dmg)const override;
	void showFullInfo()const override;
	WeaponPtr clone()const override;
protected:
	int multiplyDamage(int damage)const override;
private:
	MagicPtr m_magic;
};

class Axe : public Weapon
{
public:
	Axe(std::string name, int damage, MagicPtr magic);
	Axe(const Axe& axe);
	Axe& operator=(const Axe& axe);
	~Axe();
	void injureUnit(Unit& unit, int damage)const override;
	void showFullInfo()const override;
	WeaponPtr clone()const override;
protected:
	int multiplyDamage(int dmg)const override;
private:
	MagicPtr m_magic;
};


#endif