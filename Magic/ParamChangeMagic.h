#ifndef PARAM_CHANGE_MAGIC_H_
#define PARAM_CHANGE_MAGIC_H_

#include "FreeParamChangeMagic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"

/* A base class for all magic, that comes to magic book*/
class ParamChangeMagic : public FreeParamChangeMagic, 
	public IBuff, public IManaCost
{
public:
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	virtual ~ParamChangeMagic() = default;
	ParamChangeMagic(std::string name, int manaCost,
		Time time, const ElementsInit& holder);
	ParamChangeMagic(std::string name, int manaCost,
		Time time, const ElementHolder& holder);
};
#endif
