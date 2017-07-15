#	include "stdafx.h"
#include "RenderMgr.h"


CRenderMgr::CRenderMgr()
{
}


CRenderMgr::~CRenderMgr()
{
}

// 스테이트는 두 가지로 나뉜다.
// 1. 내 캐릭터는 상태 스테이트
// 2. 프레임 상태의 스테이트
// 3. 이 검사는 매 프레임(애니메이션이 호출되는곳이면 호출)마다 검사하게 된다.



void CRenderMgr::SingleRender(const TEXINFO*& pTexInfo, D3DXMATRIX& _matWorld, 
	D3DXVECTOR3*& _vCenter, D3DXVECTOR3*& _vPosition, SINGLE_RENDER_TYPE type, FRAME& _frame)
{
	//_vPosition->x *= _frame;
	//_vPosition->y *= _frame;
	switch (type)
	{
	case E_SINGLE_RENDER_TYPE_STRAIGHT:
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(pTexInfo->pTexture, NULL,
			_vCenter, _vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
		break;
	case E_SINGLE_RENDER_TYPE_FLASH: // 삐까뻔쩍
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(pTexInfo->pTexture, NULL,
			_vCenter, _vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
		break;
	}
}
void CRenderMgr::MultiRender()
{
}