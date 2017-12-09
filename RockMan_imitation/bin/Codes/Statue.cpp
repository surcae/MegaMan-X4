#include "stdafx.h"
#include "Statue.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CStatue::CStatue()
{
}


CStatue::~CStatue()
{
}

HRESULT CStatue::Initialize()
{
	// 2개 이상 만들 수 있음.
	this->SetSortID(OBJ_NUM_BG4);
	D3DXMatrixScaling(&m_Info.matScale, 3.5, 3.5, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, 100, 210, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);

	return S_OK;
}

HRESULT CStatue::Progress()
{
	D3DXMatrixTranslation(&m_Info.matTrans, 100 + (*m_pvecScroll).x, 210 + (*m_pvecScroll).y * 0.1f, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	return S_OK;
}

HRESULT CStatue::Render()
{
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Statue"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);

	D3DXMatrixTranslation(&m_Info.matTrans, 700 + (*m_pvecScroll).x, 210 + (*m_pvecScroll).y * 0.1f, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Statue"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);

	D3DXMatrixTranslation(&m_Info.matTrans, 1300 + (*m_pvecScroll).x, 210 + (*m_pvecScroll).y * 0.1f, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Statue"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	return S_OK;
}
