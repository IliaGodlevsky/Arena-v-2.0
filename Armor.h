#pragma once

#ifndef ARMOR_H_
#define ARMOR_H_

#include "Unit.h"

class Armor
{
public:
	Armor(int armor);
	virtual void PutOn(Unit* unit)const = 0;
	virtual void PutOff(Unit* unit)const = 0;
protected:
	Battles armor;
};

class Mail : public Armor
{
public:
	Mail(int armor, Vitals health);
	void PutOn(Unit* unit)const override;
	void PutOff(Unit* unit)const override;
};
#endif