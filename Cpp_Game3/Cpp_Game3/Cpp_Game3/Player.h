#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Start()override;
	virtual int Update(bool _Pause)override;
	virtual void Render()override;
	virtual void Release()override;
private:
	int HP;
	bool Buddy;
public:
	void SetBuddy(bool _Buddy) { Buddy = _Buddy; }
public:
	Player();
	virtual ~Player();
};

