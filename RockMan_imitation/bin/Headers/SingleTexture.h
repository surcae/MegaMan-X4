#pragma once
#include "Texture.h"

#define MAX_SIZE 256

class CSingleTexture :
	public CTexture
{
private:
	TEXINFO* m_pTexInfo;
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL,
		const int& cnt = 0);
	virtual HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStateKey = NULL,
		const int& cnt = 0);
	virtual HRESULT Release(void);
public:
	CSingleTexture();
	virtual ~CSingleTexture();
};

