#pragma once
#include "MyScene.h"
#include "Device.h"
class CLogo : 
	public CMyScene
{
private:
	const D3DXVECTOR3 m_vPos = D3DXVECTOR3(0.f, 0.f, 0.f);
	D3DXVECTOR2 m_vCenter = D3DXVECTOR2(0.f, 0.f);
	D3DXMATRIX m_matWorld;
	const TCHAR* m_LogoObjKey = L"LogoObj";
private: // Fast 
	const LPD3DXSPRITE Local_Sprite = GET_SINGLE(CDevice)->GetSprite();

public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress();
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	CLogo();
	~CLogo();
};

