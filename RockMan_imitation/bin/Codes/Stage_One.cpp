#include "stdafx.h"
#include "Stage_One.h"

CStage_One::CStage_One()
{
}
CStage_One::~CStage_One()
{
	Release();
}

HRESULT CStage_One::Initialize(void) {
	




	return S_OK;
}
HRESULT CStage_One::Progress(void) { return S_OK; }
HRESULT CStage_One::Render(void) { return S_OK; }
HRESULT CStage_One::Release(void) { return S_OK; }