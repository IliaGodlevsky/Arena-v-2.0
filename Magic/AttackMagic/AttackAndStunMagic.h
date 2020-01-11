#ifndef ATTACK_AND_STUN_MAGIC_H_
#define ATTACK_AND_STUN_MAGIC_H_

#include "AttackMagic.h"
#include "../../Timer/Timer.h"

class AttackAndStunMagic : public AttackMagic
{
public:
	AttackAndStunMagic(std::string name, int manaCost,
		Timer timer, int damage);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
protected:
	Timer m_timer;
};

#endif