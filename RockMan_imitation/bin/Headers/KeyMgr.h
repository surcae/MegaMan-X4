#pragma once
class CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr)
private:
	LPDIRECTINPUT8			m_pDI;			// Input Object
	LPDIRECTINPUTDEVICE8	m_pKeyboard;	// Keyboard device
	BYTE					m_Keys[256];
public:
	HRESULT CreateKeyBoardDevice(HWND _hWnd);
	void FreeDirectInput();
	void OnActivate(WPARAM wParam);
	HRESULT ReadData();
public:
	BOOL KeyDown(BYTE Key); // Handler
private:
	// Command* pCom1 = execute(CObj);
	// Command* pCom2 = execute(CObj);
	// Command* pCom3 = execute(CObj);
private:
	CKeyMgr();
public:
	~CKeyMgr();
};

