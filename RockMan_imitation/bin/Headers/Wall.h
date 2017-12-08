#pragma once
#include "StaticObjects.h"

class CWall :
	public CStaticObjects
{
private:
	TRANSFORM plat[4];
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CWall();
	virtual ~CWall();
};

