#pragma once
#include "Obj.h"
#include "ObjSortMgr.h"

class CStaticObjects :
	public CObj
{
protected:
	D3DXVECTOR3* m_pvecScroll = &GET_SINGLE(CObjSortMgr)->m_vecScroll;
public:
	virtual HRESULT Initialize() { return S_OK; };
	virtual HRESULT Progress() { return S_OK; };
	virtual HRESULT Render() { return S_OK; };
	virtual HRESULT Release() { return S_OK; };
public:
	CStaticObjects();
	virtual ~CStaticObjects();
};

