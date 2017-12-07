/*Interface*/
#pragma once
#include "Include.h"
class CObj
{
private:
	OBJ_NUM SortObjNum;
protected:
	OBJINFO m_Info;
public:
	OBJ_NUM GetSortID() {
		return this->SortObjNum;
	}
	void SetSortID(OBJ_NUM _param) {
		this->SortObjNum = _param;
	}
public:
	virtual HRESULT Initialize()PURE;
	virtual HRESULT Progress()PURE;
	virtual HRESULT Render()PURE;
	virtual HRESULT Release()PURE;
public:
	CObj();
	virtual ~CObj();
};

