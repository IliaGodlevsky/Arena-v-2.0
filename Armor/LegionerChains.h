#ifndef LEGIONER_CHAINS_H_
#define LEGIONER_CHAINS_H_

#include "Armor.h"
#include "../Vitals/Vitals.h"

class LegionerChains : public Armor
{
public:
	LegionerChains(std::string name, int armor,
		Vitals health, Vitals mana);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
	ArmPtr clone()const;
private:
	Vitals m_health;
	Vitals m_mana;
};

#endif