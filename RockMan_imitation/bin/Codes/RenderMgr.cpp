#include "stdafx.h"
#include "RenderMgr.h"


CRenderMgr::CRenderMgr()
{
}


CRenderMgr::~CRenderMgr()
{
}

void CRenderMgr::SingleRender(const TEXINFO*& pTexInfo, D3DXMATRIX& _matWorld, D3DXVECTOR3*& _vCenter, D3DXVECTOR3*& _vPosition)
{
	RenderSprite->SetTransform(&_matWorld);
	RenderSprite->Draw(pTexInfo->pTexture, NULL,
		_vCenter, _vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
}
void CRenderMgr::MultiRender()
{
}