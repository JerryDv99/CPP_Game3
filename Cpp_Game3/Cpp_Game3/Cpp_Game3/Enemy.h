#pragma once
#include "Object.h"

class Enemy : public Object
{
private:
	ULONGLONG eTime;
	int Count;
	int Rand;
public:
	virtual void Start()override;
	virtual int  Update(bool _Pause)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Enemy();
	virtual ~Enemy();
};

