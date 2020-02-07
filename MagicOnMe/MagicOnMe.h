#ifndef MAGIC_ON_ME
#define MAGIC_ON_ME

#include "../Globals/Globals.h"
#include "../Containers/ExpireableContainer.h"

/* A container that collects magics, under what unit is*/
class MagicOnMe : public ExpireableContainer<MagicPtr>
{
public:
	MagicOnMe(Unit* unit);
	MagicOnMe(Unit* unit, const MagicOnMe& magicOnMe);
	MagicOnMe(const MagicOnMe&) = delete;
	MagicOnMe(MagicOnMe&&) = delete;
	MagicOnMe& operator=(const MagicOnMe&) = delete;
	MagicOnMe& operator=(MagicOnMe&&) = delete;
	bool itemHasPassedControl(const MagicPtr& magic)const override;
	void takeOffExpired() override;
	void takeNew(const MagicPtr& magic) override;
	void showShortInfo()const override;
	void makeExpire(MagicPtr& magic)override;
private:
	void showItem(const MagicPtr& magic)const override;
	void setItemColor(const MagicPtr& magic)const override;
	Unit* m_unit = nullptr; // unit, that have this vector of spells
};
#endif