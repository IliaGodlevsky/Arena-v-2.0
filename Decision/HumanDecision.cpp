#include "HumanDecision.h"
#include "../Magic/Magic.h"
#include "../Unit/Unit.h"

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

bool HumanDecision::wantToCastMagic()const
{
	enum { DONT_WANT, WANT };
	m_wantToCastMagic = static_cast<bool>(inputNumber(
		WANT_TO_CAST_QUESTION, WANT, DONT_WANT));
	return m_wantToCastMagic;
}

MagicPtr HumanDecision::chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const
{
	wantToCastMagic();
	if (!m_wantToCastMagic || !decidingUnit.m_magicBook.canCastAnySpell())
		return nullptr;
	std::cout << decidingUnit.getName() << " choose spell to cast\n";
	decidingUnit.m_magicBook.showShortInfo();
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
	std::cout << decidingUnit.getName() << " choose unit to cast\n";
	showUnits(units);
	int unitToCastIndex = inputNumber(UNIT_TO_CAST_CHOOSE_MESSAGE,
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