#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	char* BackGround[128];
	int BColor1;
	int BColor2;
	int BColor3;
	int Cursor;
	bool Check;
	bool Guide;
public:
	Menu();
	virtual ~Menu();
};
