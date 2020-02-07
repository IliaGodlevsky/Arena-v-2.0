#ifndef SILENCE_H_
#define SILENCE_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"

class SilenceMagic : public Magic, public IBuff, public IManaCost
{
public:
	SilenceMagic(std::string name, int manaCost, int duration);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showShortInfo()const override;
	void showFullInfo()const override;
private:
	int m_duration = 0;
};

#endif