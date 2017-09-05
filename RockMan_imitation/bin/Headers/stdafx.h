// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once
#include "../../RockMan/targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#include "Include.h"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <d3d9.h>
#include <d3dx9.h>
#include "d3dx9tex.h"

// Sounds Files...
#include <MMSystem.h>
#include <dsound.h>
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "winmm.lib")

// Key Input Files...
#define DIRECTINPUT_VERSION 0x0800
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#include "dinput.h"