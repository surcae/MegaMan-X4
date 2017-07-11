#include "stdafx.h"
#include "ObjSortMgr.h"
#include "Obj.h"

HRESULT CObjSortMgr::AddSortedObj(CObj* paramObj)
{
	OBJ_NUM Received_ObjNum = paramObj->GetSortID();
	m_ObjList[Received_ObjNum].push_back(paramObj);
	return S_OK;
}

void CObjSortMgr::RenderObjects()
{

	for (auto& ref : m_ObjList) {
		for (list<CObj*>::iterator iter = ref.begin(); iter != ref.end(); ++iter)
		{
			(*iter)->Render();
		}
		ref.clear();
	}
}

void CObjSortMgr::Release()
{
	if (!m_ObjList.size())
		return;
	
	for (auto& ref : m_ObjList) {
		for (list<CObj*>::iterator iter = ref.begin(); iter != ref.end();)
		{
			(*iter)->Release();
			delete *iter;
			*iter = nullptr;
		}
		ref.clear();
	}
	m_ObjList.clear();
}

CObjSortMgr::CObjSortMgr()
{
	ZeroMemory(&m_ObjList, sizeof(m_ObjList));
}
CObjSortMgr::~CObjSortMgr()
{
	Release();
}
