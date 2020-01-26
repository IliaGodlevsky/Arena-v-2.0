#include "../Unit/Unit.h"

#include "SimpleComputerDecision.h"
#include "../Interface/Interface.h"

inline bool canKill(UnitPtr unit1, UnitPtr unit2)
{
	unit1->injureUnit(*unit2);
	return !unit2->isAlive();
}

inline bool canBeKilled(UnitPtr unit1, UnitPtr unit2)
{
	return canKill(unit2, unit1);
}

inline bool isDeadAfterBuff(UnitPtr unit1, 
	UnitPtr unit2, MagicPtr& magic)
{
	unit1->castMagic(*unit1, magic);
	return canKill(unit1, unit2);
}

inline bool isDeadAfterDebuff(UnitPtr unit1,
	UnitPtr unit2, MagicPtr& magic)
{
	unit1->castMagic(*unit2, magic);
	return canKill(unit1, unit2);
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
	UnitPtr unitToCast = findUnitCanBeKilled(decideingUnit, arena, canBeKilled);
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
	size_t i = randomNumber(arena.size() - 1);
	size_t count = 0;
	while (count < arena.size())
	{
		if (!isWrongSpellToCast(decidingUnit, *arena[i], magicToCast)
			&& !arena[i]->m_magicOnMe.hasItem(magicToCast)
			&& decidingUnit.isEnoughManaFor(magicToCast))
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
		if (!decidingUnit.isAlly(*units[i]) && units[i]->isAlive())
			if (predicate(me, enemy))
				victims.push_back(units[i]);
	}
	if (victims.empty())
		return nullptr;
	else
		return victims[randomNumber(victims.size() - 1)];
}

bool SimpleComputerDecision::isDeadAfterCast(const Unit& unit1, 
	const UnitPtr& unit2, MagicPtr& magic, CastPredicate castPredicate, DecisionPredicate predicate)const
{
	UnitPtr me = unit1.getPureClone();
	UnitPtr victim = unit2->getPureClone();
	if ((this->*predicate)(unit1, *unit2, magic) && unit1.isEnoughManaFor(magic))
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
		index random = randomNumber(pair.size() - 1);
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
			if (isDeadAfterCast(decidingUnit, units[j], magic, isDeadAfterBuff,
				&SimpleComputerDecision::canCastBuffOnUnit))
				victims.push_back(std::make_pair(units[j], magic->clone()));
			else if (isDeadAfterCast(decidingUnit, units[j], magic, isDeadAfterDebuff,
				&SimpleComputerDecision::canCastDebuffOnUnit))
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
			if (!decidingUnit.isAlly(*units[j]) &&
				!isWrongSpellToCast(decidingUnit, *units[j], magic) &&
				decidingUnit.isEnoughManaFor(magic)
				&& units[j]->isAlive())
			{
				me->castMagic(*enemy, magic);
				if (!enemy->isAlive())
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
		buff = DYNAMIC(IBuff*, magic);
		if (decidingUnit->isEnoughManaFor(magic))
		{
			if (!buff->isBuff() && !enemy->m_magicOnMe.hasItem(magic))
			{
				me = decidingUnit->getPureClone();
				aim = enemy->getPureClone();
				me->castMagic(*aim, magic);
				if (!aim->isAlive())
					magics.push_back(std::make_pair(enemy, magic->clone()));
				else if (!canBeKilled(me, aim))
					magics.push_back(std::make_pair(enemy, magic->clone()));
			}
			else if (buff->isBuff() && !decidingUnit->m_magicOnMe.hasItem(magic))
			{
				me = decidingUnit->getPureClone();
				me->castMagic(*me, magic);
				aim = enemy->getPureClone();
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