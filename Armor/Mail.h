#ifndef MAIL_H_
#define MAIL_H_

#include "Armor.h"

#include "../Vitals/Vitals.h"

class Mail : public Armor
{
public:
	Mail(std::string name,
		int armor, Vitals health);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
	ArmPtr clone()const;
private:
	Vitals m_health;
};

#endif
