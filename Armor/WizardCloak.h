#pragma once

#ifndef WIZARD_CLOAK_H_
#define WIZARD_CLOAK_H_

#include "Armor.h"
#include "../Vitals/Vitals.h"

class WizardCloak : public Armor
{
public:
	WizardCloak(std::string name,
		int armor, Vitals mana);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
	ArmPtr clone()const;
private:
	Vitals m_mana;
};

#endif