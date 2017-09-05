#include "stdafx.h"
#include "TimeMgr.h"


void CTimeMgr::InitTimeMgr(void)
{
	QueryPerformanceCounter(&m_FrameTime);
	QueryPerformanceCounter(&m_FixTime);
	QueryPerformanceCounter(&m_LastTime);
	QueryPerformanceFrequency(&m_CpuTick); // 1초에 cpu가 낼 수 있는 연산시간
}

void CTimeMgr::SetTime(void) // 프레임 마다 호출된다.
{
	QueryPerformanceCounter(&m_FrameTime); // 프레임 마다 갱신된다. 프레임 마다 새 숫자가 입력된다.
	if (m_FrameTime.QuadPart - m_LastTime.QuadPart > m_CpuTick.QuadPart) // 이 연산을 프레임 마다 거칠 때마다 1초가 넘었는지를 검사한다. m_CpuTick에는 1초가 들어가겠다.
	{
		// 1초동안 연산한 주파수 양을 다시 받아온다.
		QueryPerformanceFrequency(&m_CpuTick); // 위의 if문을 위한 재갱신용임
		m_LastTime.QuadPart = m_FrameTime.QuadPart; // 들어온 순간의 Frame 타임은 곧 Last 타임이 되니 Last에 넣어둔다.
	}

	m_fTime = float(m_FrameTime.QuadPart - m_FixTime.QuadPart) / m_CpuTick.QuadPart; //나누는 이유는 단위가 맞지 않기 떄문에 시간으로 바꿔주기 위함임 즉 이 값을 곱하기로 쓰면
	
	m_FixTime = m_FrameTime;
	
	/*
	if(DeltaTick - LastTick > GET_SINGLE(CTimeMgr)->GetTime()){
		// TODO: SOMETHING
	}

	*/
}

CTimeMgr::CTimeMgr()
{
}


CTimeMgr::~CTimeMgr()
{
}
