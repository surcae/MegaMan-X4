#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"
#include "SingleTexture.h"
#include "MultiTexture.h"

CTextureMgr::CTextureMgr()
{
}
CTextureMgr::~CTextureMgr()
{
	Release();
}
const TEXINFO * CTextureMgr::GetTexture(const TCHAR* pObjKey, const TCHAR* pStateKey, const int & iCnt){
map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	if (iter == m_MapTexture.end()) return NULL; // Not found
	else { iter->second->GetTexture(pObjKey, iCnt); }

	return nullptr; // Not Success == error
}

HRESULT CTextureMgr::InsertTexture(const TCHAR* pFileName, const TEX_TYPE type, const TCHAR* pStateKey /*=NULL*/, const int &cnt /*=0*/)
{
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pFileName);
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
	}
	
	iter->second->InsertTexture(pFileName, pStateKey, cnt);
	return S_OK;
}