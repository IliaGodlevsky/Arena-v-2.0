#ifndef SHIELD_H_
#define SHIELD_H_

#include "../Globals/Globals.h"
#include "../Armor/Armor.h"

class Shield;
using ShieldPtr = std::unique_ptr<Shield>;

class Shield
{
public:
	Shield(std::string name, int armor, 
		int reflectChance);
	void showFullInfo()const;
	void showShortInfo();
	bool isReflectChance()const;
	void putOn(Unit& unit)const;
	void putOff(Unit& unit)const;
	ShieldPtr clone()const;
	virtual ShieldPtr getPureShield()const final;
	~Shield() = default;
protected:
	Armor m_armor;
	std::string m_name;
	int m_reflectChance;
};

#endif