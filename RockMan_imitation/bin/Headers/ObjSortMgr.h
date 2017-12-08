#pragma once
class CObj;
class CObjSortMgr
{
	// 이 매니져는 스테이지 오브젝트들만 관리합니다.
	DECLARE_SINGLETON(CObjSortMgr)
private:
	vector<vector<CObj*>> m_Objvector;
public:
	D3DXVECTOR3 m_vecScroll = D3DXVECTOR3(300, 0, 0);
	void Initialize();
	HRESULT AddSortedObj(CObj* paramObj);
	void ProgressObjects();
	void RenderObjects();
	void Release();
public:
	CObjSortMgr();
	~CObjSortMgr();
};

