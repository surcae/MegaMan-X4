#pragma once
#include "StaticObjects.h"

class CSBigShip :
	public CStaticObjects
{
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CSBigShip();
	virtual ~CSBigShip();
};

