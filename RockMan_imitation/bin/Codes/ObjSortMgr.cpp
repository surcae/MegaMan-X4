#include "stdafx.h"
#include "ObjSortMgr.h"
#include "Obj.h"

void CObjSortMgr::Initialize()
{
	this->m_Objvector.resize(20);
	this->m_vecScroll = D3DXVECTOR3(-600, 30, 0);
}

HRESULT CObjSortMgr::AddSortedObj(CObj* paramObj)
{
	OBJ_NUM Received_ObjNum = paramObj->GetSortID();
	m_Objvector[Received_ObjNum].push_back(paramObj);
	
	return S_OK;
}

void CObjSortMgr::ProgressObjects()
{
	for (auto& ref : m_Objvector) {
		for (vector<CObj*>::iterator iter = ref.begin(); iter != ref.end(); ++iter)
		{
			(*iter)->Progress();
		}
	}
}

void CObjSortMgr::RenderObjects()
{
	for (auto& ref : m_Objvector) {
		for (vector<CObj*>::iterator iter = ref.begin(); iter != ref.end(); ++iter)
		{
			(*iter)->Render();
		}
	}
}

void CObjSortMgr::Release()
{
	if (!m_Objvector.size())
		return;
	
	for (auto& ref : m_Objvector) {
		for (vector<CObj*>::iterator iter = ref.begin(); iter != ref.end();)
		{
			(*iter)->Release();
			delete *iter;
			*iter = nullptr;
		}
		ref.clear();
	}
	m_Objvector.clear();
}

CObjSortMgr::CObjSortMgr()
{
	ZeroMemory(&m_Objvector, sizeof(m_Objvector));
}
CObjSortMgr::~CObjSortMgr()
{
	Release();
}
