#pragma once
// 크리티컬 섹션으로 단일 프로세스에 대해 다중 쓰레드를 구현해서 사용함.
// 보통 랜더링, 키 입력, Process() 함수를 3중 쓰레딩으로 접근 Tick을 늘릴 것임.
// 프로젝트 제출용까지는 적용 안하고 회사용으로 만들때만 멀티 쓰레드 (Lock-Free 알고리즘 써서 (뮤텍스 락) 만들 계획)
#include <thread>

class CMultiThread
{
private:
	CRITICAL_SECTION m_Critic; // 섹션 자체 메모리
public:
	void EnterCriticalSection();
public:
	CMultiThread();
	~CMultiThread();
};

