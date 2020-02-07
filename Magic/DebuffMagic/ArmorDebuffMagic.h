#ifndef ARMOR_DEBUFF_H_
#define ARMOR_DEBUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/ArmorReduceElem.h"

class ArmorDebuffMagic : public ParamChangeMagic
{
public:
	ArmorDebuffMagic(std::string name, int manaCost,
		Time time, ArmorReduceElem armorReduce);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~ArmorDebuffMagic() = default;
private:
	ArmorReduceElem m_armorReduce;
};

#endif