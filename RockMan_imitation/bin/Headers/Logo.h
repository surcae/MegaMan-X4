#pragma once
#include "MyScene.h"
#include "Device.h"
#include "TextureMgr.h"

class CLogo : 
	public CMyScene
{
private:
	D3DXVECTOR3 m_vPos = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXVECTOR3 m_vCenter = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXMATRIX m_matWorld;
	const TCHAR* m_LogoObjKey = L"LogoObj";
private: // Fast Dotting
	const LPD3DXSPRITE m_pMember_Sprite = GET_SINGLE(CDevice)->GetSprite();
	const TEXINFO* m_pTexInfo;
public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress();
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	CLogo();
	~CLogo();
};

