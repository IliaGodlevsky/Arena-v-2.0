#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "../Globals/Globals.h"
#include "../UnitState/UnitState.h"
#include "../UnitState/ActiveUnitState.h"
#include "../Containers/ExpireableContainer.h"

bool isMoreImportantState(const StatePtr& st1, const StatePtr& st2);

class StateHolder : public ExpireableContainer<StatePtr>
{
public:
	StateHolder(DecisionPtr decision);
	StateHolder(Unit* unit, DecisionPtr decision, const StateHolder& stateHolder);
	StateHolder(const StateHolder& stateHolder) = delete;
	StateHolder(StateHolder&& stateHolder) = delete;
	StateHolder& operator=(const StateHolder& stateHolder) = delete;
	StateHolder& operator=(StateHolder&& stateHolder) = delete;
public:
	void makeExpire(size_t stateIndex)override;
	bool castMagic(Unit& caster, Unit& unit, MagicPtr& magic);
	bool injureUnit(WeaponPtr& weapon, Unit& unit, int damage);
	void takeNew(const StatePtr& unitState) override;
	void expireIfFound(const StatePtr& unitState) override;
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
	void takeOffExpired(int round) override;
	void showShortInfo()const override;
	~StateHolder();
private:
	DecisionPtr m_decision = nullptr;
	Unit* m_unit = nullptr;
};

#endif