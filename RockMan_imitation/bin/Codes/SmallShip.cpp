#include "stdafx.h"
#include "SmallShip.h"
#include "TextureMgr.h"
#include "TimeMgr.h"
#include "RenderMgr.h"

HRESULT CSmallShip::Initialize()
{
	// Insert Ship TGA
	this->SetSortID(OBJ_NUM_BG2);
	D3DXMatrixScaling(&m_objInfo[0].matScale, -2, 2, 1);
	D3DXMatrixTranslation(&m_objInfo[0].matTrans, 700, 250, 0);
	m_objInfo[0].matWorld = m_objInfo[0].matScale * m_objInfo[0].matTrans;

	m_objInfo[0].vCenter = D3DXVECTOR3(0, 0, 0);
	m_objInfo[0].vPos = D3DXVECTOR3(0, 0, 0);

	D3DXMatrixScaling(&m_objInfo[1].matScale, 3, 3, 1);
	D3DXMatrixTranslation(&m_objInfo[1].matTrans, -300, 100, 0);
	m_objInfo[1].matWorld = m_objInfo[1].matScale * m_objInfo[1].matTrans;

	m_objInfo[1].vCenter = D3DXVECTOR3(0, 0, 0);
	m_objInfo[1].vPos = D3DXVECTOR3(0, 0, 0);
	return S_OK;
}

HRESULT CSmallShip::Progress()
{
	x = x - 100 * GET_SINGLE(CTimeMgr)->GetTime();
	if (x < -300)
		x = 1600;

	D3DXMatrixTranslation(&m_objInfo[0].matTrans, x, y, 0);
	m_objInfo[0].matWorld = m_objInfo[0].matScale * m_objInfo[0].matTrans;

	x2 = x2 + 400 * GET_SINGLE(CTimeMgr)->GetTime();
	if (x2 > 1600)
		x2 = -300;

	D3DXMatrixTranslation(&m_objInfo[1].matTrans, x2, y2, 0);
	m_objInfo[1].matWorld = m_objInfo[1].matScale * m_objInfo[1].matTrans;
	return S_OK;
}

HRESULT CSmallShip::Render()
{
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"SmallShip"),
		m_objInfo[0].matWorld, m_objInfo[0].vCenter, m_objInfo[0].vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"SmallShip"),
		m_objInfo[1].matWorld, m_objInfo[1].vCenter, m_objInfo[1].vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	return S_OK;
}

CSmallShip::CSmallShip()
{
}
CSmallShip::~CSmallShip()
{
}
