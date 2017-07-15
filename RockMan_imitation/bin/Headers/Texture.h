#pragma once
/* Abstract Class */
class CTexture {
private:
	TEX_TYPE MyType;
public:
	TEX_TYPE getMyType(void) {
		return MyType;
	}
public:
	virtual const TEXINFO* GetTexture(const TCHAR* pStateKey = NULL,
		const int& cnt = 0)PURE;
	virtual HRESULT InsertTexture(const TCHAR* pFileName, const TCHAR* pStateKey = NULL,
		const int& cnt = 0)PURE;
	virtual HRESULT Release(void)PURE;
public:
	CTexture();
	virtual ~CTexture();
};