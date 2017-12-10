#include "stdafx.h"
#include "BigShip.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CBigShip::CBigShip()
{
}


CBigShip::~CBigShip()
{
}

HRESULT CBigShip::Initialize()
{
	// Insert Ship TGA
	this->SetSortID(OBJ_NUM_BG);

	xpos = 100;
	ypos = 100;

	D3DXMatrixScaling(&m_Info.matScale, -2, 2, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, xpos, ypos, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);
	return S_OK;
}

HRESULT CBigShip::Progress()
{
	xpos = xpos + 100 * GET_SINGLE(CTimeMgr)->GetTime();
	if (xpos > 3000)
		xpos = -50;

	D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + (*m_pvecScroll).y * 0.5f, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	return S_OK;
}

HRESULT CBigShip::Render()
{
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BigShip"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	return S_OK;
}
