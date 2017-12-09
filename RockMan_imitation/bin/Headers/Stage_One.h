#pragma once
#include "Field.h"
class CTextureMgr;
class CStage_One :
	public CField
{
private:
	// For BackGrounds
	D3DXMATRIX matScale[2];
	D3DXMATRIX matTrans[2];
	//BackGround:
	D3DXMATRIX BackMatrix[2];
	const TEXINFO* pBGTexture = nullptr;
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

