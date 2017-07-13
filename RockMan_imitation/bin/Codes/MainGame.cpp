#include "stdafx.h"
#include "MainGame.h"
#include "Device.h"
#include "SoundMgr.h"
#include "SceneMgr.h"

HRESULT CMainGame::Initialize(void)
{
	if (FAILED(GET_SINGLE(CDevice)->InitDevice(g_hWnd))) {
		MessageBox(g_hWnd, L"Device Initialize Failed!", L"Init Failed", MB_OK);
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSoundMgr)->Init())) {
		MessageBox(g_hWnd, L"Sound Initialize Failed!", L"Init Failed", MB_OK);
		return E_FAIL;
	}
	if (FAILED(GET_SINGLE(CSceneMgr)->InitScene(STAGE_LOGO))) {
		MessageBox(g_hWnd, L"Scene Initialize Failed!", L"Init Failed", MB_OK);
		return E_FAIL;
	}
	
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
	GET_SINGLE(CSceneMgr)->Progress();
	return S_OK;
}
HRESULT CMainGame::Render(void) {
	
	while(GetTickCount() - StartTick >= 500) {
		GET_SINGLE(CDevice)->RenderBegin();
		GET_SINGLE(CSceneMgr)->Render();
		GET_SINGLE(CDevice)->RenderEnd();
		StartTick = GetTickCount();
	}
	return S_OK;
}

void CMainGame::Release(void)
{
	// Nothing
}
