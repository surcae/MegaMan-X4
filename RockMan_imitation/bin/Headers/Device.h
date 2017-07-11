#pragma once
class CDevice
{
	DECLARE_SINGLETON(CDevice)
private:
	// A Struct for Device performance
	LPDIRECT3D9 m_p3D;

	// Device Struct
	LPDIRECT3DDEVICE9 m_pDevice;

	// Image Print Struct (Sprite)
	LPD3DXSPRITE m_pSprite;

	// Font Print Struct on Screen
	LPD3DXFONT m_pFont;
public:
	LPDIRECT3DDEVICE9 GetDevice()
	{
		return m_pDevice;
	}
	LPD3DXSPRITE GetSprite()
	{
		return m_pSprite;
	}
	LPD3DXFONT GetFont()
	{
		return m_pFont;
	}
	HRESULT InitDevice(HWND hWnd);
	void Release();
public:
	void RenderBegin(); // Start Render
	void RenderEnd();   // End Render

	/* If you may use 3D Technic, you should use below functions. */
	/*void SetTransform(_D3DTRANSFORMSTATETYPE Type,
		const D3DXMATRIX* pMatrix);
	void SetRenderState(_D3DRENDERSTATETYPE Type,
		DWORD dwFlag);*/
private:
	CDevice();
public:
	~CDevice();
};

