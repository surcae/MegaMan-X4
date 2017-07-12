#include "stdafx.h"
#include "MultiTexture.h"

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
void CMultiTexture::Release(void)
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
}

HRESULT CMultiTexture::Release(const TCHAR *pStateKey)
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
	return S_OK;
}