/*Interface*/
#pragma once
#include "Include.h"
class CObj
{
protected:
	INFO m_Info;
public:
	virtual HRESULT Initialize()PURE;
	virtual HRESULT Progress()PURE;
	virtual HRESULT Render()PURE;
	virtual HRESULT Release()PURE;
public:
	CObj();
	virtual ~CObj();
};

