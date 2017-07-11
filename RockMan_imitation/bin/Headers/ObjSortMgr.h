#pragma once
class CObj;
class CObjSortMgr
{
	DECLARE_SINGLETON(CObjSortMgr)
private:
	vector<list<CObj*>> m_ObjList;
public:
	HRESULT AddSortedObj(CObj* paramObj);
	void RenderObjects();
	void Release();
public:
	CObjSortMgr();
	~CObjSortMgr();
};

