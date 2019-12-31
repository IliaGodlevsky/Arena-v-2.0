#ifndef MAGIC_ON_ME
#define MAGIC_ON_ME

#include "../Globals/Globals.h"
#include "../Containers/ExpireableContainer.h"

class MagicOnMe : public ExpireableContainer<MagicPtr>
{
public:
	MagicOnMe(Unit* unit);
	void takeOffExpired(int round) override;
	void takeNew(const MagicPtr& magic) override;
	void showShortInfo()const override;
private:
	Unit* m_unit; // unit, that have this vector of spells
};
#endif