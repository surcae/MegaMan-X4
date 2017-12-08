#pragma once
#include "StaticObjects.h"

class CPlatform :
	public CStaticObjects
{
private:
	TRANSFORM plat[4];
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CPlatform();
	virtual ~CPlatform();
};

