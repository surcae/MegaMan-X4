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
	return S_OK;
};

HRESULT CPlayer::Release()
{
	return S_OK;
}