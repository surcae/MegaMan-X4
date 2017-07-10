#include "stdafx.h"
#include "MultiTexture.h"

CMultiTexture::CMultiTexture()
{
}
CMultiTexture::~CMultiTexture()
{
	Release();
}


const TEXINFO * CMultiTexture::GetTexture(const TCHAR * pStateKey, const int & iCnt)
{
	return nullptr;
}

HRESULT CMultiTexture::InsertTexture(const TCHAR * pFileName, const TCHAR * pStateKey, const int & iCnt)
{
	return S_OK;
}

void CMultiTexture::Release(void)
{
}
