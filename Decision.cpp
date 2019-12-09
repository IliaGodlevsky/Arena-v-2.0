#include <iostream>
#include <random>

#include "Decision.h"
#include "Unit.h"

Decision::Decision()
{

}

bool Decision::isSameUnit(const Unit& unit1, const Unit& unit2)const
{
	return &unit1 == &unit2;
}

bool Decision::canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return magic->isBuff() && isSameUnit(caster, aim);
}
bool Decision::canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !magic->isBuff() && !isSameUnit(caster, aim);
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
HumanDecision::HumanDecision()
{

}

void HumanDecision::showUnits(const Gladiators& units)const
{
	for (size_t i = 0; i < units.size(); i++)
		units[i]->showFullInfo();
}

UnitPtr HumanDecision::chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const
{
	std::cout << decidingUnit.getName() << " choose unit to attack\n";
	int unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE, 
		units.size() - 1, 0);
	while (isSameUnit(*units[unitIndex], decidingUnit))
	{
		std::cout << "You can't attack yourselt\n";
		unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE, 
			units.size() - 1, 0);
	}
	return units[unitIndex];
}

bool HumanDecision::wantToCastMagic()const
{
	enum { DONT_WANT, WANT };
	m_wantToCastMagic = static_cast<bool>(inputNumber("do you want to cast a magic",
		WANT, DONT_WANT));
	return m_wantToCastMagic;
}

MagicPtr HumanDecision::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	wantToCastMagic();
	if (!m_wantToCastMagic)
		return nullptr;
	std::cout << decidingUnit.getName() << " choose spell to cast\n";
	showUnits(units);
	decidingUnit.m_magicBook.showShortInfo();
	int magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE, 
		decidingUnit.m_magicBook.size() - 1, 0);
	return MagicPtr(decidingUnit.m_magicBook
		[magicToCastIndex]->clone());
}

UnitPtr HumanDecision::chooseUnitToCast(const Unit& decidingUnit, 
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (!m_wantToCastMagic)
		return nullptr;
	std::cout << decidingUnit.getName() << " choose unit to cast\n";
	showUnits(units);
	int unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE, 
		units.size() - 1, 0);
	while (isWrongSpellToCast(decidingUnit, *units[unitToCastIndex], magicToCast))
	{
		std::cout << "You can't use this spell on this unit\n";
		unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
			units.size() - 1, 0);
	}
	return units[unitToCastIndex];
}

bool HumanDecision::isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !canCastBuffOnUnit(caster, aim, magic) || !canCastDebuffOnUnit(caster, aim, magic);
}


//ComputerDecision::ComputerDecision(const std::vector<Unit*>& arena)
//	: Decision(arena)
//{
//
//}