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
	Object* pBullet[128];
	Object* eBullet[128];
	Object* pPlayer;
	Object* pEnemy[32];
	Object* pCursor;
	Object* pItem;
	ULONGLONG Time;
	ULONGLONG iTime;
	ULONGLONG BuffTime;
	ULONGLONG SuperArmor;
	bool Pause;
	bool Static;
	bool Molotov;
	bool Shield;
	bool Buddy;
	bool Hit;
	bool SA;
	int Angle;
	int FnB;
	int Score;
	int Kill;
public:
	void CreateObject(int _StateIndex, Vector3 _Position);
	void CreateEBullet(int _StateIndex, Vector3 _Position);
	void Start();
	int Update();
	void Render();
	void Release();
	void SetPause(bool _Pause) { Pause = _Pause; }
	int GetScore() { return Score; }
	int GetKill() { return Kill; }
private:
	ObjectManager();
public:
	~ObjectManager();
};