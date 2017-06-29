#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"

const TEXINFO * CTextureMgr::GetTexture(const TCHAR* pObjKey, const TCHAR* pStateKey, const int & iCnt)
{
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	if (iter == m_MapTexture.end()) return NULL; // Not found
	else { iter->second->GetTexture(pObjKey, iCnt); }

	return nullptr; // Not Success == error
}

HRESULT CTextureMgr::InsertTexture(const TCHAR* pFileName, const TCHAR* pStateKey, const int &cnt)
{
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pFileName);
	return S_OK;
}

CTextureMgr::CTextureMgr()
{
}
CTextureMgr::~CTextureMgr()
{
}
