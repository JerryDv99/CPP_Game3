#pragma once
#include "Headers.h"

class UIManager
{
private:
	static UIManager* Instance;
public:
	static UIManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new UIManager;
		return Instance;
	}
private:
	char* Border[64];
	int Length;
public:
	void WriteUI(float _x, float _y, char* _str, int _Color);
	void Start();
	void Update();
	void Render();
	void Release();
private:
	UIManager();
public:
	~UIManager();
};

