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



	#pragma endregion // Can Open!!

	//this->pBGTexture = GET_SINGLE(CTextureMgr)->GetTexture(L"BG");
	
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CSBigShip>::CreateInstance() );
	GET_SINGLE(CObjSortMgr)->AddSortedObj(CFactory<CBigShip>::CreateInstance() );
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

	return S_OK;
}
HRESULT CStage_One::Progress(void) { 
	D3DXMatrixTranslation(&matTrans[1], GET_SINGLE(CObjSortMgr)->m_vecScroll.x * 0.1f, GET_SINGLE(CObjSortMgr)->m_vecScroll.y * 0.1f, 0);
	BackMatrix[1] = matScale[1] * matTrans[1];
	if (KEY_DOWN('O')) // 시작키. 제로 소환
	{
		GET_SINGLE(CSoundMgr)->SoundPlay(E_SOUND_LAZER, NOLOOP);
		CPlayer::SetSpawn();
	}
	if (KEY_DOWN('P')) // 히트 박스 랜더 On/Off
	{
		bHitBoxRenderOnOff = !bHitBoxRenderOnOff;
	}
	GET_SINGLE(CObjSortMgr)->ProgressObjects();
	return S_OK;
}
HRESULT CStage_One::Render(void) { 
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BG", NULL, NULL), this->BackMatrix[0], 
		(D3DXVECTOR3(0, 0, 0)), (D3DXVECTOR3(0 ,0 ,0)), E_SINGLE_RENDER_TYPE_STRAIGHT, 0); // 배경
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BG2", NULL, NULL), this->BackMatrix[1],
		(D3DXVECTOR3(0, 0, 0)), (D3DXVECTOR3(0, 0, 0)), E_SINGLE_RENDER_TYPE_STRAIGHT, 0); // 배경2
	
	/* 히트박스 렌더링 */
	GET_SINGLE(CObjSortMgr)->RenderObjects();
	if (bHitBoxRenderOnOff) // 키 입력시 활성화됨
	{
		GET_SINGLE(CCollisionMgr)->RenderCollision();
	}
	return S_OK;
}
HRESULT CStage_One::Release(void) { return S_OK; }