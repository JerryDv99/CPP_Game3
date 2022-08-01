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
	Object* pCursor;
	Object* pItem;
	ULONGLONG Time;
	bool Pause;
	bool Static;
	bool Shield;
	bool Buddy;
	int Angle;
	int FnB;
public:
	void CreateObject(int _StateIndex, Vector3 _Position);
	void Start();
	void Update();
	void Render();
	void Release();
	void SetPause(bool _Pause) { Pause = _Pause; }
private:
	ObjectManager();
public:
	~ObjectManager();
};