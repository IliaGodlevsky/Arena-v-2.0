#ifndef MAGICBOOK_H_
#define MAGICBOOK_H_

#include "../Globals/Globals.h"
#include "../Containers/TemplateContainer.h"

class MagicBook : public TemplateContainer<MagicPtr>
{
public:
	MagicBook(Unit* unit);
	MagicBook(const MagicBook& book) = delete;
	MagicBook(MagicBook&& book) = delete;
	MagicBook& operator=(const MagicBook& book) = delete;
	MagicBook& operator=(MagicBook&& book) = delete;
	MagicBook(Unit* unit, const MagicBook& book);
public:
	bool itemHasPassedControl(const MagicPtr& magic)const override;
	bool canCastAnySpell()const;
	void showShortInfo()const override;
	void magicList()const;
	void takeNew(const MagicPtr& magic) override;
private:
	Unit* m_unit = nullptr; // unit, that have this vector of magic
};
#endif