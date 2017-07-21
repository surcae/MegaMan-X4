#	include "stdafx.h"
#include "RenderMgr.h"

//Global Variables
extern FADE_STATE FadeState = E_FADE_STATE_IN;
extern int FadeAlpha = 0;


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



void CRenderMgr::EffectsFade(const TEXINFO *rTexInfo, D3DXMATRIX &_matWorld,
	D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition)
{
	if (FadeState == E_FADE_STATE_DONE)
	{
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
			&_vPosition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else
	{
		if(GetTickCount() - Delta >= 250)
		{
			if (FadeState == E_FADE_STATE_IN)  // Fade out Fading in the black
			{
				if (FadeAlpha <= 255)
					FadeAlpha += 3;

				if (FadeAlpha >= 255)
				{
					FadeAlpha = 255;
					// Sit for x number of frames and show the loading screen
					//then fade back in 
					FadeState = E_FADE_STATE_DONE;
				}
				else
				{
					// 0 alpha = clear 255 = opaque
					RenderSprite->SetTransform(&_matWorld);
					RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
						&_vPosition, D3DCOLOR_ARGB(FadeAlpha, 255, 255, 255));
				}
			}
			else if (FadeState == E_FADE_STATE_OUT) //Fade back in  but fade out the black 
			{
				if (FadeAlpha >= 0)
					FadeAlpha -= 3;

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
						&_vPosition, D3DCOLOR_ARGB(FadeAlpha, 255, 255, 255));
				}
			}
			Delta = GetTickCount();
		}
	}
}

void CRenderMgr::SingleRender(const TEXINFO *rTexInfo, D3DXMATRIX& _matWorld,
	D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition, SINGLE_RENDER_TYPE type, FRAME _frame)
{
	//_vPosition->x *= _frame;
	//_vPosition->y *= _frame;
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
void CRenderMgr::MultiRender()
{
	
}