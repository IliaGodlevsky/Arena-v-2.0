#pragma once

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Magic.h"

class Weapon
{
private:
	int damage;

};

class Sword : public Weapon
{

};

class Stuff : public Weapon
{
private:
	Magic* magic;
};

#endif