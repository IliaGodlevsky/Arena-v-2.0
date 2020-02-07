#ifndef ARMOR_BUFF_H_
#define ARMOR_BUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/ArmorAmplifyElem.h"

class ArmorBuffMagic : public ParamChangeMagic
{
public:
	ArmorBuffMagic(std::string name, int manaCost,
		Time time, ArmorAmplifyElem armorAmplify);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~ArmorBuffMagic() = default;
private:
	ArmorAmplifyElem m_armorAmplify;
};

#endif