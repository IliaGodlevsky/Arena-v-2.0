#ifndef MAGIC_ON_ME
#define MAGIC_ON_ME

#include "../Globals/Globals.h"
#include "../Containers/ExpireableContainer.h"

class MagicOnMe : public ExpireableContainer<MagicPtr>
{
public:
	MagicOnMe(Unit* unit);
	MagicOnMe(Unit* unit, const MagicOnMe& magicOnMe);
	MagicOnMe(const MagicOnMe&) = delete;
	MagicOnMe(MagicOnMe&&) = delete;
	MagicOnMe& operator=(const MagicOnMe&) = delete;
	MagicOnMe& operator=(MagicOnMe&&) = delete;
public:
	void takeOffExpired(int round) override;
	void takeNew(const MagicPtr& magic) override;
	void showShortInfo()const override;
	void makeExpire(size_t magicIndex)override;
private:
	Unit* m_unit = nullptr; // unit, that have this vector of spells
};
#endif