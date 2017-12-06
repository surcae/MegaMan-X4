#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"
#include "KeyMgr.h"
#include "RenderMgr.h"
#include "Factory.h"

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
		TEXTURE_ERROR_MSG(L"BackGround");
		return E_FAIL;
	}

	// LogoRes below
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/SelectRock.png",
		TEXTYPE_SINGLE, L"SelectRock")))
	{
		TEXTURE_ERROR_MSG(L"SelectRock");
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/SelectZero.png",
		TEXTYPE_SINGLE, L"SelectZero")))
	{
		TEXTURE_ERROR_MSG(L"SelectZero");
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/SelectImgRock%d.png",
		TEXTYPE_MULTI, L"SelectImgR", L"State_SelectRock", 3)))
	{
		TEXTURE_ERROR_MSG(L"SelectRock");
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/SelectImgZero%d.png",
		TEXTYPE_MULTI, L"SelectImgR", L"State_SelectZero", 3)))
	{
		TEXTURE_ERROR_MSG(L"SelectZero");
		return E_FAIL;
	}
	
	this->m_pLogoTexInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"Selects");
	if (!m_pLogoTexInfo)
		return E_FAIL;
	
	/* 표본 보고 따라할 것 */
	D3DXMATRIX matTrans;
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, 2.5f, 2.5f, 1.f);
	D3DXMatrixTranslation(&matTrans, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matScale * matTrans;
	
	m_vCenter = D3DXVECTOR3(m_pLogoTexInfo->ImageInfo.Width / 2.f,
		m_pLogoTexInfo->ImageInfo.Height / 2.f, 0.f);

	if (FAILED(TextureSetting(m_vecLogoRes)))
	{
		MessageBox(g_hWnd, L"Logo Transforming Failed", L"Error!", MB_HELP);
		return E_FAIL;
	}

	return S_OK;
};

void CLogo::StartAnim()
{

}

HRESULT CLogo::TextureSetting(std::vector<TRANSFORM*>& _param)
{
	for (vector<TRANSFORM*>::iterator iter = _param.begin(); iter != _param.end(); ++iter)
	{
		switch ((*iter)->myLogoObj)
		{
		case LOGO_ROCK_1:
		{
			(*iter)->texInfo = GET_SINGLE(CTextureMgr)->GetTexture(L"SelectRock");
			// push_back();
		}
		break;
		case LOGO_ROCK_2:
		{

		}
		break;
		case LOGO_ZERO_3:
		{

		}
		break;
		case LOGO_ZERO_4:
		{

		}
		break;
		case LOGO_ROCKTEXT_5:
		{

		}
		break;
		case LOGO_ZEROTEXT_6:
		{

		}
		break;
		}
		if ((*iter)->matScale != NULL)
			D3DXMatrixScaling(&(*iter)->matScale, 2.5f, 2.5f, 1.0f);

		D3DXMatrixTranslation(&(*iter)->matWorld, m_vCenter.x, m_vCenter.y, m_vCenter.z); //(*iter)->matScale, (*iter)->matRot, (*iter)->matTrans)
	}
	return S_OK;
}

HRESULT CLogo::Progress() {
	StartAnim();

	if (GetAsyncKeyState(VK_RETURN))
	{
		// Before change my stage, first you need to call Release();
		// TODO: Change Stage

	// TODO: If you pressed any key, call CSceneMgr that change Stage
		return S_OK;
	}
	
	return S_OK;
};

HRESULT CLogo::Render() { 
	pRenderMgr->SingleRender(m_pLogoTexInfo, m_matWorld, 
		m_vCenter, m_vPosition, E_SINGLE_RENDER_TYPE_FADING, NULL);

	for (size_t i = 0; m_vecLogoRes.size(); ++i)
	{
		//pRenderMgr->SingleRender(&m_vecLogoRes[LOGO_ROCK_1]->texInfo, m_vecLogoRes[LOGO_ROCK_1]->matWorld, 
		//m_vecLogoRes[LOGO_ROCK_1]->vCenter, m_vecLogoRes[LOGO_ROCK_1]->vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);

		//Multi
		//int Cnt = GET_SINGLE(CTextureMgr)->GetTexture(m_vecLogoRes[i]->ObjName, m_vecLogoRes[i]->pStateKey, m_vecLogoRes[i].)
		//pRenderMgr->MultiRender(&m_vecLogoRes[i]->texInfo, m_vecLogoRes[i]->matWorld, E_MULTI_RENDER_TYPE_STRAIGHT, m_vecLogoRes[i])
	}

	return S_OK;
};
HRESULT CLogo::Release() {
	return S_OK;
};
