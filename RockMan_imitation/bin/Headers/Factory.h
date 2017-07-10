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
public:
	// after add a function 'CreateMissile()'
	// static CObj* CreateMissile();
public:
	CFactory(void) {}
	~CFactory(void) {}
};