#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

HRESULT CPlayer::Initialize() {
//	m_Info.xpos = 0;
//	m_Info.ypos = 0;


	return S_OK;
};
HRESULT CPlayer::Progress() {
	return S_OK;
};
HRESULT CPlayer::Render() {
	RECT MyRECT = { 0, 0, 0, 0 };

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