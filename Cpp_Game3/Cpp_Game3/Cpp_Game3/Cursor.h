#pragma once
#include "Object.h"

class Cursor : public Object
{
public:
	virtual void Start()override;
	virtual int Update(bool _Pause)override;
	virtual void Render()override;
	virtual void Release()override;
private:
	int Angle;
	int FnB;
public:
	int GetAngle() { return Angle; }
	int GetFnB() { return FnB; }
public:
	Cursor();
	virtual ~Cursor();
};

