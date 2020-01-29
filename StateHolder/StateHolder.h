#ifndef STATE_HOLDER_H_
#define STATE_HOLDER_H_

#include "../Globals/Globals.h"
#include "../UnitState/UnitState.h"
#include "../Containers/ExpireableContainer.h"

bool isMoreImportantState(const StatePtr& st1, 
	const StatePtr& st2);
template <typename Predicate>
bool stateAccumulator(const std::vector<StatePtr>& states, 
	Predicate pred)
{
	bool accum = true;
	for (size_t i = 0; i < states.size(); i++)
		accum = pred(states[i], accum);
	return accum;
}
bool castAccum(const StatePtr st1, bool accum);
bool attackAccum(const StatePtr st1, bool accum);

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
	void makeExpire(size_t stateIndex)override;
	bool canCast()const;
	bool canAttack()const;
	bool canTakeDamage(Unit& unit, int damage)const;
	bool canTakeMagicEffect(Unit& unit, Unit& caster, MagicPtr& magic)const;
	void takeNew(const StatePtr& unitState) override;
	void expireIfFound(const StatePtr& unitState) override;
	void takeOffExpired() override;
	void showShortInfo()const override;
	void setItemColor(const StatePtr& unitState)const override;
	~StateHolder();
private:
	Unit* m_holder = nullptr;
};

#endif