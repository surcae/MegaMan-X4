#pragma once
#include "stdafx.h"
#include "Stage_One.h"
#include "TextureMgr.h"

CStage_One::CStage_One()
{
}
CStage_One::~CStage_One()
{
	Release();
}

HRESULT CStage_One::Initialize(void) {
	this->pTextureMgr = GET_SINGLE(CTextureMgr);
	// BackGround Initialize
	if (FAILED(pTextureMgr->InsertTexture(L"../Resource/BackGrounds/Logo.png", TEXTYPE_SINGLE, L"BG", NULL, 0)))
	{
		return E_FAIL;
	}

	
	return S_OK;
}
HRESULT CStage_One::Progress(void) { return S_OK; }
HRESULT CStage_One::Render(void) { return S_OK; }
HRESULT CStage_One::Release(void) { return S_OK; }