#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"
#include "SingleTexture.h"
#include "MultiTexture.h"

#define MESSAGESIZE 128

void CTextureMgr::Release(CTexture * pTexture, TEX_TYPE& type)
{
	// 해당 텍스쳐에 들어가서 Release()를 해주는 고마운 함수(?)
	if (type == TEXTYPE_SINGLE)
	{
		pTexture->Release();
	}
	else
	{
		pTexture->Release();
	}
}

CTextureMgr::CTextureMgr()
{
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
	const TCHAR *pObjKey, const TCHAR *pStateKey /*=NULL*/, const int &cnt /*=0*/)
{
	/* Object의 텍스쳐가 하나도 없으면 바로 Insert 진행 */
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	CTexture* pTexture = nullptr;

	/* Insert new Texture of new Object */
	if (iter == m_MapTexture.end())
	{
		
		
		switch (type) {
		case TEXTYPE_SINGLE:
			pTexture = new CSingleTexture();
			break;
		case TEXTYPE_MULTI:
			pTexture = new CMultiTexture();
			break;
		}

		if (FAILED(pTexture->InsertTexture(pFileName, type, pObjKey, pStateKey, cnt)))
		{
			return E_FAIL;
		}

		m_MapTexture.insert(make_pair(pObjKey, pTexture));
	}
	else
	{
		//if (type == TEXTYPE_SINGLE)
		//{
		//	WCHAR Message[MESSAGESIZE] = L"Continue? Your Texture was overlapped:";
		//	lstrcat(Message, pObjKey);
		//	if (IDOK == MessageBox(g_hWnd, Message, L"Caution", MB_OKCANCEL))
		//	{
		//		CTexture* pTexture = nullptr;
		//		iter->second->Release(); // Direct Delete
		//		pTexture = (iter->second);
		//		if (FAILED(pTexture->InsertTexture(pFileName,, cnt)))
		//		{
		//			return E_FAIL;
		//		}
		//		m_MapTexture.insert(make_pair(pObjKey, pTexture));
		//		return S_OK;
		//	}
		//	// Not Create, Not release established Texture
		//	return S_OK;
		//}
		//else // == TEXTYPE_MULTI
		//{
		//	CMultiTexture* pMultiTexture = (CMultiTexture*)(iter->second);
		//	if (pMultiTexture->CheckOverlapState(pStateKey))
		//	{
		//		WCHAR Message[MESSAGESIZE] = L"Continue? Your Multi_StateKey was overlapped:";
		//		lstrcat(Message, pStateKey);
		//		if (IDOK == MessageBox(g_hWnd, Message, L"Caution", MB_OKCANCEL))
		//		{
		//			if (FAILED(pMultiTexture->Release(pStateKey))) // 멀티 특정 부분만 Release() 한다.
		//			{
		//				return E_FAIL;
		//			}
		//			CTexture* pTexture = nullptr;
		//			
		//			if (FAILED(pTexture->InsertTexture(pFileName, pStateKey, cnt)))
		//			{
		//				return E_FAIL;
		//			}
		//			m_MapTexture.insert(make_pair(pObjKey, pTexture));
		//			return S_OK;
		//		}
		//	}
		//	// Not Create
		//	return S_OK;
		//}
		//MessageBox(g_hWnd, L"Already inserted files!", L"Overlapped", MB_OK); 
		switch (type) {
		case TEXTYPE_SINGLE:
			MessageBox(g_hWnd, L"SingleTexture Overlaped fix your codes...", L"Error!", MB_OK);
			return E_FAIL;
			break;
		case TEXTYPE_MULTI:
			// TODO: 멀티텍스쳐의 경우에는 pStateKey의 존재유무에 따라 중복처리 코드가 다르다.
			// 1. pStateKey가 이미 존재할 경우 에러를 띄우고 종료
			// 2. pStateKey가 없을 경우 다른 State를 만들기 때문에 새로 만들어주는 코드를 넣어주자.
			if (((iter->second))->GetTexture(pStateKey) == nullptr) {
				// 새로 추가
				iter->second->InsertTexture(pFileName, pStateKey, cnt);
			}
			else
			{
				// 이미 pStateKey가 존재시 에러 발생 처리
				return E_FAIL;
			}
			break;
		}
	}
	return S_OK;
}