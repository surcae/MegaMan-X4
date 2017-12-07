#pragma once
#include "DynamicObjects.h"
class CSmallShip :
	public CDynamicObjects
{
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CSmallShip();
	virtual ~CSmallShip();
};

