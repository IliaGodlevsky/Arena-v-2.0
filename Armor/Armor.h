#ifndef ARMOR_H_
#define ARMOR_H_

#include "../Globals/Globals.h"
#include "../Battles/Battles.h"

class Armor;
using ArmPtr = std::unique_ptr<Armor>;

class Armor
{
public:
	Armor(std::string name, int armor);
	virtual void putOn(Unit& unit)const;
	virtual void putOff(Unit& unit)const;
	virtual ~Armor() = default;
	virtual void showFullInfo()const;
	virtual void showShortInfo()const final;
	virtual ArmPtr clone()const;
protected:
	std::string m_name;
	Battles m_armor;
};
#endif