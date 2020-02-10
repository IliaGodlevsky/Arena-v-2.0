#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "../Globals/Globals.h"
#include "../UnitState/UnitState.h"
#include "../Containers/ExpireableContainer.h"

/*A container class, that collects unit
states, and checks them for expireness */
class StateHolder : public ExpireableContainer<StatePtr>
{
public:
	StateHolder(Unit* unit);
	StateHolder(Unit* unit, const StateHolder& stateHolder);
	StateHolder(const StateHolder& stateHolder) = delete;
	StateHolder(StateHolder&& stateHolder) = delete;
	StateHolder& operator=(const StateHolder& stateHolder) = delete;
	StateHolder& operator=(StateHolder&& stateHolder) = delete;
	bool itemHasPassedControl(const StatePtr& unitState)const override;
	void makeExpire(StatePtr& state)override;
	bool canCast()const;
	bool canAttack()const;
	bool canTakeDamage(Unit& unit, int damage)const;
	bool canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const;
	void takeNew(const StatePtr& unitState) override;
	void expireIfFound(const StatePtr& unitState) override;
	void takeOffExpired() override;
	~StateHolder();
private:
	void setItemColor(const StatePtr& unitState)const override;
	Unit* m_holder = nullptr;
};

#endif