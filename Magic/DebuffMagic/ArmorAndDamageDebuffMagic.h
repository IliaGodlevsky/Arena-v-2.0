#ifndef ARMOR_AND_DAMAGE_DEBUFF_H_
#define ARMOR_AND_DAMAGE_DEBUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/ArmorReduceElem.h"
#include "../Elements/DamageReduceElem.h"

class ArmorAndDamageDebuffMagic
	: public ParamChangeMagic
{
public:
	ArmorAndDamageDebuffMagic(std::string name, int manaCost,
		Timer timer, ArmorReduceElem armorReduce,
		DamageReduceElem damageReduce);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~ArmorAndDamageDebuffMagic() = default;
private:
	ArmorReduceElem m_armorReduce;
	DamageReduceElem m_damageReduce;
};

#endif