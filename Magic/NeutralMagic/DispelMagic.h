#ifndef DISPEL_H_
#define DISPEL_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"

class DispelMagic : public Magic, public IBuff, public IManaCost
{
public:
	DispelMagic(std::string name, int manaCost);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	int getCost()const override;
private:
	int m_manaCost = 0;
};

#endif