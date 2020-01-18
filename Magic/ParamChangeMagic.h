#ifndef PARAM_CHANGE_MAGIC_H_
#define PARAM_CHANGE_MAGIC_H_

#include "FreeParamChangeMagic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"
#include "../Timer/Timer.h"

class ParamChangeMagic : public FreeParamChangeMagic, 
	public IBuff, public IManaCost
{
public:
	ParamChangeMagic(std::string name, int manaCost,
		Timer timer);
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	int getCost()const override;
	int getDuration()const override;
	int getStartTime()const override;
	void setStartTime(int round)override;
	bool isExpired()const override;
	virtual ~ParamChangeMagic() = default;
protected:
	int m_manaCost = 0;
};
#endif