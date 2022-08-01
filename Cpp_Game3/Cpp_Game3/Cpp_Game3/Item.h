#pragma once
#include "Object.h"

class Item : public Object
{
public:
	virtual void Start()override;
	virtual int Update(bool _Pause)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Item();
	virtual ~Item();
};

