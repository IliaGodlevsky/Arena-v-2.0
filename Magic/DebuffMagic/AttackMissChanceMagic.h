#ifndef ATTACK_MISS_CHANCE_MAGIC_H_
#define ATTACK_MISS_CHANCE_MAGIC_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"
#include "../../Timer/Timer.h"

class AttackMissChanceMagic : public Magic, 
	public IManaCost, public IBuff
{
public:
	AttackMissChanceMagic(std::string name, 
		int missChance, int manaCost, Timer timer);
	MagicPtr clone()const override;
	bool isBuff()const override;
	void effectUnit(Unit& unit) override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	int getCost()const override;
private:
	Timer m_timer;
	int m_missChance = 0;
	int m_manaCost = 0;
};
#endif