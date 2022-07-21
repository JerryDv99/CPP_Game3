#pragma once
#include "Scene.h"

class Logo : public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	ULONGLONG LTime;
	int Length;
	int MaxSize;
	char* Buffer[128];

	int ColorL1;
	int ColorL2;
	int ColorP1;
	int ColorP2;
	int Count;
public:
	Logo();
	virtual ~Logo();
};

