#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"
#include "SingleTexture.h"
#include "MultiTexture.h"

CTextureMgr::CTextureMgr()
{
	ZeroMemory(&m_MapTexture, sizeof(std::map<const TCHAR*, CTexture*>));
	ZeroMemory(&m_stFileName, sizeof(std::stack<TCHAR*>));
}
CTextureMgr::~CTextureMgr()
{
	Release();
}

const TEXINFO* CTextureMgr::GetTexture(const TCHAR* pObjKey, const TCHAR* pStateKey, const int& iCnt){
map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	if (iter == m_MapTexture.end()) return NULL; // Not found
	else return iter->second->GetTexture(pStateKey, iCnt); 

	return nullptr; // Not Success == error
}

HRESULT CTextureMgr::InsertTexture(const TCHAR* pFileName, const TEX_TYPE type,
	const TCHAR* pObjKey, const TCHAR* pStateKey /*=NULL*/, const int &cnt /*=0*/)
{
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	if (iter == m_MapTexture.end())
	{
		CTexture* pTexture = nullptr;
		
		switch (type) {
		case TEXTYPE_SINGLE:
			pTexture = new CSingleTexture();
			break;
		case TEXTYPE_MULTI:
			pTexture = new CMultiTexture();
			break;
		}
		if (FAILED(pTexture->InsertTexture(pFileName, pStateKey, cnt)))
		{
			return E_FAIL;
		}

		m_MapTexture.insert(make_pair(pObjKey, pTexture));
	}
	else
	{
		// if m_MapTexture has Already exist texture file...
		MessageBox(g_hWnd, L"Already inserted files!", L"Overlapped", MB_OK);
	}
	return S_OK;
}