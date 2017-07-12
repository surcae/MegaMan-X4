#include "stdafx.h"
#include "SingleTexture.h"
#include "Device.h"
#include <Windows.h>

CSingleTexture::CSingleTexture()
{
}
CSingleTexture::~CSingleTexture()
{
	Release();
}

const TEXINFO* CSingleTexture::GetTexture(const TCHAR* pStateKey /*=nullptr*/,
	const int& cnt /*=0*/) {
	return m_pTexInfo; // Failed
}
HRESULT CSingleTexture::InsertTexture(const TCHAR* pFileName, const TCHAR* pStateKey,
	const int& cnt) {
	// Make a new TextureInfo Struct data.
	m_pTexInfo = new TEXINFO;
	ZeroMemory(m_pTexInfo, sizeof(TEXINFO));

	//1. Load your image files and insert your image variable.
	if (FAILED(D3DXGetImageInfoFromFile(pFileName, &(m_pTexInfo->ImageInfo)))) {
		return E_FAIL;
	}

	//2. Create a texture from files.
	D3DXIMAGE_INFO* pTempImageInfo = &m_pTexInfo->ImageInfo;

	if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDevice)->GetDevice(),
		pFileName, pTempImageInfo->Width, pTempImageInfo->Height, pTempImageInfo->MipLevels,
		0/*Usage*/, pTempImageInfo->Format, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT,
		D3DCOLOR_ARGB(255, 255, 255, 255),
		pTempImageInfo,
		NULL/*pPalette*/,
		&m_pTexInfo->pTexture)))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CSingleTexture::Release(void) {
	if (m_pTexInfo)
	{
		m_pTexInfo->pTexture->Release();
		delete &(m_pTexInfo->ImageInfo);
		m_pTexInfo = nullptr;
		return;
	}
	else // Release Failed
	{
		MessageBox(g_hWnd, L"There is no Texture Pointer on your member(=nullptr)",
			L"Error!", MB_ICONERROR);
	}
}