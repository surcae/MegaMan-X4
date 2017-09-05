#pragma once
#include "Include.h"

class CTimeMgr
{
	DECLARE_SINGLETON(CTimeMgr)
private:
	LARGE_INTEGER m_FrameTime;
	LARGE_INTEGER m_FixTime;
	LARGE_INTEGER m_LastTime;
	LARGE_INTEGER m_CpuTick;
	float m_fTime;
public:
	float GetTime(void) const {
		return m_fTime;
	}
public:
	void InitTimeMgr(void); //처음에 무조건 한 번 호출
	void SetTime(void); //프레임 마다 호출 (MainGame 돌아가는곳에 설치해두면 좋음)
private:
	CTimeMgr();
public:
	~CTimeMgr();
};

