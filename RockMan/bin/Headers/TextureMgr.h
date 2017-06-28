#pragma once
class CTexture;
class CTextureMgr
{
	DECLARE_SINGLETON(CTextureMgr)
private:
	// Memory Buckets for Textures. Your texture will be saved in m_MapTexture.
	map<const TCHAR*, CTexture*> m_MapTexture;
public:
	const TEXINFO* GetTexture(const TCHAR* pObjKey,
		const TCHAR* pStateKey = NULL, const int& iCnt = 0);
	HRESULT InsertTexture(const TCHAR* pFileName = NULL, const TCHAR* pStateKey = NULL,	const int& cnt = 0);
private:
	CTextureMgr();
public:
	~CTextureMgr();
};

