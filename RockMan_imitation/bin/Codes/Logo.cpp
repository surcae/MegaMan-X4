#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"
#include "KeyMgr.h"

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
	this->m_pTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(this->m_LogoObjKey);
	
	if (!m_pTexInfo)
		return E_FAIL;
	
	D3DXMATRIX matTrans;
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	m_matWorld = matTrans;
	

	m_vCenter = D3DXVECTOR3(m_pTexInfo->ImageInfo.Width / 2.f,
		m_pTexInfo->ImageInfo.Height / 2.f, 0.f);
	return S_OK;
};
HRESULT CLogo::Progress() {
	// TODO: If you pressed any key, call CSceneMgr that change Stage
	return S_OK; 
};
HRESULT CLogo::Render() { 
	m_pMember_Sprite->SetTransform(&m_matWorld);
	m_pMember_Sprite->Draw(m_pTexInfo->pTexture, NULL,
		&m_vCenter, &m_vPosition, D3DCOLOR_ARGB(255, 0, 255, 255));
	return S_OK;
};
HRESULT CLogo::Release() {
	return S_OK;
};
