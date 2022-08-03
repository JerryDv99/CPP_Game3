#pragma once
#include "Scene.h"

class Stage : public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
private:
	bool Tuto;
	bool ITuto;

	char* ComboUI[64];
	char* PlayerUI[64];
	int Life;
	int Score;
	int Kill;
	int Combo;
	int ComboGauge;
	int Hit;
public:
	Stage();
	virtual ~Stage();
};
