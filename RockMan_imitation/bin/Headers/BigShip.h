#pragma once
#include "DynamicObjects.h"
class CBigShip :
	public CDynamicObjects
{
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CBigShip();
	virtual ~CBigShip();
};

