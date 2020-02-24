#include "../Unit/Unit.h"

#include "SimpleComputerDecision.h"
#include "../Interface/Interface.h"

bool canKill(UnitPtr activeUnit, UnitPtr passiveUnit)
{
	activeUnit->injureUnit(*passiveUnit);
	return passiveUnit->isDead();
}

bool canBeKilled(UnitPtr activeUnit, UnitPtr passiveUnit)
{
	return canKill(passiveUnit, activeUnit);
}

bool isDeadAfterBuffAndHit(UnitPtr activeUnit, 
	UnitPtr passiveUnit, MagicPtr& buff)
{
	activeUnit->castMagic(*activeUnit, buff);
	return canKill(activeUnit, passiveUnit);
}

bool isDeadAfterDebuffAndHit(UnitPtr activeUnit,
	UnitPtr passiveUnit, MagicPtr& debuff)
{
	return !isDeadAfterDebuff(activeUnit, passiveUnit, debuff)
		&& canKill(activeUnit, passiveUnit);
}

bool isDeadAfterDebuff(UnitPtr activeUnit,
	UnitPtr passiveUnit, MagicPtr& debuff)
{
	activeUnit->castMagic(*passiveUnit, debuff);
	return passiveUnit->isDead();
}

SimpleComputerDecision::SimpleComputerDecision()
{

}

SimpleComputerDecision::SimpleComputerDecision(const SimpleComputerDecision& decision)
	: RandomComputerDecision(decision),
	m_unitToAttack(decision.m_unitToAttack),
	m_unitToCast(decision.m_unitToCast)
{
	if (nullptr != m_magicToCast)
		m_magicToCast = decision.m_magicToCast->clone();
	else
		m_magicToCast = nullptr;
}

UnitPtr SimpleComputerDecision::chooseUnitToAttack(const Unit& decidingUnit,
	const Gladiators& arena)const
{
	m_unitToAttack = findUnitCanBeKilled(decidingUnit, arena, canKill);
	if (nullptr != m_unitToAttack)
		return m_unitToAttack;
	else
		return RandomComputerDecision::chooseUnitToAttack(decidingUnit, arena);
}

UnitPtr SimpleComputerDecision::getUnitPointer(const Unit& decidingUnit, 
	const Gladiators& units)const
{
	for (size_t i = 0; i < units.size(); i++)
		if (&decidingUnit == &(*units[i]))
			return units[i];
	return nullptr; // unit is always in the vector so this return will never work
}

MagicPtr SimpleComputerDecision::chooseMagicToCast(const Unit& decideingUnit,
	const Gladiators& arena)const
{
	m_unitToCast = m_unitToAttack = nullptr;
	m_magicToCast = nullptr;
	MagicAim cast;
	auto unitToCast = findUnitCanBeKilled(decideingUnit, arena, canBeKilled);
	if (nullptr != unitToCast)
	{
		cast = findMagicToPreventKill(unitToCast, getUnitPointer(decideingUnit, arena));
		if (nullptr != std::get<UNIT_TO_CAST>(cast) && nullptr != std::get<MAGIC_TO_CAST>(cast))
		{
			m_unitToCast = std::get<UNIT_TO_CAST>(cast);
			return std::get<MAGIC_TO_CAST>(cast)->clone();
		}
	}
	cast = findMagicToKillUnit(decideingUnit, arena);
	if (nullptr != std::get<UNIT_TO_CAST>(cast) && nullptr != std::get<MAGIC_TO_CAST>(cast))
	{
		m_unitToCast = std::get<UNIT_TO_CAST>(cast);
		return std::get<MAGIC_TO_CAST>(cast)->clone();
	}
	cast = findUnitToKillWithWeaponAndMagic(decideingUnit, arena);
	if (nullptr != std::get<UNIT_TO_CAST>(cast) && nullptr != std::get<MAGIC_TO_CAST>(cast))
	{
		m_unitToCast = std::get<UNIT_TO_CAST>(cast);
		m_unitToAttack = std::get<UNIT_TO_CAST>(cast);
		return std::get<MAGIC_TO_CAST>(cast)->clone();
	}
	return RandomComputerDecision::chooseMagicToCast(decideingUnit, arena);
}

UnitPtr SimpleComputerDecision::chooseUnitToCast(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& arena)const
{
	if (nullptr != m_unitToCast)
		return m_unitToCast;
	else 
		return findUnitWithOutChosenMagic(decidingUnit, magicToCast, arena);
}

UnitPtr SimpleComputerDecision::findUnitWithOutChosenMagic(const Unit& decidingUnit,
	const MagicPtr& magicToCast, const Gladiators& arena)const
{
	if (nullptr == magicToCast)
		return nullptr;
	int i = randomNumber((int)arena.size() - 1);
	size_t count = 0;
	while (count < arena.size())
	{
		if (!isWrongSpellToCast(decidingUnit, *arena[i], magicToCast)
			&& !arena[i]->m_magicOnMe.hasItem(magicToCast))
			return arena[i];
		i++;
		count++;
		if (i >= arena.size())
			i = 0;
	}
	return nullptr;
}

UnitPtr SimpleComputerDecision::findUnitCanBeKilled(const Unit& decidingUnit,
	const Gladiators& units, Predicate predicate)const
{
	Gladiators victims;
	UnitPtr me = nullptr;
	UnitPtr enemy = nullptr;
	for (size_t i = 0; i < units.size(); i++)
	{
		me = decidingUnit.getPureClone();
		enemy = units[i]->getPureClone();
		if (!isWrongUnitToAttack(decidingUnit, *units[i]) && predicate(me, enemy))
				victims.push_back(units[i]);
	}
	return victims.empty() ? nullptr 
		: victims[randomNumber((int)victims.size() - 1)];
}

bool SimpleComputerDecision::isDeadAfterCast(const Unit& unit1, 
	const UnitPtr& unit2, MagicPtr& magic, CastPredicate castPredicate, 
	DecisionPredicate predicate)const
{
	auto me = unit1.getPureClone();
	auto victim = unit2->getPureClone();
	if (predicate(unit1, *unit2, magic) && unit1.isEnoughManaFor(magic))
		return castPredicate(me, victim, magic);
	return false;
}

MagicAim SimpleComputerDecision::makePair(
	std::vector<MagicAim>& pair)const
{
	if (pair.empty())
		return std::make_pair(nullptr, nullptr);
	else
	{
		index random = randomNumber((int)pair.size() - 1);
		return std::make_pair(std::get<UNIT_TO_CAST>(pair[random]),
			std::get<MAGIC_TO_CAST>(pair[random])->clone());
	}
}

MagicAim SimpleComputerDecision::findUnitToKillWithWeaponAndMagic(const Unit& decidingUnit,
	const Gladiators& units)const
{
	std::vector<MagicAim> victims;
	MagicPtr magic = nullptr;
	for (size_t i = 0; i < decidingUnit.m_magicBook.size(); i++)
	{
		magic = decidingUnit.m_magicBook[i]->clone();
		for (size_t j = 0; j < units.size(); j++)
		{
			if (isDeadAfterCast(decidingUnit, units[j], magic, 
				isDeadAfterBuffAndHit, canCastBuffOnUnit))
				victims.push_back(std::make_pair(units[j], magic->clone()));
			else if (isDeadAfterCast(decidingUnit, units[j], magic, 
				isDeadAfterDebuffAndHit, canCastDebuffOnUnit))
				victims.push_back(std::make_pair(units[j], magic->clone()));
		}
	}
	return makePair(victims);
}

MagicAim SimpleComputerDecision::findMagicToKillUnit(
	const Unit& decidingUnit, const Gladiators& units)const
{
	std::vector<MagicAim> magics;
	UnitPtr enemy = nullptr;
	UnitPtr me = nullptr;
	MagicPtr magic = nullptr;
	for (size_t i = 0; i < decidingUnit.m_magicBook.size(); i++)
	{
		magic = decidingUnit.m_magicBook[i]->clone();
		for (size_t j = 0; j < units.size(); j++)
		{
			me = decidingUnit.getPureClone();
			enemy = units[j]->getPureClone();
			if (!isWrongUnitToAttack(decidingUnit, *units[j]) &&
				!isWrongSpellToCast(decidingUnit, *units[j], magic) &&
				!canKill(me->getPureClone(), enemy->getPureClone()) &&
				decidingUnit.isEnoughManaFor(magic) &&
				isDeadAfterDebuff(me,enemy,magic))
			{
				magics.push_back(std::make_pair(units[j], magic->clone()));
			}
		}
	}
	return makePair(magics);
}

MagicAim SimpleComputerDecision::findMagicToPreventKill(const UnitPtr& enemy,
	const UnitPtr& decidingUnit)const
{ 
	std::vector<MagicAim> magics;
	UnitPtr me = nullptr;
	UnitPtr aim = nullptr;
	MagicPtr magic = nullptr;
	IBuff* buff = nullptr;
	for (size_t i = 0; i < decidingUnit->m_magicBook.size(); i++)
	{
		magic = decidingUnit->m_magicBook[i]->clone();
		buff = dCast<IBuff*>(magic);
		me = decidingUnit->getPureClone();
		aim = enemy->getPureClone();
		if (decidingUnit->isEnoughManaFor(magic))
		{
			if (!buff->isBuff() && !enemy->m_magicOnMe.hasItem(magic))
			{
				if (isDeadAfterDebuff(me, aim, magic) || !canBeKilled(me, aim))
					magics.push_back(std::make_pair(enemy, magic->clone()));
			}
			else if (buff->isBuff() && !decidingUnit->m_magicOnMe.hasItem(magic))
			{
				me->castMagic(*me, magic);
				if (!canBeKilled(me, aim))
					magics.push_back(std::make_pair(decidingUnit, magic->clone()));
			}
		}
	}
	return makePair(magics);
}

std::string SimpleComputerDecision::getDecisionType()const
{
	return "Computer";
}

DecisionPtr SimpleComputerDecision::clone()const
{
	return DecisionPtr(new SimpleComputerDecision(*this));
}