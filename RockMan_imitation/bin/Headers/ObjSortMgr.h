#pragma once
class CObj;
class CObjSortMgr
{
	// 이 매니져는 스테이지 오브젝트들만 관리합니다.
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

