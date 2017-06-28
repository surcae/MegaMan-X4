#include "stdafx.h"
#include "MainGame.h"
#include "Stage.h"

HRESULT CMainGame::Initialize(void)
{
	m_pStage = new CStage(STAGE_ONE);
	return S_OK;
}

CMainGame::CMainGame()
{
}
CMainGame::~CMainGame()
{
	m_pStage->Release();
}
HRESULT CMainGame::Progress(void) {
	m_pStage->Progress();
	return S_OK;
}
HRESULT CMainGame::Render(void) {
	m_pStage->Render();
	return S_OK;
}
