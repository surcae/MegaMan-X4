#pragma once
#include "Texture.h"
class CMultiTexture :
	public CTexture
{
public:
	HRESULT InsertTexture();
public:
	CMultiTexture();
	virtual ~CMultiTexture();
};

