#include "stdafx.h"
#include "Monster.h"
#include "TextureMgr.h"
#include "RenderMgr.h"
#include "TimeMgr.h"
#include "SoundMgr.h"

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

	int j = rand() % 15;
	if (j < 7)
	{
		isFlyer = false;
	}
	else
	{
		isFlyer = true;
	}

	if (!isFlyer)
	{
		ypos = 480;
		speed = 80;
		fMax = 10;
	}
	else
	{
		speed = rand() % 100 + 200;
		ypos += (200 + ((rand() % 40) - 20));
		fMax = 3;
	}

	D3DXMatrixScaling(&m_Info.matScale, 1, 1, 1);
	D3DXMatrixTranslation(&m_Info.matTrans, xpos, ypos, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(0, 0, 0);
	return S_OK;
}

HRESULT CMonster::Progress()
{
	if (!isHit)
	{
		if (bLeft)
		{
			xpos += speed * TIME;
		}
		else if (bRight)
		{
			xpos -= speed * TIME;
		}
	}
	if (isHit)
	{
		if (!Sound)
		{
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_BOMB, 0);
			Sound = true;
		}
		boomFrame += (10 * TIME);
		if (boomFrame > 5)
		{
			Activated = false;
		}
		return S_OK;
	}
	m_Frame += (28 * TIME);
	if (m_Frame > fMax)
		m_Frame = 0.f;
	return S_OK;
}

HRESULT CMonster::Render()
{
	if (Activated)
	{
		if (isHit)
		{
			D3DXMatrixScaling(&m_Info.matScale, 3, 3, 1);
			D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
			m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Boom", L"boom", (int)boomFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
			return S_OK;
		}
		if (bLeft)
		{
			if (!isFlyer)
			{
				D3DXMatrixScaling(&m_Info.matScale, -1.2, 1.2, 1);
				D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
				m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
				GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Mop", L"Mops", (int)m_Frame),
					m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
			}
			else
			{
				D3DXMatrixScaling(&m_Info.matScale, 1.2, 1.2, 1);
				D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
				m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
				GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Mop", L"Mops2", (int)m_Frame),
					m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
			}
		}
		else if (bRight)
		{
			if (!isFlyer)
			{
				D3DXMatrixScaling(&m_Info.matScale, 1.2, 1.2, 1);
				D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
				m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
				GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Mop", L"Mops", (int)m_Frame),
					m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
			}
			else
			{
				D3DXMatrixScaling(&m_Info.matScale, -1.2, 1.2, 1);
				D3DXMatrixTranslation(&m_Info.matTrans, xpos + (*m_pvecScroll).x, ypos + m_pvecScroll->y, 0);
				m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
				GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Mop", L"Mops2", (int)m_Frame),
					m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
			}
		}
	}
	return S_OK;
}
