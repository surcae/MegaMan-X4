#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"
#include "KeyMgr.h"
#include "RenderMgr.h"

CLogo::CLogo()
{
	D3DXMatrixIdentity(&m_matWorld);
}
CLogo::~CLogo()
{
}

HRESULT CLogo::Initialize() {
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/Select.png",
		TEXTYPE_SINGLE, L"Selects")))
	{
		TEXTURE_ERROR_MSG(BackGround);
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/SelectRock.png",
		TEXTYPE_SINGLE, L"SelectRock")))
	{
		TEXTURE_ERROR_MSG(BackGround);
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/SelectZero.png",
		TEXTYPE_SINGLE, L"SelectZero")))
	{
		TEXTURE_ERROR_MSG(BackGround);
		return E_FAIL;
	}	

	this->m_pLogoTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Selects");
	
	if (!m_pLogoTexInfo)
		return E_FAIL;
	
	D3DXMATRIX matTrans;
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, 1.5f, 1.5f, 1.f);
	D3DXMatrixTranslation(&matTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	m_matWorld = matScale * matTrans;
	

	m_vCenter = D3DXVECTOR3(m_pLogoTexInfo->ImageInfo.Width / 2.f,
		m_pLogoTexInfo->ImageInfo.Height / 2.f, 0.f);
	return S_OK;
};
HRESULT CLogo::Progress() {
	if (GetAsyncKeyState(VK_RETURN))
	{
		// Before change my stage, first you need to call Release();
		// TODO: Change Stage
		
	}
	// TODO: If you pressed any key, call CSceneMgr that change Stage
	return S_OK; 
};
HRESULT CLogo::Render() { 
	GET_SINGLE(CRenderMgr)->SingleRender(m_pLogoTexInfo, m_matWorld, 
		m_vCenter, m_vPosition, E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
	return S_OK;
};
HRESULT CLogo::Release() {
	return S_OK;
};
