#ifndef STUN_MAGIC_H_
#define STUN_MAGIC_H_

#include "../Magic.h"
#include "../../PossibilityCounter/PosibilityCounter.h"

class StunMagic : public Magic
{
public:
	StunMagic(std::string name, Timer timer, 
		PosibilityCounter propability);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
private:
	PosibilityCounter m_posibility;
	Timer m_timer;
};

#endif