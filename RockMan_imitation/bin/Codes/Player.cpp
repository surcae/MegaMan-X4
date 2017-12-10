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
	y = 0.f;
}
CPlayer::~CPlayer()
{
}

void CPlayer::FrameProcess()
{
	switch (eStatus)
	{
	case E_STATUS_IDLE:
	{
		m_fFrameSpeed = 5;
		FrameMax = 5; // IDLE 5장
	}
	break;
	case E_STATUS_WALK:
	{
		m_fFrameSpeed = 26;
		FrameMax = 13; // IDLE 5장
	}
	break;
	}

	m_fFrame += (m_fFrameSpeed * TIME);
	if (m_fFrame > FrameMax)
		m_fFrame = 0.f;
}

void CPlayer::KeyCheck()
{
	// 공격시 프레임

// 포지션 바꾸는 포인터 줘서 각각 공격때마다 포지션 다르게 주기
	this->eStatus = E_STATUS_IDLE;

	if (KEY_DOWN(VK_LEFT))
	{
		x -= m_fSpeed * TIME;
		if (400 < x && x < 1200)
			(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
		Pointer = D_LEFT;
		eStatus = E_STATUS_WALK;
		
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		x += m_fSpeed * TIME;
		if(400 < x && x < 1200)
			(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
		Pointer = D_RIGHT;
		eStatus = E_STATUS_WALK;
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
	if (y >= 480)
	{
		y = 480;
		ForStartFrame += (35.f * TIME);
		if ((int)ForStartFrame / 1 == 1)
		{
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn2"), m_Info.matWorld,
			D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn2")->ImageInfo.Height, 0), D3DXVECTOR3(0, 0, 0),
			E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);

			return;
		}

		if ((int)ForStartFrame / 2 == 1)
		{
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn3"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Height, 0)/*D3DXVECTOR3(pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Width / 2.f,
					pTextureMgr->GetTexture(L"Spawn3")->ImageInfo.Height / 1.f - 10.f, 0.f)*/, D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);

			return;
		}

		if ((int)ForStartFrame / 3 == 1)
		{
			RECT rct = { 0, 0, 61*2, 64*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 4 == 1)
		{
			RECT rct = { 61*2, 0, 129*2, 64*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 5 == 1)
		{
			RECT rct = { 129*2, 0, 193*2, 64*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 6 == 1)
		{
			RECT rct = { 193*2, 0, 249*2, 64*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 7 == 1)
		{
			RECT rct = { 249*2, 0, 300*2, 64*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}
		
		if ((int)ForStartFrame / 8 == 1 || (int)ForStartFrame / 9 == 1 || (int)ForStartFrame / 10 == 1 
			|| (int)ForStartFrame / 11 == 1 || (int)ForStartFrame / 12 == 1)
		{
			RECT rct = { 300*2, 0, 339*2, 64*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 13 == 1)
		{
			RECT rct = { 0, 0, 41*2, 58*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 14 == 1)
		{
			RECT rct = { 41*2, 0, 82*2, 58*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 15 == 1)
		{
			RECT rct = { 82*2, 0, 123*2, 58*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 16 == 1)
		{
			RECT rct = { 123*2, 0, 163*2, 58*2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);

			return;
		}

		if ((int)ForStartFrame / 17 == 1)
		{
			isStart = true;
			this->isSpawn = false;
			isControllActivated = true;
			ForStartFrame = 1.f;
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
			D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
			E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
	}
}

HRESULT CPlayer::Initialize() {
	this->SetSortID(OBJ_NUM_PLAYER);
	this->pTextureMgr = GET_SINGLE(CTextureMgr);
	D3DXMatrixScaling(&m_Info.matScale, 1.0f, 1.0f, 1.f);
	D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0); // 나중에 스크롤 더해주면 됨.
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	return S_OK;
};
HRESULT CPlayer::Progress() {
	FrameProcess();

	if(isControllActivated)
		KeyCheck();


	// Player Location Max
	if (x < 0) x = 0;
	if (x > 1600) x = 1600;
	return S_OK;
};
HRESULT CPlayer::Render() {
	if(isSpawn)
		SpawnRender();
	if (Pointer == D_RIGHT)
	{
		D3DXMatrixScaling(&m_Info.matScale, 1.0f, 1.0f, 1.f);
		D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0);
		m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
		
	}
	else
	{
		D3DXMatrixScaling(&m_Info.matScale, -1.0f, 1.0f, 1.f);
		D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0);
		m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	}

	// 본격 렌더링 시작!!
	if (isStart) // 소환이 끝나면 시작됨
	{
		switch (eStatus)
		{
		case E_STATUS_IDLE:
		{
			GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"IDLE"),
				m_Info.matWorld, (D3DXVECTOR3(0,
					GET_SINGLE(CTextureMgr)->GetTexture(L"IDLE")->ImageInfo.Height, 0.f)), m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 5, NULL, 48 * 2, 50 * 2, (int)m_fFrame);
		}
		break;
		case E_STATUS_WALK:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"Walk", (int)m_fFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		}
		// 전반적인 캐릭터 렌더링
	}
	// 어택용 프레임 변수를 만들까?
	//RECT MyRECT = { 0, 0, 0, 0 };
	/* 히트 박스 그리기
	HDC hdc = BeginPaint(g_hWnd, NULL);
	Rectangle(hdc, MyRECT.left, MyRECT.top, MyRECT.right, MyRECT.bottom);
	*/
	return S_OK;
};

HRESULT CPlayer::Release()
{
	return S_OK;
}