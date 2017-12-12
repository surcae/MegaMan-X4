#include "stdafx.h"
#include "SBigShip.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CSBigShip::CSBigShip()
{
}


CSBigShip::~CSBigShip()
{
}

HRESULT CSBigShip::Initialize()
{
	// Insert Ship TGA
	this->SetSortID(OBJ_NUM_BG3);
	D3DXMatrixScaling(&m_Info.matScale, 4.5, 4.5, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, 200, 150, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);

	return S_OK;
}

HRESULT CSBigShip::Progress()
{
	D3DXMatrixTranslation(&m_Info.matTrans, 200 + (*m_pvecScroll).x, 150 + (*m_pvecScroll).y * 0.5f, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	return S_OK;
}

HRESULT CSBigShip::Render()
{
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BigShip"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	return S_OK;
}
