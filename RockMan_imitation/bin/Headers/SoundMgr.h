#pragma once
class CSoundMgr
{
	DECLARE_SINGLETON(CSoundMgr)
private:
	LPDIRECTSOUND m_pSound; // SoundCard Object
	vector<LPDIRECTSOUNDBUFFER> m_vecSoundBuff; // vector for saving sound files
public:
	HRESULT Init(void);
	HRESULT LoadWave(TCHAR* pFileName);
	void SoundPlay(SOUND_INDEX Index, DWORD dwFlag);
	void SoundStop(SOUND_INDEX Index);
	bool SoundPlaying(SOUND_INDEX Index); // 0: Not Playing 1: Now Playing
	void SetSoundVolume(SOUND_INDEX Index, int Value);
public:
	CSoundMgr();
	~CSoundMgr();
};

