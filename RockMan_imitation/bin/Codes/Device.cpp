#include "stdafx.h"
#include "Device.h"


CDevice::CDevice()
{
}
CDevice::~CDevice()
{
	Release();
}

HRESULT CDevice::InitDevice(bool isFull, HWND hWnd, const int & iWinCX, const int & iWinCY)
{
	m_p3D = Direct3DCreate9(D3D_SDK_VERSION);

	// Struct that has GPU Performance
	D3DCAPS9 deviceCaps;
	ZeroMemory(&deviceCaps, sizeof(D3DCAPS9));

	if (FAILED(m_p3D->GetDeviceCaps(D3DADAPTER_DEFAULT
		, D3DDEVTYPE_HAL, &deviceCaps)))
	{
		MessageBox(g_hWnd, L"Error", L"Cannot get Device Info", MB_OK);
		return E_FAIL;	
	}

	DWORD behaviorFlag = 0;
	// Is the device use my GPU?
	if (deviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		behaviorFlag = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		behaviorFlag = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	if (FAILED(m_p3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd
		, behaviorFlag, NULL, &m_pDevice)))
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
	m_pDevice->BeginScene();
}

void CDevice::RenderEnd()
{
	m_pDevice->EndScene();
}
