#ifndef MAGICBOOK_H_
#define MAGICBOOK_H_

#include "../Globals/Globals.h"
#include "../Containers/TemplateContainer.h"

/* A class, that collects magic, that can be casted*/
class MagicBook : public TemplateContainer<MagicPtr>
{
public:
	MagicBook(Unit* unit);
	MagicBook(const MagicBook& book) = delete;
	MagicBook(MagicBook&& book) = delete;
	MagicBook& operator=(const MagicBook& book) = delete;
	MagicBook& operator=(MagicBook&& book) = delete;
	MagicBook(Unit* unit, const MagicBook& book);
	bool itemHasPassedControl(const MagicPtr& magic)const override;
	bool canCastAnySpell()const;
	void showFullInfo()const;
	void showListOfMagic()const;	
	void takeNew(const MagicPtr& magic) override;
private:
	using ShowMethod = void(MagicBook::*)(const MagicPtr&)const;
	void showInfo(const ShowMethod& show)const;
	void showFull(const MagicPtr& magic)const;
	void showShort(const MagicPtr& magic)const;
	void setItemColor(const MagicPtr& magic)const override;
	Unit* m_unit = nullptr; // unit, that have this vector of magic
};
#endif