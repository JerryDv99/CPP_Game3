#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	Object* pBullet[256];
	Object* pPlayer;
	Object* pEnemy[32];
public:
	void CreateObject(int _StateIndex);
	void Start();
	void Update();
	void Render();
	void Release();
private:
	ObjectManager();
public:
	~ObjectManager();
};