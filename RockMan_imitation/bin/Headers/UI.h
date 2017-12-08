#pragma once
#include "StaticObjects.h"

class CUI :
	public CStaticObjects
{
public:
	HRESULT Initialize();
	HRESULT Progress();
	HRESULT Render();
public:
	CUI();
	virtual ~CUI();
};

