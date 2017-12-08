#pragma once
#include "StaticObjects.h"

class CStatue :
	public CStaticObjects
{
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CStatue();
	virtual ~CStatue();
};

