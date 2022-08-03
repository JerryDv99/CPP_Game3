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
	bool Shield;
public:
	void SetShield(bool _Shield) { Shield = _Shield; }
	void SetBuddy(bool _Buddy) { Buddy = _Buddy; }
	void HPDown() { HP -= 1; }
	int GetHP() { return HP; }
public:
	Player();
	virtual ~Player();
};

