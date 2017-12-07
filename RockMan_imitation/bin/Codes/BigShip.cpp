#include "stdafx.h"
#include "BigShip.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CBigShip::CBigShip()
{
}


CBigShip::~CBigShip()
{
}

HRESULT CBigShip::Initialize()
{
	// Insert Ship TGA
	this->SetSortID(OBJ_NUM_BG2);

	m_Info.vCenter = D3DXVECTOR3(0, 0, 0);
	m_Info.vPos = D3DXVECTOR3(300, 300, 0);
	return S_OK;
}

HRESULT CBigShip::Progress()
{
	return S_OK;
}

HRESULT CBigShip::Render()
{
	return S_OK;
}
