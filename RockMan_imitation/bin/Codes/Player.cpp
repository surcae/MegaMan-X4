#include "stdafx.h"
#include "Player.h"
#include "RenderMgr.h"
#include "CollisionMgr.h"
#include "ObjSortMgr.h"
#include "TextureMgr.h"
#include "SoundMgr.h"
#include "KeyMgr.h"

#define KEY_DOWN(code) ((GetAsyncKeyState(code)&0x8000)?1:0)

#define LOOP 1
#define NOLOOP 0

CPlayer::CPlayer()
{
	x = 500.f;
	y = 200.f;
}
CPlayer::~CPlayer()
{
}

void CPlayer::Transforming()
{
}

void CPlayer::KeyCheck()
{
	if (KEY_DOWN(VK_LEFT))
	{
		(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) += (200 * GET_SINGLE(CTimeMgr)->GetTime());
	}
	if (KEY_DOWN(VK_RIGHT))
	{
		(GET_SINGLE(CObjSortMgr)->m_vecScroll.x) -= (200 * GET_SINGLE(CTimeMgr)->GetTime());
	}
}

HRESULT CPlayer::Initialize() {
	this->SetSortID(OBJ_NUM_PLAYER);
	this->pTextureMgr = GET_SINGLE(CTextureMgr);
	D3DXMatrixScaling(&m_Info.matScale, 1.5f, 1.5f, 1.f);
	D3DXMatrixTranslation(&m_Info.matTrans, x, y, 0); // 나중에 스크롤 더해주면 됨.
	m_Info.matWorld = m_Info.matScale * m_Info.matTrans;


	
	return S_OK;
};
HRESULT CPlayer::Progress() {
	KeyCheck();
	Transforming();
	return S_OK;
};
HRESULT CPlayer::Render() {
	GET_SINGLE(CRenderMgr)->SingleRender(pTextureMgr->GetTexture(L"Spawn1"), m_Info.matWorld,
		D3DXVECTOR3(3/*pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Width / 2.f*/,
			79/*pTextureMgr->GetTexture(L"Spawn1")->ImageInfo.Height / 2.f*/, 0.f), D3DXVECTOR3(0.f, 0.f, 0.f),
		E_SINGLE_RENDER_TYPE_STRAIGHT, NULL);
	
	//RECT MyRECT = { 0, 0, 0, 0 };
	/* 히트 박스 그리기
	HDC hdc = BeginPaint(g_hWnd, NULL);
	Rectangle(hdc, 10, 10, 10, 10);
	*/
	return S_OK;
};

HRESULT CPlayer::Release()
{
	return S_OK;
}