#include "stdafx.h"
#include "SmallShip.h"
#include "TextureMgr.h"

HRESULT CSmallShip::Initialize()
{
	// Insert Ship TGA
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"../Resource/BackGrounds/BGOb2.png", TEXTYPE_SINGLE, L"SmallShip", NULL, NULL)))
	{
		return E_FAIL;
	}
	return S_OK;
}

HRESULT CSmallShip::Progress()
{
	return S_OK;
}

HRESULT CSmallShip::Render()
{
	
	return S_OK;
}

CSmallShip::CSmallShip()
{
}


CSmallShip::~CSmallShip()
{
}
