#include "stdafx.h"
#include "Stage.h"


CStage::CStage() : 
	m_Field(STAGE_ONE)
{
}
CStage::CStage(FIELD StageNum)
{
	this->m_Field = StageNum;
}

CStage::~CStage()
{
	Release();
}

HRESULT CStage::Initialize(void) { 
	

	return S_OK;
}
HRESULT CStage::Progress(void) { return S_OK; }
HRESULT CStage::Render(void) { return S_OK; }
HRESULT CStage::Release(void) { return S_OK; }