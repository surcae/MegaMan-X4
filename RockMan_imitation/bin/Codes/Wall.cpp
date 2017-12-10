#include "stdafx.h"
#include "Wall.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CWall::CWall()
{
}


CWall::~CWall()
{
}

HRESULT CWall::Initialize()
{
	// 2개 이상 만들 수 있음. // 94*98
	this->SetSortID(OBJ_NUM_WALL);

	D3DXMatrixScaling(&plat[0].matScale, 1.5f, 1.5f, 1);
	D3DXMatrixTranslation(&plat[0].matTrans, 650, -40, 0);
	plat[0].matWorld = plat[0].matScale * plat[0].matTrans;

	plat[0].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[0].vPos = D3DXVECTOR3(0, 0, 0);

	D3DXMatrixScaling(&plat[1].matScale, 1.5, 1.5f, 1);
	D3DXMatrixTranslation(&plat[1].matTrans, 650, 68, 0);
	plat[1].matWorld = plat[1].matScale * plat[1].matTrans;

	plat[1].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[1].vPos = D3DXVECTOR3(0, 0, 0);


	D3DXMatrixScaling(&plat[2].matScale, 1.5, 1.5f, 1);
	D3DXMatrixTranslation(&plat[2].matTrans, 650, 200, 0);
	plat[2].matWorld = plat[2].matScale * plat[2].matTrans;

	plat[2].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[2].vPos = D3DXVECTOR3(0, 0, 0);
	
	return S_OK;
}

HRESULT CWall::Progress()
{
	D3DXMatrixTranslation(&plat[0].matTrans, 650 + (*m_pvecScroll).x, -140 + (*m_pvecScroll).y, 0);
	plat[0].matWorld = plat[0].matScale * plat[0].matTrans;
	D3DXMatrixTranslation(&plat[1].matTrans, 650 + (*m_pvecScroll).x, -32 + (*m_pvecScroll).y, 0);
	plat[1].matWorld = plat[1].matScale * plat[1].matTrans;
	D3DXMatrixTranslation(&plat[2].matTrans, 650 + (*m_pvecScroll).x, 100 + (*m_pvecScroll).y, 0);
	plat[2].matWorld = plat[2].matScale * plat[2].matTrans;
	return S_OK;
}

HRESULT CWall::Render()
{
	for (int i = 0; i < 3; i++)
	{

		GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Wall"),
			plat[i].matWorld, plat[i].vCenter, plat[i].vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
	}	
	return S_OK;
}
