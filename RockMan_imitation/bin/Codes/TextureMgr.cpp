#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"
#include "SingleTexture.h"
#include "MultiTexture.h"

CTextureMgr::CTextureMgr()
{
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

HRESULT CTextureMgr::InsertTexture(const TCHAR *pFileName, const TEX_TYPE type,
	const TCHAR *pObjKey, const TCHAR* pStateKey /*=NULL*/, const int &cnt /*=0*/)
{
	/* Object의 텍스쳐가 하나도 없으면 바로 Insert 진행 */
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);

	/* insert new Texture of new Object */
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
		// 1. Single
		// 2. Multi
		// TODO: delete->reCreate. 모든 텍스쳐를 삭제하고 다시 생성한다.
		if (type == TEXTYPE_SINGLE)
		{
			LPCWSTR Message = L"Replace? Your object was overlapped:";
			lstrcat(L"temp", pObjKey);
			if (IDOK == MessageBox(g_hWnd, Message, L"Caution", MB_OKCANCEL))
			{
				CTexture* pTexture = nullptr;

				iter->second->Release(); // Direct Delete
				if (FAILED(pTexture->InsertTexture(pFileName, pStateKey, cnt)))
				{
					return E_FAIL;
				}
				m_MapTexture.insert(make_pair(pObjKey, pTexture));
				return S_OK;
			}
			// Not Create, Not release established Texture
			return S_OK;
		}
		else // == TEXTYPE_MULTI
		{
			CMultiTexture* pMultiTexture = (CMultiTexture*)(iter->second);
			if (pMultiTexture->CheckOverlapState(pStateKey))
			{
				LPWSTR Message = L"Continue? Your Multi_StateKey was overlapped:";
				lstrcat(Message, pStateKey);
				if (IDOK == MessageBox(g_hWnd, Message, L"Caution", MB_OKCANCEL))
				{
					if (FAILED(pMultiTexture->()))
					{
						return E_FAIL;
					}
					CTexture* pTexture = nullptr;
					
					if (FAILED(pTexture->InsertTexture(pFileName, pStateKey, cnt)))
					{
						return E_FAIL;
					}

					m_MapTexture.insert(make_pair(pObjKey, pTexture));
					return S_OK;
				}
			}
			// Not Create
			return S_OK;
		}
		MessageBox(g_hWnd, L"Already inserted files!", L"Overlapped", MB_OK);
	}
	return S_OK;
}