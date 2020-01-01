#ifndef MAGICBOOK_H_
#define MAGICBOOK_H_

#include "../Globals/Globals.h"
#include "../Containers/TemplateContainer.h"

class MagicBook : public TemplateContainer<MagicPtr>
{
public:
	MagicBook(Unit* unit);
	MagicBook(Unit* unit, const MagicBook& book);
	bool canCastAnySpell()const;
	void showShortInfo()const override;
	void magicList()const;
	void takeNew(const MagicPtr& magic) override;
private:
	Unit* m_unit; // unit, that have this vector of magic
};
#endif