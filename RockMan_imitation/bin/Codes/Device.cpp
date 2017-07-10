#include "stdafx.h"
#include "Device.h"


CDevice::CDevice()
{
}
CDevice::~CDevice()
{
	Release();
}

HRESULT CDevice::InitDevice(HWND hWnd)
{
	m_p3D = Direct3DCreate9(D3D_SDK_VERSION);

	// Struct that has GPU Performance
	D3DCAPS9 deviceCaps;
	ZeroMemory(&deviceCaps, sizeof(D3DCAPS9));

	if (FAILED(m_p3D->GetDeviceCaps(D3DADAPTER_DEFAULT
		, D3DDEVTYPE_HAL, &deviceCaps)))
	{
		MessageBox(hWnd, L"Error", L"Cannot get Device Info", MB_OK);
		return E_FAIL;	
	}

	DWORD behaviorFlag = 0;
	// Is the device use my Vertex Processing?
	if (deviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		behaviorFlag = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		behaviorFlag = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.BackBufferWidth = iWinSizeX;
	d3dpp.BackBufferHeight = iWinSizeY;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;

	// Anti-Multi Sampling
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;

	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.EnableAutoDepthStencil = true;

	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (FAILED(m_p3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd
		, behaviorFlag, &d3dpp, &m_pDevice)))
	{
		MessageBox(g_hWnd, L"Error", L"Cannot create Device!", MB_OK);
		return E_FAIL;
	}

	if (FAILED(D3DXCreateSprite(m_pDevice, &m_pSprite)))
	{
		MessageBox(g_hWnd, L"Error", L"Cannot create Sprite!", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

void CDevice::Release()
{
	if(m_pSprite)
		m_pSprite->Release();
	if(m_p3D)
		m_p3D->Release();
	if(m_pDevice)
		m_pDevice->Release();
}

void CDevice::RenderBegin()
{
	m_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
		/*0xff0000ff*/D3DCOLOR_ARGB(255, 0, 255, 0), 1.0f/*Plate, Æò¸é*/, 0);
	m_pDevice->BeginScene();
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void CDevice::RenderEnd()
{
	m_pSprite->End();
	m_pDevice->EndScene();
	m_pDevice->Present(NULL, NULL, g_hWnd, NULL);
}
