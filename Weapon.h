#ifndef WEAPON_H_
#define WEAPON_H_

#include "Globals.h"
#include "WeaponMagic.h"
#include "Battles.h"

class Weapon
{
public:
	Weapon(std::string name, int damage);
	Weapon(const Weapon& weapon);
	Weapon& operator=(const Weapon& weapon);
	virtual ~Weapon() = default;
public:
	virtual void Injure(Unit& unit, int dmg )const = 0;
	virtual void ShowFullInfo()const = 0;
	virtual void ShowShortInfo()const final;
	virtual bool CanSmash(const Unit& unit)const final;
protected:
	virtual int Multiply(int dmg)const = 0;
protected:
	Battles damage;
	std::string name;
};

class Sword : public Weapon
{
public:
	Sword(std::string name, int damage, Degenerate* spell);
	Sword(const Sword& sword);
	Sword& operator=(const Sword& sword);
	~Sword();
	void Injure(Unit& unit, int dmg)const override;
	void ShowFullInfo()const override;
protected:
	int Multiply(int dmg)const;
private:
	MagicPtr spell;
};

class Axe : public Weapon
{
public:
	Axe(std::string name, int damage, Crush* spell);
	Axe(const Axe& axe);
	Axe& operator=(const Axe& axe);
	~Axe();
	void Injure(Unit& unit, int dmg)const override;
	void ShowFullInfo()const override;
protected:
	int Multiply(int dmg)const;
private:
	MagicPtr spell;
};


#endif