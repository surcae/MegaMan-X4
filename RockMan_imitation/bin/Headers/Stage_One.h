#pragma once
#include "Field.h"
class CStage_One :
	public CField
{
public:
	virtual HRESULT Initialize(void);
	virtual HRESULT Progress(void);
	virtual HRESULT Render(void);
	virtual HRESULT Release(void);
public:
	CStage_One();
	~CStage_One();
};

