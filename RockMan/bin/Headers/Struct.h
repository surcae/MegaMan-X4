#pragma once
#ifndef _STRUCT_H_
#define _STRUCT_H_
#include "d3d9.h"
#include "d3dx9tex.h"
struct tagINFO
{
	double xpos;
	double ypos;
};

typedef tagINFO INFO;

struct tagTexture
{
	LPDIRECT3DTEXTURE9 pTexture;
	D3DXIMAGE_INFO ImageInfo;
};

typedef tagTexture TEXINFO;

#endif