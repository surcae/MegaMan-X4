#include "stdafx.h"
#include "SoundMgr.h"


CSoundMgr::CSoundMgr()
{
}
CSoundMgr::~CSoundMgr()
{
	for (size_t i = 0; i < m_vecSoundBuff.size(); ++i)
	{
		m_vecSoundBuff[i]->Release();
	}
	m_vecSoundBuff.clear();
	m_pSound->Release();
}
HRESULT CSoundMgr::Init(void) {
	// Create Sound Device
	if (FAILED(DirectSoundCreate(NULL, &m_pSound, NULL)))
	{
		MessageBox(g_hWnd, L"Failed creating Sound Device!", L"Create Error", MB_OK);
		return E_FAIL;
	}

	// Set Sound Device CooperativeLevel
	if (FAILED(m_pSound->SetCooperativeLevel(g_hWnd, DSSCL_PRIORITY)))
	{
		MessageBox(g_hWnd, L"Failed setting Sound Device CooperativeLevel!", L"Setting Error", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}
HRESULT CSoundMgr::LoadWave(TCHAR* pFileName) {
	HMMIO hFile;

	// Create File
	hFile = mmioOpen(pFileName, NULL, MMIO_READ); // Open WAV File

	// Junk Structure
	MMCKINFO pParent;
	memset(&pParent, 0, sizeof(pParent));
	pParent.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmioDescend(hFile, &pParent, NULL, MMIO_FINDRIFF);

	MMCKINFO	pChild;
	memset(&pChild, 0, sizeof(pChild));
	pChild.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmioDescend(hFile, &pChild, &pParent, MMIO_FINDCHUNK);

	WAVEFORMATEX	wft;
	memset(&wft, 0, sizeof(wft));
	mmioRead(hFile, (char*)&wft, sizeof(wft));

	mmioAscend(hFile, &pChild, 0);
	pChild.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmioDescend(hFile, &pChild, &pParent, MMIO_FINDCHUNK);

	DSBUFFERDESC	BuffInfo;
	memset(&BuffInfo, 0, sizeof(DSBUFFERDESC));
	BuffInfo.dwBufferBytes = pChild.cksize;
	BuffInfo.dwSize = sizeof(DSBUFFERDESC);
	BuffInfo.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLVOLUME;
	BuffInfo.lpwfxFormat = &wft;

	LPDIRECTSOUNDBUFFER	SoundBuff;

	if (FAILED(m_pSound->CreateSoundBuffer(&BuffInfo, &SoundBuff
		, NULL)))
	{
		MessageBox(g_hWnd, L"Failed creating SoundBuffer!", L"Create Error", MB_OK);
		return E_FAIL;
	}

	void *pWrite1 = NULL, *pWrite2 = NULL;
	DWORD dwlength1, dwlength2;

	// Declare to system that 'I'll use this memories'
	SoundBuff->Lock(0, pChild.cksize, &pWrite1, &dwlength1
		, &pWrite2, &dwlength2, 0);

	if (pWrite1 > 0)
		mmioRead(hFile, (char*)pWrite1, dwlength1);
	if (pWrite2 > 0)
		mmioRead(hFile, (char*)pWrite2, dwlength2);

	SoundBuff->Unlock(pWrite1, dwlength1, pWrite2, dwlength2);

	mmioClose(hFile, 0);

	m_vecSoundBuff.push_back(SoundBuff);
	return S_OK;
}
void CSoundMgr::SoundPlay(SOUND_INDEX Index, DWORD dwFlag) {
	if (Index < 0 || Index >(signed)m_vecSoundBuff.size())
		return;

	m_vecSoundBuff[Index]->SetCurrentPosition(0);

	DWORD dwFre;
	m_vecSoundBuff[Index]->GetFrequency(&dwFre);
	m_vecSoundBuff[Index]->Play(0, 0, dwFlag);
}
void CSoundMgr::SoundStop(SOUND_INDEX Index) {
	if (Index < 0 || Index >(signed)m_vecSoundBuff.size())
		return;

	m_vecSoundBuff[Index]->Stop();
}
bool CSoundMgr::SoundPlaying(SOUND_INDEX Index) {
	DWORD dwStatus = 0;
	m_vecSoundBuff[Index]->GetStatus(&dwStatus);

	if (dwStatus & DSBSTATUS_PLAYING)
		return true;
	else
		return false;
}
void CSoundMgr::SetSoundVolume(SOUND_INDEX Index, int Value) {
	m_vecSoundBuff[Index]->SetVolume(Value);
}