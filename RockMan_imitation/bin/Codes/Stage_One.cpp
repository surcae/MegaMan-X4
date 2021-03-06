#pragma once
#include "stdafx.h"
#include "Stage_One.h"
#include "TextureMgr.h"
#include "RenderMgr.h"
#include "ObjSortMgr.h"
#include "Factory.h"
#include "SoundMgr.h"
#include "CollisionMgr.h"
#include <math.h>

#include "BigShip.h"
#include "SBigShip.h"
#include "SmallShip.h"
#include "Statue.h"
#include "Platform.h"
#include "Wall.h"
#include "UI.h"

#include "Player.h"
#include "Monster.h"

#define KEY_DOWN(code) ((GetAsyncKeyState(code)&0x8000)?1:0)
#define LOOP 1
#define NOLOOP 0

CStage_One::CStage_One()
{
}
CStage_One::~CStage_One()
{
	Release();
}

void CStage_One::CreateMonster()
{
	CMonster* pCreatedMop = new CMonster();
	pCreatedMop->Initialize();
	this->m_vecMonster->push_back(pCreatedMop);
}

HRESULT CStage_One::Initialize(void) {
	// Sound Insert
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/bgm.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Ready.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Lazer.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Dash.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Jump.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Plat.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/A1.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/A2.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/A3.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Sword.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Bomb.wav")))
	{
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->LoadWave(L"../Resource/Sound/Fire.wav")))
	{
		return E_FAIL;
	}



	GET_SINGLE(CSoundMgr)->SetSoundVolume(E_SOUND_THEME, -1000);
	GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_THEME, LOOP);
	GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_READY, NOLOOP);

	// BackGround Initialize
	this->pTextureMgr = GET_SINGLE(CTextureMgr);

    #pragma region TEXTURE INSERT AREA
	// BG1
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/Logo.png", TEXTYPE_SINGLE, L"BG", NULL, 0)))
	{
		return E_FAIL;
	}
	// BG2
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/BG2.png", TEXTYPE_SINGLE, L"BG2", NULL, 0)))
	{
		return E_FAIL;
	}
	// Big Ship
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/BGOb1.png", TEXTYPE_SINGLE, L"BigShip", NULL, NULL)))
	{
		return E_FAIL;
	}
	// Small Ship
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/BGOb2.png", TEXTYPE_SINGLE, L"SmallShip", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/Statue.png", TEXTYPE_SINGLE, L"Statue", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/Platform.png", TEXTYPE_SINGLE, L"Platform", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/Platform_long.png", TEXTYPE_SINGLE, L"Platform_long", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/Wall.png", TEXTYPE_SINGLE, L"Wall", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Single/Spawn1.png", TEXTYPE_SINGLE, L"Spawn1", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Single/Spawn2.png", TEXTYPE_SINGLE, L"Spawn2", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Single/Spawn3.png", TEXTYPE_SINGLE, L"Spawn3", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Single/Spawn4.png", TEXTYPE_SINGLE, L"Spawn4", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Single/Spawn5.png", TEXTYPE_SINGLE, L"Spawn5", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/hpbar.png", TEXTYPE_SINGLE, L"UI", NULL, NULL)))
	{
	return E_FAIL;
	}

	// Player!!!!
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Single/IDLE.png", TEXTYPE_SINGLE, L"IDLE", NULL, NULL)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Walk%d.png", TEXTYPE_MULTI, L"Zero", L"Walk", 14)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/DashStart%d.png", TEXTYPE_MULTI, L"Zero", L"DashStart", 7)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/DashEnd%d.png", TEXTYPE_MULTI, L"Zero", L"DashEnd", 4)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Hit%d.png", TEXTYPE_MULTI, L"Zero", L"Hit", 10)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/JumpStart%d.png", TEXTYPE_MULTI, L"Zero", L"JumpStart", 4)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/JumpOff%d.png", TEXTYPE_MULTI, L"Zero", L"JumpOff", 3)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/JumpDown%d.png", TEXTYPE_MULTI, L"Zero", L"JumpDown", 4)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Attach%d.png", TEXTYPE_MULTI, L"Zero", L"Attach", 1)))
	{
		return E_FAIL;
	}

	// 몹
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Mop%d.png", TEXTYPE_MULTI, L"Mop", L"Mops", 10)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Mop2_%d.png", TEXTYPE_MULTI, L"Mop", L"Mops2", 3)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/boom%d.png", TEXTYPE_MULTI, L"Boom", L"boom", 5)))
	{
		return E_FAIL;
	}

	// 공격모션
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Attack_M1_%d.png", TEXTYPE_MULTI, L"Zero", L"A1", 7)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Attack_M2_%d.png", TEXTYPE_MULTI, L"Zero", L"A2", 7)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/Attack_M3_%d.png", TEXTYPE_MULTI, L"Zero", L"A3", 11)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/AF%d.png", TEXTYPE_MULTI, L"Zero", L"Fire", 10)))
	{
		return E_FAIL;
	}
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Texture/Multi/JA%d.png", TEXTYPE_MULTI, L"Zero", L"JA", 8)))
	{
		return E_FAIL;
	}


	// Dash Effect
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/Effect/dash.png", TEXTYPE_SINGLE, L"DashEffect", NULL, NULL)))
	{
		return E_FAIL;
	}


#pragma endregion // Can Open!!

	//this->pBGTexture = GET_SINGLE(CTextureMgr)->GetTexture(L"BG");

	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CSBigShip>::CreateInstance());
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CBigShip>::CreateInstance());
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CSmallShip>::CreateInstance());
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CStatue>::CreateInstance());
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CPlatform>::CreateInstance());
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CWall>::CreateInstance());
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CUI>::CreateInstance());

	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CPlayer>::CreateInstance());



	D3DXMatrixTranslation(&matTrans[0], 0, 0, 0);
	D3DXMatrixTranslation(&matTrans[1], 0, 0, 0);
	D3DXMatrixScaling(&matScale[0], 1.0f, 1.0f, 1.f);
	D3DXMatrixScaling(&matScale[1], 1.0f, 1.0f, 1.f);

	BackMatrix[0] = matScale[0] * matTrans[0];
	BackMatrix[1] = matScale[1] * matTrans[1];

	GET_SINGLE(CCollisionMgr)->SetPointer(this->m_vecMonster);

	return S_OK;
}
HRESULT CStage_One::Progress(void) {
	if (MopCreate)
	{
		DWORD curTime = GetTickCount();
		if (Time - curTime >= 2000)
		{
			Time += 2000;
			CreateMonster();
		}
	}
	D3DXMatrixTranslation(&matTrans[1], GET_SINGLE(CObjSortMgr)->m_vecScroll.x * 0.1f, GET_SINGLE(CObjSortMgr)->m_vecScroll.y * 0.1f, 0);
	BackMatrix[1] = matScale[1] * matTrans[1];
	if (KEY_DOWN('O')) // 시작키. 제로 소환
	{
		GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_LAZER, NOLOOP);
		CPlayer::SetSpawn();
	}
	if (KEY_DOWN('P')) // 시작키. 몹 소환
	{
		MopCreate = true;
		Time = GetTickCount();
	}
	GET_SINGLE(CObjSortMgr)->ProgressObjects();
	for (vector<CMonster*>::iterator it = m_vecMonster->begin(); it != m_vecMonster->end(); it++)
	{
		(*it)->Progress();
	}
	return S_OK;
}
HRESULT CStage_One::Render(void) { 
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BG", NULL, NULL), this->BackMatrix[0], 
		(D3DXVECTOR3(0, 0, 0)), (D3DXVECTOR3(0 ,0 ,0)), E_SINGLE_RENDER_TYPE_STRAIGHT, 0); // 배경
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BG2", NULL, NULL), this->BackMatrix[1],
		(D3DXVECTOR3(0, 0, 0)), (D3DXVECTOR3(0, 0, 0)), E_SINGLE_RENDER_TYPE_STRAIGHT, 0); // 배경2
	
	/* 히트박스 렌더링 */ /* 몬스터 렌더링 */
	GET_SINGLE(CObjSortMgr)->RenderObjects();
	for (vector<CMonster*>::iterator it = m_vecMonster->begin(); it != m_vecMonster->end(); it++)
	{
		(*it)->Render();
	}
	return S_OK;
}
HRESULT CStage_One::Release(void) { return S_OK; }