#pragma once
class CMainGame
{
private:
	int StartTick = GetTickCount();
public:
	HRESULT Initialize(void);
	HRESULT Update(void);
	HRESULT Render(void);
	HRESULT Release(void);
public:
	CMainGame();
	~CMainGame();
};

