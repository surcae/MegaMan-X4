#include "stdafx.h"
#include "RenderMgr.h"

#pragma warning (disable : 4244)

//Global Variables
extern FADE_STATE FadeState = E_FADE_STATE_IN;
extern float FadeAlpha = 0;


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
// IN: 밝아짐 OUT: 점점 어두워짐

void CRenderMgr::EffectsFade(const TEXINFO *rTexInfo, D3DXMATRIX &_matWorld,
	D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition)
{
	float iScale = 100;

	if (FadeState == E_FADE_STATE_DONE)
	{
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
			&_vPosition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else
	{
		if (FadeState == E_FADE_STATE_IN)  // Fade out Fading in the black
		{
			if (FadeAlpha < 255)
				FadeAlpha += iScale * GET_SINGLE(CTimeMgr)->GetTime();

			if (FadeAlpha >= 255)
			{
				FadeAlpha = 255;
				// Sit for x number of frames and show the loading screen
				// then fade back in 
				FadeState = E_FADE_STATE_DONE;
			}
			else
			{
				// 0 alpha = clear 255 = opaque
				RenderSprite->SetTransform(&_matWorld);
				RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
					&_vPosition, D3DCOLOR_ARGB(int(FadeAlpha), 255, 255, 255));
			}
		}
		else if (FadeState == E_FADE_STATE_OUT) //Fade back in  but fade out the black 
		{
			if (FadeAlpha > 0)
				FadeAlpha -= iScale * GET_SINGLE(CTimeMgr)->GetTime();

			if (FadeAlpha <= 0)
			{
				FadeAlpha = 0;
				//We are faded back in 
				//done 
				FadeState = E_FADE_STATE_DONE;
			}
			else
			{
				// 0 alpha = clear 255 = opaque
				RenderSprite->SetTransform(&_matWorld);
				RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
					&_vPosition, D3DCOLOR_ARGB(int(FadeAlpha), 255, 255, 255));
			}
		}
	}
}

void CRenderMgr::SingleRender(const TEXINFO *rTexInfo, D3DXMATRIX& _matWorld,
	D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition, 
	SINGLE_RENDER_TYPE type, FRAME _frame, RECT* pRect /*=NULL*/, int Width /*= 0*/, int Height /*= 0*/, int curFrame /*=0*/)
{
	//_vPosition->x *= _frame;
	//_vPosition->y *= _frame;
	if (_frame == NULL)
	{
		switch (type)
		{
		case E_SINGLE_RENDER_TYPE_STRAIGHT:
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, NULL,
				&_vCenter, &_vPosition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case E_SINGLE_RENDER_TYPE_FLASH: // 삐까뻔쩍
			// 미완성
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, NULL,
				&_vCenter, &_vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
			break;
		case E_SINGLE_RENDER_TYPE_FADING:
			EffectsFade(rTexInfo, _matWorld, _vCenter, _vPosition);
			break;
		}
	}
	else if(_frame == 1) // 싱글 텍스쳐인데 여러개 좌표 형성으로 출력하고자 할 때
	{
		RECT* tmp = pRect;
		switch (type)
		{
		case E_SINGLE_RENDER_TYPE_STRAIGHT:
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, pRect,
				&D3DXVECTOR3(((*tmp).right - (*tmp).left) / 2.f, ((*tmp).bottom - (*tmp).top) / 1.f,0), &D3DXVECTOR3(0,0,0), D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case E_SINGLE_RENDER_TYPE_FLASH: // 삐까뻔쩍
										 // 미완성
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, NULL,
				&_vCenter, &_vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
			break;
		case E_SINGLE_RENDER_TYPE_FADING:
			EffectsFade(rTexInfo, _matWorld, _vCenter, _vPosition);
			break;
		}
	}
	else if (_frame > 1) // 다수의 프레임 싱글텍스쳐 일시 (크기가 일정할 때만 적용)
	{
		RECT tmp = {0 + (curFrame) * Width, 
					0,
					(curFrame + 1) * Width,
					Height};
		switch (type)
		{
		case E_SINGLE_RENDER_TYPE_STRAIGHT:
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, &tmp,
				&D3DXVECTOR3((tmp.right - tmp.left) / 2.f, (tmp.bottom - tmp.top), 0), &D3DXVECTOR3(0, 0, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case E_SINGLE_RENDER_TYPE_FLASH: // 삐까뻔쩍
										 // 미완성
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, NULL,
				&_vCenter, &_vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
			break;
		case E_SINGLE_RENDER_TYPE_FADING:
			EffectsFade(rTexInfo, _matWorld, _vCenter, _vPosition);
			break;
		}
	}
}
void CRenderMgr::MultiRender(const TEXINFO *rTexInfo, D3DXMATRIX _matWorld, MULTI_RENDER_TYPE type) // 멀티 스프라이트용
{
	// 미완성
	switch (type)
	{
	case E_MULTI_RENDER_TYPE_STRAIGHT:
	{
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(rTexInfo->pTexture, NULL,
			&D3DXVECTOR3(rTexInfo->ImageInfo.Width / 2.f, rTexInfo->ImageInfo.Height, 0.f), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	break;
	case E_MULTI_RENDER_TYPE_FLASH:
	{
		RenderSprite->SetTransform(&_matWorld);
	}
	break;
	case E_MULTI_RENDER_TYPE_FADING:
	{
		RenderSprite->SetTransform(&_matWorld);
	}
	break;
	}
}