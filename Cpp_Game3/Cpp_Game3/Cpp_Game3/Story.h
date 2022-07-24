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
public:
	Story();
	virtual ~Story();
};

