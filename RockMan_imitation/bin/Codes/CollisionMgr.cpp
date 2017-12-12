#include "stdafx.h"
#include "CollisionMgr.h"


void CCollisionMgr::RenderCollision()
{
	// 호출되면 히트 박스를 생성시킴.
	RECT hitBox[4];
	hitBox[0] = {
		-10, 430, 1500, 600
	}; // 가장 아래 발판
	hitBox[1] = {
		
	};
	hitBox[2] = {
		-10, 100, 300, 270
	};
	hitBox[3] = {
		800, 100, 1000, 270
	};
}

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}
