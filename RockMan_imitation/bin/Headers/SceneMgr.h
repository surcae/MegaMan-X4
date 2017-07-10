#pragma once
#include "Include.h"
class CMyScene;
class CSceneMgr
{
public:
	DECLARE_SINGLETON(CSceneMgr)
private:
	CMyScene* m_pMyScene = nullptr;
public:
	HRESULT InitScene(FIELD _stage);
	void Progress();
	void Render();
	void Release();
private:
	CSceneMgr();
public:
	~CSceneMgr();
};

