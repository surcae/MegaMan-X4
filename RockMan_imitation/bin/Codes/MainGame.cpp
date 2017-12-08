#include "stdafx.h"
#include "MainGame.h"
#include "Device.h"
#include "SoundMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "ObjSortMgr.h"
#include "KeyMgr.h"

HRESULT CMainGame::Initialize(void)
{
	// Mgr
	GET_SINGLE(CObjSortMgr)->Initialize();
	// Device
	if (FAILED(GET_SINGLE(CDevice)->InitDevice(g_hWnd))) {
		MessageBox(g_hWnd, L"Device Initialize Failed!", L"Init Failed", MB_OK);
		return E_FAIL;
	}
	
	// SoundDevice
	if (FAILED(GET_SINGLE(CSoundMgr)->Init())) {
		MessageBox(g_hWnd, L"Sound Initialize Failed!", L"Init Failed", MB_OK);
		return E_FAIL;
	}

	// Logo Scene
	if (FAILED(GET_SINGLE(CSceneMgr)->InitScene(STAGE_ONE))) {
		MessageBox(g_hWnd, L"Scene Initialize Failed!", L"Init Failed", MB_OK);
		return E_FAIL;
	}

	// KeyBoard
	GET_SINGLE(CKeyMgr)->CreateKeyBoardDevice(g_hWnd);

	
	return S_OK;
}

CMainGame::CMainGame()
{
}
CMainGame::~CMainGame()
{
	Release();
}
HRESULT CMainGame::Update(void) {
	GET_SINGLE(CTimeMgr)->SetTime();
	GET_SINGLE(CSceneMgr)->Progress();
	return S_OK;
}
HRESULT CMainGame::Render(void) {
		GET_SINGLE(CDevice)->RenderBegin();
		GET_SINGLE(CSceneMgr)->Render();
		GET_SINGLE(CDevice)->RenderEnd();
	return S_OK;
}

void CMainGame::Release(void)
{
	// Nothing
}
