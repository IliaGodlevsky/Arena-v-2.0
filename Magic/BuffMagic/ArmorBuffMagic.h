#ifndef ARMOR_BUFF_H_
#define ARMOR_BUFF_H_

#include "../Magic.h"

class ArmorBuffMagic : virtual public Magic
{
public:
	ArmorBuffMagic(std::string name, int manaCost,
		const Timer& timer, int armorAmplify);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~ArmorBuffMagic() = default;
protected:
	int m_armorAmplify = 0;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const;
	virtual void putOn(Unit& unit)const;
};

#endif