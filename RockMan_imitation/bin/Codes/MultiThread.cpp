#include "stdafx.h"
#include "MultiThread.h"


void CMultiThread::EnterCriticalSection()
{
	TryEnterCriticalSection(&m_Critic);
}

CMultiThread::CMultiThread()
{
	::InitializeCriticalSection(&m_Critic);
}


CMultiThread::~CMultiThread()
{
	::DeleteCriticalSection(&m_Critic);
}
