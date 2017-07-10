#pragma warning (disable: 4150)

#ifndef _MACRO_H_
#define _MACRO_H_

#define DECLARE_SINGLETON(type) public:			\
static type** GetInstance()						\
{												\
	static type* pInstance = new type();        \
	if (pInstance == NULL)						\
	{											\
		pInstance = new type();				    \
	}											\
	return &pInstance;							\
}												\
static void	DestroyInstance() {					\
 	type** ppInstance = GetInstance();		    \
	if(ppInstance != NULL) {					\
		delete *ppInstance;                     \
		*ppInstance = NULL;                     \
	}                                           \
}				                                \

#define GET_SINGLE(type) (*type::GetInstance())
#define DESTROY_SINGLE(type) (*type::GetInstance())->DestroyInstance())
#define SAFE_DELETE(type) {if(type) delete type; type = nullptr;}
#define TEXTURE_ERROR_MSG(type) MessageBox(g_hWnd, L"type Insert Failed!", L"InsertTexture Error", MB_OK)
#endif
