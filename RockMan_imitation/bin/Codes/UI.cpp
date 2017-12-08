#include "stdafx.h"
#include "UI.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CUI::CUI()
{
}


CUI::~CUI()
{
}

HRESULT CUI::Initialize()
{
	// 컬링에 영향 X
	this->SetSortID(OBJ_NUM_UI);
	D3DXMatrixScaling(&m_Info.matScale, 3, 3, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, 20, 100, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);

	return S_OK;
}

HRESULT CUI::Progress()
{
	return S_OK;
}

HRESULT CUI::Render()
{
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"UI"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	return S_OK;
}
