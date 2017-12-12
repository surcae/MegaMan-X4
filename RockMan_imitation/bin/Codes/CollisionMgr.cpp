#include "stdafx.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "Monster.h"
#include "SoundMgr.h"

#define PLX pPlayer->GetPos().x
#define PLY pPlayer->GetPos().y

#define HW 40
#define HH 40

void CCollisionMgr::CollisionCheck(CPlayer* pPlayer)
{
	D3DXVECTOR3 *PlayerScroll = pPlayer->GetScroll();
	myRECT hitBox[3];
	hitBox[0] = {
		-10, 480, 1500, 650
	}; // 가장 아래 발판
	hitBox[1] = {
		-10 + PlayerScroll->x, -20 + PlayerScroll->y, 1500 + PlayerScroll->x, 30 + PlayerScroll->y
	}; // 위 발판 
	hitBox[2] = { 
		620 + PlayerScroll->x, -140 + PlayerScroll->y, 844 + PlayerScroll->x, 250 + PlayerScroll->y
	}; // 벽 94 98
	
	if (PLX + HW < hitBox[0].right && hitBox[0].left < PLX - HW
		&& PLY + HH > hitBox[0].bottom && hitBox[0].top > PLY - HH)
	{
		hitBox[1].left = 0;
		return;
	}
}

void CCollisionMgr::AttackandMop(RECT src)
{
	for (vector<CMonster*>::iterator it = (*pVector).begin(); it != (*pVector).end(); ++it)
	{
		
		RECT tmp;
		RECT dest = {(LONG)(*it)->GetXPos() - 30, (LONG)(*it)->GetXPos() - 30, (LONG)(*it)->GetXPos() + 30, (LONG)(*it)->GetXPos() + 30 };
		if (IntersectRect(&tmp, &src, &dest))
		{
			(*it)->isHit = true;
			
		}
	}
}

CCollisionMgr::CCollisionMgr()
{
}
CCollisionMgr::~CCollisionMgr()
{
}