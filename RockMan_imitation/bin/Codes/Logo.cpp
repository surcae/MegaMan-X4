#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"
#include "KeyMgr.h"
#include "RenderMgr.h"

CLogo::CLogo()
{
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
	m_pMember_Sprite->SetTransform(&m_matWorld);
	m_pMember_Sprite->Draw(m_pLogoTexInfo->pTexture, NULL,
		&m_vCenter, &m_vPosition, D3DCOLOR_ARGB(255, 255, 255, 255));
	return S_OK;
};
HRESULT CLogo::Release() {
	// 여기하면서 Release() 각각 호출하는중이었음.
	// CTextureMgr 싱글턴 호출해서 Release(TEXTURE, TYPE) 해서 릴리즈 해주고 다 릴리즈 해야함.
	// 다음 스테이지 가기 전에 정말 안 쓰는 메모리는 지워줘야함.
	//this->m_pLogoTexInfo->ImageInfo
	return S_OK;
};
