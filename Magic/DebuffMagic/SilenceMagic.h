#ifndef SILENCE_H_
#define SILENCE_H_

#include "../../Globals/Globals.h"

#include "../Magic.h"

class SilenceMagic : public Magic
{
public:
	SilenceMagic(std::string name, int manaCost,
		int duration);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit)const override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
protected:
	bool hasEqualParametres(const MagicPtr& magic)const;
	void showData()const override;
	void putOn(Unit& unit)const override;
};

#endif