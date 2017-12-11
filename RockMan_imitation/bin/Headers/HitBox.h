#pragma once
#include "StaticObjects.h"

class CHitBox :
	public CStaticObjects
{
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CHitBox();
	virtual ~CHitBox();
};

