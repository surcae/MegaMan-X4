#pragma once
#include "Include.h"

class CStage
{
private:
	FIELD m_Field;
public:
	HRESULT Initialize(void);
	HRESULT Progress(void);
	HRESULT Render(void);
	HRESULT Release(void);
public:
	CStage();
	CStage(FIELD StageNum);
	~CStage();
};

