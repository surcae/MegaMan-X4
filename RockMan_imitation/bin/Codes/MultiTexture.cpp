#include "stdafx.h"
#include "MultiTexture.h"
#include "Device.h"

CMultiTexture::CMultiTexture()
{
}
CMultiTexture::~CMultiTexture()
{
	Release();
}

const TEXINFO* CMultiTexture::GetTexture(const TCHAR *pStateKey, const int & iCnt)
{
	map<const TCHAR*, vector<TEXINFO*>>::iterator iter = this->m_MapTexture.find(pStateKey);
	if (iter == m_MapTexture.end()) {
		MessageBox(g_hWnd, L"Cannot find StateKey_Objects!", pStateKey, MB_OK);
		return iter->second[iCnt];
	}
	return nullptr; // Failed
}

HRESULT CMultiTexture::InsertTexture(const TCHAR* pFileName, const TCHAR * pStateKey, const int & iCnt)
{
	TCHAR szPath[128] = L"";
	vector<TEXINFO*>	vecTexture;

	for (int i = 0; i < iCnt; ++i)
	{
		wsprintf(szPath, pFileName, i);

		TEXINFO* pTexInfo = new TEXINFO;
		ZeroMemory(pTexInfo, sizeof(TEXINFO));

		//이미지 파일 정보 읽어온다.
		if (FAILED(D3DXGetImageInfoFromFile(szPath, &pTexInfo->ImageInfo))) {
			return E_FAIL;
		}

		if (FAILED(D3DXCreateTextureFromFileEx(GET_SINGLE(CDevice)->GetDevice(),
			szPath, pTexInfo->ImageInfo.Width, pTexInfo->ImageInfo.Height,
			pTexInfo->ImageInfo.MipLevels, 0, pTexInfo->ImageInfo.Format,
			D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT
			, D3DCOLOR_ARGB(255, 255, 255, 255)
			, &pTexInfo->ImageInfo
			, NULL, &pTexInfo->pTexture)))
		{
			return E_FAIL;
		}

		vecTexture.push_back(pTexInfo);
	}

	m_MapTexture.insert(make_pair(pStateKey, vecTexture));

	return S_OK;
}

BOOLEAN CMultiTexture::CheckOverlapState(const TCHAR *pStateKey)
{
	map<const TCHAR*, vector<TEXINFO*>>::iterator iter = m_MapTexture.find(pStateKey);
	if (iter == m_MapTexture.end())
		return false;	// Overlapped X
	else
		return true;	// Overlapped!!
}
void CMultiTexture::SeekStateKey(const TCHAR * pStateKey)
{
	
}
HRESULT CMultiTexture::Release(void) // 전체 삭제
{
	for (map<const TCHAR*, vector<TEXINFO*>>::iterator iter = m_MapTexture.begin(); iter != m_MapTexture.end(); ++iter)
	{
		for (vector<TEXINFO*>::iterator sub_iter = iter->second.begin(); sub_iter != iter->second.end(); ++sub_iter)
		{
			delete *sub_iter;
			*sub_iter = nullptr;
		}
		iter->second.clear();
	}
	m_MapTexture.clear();
	return S_OK;
}

HRESULT CMultiTexture::Release(const TCHAR *pStateKey) // 해당 states 삭제
{
	map<const TCHAR*, vector<TEXINFO*>>::iterator finder = m_MapTexture.find(pStateKey);
	if (finder == m_MapTexture.end())
		return E_FAIL;
	else
	{
		for (size_t i = 0; i < finder->second.size(); ++i)
		{
			finder->second[i]->pTexture->Release();
			SAFE_DELETE(finder->second[i]);
		}
		finder->second.clear();
		return S_OK;
	}
}