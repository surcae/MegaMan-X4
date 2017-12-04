#pragma once
#include "Enum.h"
#include "d3d9.h"
#include "d3dx9tex.h"

#ifndef _STRUCT_H_
#define _STRUCT_H_

struct tagObjInfo
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vDir;
	D3DXVECTOR3 vLook;
	D3DXVECTOR3 vCenter;
	D3DXMATRIX matWorld;

	tagObjInfo(void) {}
	tagObjInfo(const tagObjInfo& Info)
		:vPos(Info.vPos), vDir(Info.vDir),
		vLook(Info.vLook), matWorld(Info.matWorld)
	{}
};

typedef tagObjInfo OBJINFO;

struct tagTexture
{
	LPDIRECT3DTEXTURE9 pTexture;
	D3DXIMAGE_INFO ImageInfo;
	int Cnt; // For Multi-Tex
};

typedef tagTexture TEXINFO;

struct tagLogo
{
	D3DXMATRIX matWorld;
	D3DXMATRIX matScale;
	D3DXMATRIX matTrans;
	D3DXMATRIX matRot;
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vCenter;
	const TCHAR *pObjName;
	const TCHAR *pStateKey;
	LOGO_OBJ myLogoObj;

	TEXINFO* texInfo;
};

typedef tagLogo TRANSFORM;
#endif