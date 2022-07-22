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
	char* GuideScene[64];
public:
	void Start();
	void Update();
	void Render();
	void Release();
public:
	GuideManager();
	virtual ~GuideManager();
};

