#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	int Length;
	int MaxSize;
	char* Buffer[64];

	int ColorL1;
	int ColorL2;
	int ColorP1;
	int ColorP2;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};

