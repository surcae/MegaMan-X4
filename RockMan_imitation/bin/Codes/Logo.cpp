#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"
#include "KeyMgr.h"
#include "RenderMgr.h"

int Alpha = 0;

CLogo::CLogo()
{
	D3DXMatrixIdentity(&m_matWorld);
}
CLogo::~CLogo()
{
}

HRESULT CLogo::Initialize() {
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/Logo.png",
		TEXTYPE_SINGLE, this->m_LogoObjKey)))
	{
		TEXTURE_ERROR_MSG(BackGround);
		return E_FAIL;
	}

	this->m_pLogoTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(this->m_LogoObjKey);
	
	if (!m_pLogoTexInfo)
		return E_FAIL;
	
	D3DXMATRIX matTrans;
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	m_matWorld = matTrans;
	

	m_vCenter = D3DXVECTOR3(m_pLogoTexInfo->ImageInfo.Width / 2.f,
		m_pLogoTexInfo->ImageInfo.Height / 2.f, 0.f);
	return S_OK;
};
HRESULT CLogo::Progress() {
	if (GetAsyncKeyState(VK_RETURN))
	{
		// Before change my stage, first you need to call Release();
		this->Release();
		// Change Stage
		
	}
	// TODO: If you pressed any key, call CSceneMgr that change Stage
	return S_OK; 
};
HRESULT CLogo::Render() { 
	GET_SINGLE(CRenderMgr)->SingleRender(m_pLogoTexInfo, m_matWorld, 
		m_vCenter, m_vPosition, E_SINGLE_RENDER_TYPE_FADING, NULL);
	/*m_pMember_Sprite->SetTransform(&m_matWorld);
	if (Alpha >= 255)
		Alpha = 255;
	else
	{
		Alpha += 2;
	}
	m_pMember_Sprite->Draw(m_pLogoTexInfo->pTexture, NULL,
	&m_vCenter, &m_vPosition, D3DCOLOR_ARGB(Alpha, 255, 255, 255));*/
	
	return S_OK;
};
HRESULT CLogo::Release() {
	return S_OK;
};
