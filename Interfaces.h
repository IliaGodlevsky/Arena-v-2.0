#pragma once

#ifndef INTERFACE_H_
#define INTERFACE_H_

// conception is taken from C#, were you can inherit
// from the interface
class IChangeBattleParams
{
public:
	virtual void ChangeParam(int extend) = 0;
	virtual void ChangeLimit(int extend) = 0;
};


#endif