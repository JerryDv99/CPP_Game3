#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	int HP;
public:
	Player();
	virtual ~Player();
};

