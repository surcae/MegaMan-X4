#include "stdafx.h"
#include "Device.h"
#include "Logo.h"
#include "TextureMgr.h"

CLogo::CLogo()
{
}
CLogo::~CLogo()
{
}

HRESULT CLogo::Initialize() {
	if (FAILED(GET_SINGLE(CTextureMgr)
		->InsertTexture(L"../Resource/BackGrounds/TopBackGrounds.png", TEXTYPE_SINGLE))) {
		TEXTURE_ERROR_MSG(BackGround);
		return E_FAIL;
	}
	
	return S_OK;
};
HRESULT CLogo::Progress() { return S_OK; };
HRESULT CLogo::Render() { 
	




	return S_OK;
};
HRESULT CLogo::Release() { return S_OK; };
