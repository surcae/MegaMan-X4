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
		return nullptr;
	}

	return nullptr; // 나중에 수정
}

HRESULT CMultiTexture::InsertTexture(const TCHAR* pFileName, const TCHAR * pStateKey, const int & iCnt)
{
	return S_OK;
}

void CMultiTexture::Release(void)
{
	for (map<const TCHAR*, vector<TEXINFO*>>::iterator iter = m_MapTexture.begin(); iter != m_MapTexture.end(); ++iter)
	{
		for (vector<TEXINFO*>::iterator sub_iter = iter->second.begin();sub_iter != iter->second.end(); ++sub_iter)
		{
			delete *sub_iter;
			*sub_iter = nullptr;
		}
		iter->second.clear();
	}
	m_MapTexture.clear();
}