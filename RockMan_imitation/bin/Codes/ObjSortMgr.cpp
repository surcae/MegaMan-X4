#include "stdafx.h"
#include "ObjSortMgr.h"
#include "Obj.h"

HRESULT CObjSortMgr::AddSortedObj(CObj* paramObj)
{
	OBJ_NUM Received_ObjNum = paramObj->GetSortID();
	m_ObjList[Received_ObjNum].push_back(paramObj);
	return S_OK;
}

CObjSortMgr::CObjSortMgr()
{
	ZeroMemory(&m_ObjList, sizeof(m_ObjList));
}
CObjSortMgr::~CObjSortMgr()
{
}
