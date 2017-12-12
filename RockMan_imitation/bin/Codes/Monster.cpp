#include "stdafx.h"
#include "Monster.h"
#include "TextureMgr.h"
#include "RenderMgr.h"
#include "TimeMgr.h"

#define TIME GET_SINGLE(CTimeMgr)->GetTime() 
CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

HRESULT CMonster::Initialize()
{
	// Insert Ship TGA
	int i = rand() % 10;
	if (i < 5)
	{
		this->xpos = -200;
		bLeft = true;
	}
	else
	{
		this->xpos = 1600;
		bRight = true;
	}

	ypos = 480;

	D3DXMatrixScaling(&m_Info.matScale, 1, 1, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, xpos, ypos, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);
	return S_OK;
}

HRESULT CMonster::Progress()
{
	if (bLeft)
	{
		xpos += 50 * TIME;
	}
	else if(bRight)
	{
		xpos -= 50 * TIME;
	}
	if (isHit)
	{
		boomFrame += (20 * TIME);
		if (boomFrame > 5)
			Activated = false;
		return S_OK;
	}
	m_Frame += (20 * TIME);
	if (m_Frame > 10)
		m_Frame = 0.f;
	return S_OK;
}

HRESULT CMonster::Render()
{
	if (Activated)
	{
		if (isHit)
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Boom", L"boom", (int)boomFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
			return S_OK;
		}
		if (bLeft)
		{
			D3DXMatrixScaling(&m_Info.matScale, -1, 1, 1);
			D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
			m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Mop", L"Mops", (int)m_Frame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		else if (bRight)
		{
			D3DXMatrixScaling(&m_Info.matScale, 1, 1, 1);
			D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
			m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Mop", L"Mops", (int)m_Frame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
	}
	return S_OK;
}
