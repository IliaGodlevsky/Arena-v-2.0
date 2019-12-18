#pragma once

#ifndef MAGIC_SWORD_H_
#define MAGIC_SWORD_H_

#include "MagicWeapon.h"

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

#endif