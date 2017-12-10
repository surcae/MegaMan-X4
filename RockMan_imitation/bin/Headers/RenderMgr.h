#pragma once
#include "Include.h"
#include "Device.h"
#include "TimeMgr.h"

/* UTF-Korean */
/*
Rendering Helper for each Sprite Mode; Single, Multi
스프라이트 모드에 따른 랜더링을 도와주는 매니져
싱글일땐, 랜더 스타팅 좌표를 조정해서 프레임별로 움직이게 보이게 할 수 있다.
멀티일땐, 행동에 따른 각 파일 갯수만큼 랜더하여 프레임별로 움직이게 보이게 할 수 있다.
속도상으로는 싱글이 더욱 빠르다. 메모리도 덜 들기도 한다. 멀티로 하면 파일이 많아서
리소스를 많이 차지하고 부를때 애매하다. 하지만 각 원하는 부위별로 나눌 수 있다는 장점이 있다.

*/
class CRenderMgr
{
	DECLARE_SINGLETON(CRenderMgr)
private:
	//float fDelta = GET_SINGLE(CTimeMgr)->GetTime();
	const LPD3DXSPRITE& RenderSprite = GET_SINGLE(CDevice)->GetSprite();
	void EffectsFade(const TEXINFO *rTexInfo, D3DXMATRIX &_matWorld,
		D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition);
public:
	void SingleRender(const TEXINFO *rTexInfo, D3DXMATRIX& _matWorld,
		D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition,
		SINGLE_RENDER_TYPE type, FRAME _frame, 
		RECT* pRect = NULL, int Width = 0, int Height = 0,
		int curFrame = 0);
	void MultiRender(const TEXINFO *rTexInfo, D3DXMATRIX _matWorld, MULTI_RENDER_TYPE type);
private:
	CRenderMgr();
public:
	~CRenderMgr();
};