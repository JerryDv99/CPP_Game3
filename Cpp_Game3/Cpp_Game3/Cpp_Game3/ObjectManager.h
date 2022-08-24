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
	map<string, list<Object*>> ObjectList;

	Object* pPlayer;
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
	bool Skill;
	bool AtvSkill;
	bool Bounce;
	bool Inhale;
	bool M;
	ULONGLONG Active;
	ULONGLONG TKirby;
	int Score;
	int Kill;
	int HP;
	int Rend;
	float KWidth;
	float KHeight;
public:
	void AddObject(Object* _Object);
	void Start();
	int Update();
	void Render();
	void SoftRelease();
	void Release();
public:
	void SetPause(bool _Pause) { Pause = _Pause; }
	void SetSkill(bool _Skill) { Skill = _Skill; }
	int GetScore() { return Score; }
	int GetKill() { return Kill; }
	int GetHP() { return HP; }
	bool GetActive() { return AtvSkill; }
private:
	ObjectManager();
public:
	~ObjectManager();
};