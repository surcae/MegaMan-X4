#pragma once
// 여기서 발판에 따른 Status 직접 변경을 해준다.
class CCollisionMgr
{
	DECLARE_SINGLETON(CCollisionMgr)
public:
	void RenderCollision();
public:
	CCollisionMgr();
	~CCollisionMgr();
};

