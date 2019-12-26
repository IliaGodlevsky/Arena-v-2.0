//#include "ComputerDecision.h"
//
//#include "../Magic/Magic.h"
//#include "../Unit/Unit.h"
//
//ComputerDecision::ComputerDecision()
//{
//	// create vector with pointers to a method
//}
//
////UnitPtr ComputerDecision::chooseUnitToAttack(const Unit& decidingUnit,
////	const Gladiators& arena)const
////{
////	return m_unitToAttack;
////}
////
////MagicPtr ComputerDecision::chooseMagicToCast(const Unit& decidingUnit,
////	const Gladiators& arena)const
////{
////	decide(decidingUnit, arena);
////	return m_magicToCast->clone();
////}
////
////UnitPtr ComputerDecision::chooseUnitToCast(const Unit& decidingUnit, 
////	const MagicPtr& magicToCast, const Gladiators& arena)const
////{
////	return m_unitToCast;
////}
//
//index ComputerDecision::chooseUnitToKillByWeapon(Unit& decidingUnit, Gladiators& arena)
//{
//	for (size_t i = 0; i < arena.size(); i++)
//	{
//		if (!isSameUnit(decidingUnit, *arena[i]))
//		{
//			decidingUnit.injureUnit(*arena[i]);
//			if (!arena[i]->isAlive())
//				return i;
//		}
//	}
//	return arena.size();
//}
//
//index ComputerDecision::chooseUnitToKillWithMagic(Unit& decidingUnit, Gladiators& arena)
//{
//	for (size_t i = 0; i < arena.size(); i++)
//	{
//		for (size_t j = 0; j < decidingUnit.m_magicBook.size(); j++)
//		{
//			if (!isSameUnit(decidingUnit, *arena[i]))
//			{
//				decidingUnit.castMagic(*arena[i], decidingUnit.m_magicBook[j]);
//				if (!arena[i]->isAlive())
//				{
//					m_magicToCast = decidingUnit.m_magicBook[j]->clone();
//					return i;
//				}
//			}
//		}
//	}
//	return arena.size();
//}
//
//index ComputerDecision::chooseUnitToKillWithMagicAndWeapon(Unit& decidingUnit, Gladiators& arena)
//{
//	for (size_t i = 0; i < arena.size(); i++)
//	{
//		for (size_t j = 0; j < decidingUnit.m_magicBook.size(); j++)
//		{
//			if (!isSameUnit(decidingUnit, *arena[i]))
//			{
//				decidingUnit.castMagic(*arena[i], decidingUnit.m_magicBook[j]);
//				decidingUnit.injureUnit(*arena[i]);
//				if (!arena[i]->isAlive())
//				{
//					m_magicToCast = decidingUnit.m_magicBook[j]->clone();
//					return i;
//				}
//			}
//		}
//	}
//	return arena.size();
//}
//
//index ComputerDecision::findUnitCanKillYouByWeapon(Unit& decidingUnit, Gladiators& arena)
//{
//	for (size_t i = 0; i < arena.size(); i++)
//	{
//		if (isSameUnit(decidingUnit, *arena[i]))
//		{
//			arena[i]->injureUnit(decidingUnit);
//			if (!decidingUnit.isAlive())
//				return i;
//		}
//	}
//	return arena.size();
//}
//
//index ComputerDecision::findUnitCanKillYouByMagic(Unit& decidingUnit, Gladiators& arena)
//{
//	for (size_t i = 0; i < arena.size(); i++)
//	{
//		for (size_t j = 0; j < arena[i]->m_magicBook.size(); j++)
//			if (isSameUnit(decidingUnit, *arena[i]))
//			{
//				arena[i]->castMagic(decidingUnit, arena[i]->m_magicBook[j]);
//				if (!decidingUnit.isAlive())
//					return i;
//			}
//	}
//	return arena.size();
//}
//
//index ComputerDecision::findUnitCanKillYouWithWeaponAndMagic(Unit& decidingUnit, Gladiators& arena)
//{
//	for (size_t i = 0; i < arena.size(); i++)
//	{
//		for (size_t j = 0; j < arena[i]->m_magicBook.size(); j++)
//			if (isSameUnit(decidingUnit, *arena[i]))
//			{
//				arena[i]->castMagic(decidingUnit, arena[i]->m_magicBook[j]);
//				arena[i]->injureUnit(decidingUnit);
//				if (!decidingUnit.isAlive())
//					return i;
//			}
//	}
//	return arena.size();
//}
//
//index ComputerDecision::chooseRandomUnitToAttack(Unit& decidingUnit, Gladiators& arena)
//{
//	index randomUnitIndex = randomNumber(arena.size() - 1);
//	while(isSameUnit(*arena[randomUnitIndex],decidingUnit))
//		randomUnitIndex = randomNumber(arena.size() - 1);
//	return randomUnitIndex;
//}
//
//index ComputerDecision::chooseRandomUnitToCast(Unit& decidingUnit, Gladiators& arena)
//{
//	return chooseRandomUnitToAttack(decidingUnit, arena);
//}
//
//void ComputerDecision::prepareUnitForSimulation(const Unit& decidingUnit, UnitPtr simulateUnit)
//{
//	simulateUnit = decidingUnit.clone();
//	simulateUnit->m_weapon = decidingUnit.m_weapon->getPureWeapon();
//	simulateUnit->m_shield = decidingUnit.m_shield->getPureShield();
//}
//
//void ComputerDecision::prepareUnitsForSimulation(const Gladiators& arena, Gladiators& simulateArena)
//{
//	for (size_t l = 0; l < arena.size(); l++)
//		prepareUnitForSimulation(*arena[l], simulateArena[l]);
//}
//
//index ComputerDecision::simulate(const Unit& decidingUnit, const Gladiators& arena)
//{
//	index unitIndex = 0;
//	UnitPtr me;
//	Gladiators alterArena;
//	for (size_t i = 0; i < battleStates.size();i++)
//	{
//		prepareUnitForSimulation(decidingUnit, me);
//		prepareUnitsForSimulation(arena, alterArena);
//		unitIndex = (this->*battleStates[i])(*me, alterArena);
//	}
//	return unitIndex;
//}