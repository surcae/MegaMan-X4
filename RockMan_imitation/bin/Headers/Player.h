#pragma once
#include "DynamicObjects.h"

class CTextureMgr;
class CPlayer :
	public CDynamicObjects
{
private:
	float JumpPowerMax = 10.f;
	float JumpPowerMin = -10.f;
	int FrameMax = 0;
	float ForStartFrame = 1.f;
	float m_fFrame = 1;
	float m_fFrameSpeed = 5;
	float DASH_FRAME = 0;
	STATUS eStatus = E_STATUS_IDLE;
	bool isStart = false;
	static bool isSpawn;
	bool isDashSoundPlayed = false;
	bool isControllActivated = false; // 키보드 입력 활성화 (처음 시작할 때와 피격시 비활성화. 평상시엔 활성화)
private:
	CTextureMgr* pTextureMgr = nullptr;
private:
	float MaxYpos = 480.f;
	int Hp = 100;
	float x, y;
	float m_fSpeed = 220.f;
	DIRECTION Pointer = D_RIGHT;
	POS_STATION bPosStation = E_POS_STATION_GROUND;
public:
	void FrameProcess();
	void KeyCheck();
public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress(); // Updates
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	void SpawnRender();
	static void SetSpawn() {
		isSpawn = true;
	}
public:
	CPlayer();
	virtual ~CPlayer();
};

