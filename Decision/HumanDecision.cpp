#include "HumanDecision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"
#include "../Arena/Arena.h"

HumanDecision::HumanDecision()
{

}

UnitPtr HumanDecision::chooseUnitToAttack(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	std::cout << decidingUnit.getName() << " choose unit to attack\n";
	index unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE,
		units.size(), 1);
	while (isSameUnit(*units[unitIndex - 1], decidingUnit))
	{
		std::cout << "You can't attack yourselt\n";
		unitIndex = inputNumber(UNIT_TO_ATTACK_CHOOSE_MESSAGE,
			units.size(), 1);
	}
	return units[unitIndex - 1];
}

bool HumanDecision::wantToCastMagic(const Unit& decidingUnit)const
{
	if (!decidingUnit.m_magicBook.canCastAnySpell())
	{
		m_wantToCastMagic = false;
		return m_wantToCastMagic;
	}
	enum { DONT_WANT, WANT };
	std::cout << decidingUnit.getName() << ", ";
	m_wantToCastMagic = static_cast<bool>(inputNumber(
		WANT_TO_CAST_QUESTION, WANT, DONT_WANT));
	return m_wantToCastMagic;
}

MagicPtr HumanDecision::chooseMagicToCast(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	wantToCastMagic(decidingUnit);
	if (!m_wantToCastMagic || !decidingUnit.m_magicBook.canCastAnySpell())
		return nullptr;
	std::cout << "Choose spell to cast\n";
	decidingUnit.m_magicBook.magicList();
	index magicToCastIndex = inputNumber(MAGIC_TO_CAST_CHOOSE_MESSAGE,
		decidingUnit.m_magicBook.size(), 1);
	return MagicPtr(decidingUnit.m_magicBook
		[magicToCastIndex - 1]->clone());
}

UnitPtr HumanDecision::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& units)const
{
	if (!m_wantToCastMagic || !decidingUnit.m_magicBook.canCastAnySpell())
		return nullptr;
	auto& arena = Arena::getInstance();
	arena.showUnits();
	std::cout << decidingUnit.getName() << ", ";
	index unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
		units.size(), 1);
	while (isWrongSpellToCast(decidingUnit, *units[unitToCastIndex - 1], magicToCast))
	{
		std::cout << "You can't use this spell on this unit\n";
		unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
			units.size(), 1);
	}
	return units[unitToCastIndex - 1];
}

bool HumanDecision::isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& magic)const
{
	return !canCastBuffOnUnit(caster, aim, magic) &&
		!canCastDebuffOnUnit(caster, aim, magic);
}