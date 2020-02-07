#ifndef ATTACK_MISS_CHANCE_MAGIC_H_
#define ATTACK_MISS_CHANCE_MAGIC_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"

class AttackMissChanceMagic : public Magic, 
	public IManaCost, public IBuff
{
public:
	AttackMissChanceMagic(std::string name, 
		int missChance, int manaCost, int duration);
	MagicPtr clone()const override;
	bool isBuff()const override;
	void effectUnit(Unit& unit) override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
private:
	int m_duration = 0;
	int m_missChance = 0;
};
#endif