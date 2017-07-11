#include "stdafx.h"
#include "Obj.h"

CObj::CObj()
{
	ZeroMemory(&m_Info, sizeof(OBJINFO));
}
CObj::~CObj()
{
}
