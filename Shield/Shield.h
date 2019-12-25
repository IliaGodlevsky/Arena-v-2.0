#ifndef SHIELD_H_
#define SHIELD_H_

#include "../PossibilityCounter/PosibilityCounter.h"
#include "../Globals/Globals.h"

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
	ShieldPtr getPureShield()const final;
	~Shield() = default;
protected:
	std::string m_name;
	int m_armor;
	int m_reflectChance;
};

#endif