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
	D3DXMatrixScaling(&m_Info.matScale, 3, 3, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, 300, 300, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);


	
	return S_OK;
}

HRESULT CSBigShip::Progress()
{
	return S_OK;
}

HRESULT CSBigShip::Render()
{
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BigShip"),
		m_Info.matWorld, m_Info.vCenter, m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	return S_OK;
}
