#pragma once
class CTexture;
class CTextureMgr
{
	DECLARE_SINGLETON(CTextureMgr)
private:
	// Memory Buckets for Textures. Your texture will be saved in m_MapTexture.
	map<const TCHAR*, CTexture*> m_MapTexture;
public:
	// const TEXINFO* GetTexture(const TCHAR* pObjKey, const TCHAR* pStateKey, const int & iCnt);
	const TEXINFO* GetTexture(const TCHAR* pObjKey,
		const TCHAR* pStateKey = NULL, const int& iCnt = 0);
	HRESULT InsertTexture(const TCHAR* pFileName, const TEX_TYPE type, const TCHAR* pObjKey, const TCHAR* pStateKey = NULL,	const int& cnt = 0);
	void Release() {
		for (map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.begin();
			iter != m_MapTexture.end(); /*Continue*/) {
			delete iter->second;
			iter->second = NULL;
			++iter;
		}
		m_MapTexture.clear();
	}
private:
	CTextureMgr();
public:
	~CTextureMgr();
};

