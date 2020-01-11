#ifndef OFFSET_DAMAGE_BUFF_H_
#define OFFSET_DAMAGE_BUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/DamageAmplifyElem.h"
#include "../Elements/ArmorReduceElem.h"

class OffsetDamageBuffMagic
	: public ParamChangeMagic
{
public:
	OffsetDamageBuffMagic(std::string name, int manaCost,
		Timer timer, ArmorReduceElem armorReduce, 
		DamageAmplifyElem damageAmplify);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~OffsetDamageBuffMagic() = default;
private:
	DamageAmplifyElem m_damageAmplify;
	ArmorReduceElem m_armorReduce;
};

#endif