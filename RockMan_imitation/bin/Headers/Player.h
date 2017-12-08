#pragma once
#include "DynamicObjects.h"

class CTextureMgr;
class CPlayer :
	public CDynamicObjects
{
private:
	bool isControllActivated = false; // 키보드 입력 활성화 (처음 시작할 때와 피격시 비활성화. 평상시엔 활성화)
private:
	DIRECTION Pointer = D_RIGHT;
	CTextureMgr* pTextureMgr = nullptr;
private:
	float x, y;
	float m_fSpeed = 5.f;
public:
	void Transforming();
	void KeyCheck();
public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress(); // Updates
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	CPlayer();
	virtual ~CPlayer();
};

