#ifndef COMPUTER_DECISION_H_
#define COMPUTER_DECISION_H_

#include "Decision.h"

class ComputerDecision : public Decision
{
public:
	ComputerDecision();
	UnitPtr chooseUnitToAttack(const Unit&, 
		const Gladiators&)const override;
	MagicPtr chooseMagicToCast(const Unit&, 
		const Gladiators&)const override;
	UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, 
		const Gladiators&)const override;
private:
	using BattleState = index(ComputerDecision::*)(Unit&, Gladiators&);
	index chooseUnitToKillByWeapon(Unit& decidingUnit, Gladiators& arena);
	index chooseUnitToKillWithMagic(Unit& decidingUnit, Gladiators& arena);
	index chooseUnitToKillWithMagicAndWeapon(Unit& decidingUnit, Gladiators& arena);
	index findUnitCanKillYouByWeapon(Unit& decidingUnit, Gladiators& arena);
	index findUnitCanKillYouByMagic(Unit& decidingUnit, Gladiators& arena);
	index findUnitCanKillYouWithWeaponAndMagic(Unit& decidingUnit, Gladiators& arena);
	index chooseRandomUnitToAttack(Unit& decidingUnit, Gladiators& arena);
	index chooseRandomUnitToCast(Unit& decidingUnit, Gladiators& arena);
private:
	MagicPtr chooseMagicToPreventKillWithMagic(UnitPtr enemy)const;
	MagicPtr chooseMagicToPreventKillByWeapon(UnitPtr enemy)const;
	MagicPtr chooseRandomMagicToCast(UnitPtr enemy)const;
private:
	index simulate(const Unit& decidingUnit, const Gladiators& arena);
	void prepareUnitForSimulation(const Unit& decidingUnit, UnitPtr simulateUnit);
	void prepareUnitsForSimulation(const Gladiators& arena, Gladiators& simulateArena);
private:
	std::vector<BattleState> battleStates;
	MagicPtr m_magicToCast;
	UnitPtr m_unitToCast;
	UnitPtr m_unitToAttack;
};

#endif