#pragma once
/* Abstract Class */
class CTexture {
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL,
		const int& cnt = 0)PURE;
	virtual HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStateKey = NULL,
		const int& cnt = 0)PURE;
	virtual void Release(void)PURE;
public:
	CTexture();
	virtual ~CTexture();
};