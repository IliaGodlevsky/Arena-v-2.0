#ifndef ATTACK_AND_SILENCE_MAGIC_H_
#define ATTACK_AND_SILENCE_MAGIC_H_

#include "AttackMagic.h"
#include "../DebuffMagic/SilenceMagic.h"

class AttackAndSilenceMagic : public AttackMagic
{
public:
	AttackAndSilenceMagic(std::string name, int manaCost,
		Timer timer, int damage);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
protected:
	SilenceMagic m_silence;
	Timer m_timer;
};

#endif
