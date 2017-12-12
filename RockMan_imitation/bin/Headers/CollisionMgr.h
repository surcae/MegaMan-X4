#pragma once
#include "Include.h"
// 여기서 발판에 따른 Status 직접 변경을 해준다.
class CMonster;
class CPlayer;
class CCollisionMgr
{
	DECLARE_SINGLETON(CCollisionMgr)
public:
	vector<CMonster*>* pVector;
	void SetPointer(vector<CMonster*>* _param)
	{
		pVector = _param;
	}
	void CollisionCheck(CPlayer* pPlayer);
	void AttackandMop(RECT src);
public:
	CCollisionMgr();
	~CCollisionMgr();
};

