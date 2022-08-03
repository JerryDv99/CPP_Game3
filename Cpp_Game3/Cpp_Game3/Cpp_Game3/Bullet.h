#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
	ULONGLONG T;
public:
	virtual void Start()override;
	virtual int  Update(bool _Pause)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(int _Index) { Index = _Index; }
	int GetIndex() { return Index; }
	void SetT(ULONGLONG _T) { T = _T; }
public:
	Bullet();
	virtual ~Bullet();
};

