#pragma once

class GuideManager
{
private:
	static GuideManager* Instance;
public:
	static GuideManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new GuideManager;
		}
		return Instance;
	}
private:
	char* Border[64];
	char* CtrlGuide[64];
	char* ItemTuto[32];
	int Count;
	bool Check;
public:
	void Start();
	void Update();
	void Render(int _Option);
	void Release();
public:
	GuideManager();
	virtual ~GuideManager();
};

