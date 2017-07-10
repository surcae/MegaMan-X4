#pragma once
class CMyScene
{
public:
	virtual HRESULT Initialize()PURE;
	virtual HRESULT Progress()PURE;
	virtual HRESULT Render()PURE;
	virtual HRESULT Release()PURE;
public:
	CMyScene();
	virtual ~CMyScene();
};

