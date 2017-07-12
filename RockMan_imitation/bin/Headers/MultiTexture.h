#pragma once
#include "Texture.h"
class CMultiTexture :
	public CTexture
{
private:
	map<const TCHAR*, vector<TEXINFO*>> m_MapTexture;
public:
	virtual const TEXINFO* GetTexture(const TCHAR *pStateKey = NULL, const int& iCnt = 0);
public:
	virtual HRESULT InsertTexture(const TCHAR *pFileName,
		const TCHAR *pStateKey = NULL, const int& iCnt = 0);
	virtual void Release(void);
	void Release(const TCHAR *pStateKey);
	BOOLEAN CheckOverlapState(const TCHAR *pStateKey);
public:
	CMultiTexture();
	virtual ~CMultiTexture();
};