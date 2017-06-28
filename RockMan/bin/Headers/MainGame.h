#pragma once
#include "Include.h"
class CStage;

class CMainGame
{
private:
	CStage* m_pStage;
public:
	HRESULT Initialize(void);
	HRESULT Progress(void);
	HRESULT Render(void);

public:
	CMainGame();
	~CMainGame();
};

