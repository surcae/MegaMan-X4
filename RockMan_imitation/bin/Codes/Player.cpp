#include "stdafx.h"
#include "Player.h"
#include "RenderMgr.h"
#include "CollisionMgr.h"
#include "ObjSortMgr.h"
#include "TextureMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"

#pragma warning (disable : 4244)

#define KEY_DOWN(code) ((GetAsyncKeyState(code)&0x8000)?1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)
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
		FrameMax = 13;
	}
	break;
	case E_STATUS_DASH:
	{
		m_fFrameSpeed = 26;
		FrameMax = 6.5;
	}
	break;
	case E_STATUS_DASHEND:
	{
		m_fFrameSpeed = 22;
		FrameMax = 3;
	}
	break;
	}
	
	// 특수 프레임 지정하는곳
	if (eStatus == E_STATUS_DASH)
	{
		DASH_FRAME += (m_fFrameSpeed * TIME);
		if (DASH_FRAME > FrameMax)
		{
			DASH_FRAME = FrameMax;
			return;
		}
	}

	// 일반 프레임 지정
	m_fFrame += (m_fFrameSpeed * TIME);
	if (m_fFrame > FrameMax)
		m_fFrame = 0.f;
}

void CPlayer::KeyCheck()
{
	/* 아무것도 안 눌렀을 때 처리하는곳 */
	if (eStatus == E_STATUS_DASH && KEY_UP('Z'))
	{
		eStatus = E_STATUS_DASHEND;
		DASH_FRAME = 0.f;
		return;
	}
	else
	{
		this->eStatus = E_STATUS_IDLE;
	}
	/* 아무것도 안 눌렀을 때 처리하는곳 끝나는 곳*/

	/* 뭔가 눌렀을 때 처리하는곳*/
	if (KEY_DOWN('Z'))
	{
		eStatus = E_STATUS_DASH;
		if(DASH_FRAME == 0.f)
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_DASH, NOLOOP);

	
		/*if (!GET_SINGLE(CSoundMgr)->SoundPlaying(E_SOUND_DASH))
		{
			GET_SINGLE(CSoundMgr)->SoundStop(E_SOUND_DASH);
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_DASH, NOLOOP);
		}*/
		if (Pointer == D_RIGHT)
		{
			x += m_fSpeed * 2.5f * TIME;
			if (400 < x && x < 1200)
				(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * 2.5f * GET_SINGLE(CTimeMgr)->GetTime());
		}
		else
		{
			x -= m_fSpeed * 2.5f * TIME;
			if (400 < x && x < 1200)
				(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * 2.5f * GET_SINGLE(CTimeMgr)->GetTime());
		}
		return;
	}
	/*if (KEY_DOWN(VK_RIGHT) && (KEY_DOWN('Z')) || (KEY_DOWN(VK_LEFT) && (KEY_DOWN('Z') )))
	{
		eStatus = E_STATUS_DASH;
		if (Pointer == D_RIGHT)
		{
			x += m_fSpeed * 2 * TIME;
			if (400 < x && x < 1200)
				(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * 2 * GET_SINGLE(CTimeMgr)->GetTime());
		}
		else
		{
			x -= m_fSpeed * 2 * TIME;
			if (400 < x && x < 1200)
				(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * 2 * GET_SINGLE(CTimeMgr)->GetTime());
		}
		return;
	}*/

	if (KEY_DOWN(VK_LEFT))
	{

		x -= m_fSpeed * TIME;
		if (400 < x && x < 1200)
			(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
		Pointer = D_LEFT;
		eStatus = E_STATUS_WALK;
		
		return;
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		x += m_fSpeed * TIME;
		if(400 < x && x < 1200)
			(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
		Pointer = D_RIGHT;
		eStatus = E_STATUS_WALK;

		return;
	}
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
	if(isControllActivated)
		KeyCheck();
	FrameProcess();

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

	////////////////////
	// 본격 렌더링 시작!!
	////////////////////
	if (isStart) // 소환이 끝나면 시작됨
	{
		switch (eStatus)
		{
		case E_STATUS_IDLE:
		{
			GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"IDLE"),
				m_Info.matWorld, (D3DXVECTOR3(0, GET_SINGLE(CTextureMgr)->GetTexture(L"IDLE")->ImageInfo.Height, 0.f)), m_Info.vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 5, NULL, 48 * 2, 50 * 2, (int)m_fFrame);
		}
		break;
		case E_STATUS_WALK:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"Walk", (int)m_fFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_DASH:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"DashStart", (int)DASH_FRAME),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_DASHEND:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"DashEnd", (int)m_fFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		}
	}
	return S_OK;
};

HRESULT CPlayer::Release()
{
	return S_OK;
}