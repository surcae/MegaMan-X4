#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"

CLogo::CLogo()
{
}
CLogo::~CLogo()
{
}

HRESULT CLogo::Initialize() {
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/TopBackGrounds.png",
		TEXTYPE_SINGLE, this->m_LogoObjKey)))
	{
		TEXTURE_ERROR_MSG(BackGround);
		return E_FAIL;
	}

	const TEXINFO* pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(this->m_LogoObjKey);
	if (!pTexInfo)
		return E_FAIL;
	m_vCenter = D3DXVECTOR2(pTexInfo->ImageInfo.Width / 2.f,
		pTexInfo->ImageInfo.Height / 2.f);
	
	return S_OK;
};
HRESULT CLogo::Progress() {
	return S_OK; 
};
HRESULT CLogo::Render() { 
	/*Local_Sprite->SetTransform(&m_matWorld);
	Local_Sprite->Draw(pTexInfo->pTexture, NULL,
		&m_Info.vCenter, NULL, D3DCOLOR_ARGB(255, 0, 255, 255));
	GET_SINGLE(CDevice)->GetSprite();*/
	return S_OK;
};
HRESULT CLogo::Release() { return S_OK; };
