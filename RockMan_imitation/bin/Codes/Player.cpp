#include "stdafx.h"
#include "Player.h"
#include "RenderMgr.h"
#include "CollisionMgr.h"
#include "ObjSortMgr.h"
#include "TextureMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"

#define KEY_DOWN(code) ((GetAsyncKeyState(code)&0x8000)?1:0)
#define TIME GET_SINGLE(CTimeMgr)->GetTime() 
#define LOOP 1
#define NOLOOP 0

bool CPlayer::isSpawn = false;

CPlayer::CPlayer()
{
	x = 1000.f;
	y = 200.f;
}
CPlayer::~CPlayer()
{
}

void CPlayer::Transforming()
{
}

void CPlayer::KeyCheck()
{
	if (KEY_DOWN(VK_LEFT))
	{
		x -= m_fSpeed * TIME;
		(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		x += m_fSpeed * TIME;
		(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
	}
	/*if (KEY_DOWN(VK_UP))
	{
		(GET_SINGLE(CObjSortMgr)->m_vecScroll.y) += (200 * GET_SINGLE(CTimeMgr)->GetTime());
	}
	if (KEY_DOWN(VK_DOWN))
	{
		(GET_SINGLE(CObjSortMgr)->m_vecScroll.y) -= (200 * GET_SINGLE(CTimeMgr)->GetTime());
	}*/
}
void CPlayer::SpawnRender()
{
	D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	y += 15;
	if (y >= 430)
	{
		y = 430;
		ForStartFrame += (1 * TIME);
		if ((int)ForStartFrame / 1 == 1)
		{
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn2"), m_Info.matWorld,
			D3DXVECTOR3(pTextureMgr->GetTexture(L"Spawn2")->ImageInfo.Width / 2.f,
				pTextureMgr->GetTexture(L"Spawn2")->ImageInfo.Height / 1.f, 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
			E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);

			return;
		}

		if ((int)ForStartFrame / 2 == 1)
		{
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn3"), m_Info.matWorld,
				D3DXVECTOR3(pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Width / 2.f,
					pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Height / 1.f, 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);

			return;
		}

		if ((int)ForStartFrame / 3 == 1)
		{
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Width / 2.f,
					pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Height / 1.f, 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
			return;
		}

		if ((int)ForStartFrame / 4 == 1)
		{
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Width / 2.f,
					pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Height / 1.f, 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
			return;
		}
		
		//GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn1"), m_Info.matWorld,
		//	D3DXVECTOR3(3/*pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Width / 2.f*/,
		//		79/*pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Height / 2.f*/, 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
		//	E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
		return;
	}
	else // 레이져 빔 내려오는거 렌더
	{
		GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn1"), m_Info.matWorld,
			D3DXVECTOR3(pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Width / 2.f,
				pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Height / 1.f , 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
			E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
	}
}







HRESULT CPlayer::Initialize() {
	this->SetSortID(OBJ_NUM_PLAYER);
	this->pTextureMgr = GET_SINGLE(CTextureMgr);
	D3DXMatrixScaling(&m_Info.matScale, 1.5f, 1.5f, 1.f);
	D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0); // 나중에 스크롤 더해주면 됨.
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	return S_OK;
};
HRESULT CPlayer::Progress() {
	//if (m_pvecScroll->x > -6.5f) m_pvecScroll->x = 6.5f;
	KeyCheck();
	Transforming();

	if (x < 0) x = 0;
	if (x > 1600) x = 1600;
	if (m_pvecScroll->x > -6.5f) m_pvecScroll->x = -6.5f;
	if (m_pvecScroll->x < -880.5f) m_pvecScroll->x = -880.5f;
	return S_OK;
};
HRESULT CPlayer::Render() {
	if(isSpawn)
		SpawnRender();
	if (isStart)
	{
		// 전반적인 캐릭터 렌더링
	}
	//RECT MyRECT = { 0, 0, 0, 0 };
	/* 히트 박스 그리기
	HDC hdc = BeginPaint(g_hWnd, NULL);
	Rectangle(hdc, 10, 10, 10, 10);
	*/
	return S_OK;
};

HRESULT CPlayer::Release()
{
	return S_OK;
}