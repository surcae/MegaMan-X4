#pragma once
#include "Obj.h"
class CDynamicObjects :
	public CObj
{
public:
	virtual HRESULT Initialize() { return S_OK;  };
	virtual HRESULT Progress() { return S_OK;  };
	virtual HRESULT Render() { return S_OK;  };
	virtual HRESULT Release() { return S_OK; };
public:
	CDynamicObjects();
	virtual ~CDynamicObjects();
};
