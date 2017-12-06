#pragma once
#include "Field.h"
class CTextureMgr;
class CStage_One :
	public CField
{
private:
	CTextureMgr* pTextureMgr = nullptr;
public:
	virtual HRESULT Initialize(void);
	virtual HRESULT Progress(void);
	virtual HRESULT Render(void);
	virtual HRESULT Release(void);
public:
	CStage_One();
	~CStage_One();
};

