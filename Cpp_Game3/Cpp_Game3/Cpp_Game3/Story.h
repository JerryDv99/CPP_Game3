#pragma once
#include "Scene.h"

class Story : public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	char* Prologue[128];
	float Count;
	float Line1;
	float Line2;
	float Line3;
	ULONGLONG Time1;
public:
	Story();
	virtual ~Story();
};

