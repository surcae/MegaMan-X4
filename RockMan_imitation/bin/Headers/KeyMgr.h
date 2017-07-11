#pragma once
class CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr)
private:
	LPDIRECTINPUT8		m_pDI; // Input Object
	LPDIRECTINPUTDEVICE	m_pKeyboard; // Keyboard device
	BYTE				m_Keys[256];
public:
	HRESULT CreateKeyBoardDevice(HWND _hWnd);
	void FreeDirectInput();
	void OnActivate(WPARAM wParam);
	HRESULT ReadData();
	BOOL KeyDown(BYTE Key);
private:
	CKeyMgr();
public:
	~CKeyMgr();
};

