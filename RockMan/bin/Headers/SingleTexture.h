#pragma once
#include "Texture.h"
class CSingleTexture :
	public CTexture
{
private:
	TEXINFO* m_pTexInfo;
public:
	const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL,
		const int& cnt = 0);
	HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStateKey = NULL,
		const int& cnt = 0);
	void Release(void);
public:
	CSingleTexture();
	virtual ~CSingleTexture();
};

