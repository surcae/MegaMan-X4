#pragma once
#include "DynamicObjects.h"
class CSmallShip :
	public CDynamicObjects
{
private:
	float x = 700, y = 250, x2 = -300, y2 = 100;
	TRANSFORM m_objInfo[2];
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CSmallShip();
	virtual ~CSmallShip();
};

