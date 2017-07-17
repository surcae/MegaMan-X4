#pragma once
/*

// Sprite Texture Mode Manager //
// Encoding with UTF-Korean
 싱글텍스쳐는 Object와 1대1 텍스쳐 랜더링 관계로서
오브젝트가 하나 있다면 이 오브젝트에 대한 텍스쳐는 딱 하나만 로드된다.
따라서, 로딩시 통채로 불러와서 Sprite를 좌표시작점으로 0~32까지 랜더링,
32~64 랜더링... 이런식으로 불러와서 빠르다. 
정리하자면 한 이미지 파일에 대해서 크기별 조작을 하여 스프라이트하는 방식이다.

 멀티텍스쳐는 Object와 1대n 텍스쳐 랜더링 관계로서
오브젝트가 하나 있다면 이 오브젝트에 대한 파트로 나뉘거나 다른 부가요소를 추가하여 
각자 개별 파일로 나누는 방식이다. 예를 들어서, 팔을 스프라이트한다고 치면 팔01, 팔02 ...
이런 식으로 각 프레임 별로 파일을 나눠서 띄운다.
잘만 개조하면 멀티 텍스쳐에서 싱글 텍스쳐 기능을 사용해서 띄울 수도 있는데 이것은 사용하기가 힘들다.
그래서 각 파일별로 나눠서 그 자체로 그대로 랜더링 시키는게 바람직하다고 하겠다.
*/
class CTexture;
class CTextureMgr
{
	DECLARE_SINGLETON(CTextureMgr)
private:
	// Memory Buckets for Textures. Your texture will be saved in m_MapTexture.
	map<const TCHAR*, CTexture*> m_MapTexture;

	// Stock file names in Stack
	std::stack<const TCHAR*> m_stFileName;
public:
	const TEXINFO* GetTexture(const TCHAR* pObjKey,
		const TCHAR* pStateKey = NULL, const int& iCnt = 0);
	HRESULT InsertTexture(const TCHAR* pFileName, const TEX_TYPE type, const TCHAR* pObjKey, const TCHAR* pStateKey = NULL, const int& cnt = 0);
	size_t Show_FileCounts() {
		return m_stFileName.size(); // Show how many textures are inserted in m_MapTexture.
	}
	virtual void Release() final { // 자체 보관중이 텍스쳐 가방을 삭제시킨다.
		for (map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.begin();
			iter != m_MapTexture.end(); /*Continue*/) {
			delete iter->second;
			iter->second = NULL;
			++iter;
		}
		m_MapTexture.clear();
	}
	void Release(CTexture *pTexture, TEX_TYPE& type);
private:
	CTextureMgr();
public:
	~CTextureMgr();
};

