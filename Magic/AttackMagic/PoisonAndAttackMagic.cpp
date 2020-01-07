#include "PoisonAndAttackMagic.h"

PoisonAndAttackMagic::PoisonAndAttackMagic(std::string name, int manaCost,
	const Timer& timer, int damage, int regenReduce)
	: Magic(name, manaCost, timer),
	PoisonMagic(name, manaCost, timer, regenReduce),
	AttackMagic(name, manaCost, damage)
{

}

void PoisonAndAttackMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
	AttackMagic::effectUnit(unit);
}

void PoisonAndAttackMagic::uneffectUnit(Unit& unit)const
{
	PoisonMagic::uneffectUnit(unit);
	AttackMagic::uneffectUnit(unit);
}

MagicPtr PoisonAndAttackMagic::clone()const
{
	return MagicPtr(new PoisonAndAttackMagic(m_name, m_manaCost,
		m_timer, m_damage, m_regenReduce));
}

bool PoisonAndAttackMagic::isBuff()const
{
	return false;
}

bool PoisonAndAttackMagic::hasEqualParametres(const MagicPtr& magic)const
{
	return PoisonMagic::hasEqualParametres(magic)
		&& AttackMagic::hasEqualParametres(magic);
}

bool PoisonAndAttackMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void PoisonAndAttackMagic::putOn(Unit& unit)const
{
	AttackMagic::putOn(unit);
	PoisonMagic::putOn(unit);
}

void PoisonAndAttackMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void PoisonAndAttackMagic::showData()const
{
	AttackMagic::showData();
	PoisonMagic::showData();
}