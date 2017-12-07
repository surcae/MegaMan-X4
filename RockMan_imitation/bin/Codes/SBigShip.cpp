#include "stdafx.h"
#include "SBigShip.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CSBigShip::CSBigShip()
{
}


CSBigShip::~CSBigShip()
{
}

HRESULT CSBigShip::Initialize()
{
	// Insert Ship TGA
	this->SetSortID(OBJ_NUM_BG2);



	
	return S_OK;
}

HRESULT CSBigShip::Progress()
{
	
	return S_OK;
}

HRESULT CSBigShip::Render()
{
	//GET_SINGLE(CRenderMgr)->SingleRender()
	return S_OK;
}
