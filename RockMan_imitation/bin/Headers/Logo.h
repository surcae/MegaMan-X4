#pragma once
#include "MyScene.h"
class CLogo : 
	public CMyScene
{
public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress();
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	CLogo();
	~CLogo();
};

