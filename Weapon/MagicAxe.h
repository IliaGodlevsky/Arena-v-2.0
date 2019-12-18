#pragma once

#ifndef MAGIC_AXE_H_
#define MAGIC_AXE_H_

#include "MagicWeapon.h"

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

#endif