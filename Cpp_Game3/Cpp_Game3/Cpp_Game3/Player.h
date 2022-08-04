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
	bool Buddy;
	bool Shield;
public:
	void SetShield(bool _Shield) { Shield = _Shield; }
	void SetBuddy(bool _Buddy) { Buddy = _Buddy; }
public:
	Player();
	virtual ~Player();
};

