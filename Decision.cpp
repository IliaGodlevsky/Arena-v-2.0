#include <iostream>
#include <random>

#include "Decision.h"
#include "Unit.h"

int inputNumber(const std::string& message,
	int upper, int lower)
{
	int choice;
	std::cout << message;
	std::cin >> choice;
	while (isError(choice, upper, lower))
	{
		eatLine();
		std::cout << message;
		std::cin >> choice;
	}
	return choice;
}

bool isError(int choice, int upper, int lower)
{
	return !std::cin 
		|| choice > upper 
		|| choice < lower;
}

void eatLine()
{
	std::cin.clear();
	while (!iscntrl(std::cin.get()))
		continue;
}

Decision::Decision(const std::vector<UnitPtr>& units)
	: m_units(units)
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
HumanDecision::HumanDecision(const std::vector<UnitPtr>& arena)
	: Decision(arena)
{

}

void HumanDecision::showUnits()const
{
	for (size_t i = 0; i < m_units.size(); i++)
		m_units[i]->showFullInfo();
}

UnitPtr HumanDecision::chooseUnitToAttack(const Unit& decidingUnit)const
{
	std::cout << decidingUnit.getName() << " choose unit to attack\n";
	showUnits();
	int unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE, 
		m_units.size() - 1, 0);
	while (isSameUnit(*m_units[unitIndex], decidingUnit))
	{
		std::cout << "You can't attack yourselt\n";
		unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE, 
			m_units.size() - 1, 0);
	}
	return m_units[unitIndex];
}

bool HumanDecision::wantToCastMagic()const
{
	enum { DONT_WANT, WANT };
	m_wantToCastMagic = static_cast<bool>(inputNumber("do you want to cast a magic",
		WANT, DONT_WANT));
	return m_wantToCastMagic;
}

MagicPtr HumanDecision::chooseMagicToCast(const Unit& decidingUnit)const
{
	std::cout << decidingUnit.getName();
	if (!m_wantToCastMagic)
		return nullptr;
	std::cout << decidingUnit.getName() << " choose spell to cast\n";
	showUnits();
	decidingUnit.m_magicBook.ShowShortInfo();
	int magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE, 
		decidingUnit.m_magicBook.size() - 1, 0);
	return MagicPtr(decidingUnit.m_magicBook
		[magicToCastIndex]->clone());
}

UnitPtr HumanDecision::chooseUnitToCast(const Unit& decidingUnit, 
	const MagicPtr& magicToCast)const
{
	if (!m_wantToCastMagic)
		return nullptr;
	std::cout << decidingUnit.getName() << " choose unit to cast\n";
	showUnits();
	int unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE, 
		m_units.size() - 1, 0);
	while (isWrongSpellToCast(decidingUnit, *m_units[unitToCastIndex], magicToCast))
	{
		std::cout << "You can't use this spell on this unit\n";
		unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
			m_units.size() - 1, 0);
	}
	return m_units[unitToCastIndex];
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