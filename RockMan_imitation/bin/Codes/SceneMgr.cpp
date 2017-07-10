#include "stdafx.h"
#include "SceneMgr.h"
#include "Logo.h"
#include "Stage_One.h"
CSceneMgr::CSceneMgr()
{
}


CSceneMgr::~CSceneMgr()
{
}

HRESULT CSceneMgr::InitScene(FIELD _stage)
{
	SAFE_DELETE(m_pMyScene);
	switch (_stage)
	{
	case STAGE_LOGO:
		m_pMyScene = new CLogo;
		break;
	case STAGE_ONE:
		m_pMyScene = new CStage_One;
		break;
	}
	if (FAILED(m_pMyScene->Initialize()))
	{
		SAFE_DELETE(m_pMyScene);
		return E_FAIL;
	}
	return S_OK;
}

void CSceneMgr::Progress() {
	m_pMyScene->Progress();
}
void CSceneMgr::Render() {
	m_pMyScene->Render();
}
void CSceneMgr::Release() {

}