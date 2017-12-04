#pragma once
/*
== To use this Pattern -> CFactory<[CLASSNAME]>::[CreateSomethingFunc];
*/

class CObj;
template <typename T>
class CFactory
{
public: // default function
	static CObj* CreateInstance(void)
	{
		CObj* pObject = new T;
		pObject->Initialize();
		return pObject;
	}
	
	// Overload
	static HRESULT CreateTransform(TRANSFORM* _LogoBack)
	{
		if (_LogoBack == nullptr) return E_FAIL;
		else
		{
			// Do Something...

		}
		return S_OK
	}

	// Overload 
	static HRESULT CreateTransform()
	{
		return S_OK;
	}
public:
	// after add a function 'CreateMissile()'
	// static CObj* CreateMissile();
public:
	CFactory(void) {}
	~CFactory(void) {}
};