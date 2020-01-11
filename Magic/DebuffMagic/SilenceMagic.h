#ifndef SILENCE_H_
#define SILENCE_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"
#include "../../Timer/Timer.h"

class SilenceMagic : public Magic, public IBuff, public IManaCost
{
public:
	SilenceMagic(std::string name, int manaCost, Timer timer);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showShortInfo()const override;
	void showFullInfo()const override;
	int getCost()const override;
private:
	Timer m_timer;
	int m_manaCost = 0;
};

#endif