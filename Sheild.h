#pragma once

#ifndef SHEILD_H_
#define SHIELD_H_

#include "Armor.h"
#include "Vitals.h"

class Shield : public Armor
{
public:
	Shield(int armor, int reflect_chance);
	virtual bool Reflect()const;
protected:
	int reflect_chance;
	Battles armor;
};

class Buckler : public Shield
{

};

class TowerShield : public Shield
{

};

class SmallShield : public Shield
{

};



#endif