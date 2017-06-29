#pragma once
class CDevice
{
	DECLARE_SINGLETON(CDevice) // CDevice is a Singleton instance.
private:
	LPDIRECT3D9 m_p3D;
	LPDIRECT3DDEVICE9 m_pDevice;
	LPD3DXSPRITE m_pSprite;// print 2D Image Pointer Type
public:
	LPDIRECT3DDEVICE9 GetDevice()
	{
		return m_pDevice;
	}
	HRESULT InitDevice(bool isFull/*0:FullScreen 1:Window Mode*/, HWND hWnd,
		const int& iWinCX, const int& iWinCY);
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

