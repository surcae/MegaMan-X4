#include "stdafx.h"
#include "Player.h"
#include "RenderMgr.h"
#include "CollisionMgr.h"
#include "ObjSortMgr.h"
#include "TextureMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"
#include <math.h>

#pragma warning (disable : 4244)

#define PI 3.1415926535897

#define KEY_DOWN(code) ((GetAsyncKeyState(code)&0x8001)?1:0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8001) ? 0 : 1)
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
void CPlayer::SpawnRender()
{
	D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0);
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	y += 15;
	if (y >= MaxYpos)
	{
		y = MaxYpos;
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
			RECT rct = { 0, 0, 61 * 2, 64 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 4 == 1)
		{
			RECT rct = { 61 * 2, 0, 129 * 2, 64 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 5 == 1)
		{
			RECT rct = { 129 * 2, 0, 193 * 2, 64 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 6 == 1)
		{
			RECT rct = { 193 * 2, 0, 249 * 2, 64 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 7 == 1)
		{
			RECT rct = { 249 * 2, 0, 300 * 2, 64 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 8 == 1 || (int)ForStartFrame / 9 == 1 || (int)ForStartFrame / 10 == 1
			|| (int)ForStartFrame / 11 == 1 || (int)ForStartFrame / 12 == 1)
		{
			RECT rct = { 300 * 2, 0, 339 * 2, 64 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn4"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn4")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 13 == 1)
		{
			RECT rct = { 0, 0, 41 * 2, 58 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 14 == 1)
		{
			RECT rct = { 41 * 2, 0, 82 * 2, 58 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 15 == 1)
		{
			RECT rct = { 82 * 2, 0, 123 * 2, 58 * 2 };
			GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn5"), m_Info.matWorld,
				D3DXVECTOR3(0, pTextureMgr->GetTexture(L"Spawn5")->ImageInfo.Height, 0), D3DXVECTOR3(0.f, 0.f, 0.f),
				E_SINGLE_RENDER_TYPE_STRAIGHT, 1, &rct);
			return;
		}

		if ((int)ForStartFrame / 16 == 1)
		{
			RECT rct = { 123 * 2, 0, 163 * 2, 58 * 2 };
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
void CPlayer::KeyCheck()
{
	if (eStatus == E_STATUS_A1 || eStatus == E_STATUS_A2 || eStatus == E_STATUS_A3)
		return;
	m_fSpeed = 220;
	bool isKey = false;
	if (y >= MaxYpos)
	{
		this->bPosStation = E_POS_STATION_GROUND;
		this->m_JumpFrame.Jump_Down_Frame = 0;
		if (Played == false)
		{
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_PLAT, NOLOOP);
			Ground = false;
			Played = true;
		}
		Angle = 0;
	}
	else
		this->bPosStation = E_POS_STATION_AIR;

	/* 아무것도 안 눌렀을 때 처리하는곳 */
	if (eStatus == E_STATUS_DASH && KEY_UP('Z'))
	{
		eStatus = E_STATUS_DASHEND;
		DASH_FRAME = 0;
		return;
	}
	
	if (eStatus == E_STATUS_JUMPSTART && KEY_UP('X'))
	{
		eStatus = E_STATUS_JUMPOFF;
		m_JumpFrame.Jump_Start_Frame = 0;
		Angle = 180;
		Ground = false;
		Played = false;
		return;
	}

	if (eStatus == E_STATUS_JUMPDOWN)
	{
		isKey = true;
	}

	if (bPosStation == E_POS_STATION_AIR && eStatus != E_STATUS_JUMPSTART)
	{
		eStatus = E_STATUS_JUMPDOWN;
		m_JumpFrame.Jump_Down_Frame = 0;
	}

	
	
	/* 아무것도 안 눌렀을 때 처리하는곳 끝나는 곳*/

	/* 뭔가 눌렀을 때 처리하는곳*/
	// 충돌상태(지형 및 벽)
	if (this->bPosStation == E_POS_STATION_GROUND || this->bPosStation == E_POS_ATTACH_WALL)
	{
		if (KEY_DOWN('Z') && KEY_DOWN('X'))
		{
			m_fSpeed = m_fHighSpeed;
		}

		if (KEY_DOWN('C'))
		{
			eStatus = E_STATUS_A1;
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_A1, NOLOOP);
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_SWORD, NOLOOP);
			return;
		}

		if (KEY_DOWN('X')) // 처음 눌렀을 때
		{
			eStatus = E_STATUS_JUMPSTART;
			this->y -= (JumpPower * cos(Angle * PI / 180));
			bPosStation = E_POS_STATION_AIR;
			Angle += 0.1;
			m_JumpFrame.Jump_Start_Frame = 0.f;
			this->m_fFrame = 0;
			Played = false;
			return;
		}

		if (KEY_DOWN('Z'))
		{
			eStatus = E_STATUS_DASH;
			if (Pointer == D_RIGHT)
			{
				x += m_fHighSpeed * TIME;
				if (400 < x && x < 1200)
					(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * 2.5f * GET_SINGLE(CTimeMgr)->GetTime());
			}
			else
			{
				x -= m_fHighSpeed * TIME;
				if (400 < x && x < 1200)
					(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * 2.5f * GET_SINGLE(CTimeMgr)->GetTime());
			}
			return;
		}
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
			if (400 < x && x < 1200)
				(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
			Pointer = D_RIGHT;
			eStatus = E_STATUS_WALK;

			return;
		}
	}

	// Air 공중 상태

	if (KEY_DOWN('X') && (eStatus == E_STATUS_JUMPSTART)) // x 꾹 누르고 있으면 버그있음
	{
		this->y -= (JumpPower * cos(Angle * (PI / 180) * 3));
		m_pvecScroll->y += (m_fSpeed * 1.5 * TIME);
		if (m_pvecScroll->y > 120)
			m_pvecScroll->y = 120;
		Angle += 0.1; Ground = false;
		if (Angle >= 90)
		{
			eStatus = E_STATUS_JUMPDOWN;
		}
	}
	if (KEY_DOWN(VK_LEFT))
	{
		x -= m_fSpeed * TIME;
		if (400 < x && x < 1200)
			(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
		Pointer = D_LEFT;
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		x += m_fSpeed * TIME;
		if (400 < x && x < 1200)
			(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (m_fSpeed * GET_SINGLE(CTimeMgr)->GetTime());
		Pointer = D_RIGHT;
	}

	// 어디서나 발동
	

	if (KEY_DOWN('C'))
	{

	}

	if (bPosStation == E_POS_STATION_GROUND)
		eStatus = E_STATUS_IDLE;
}


void CPlayer::FrameProcess()
{
	switch (eStatus)
	{
	case E_STATUS_IDLE:
	{
		m_fFrameSpeed = 5;
		FrameMax = 5;
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
		FrameMax = 6;
	}
	break;
	case E_STATUS_DASHEND:
	{
		m_fFrameSpeed = 22;
		FrameMax = 3;
	}
	case E_STATUS_JUMPSTART:
	{
		m_fFrameSpeed = 22;
		FrameMax = 3;
	}
	break;
	case E_STATUS_JUMPOFF:
	{
		m_fFrameSpeed = 24;
		FrameMax = 2;
	}
	break;
	case E_STATUS_JUMPDOWN:
	{
		m_fFrameSpeed = 24;
		FrameMax = 4;
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
	if (eStatus == E_STATUS_JUMPSTART)
	{
		m_JumpFrame.Jump_Start_Frame += (m_fFrameSpeed * TIME);
		if (m_JumpFrame.Jump_Start_Frame > FrameMax)
		{
			m_JumpFrame.Jump_Start_Frame = FrameMax - 1;
			return;
		}
	}
	if (eStatus == E_STATUS_JUMPOFF)
	{
		m_JumpFrame.Jump_Off_Frame += (m_fFrameSpeed * TIME);
		if (m_JumpFrame.Jump_Off_Frame > FrameMax)
		{
			m_JumpFrame.Jump_Off_Frame = 0;
			return;
		}
	}
	if (eStatus == E_STATUS_JUMPDOWN)
	{
		m_JumpFrame.Jump_Down_Frame += (m_fFrameSpeed * TIME);
		if (m_JumpFrame.Jump_Down_Frame > FrameMax)
		{
			m_JumpFrame.Jump_Down_Frame = 1;
			return;
		}
	}

	if (eStatus == E_STATUS_A1)
	{
		m_fFrame += (26 * TIME);
		if (m_fFrame > 7)
		{
			m_fFrame = 0.f;
			eStatus = E_STATUS_IDLE;
		}
		else if ((int)m_fFrame >= 3)
		{
			LONG rockon = x + 50;
			LONG rockon_ = x - 50;

			RECT rct = { rockon - 30, rockon - 30, rockon + 30, rockon + 30};
			RECT rct2 = { rockon_ - 30, rockon_ - 30, rockon_ + 30, rockon_ + 30};
			if (Pointer == D_LEFT)
			{
				GET_SINGLE(CCollisionMgr)->AttackandMop(rct2);
			}
			else
			{
				GET_SINGLE(CCollisionMgr)->AttackandMop(rct);
			}
		}
		
		if ((int)m_fFrame == 6)
		{
			if (KEY_DOWN('C'))
			{
				m_fFrame = 0.f;
				eStatus = E_STATUS_A2;
			}
		}

		return;
	}

	if (eStatus == E_STATUS_A2)
	{
		m_fFrame += (26 * TIME);
		if (m_fFrame > 7)
		{
			m_fFrame = 0.f;
			eStatus = E_STATUS_IDLE;
			return;
		}
		else if ((int)m_fFrame >= 4)
		{
			LONG rockon = x + 50;
			LONG rockon_ = x - 50;

			RECT rct = { rockon - 30, rockon - 30, rockon + 30, rockon + 30 };
			RECT rct2 = { rockon_ - 30, rockon_ - 30, rockon_ + 30, rockon_ + 30 };
			if (Pointer == D_LEFT)
			{
				GET_SINGLE(CCollisionMgr)->AttackandMop(rct2);
			}
			else
			{
				GET_SINGLE(CCollisionMgr)->AttackandMop(rct);
			}
		}
		
		if ((int)m_fFrame == 0)
		{
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_A2, NOLOOP);
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_SWORD, NOLOOP);
		}

		if ((int)m_fFrame == 6)
		{
			if (KEY_DOWN('C'))
			{
				m_fFrame = 0.f;
				eStatus = E_STATUS_A3;
			}
		}
		return;
	}

	if (eStatus == E_STATUS_A3)
	{
		m_fFrame += (32 * TIME);
		if (m_fFrame > 11)
		{
			m_fFrame = 0.f;
			eStatus = E_STATUS_IDLE;
			return;
		}
		else if ((int)m_fFrame >= 3 || (int)m_fFrame <= 7)
		{
			LONG rockon = x + 50;
			LONG rockon_ = x - 50;

			RECT rct = { rockon - 50, rockon - 50, rockon + 50, rockon + 50 };
			RECT rct2 = { rockon_ - 50, rockon_ - 50, rockon_ + 50, rockon_ + 50 };
			if (Pointer == D_LEFT)
			{
				GET_SINGLE(CCollisionMgr)->AttackandMop(rct2);
			}
			else
			{
				GET_SINGLE(CCollisionMgr)->AttackandMop(rct);
			}
		}
		
		if((int)m_fFrame == 0)
		{
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_A3, NOLOOP);
			GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_SWORD, NOLOOP);
		}
		return;
	}

	// 일반 프레임 지정
	m_fFrame += (m_fFrameSpeed * TIME);
	if (m_fFrame > FrameMax)
		m_fFrame = 0.f;
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
	GET_SINGLE(CCollisionMgr)->CollisionCheck(this);
	if (y > MaxYpos) y = MaxYpos; // 콜리전 완성되면 지움
	if (Angle != 0) // 라디안 
	{
		Angle += (60 * TIME);
		if (Angle >= 90)
		{
			eStatus = E_STATUS_JUMPDOWN;
			y = y - (JumpPower * (cos(Angle * (PI / 180))));
			m_pvecScroll->y -= (m_fSpeed * 1.5 * TIME);
			if (m_pvecScroll->y < -50)
				m_pvecScroll->y = -50;
			if (Angle >= 360)
				Angle = 360;
		}
	} // 중력 적용값
	if(isControllActivated)
		KeyCheck();
	FrameProcess();

	// Player Location Max
	if (x < 0) x = 0; if (y < -100) y = -100;
	if (x > 1600) x = 1600; if (y > 600) y = 600;
	return S_OK;
};
HRESULT CPlayer::Render() {
	if(isSpawn)
		SpawnRender();

	// 방향에 따른 Flip 방법 설정
	if (Pointer == D_RIGHT) // 일반
	{
		D3DXMatrixScaling(&m_Info.matScale, 1.0f, 1.0f, 1.f);
		D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0);
		m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	}
	else // -x 플립
	{
		D3DXMatrixScaling(&m_Info.matScale, -1.0f, 1.0f, 1.f);
		D3DXMatrixTranslation(&m_Info.matTrans, x + m_pvecScroll->x, y + m_pvecScroll->y, 0);
		m_Info.matWorld = m_Info.matScale * m_Info.matTrans;
	}

	///////////////////////
	// 본격 렌더링 시작!! //
	///////////////////////
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
			if ((int)DASH_FRAME == 0)
				GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_DASH, NOLOOP);
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
		case E_STATUS_JUMPSTART: // 아무것도 충돌하고 있지 않으면 공중 상태
		{
			if ((int)m_JumpFrame.Jump_Start_Frame == 0)
				GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_JUMP, NOLOOP);
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"JumpStart", (int)m_JumpFrame.Jump_Start_Frame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_JUMPOFF: 
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"JumpOff", (int)m_JumpFrame.Jump_Off_Frame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_JUMPDOWN: 
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"JumpDown", (int)m_JumpFrame.Jump_Down_Frame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_DAMAGED:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"Hit", (int)m_fFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_A1:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"A1", (int)m_fFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_A2:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"A2", (int)m_fFrame),
				m_Info.matWorld, E_MULTI_RENDER_TYPE_STRAIGHT);
		}
		break;
		case E_STATUS_A3:
		{
			GET_SINGLE(CRenderMgr)->MultiRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Zero", L"A3", (int)m_fFrame),
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
