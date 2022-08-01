#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "MathManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation= Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);

	Target = nullptr;
	Count = 0;
	Speed = 1.0f;

	Time = GetTickCount64();
	Rand = rand() % 4;
	Option = rand() % 8;

	switch (Option)
	{
	case 0:
		Info.Position = Vector3(rand() % 20 + 1, 1.0f);
		break;

	case 1:
		Info.Position = Vector3(rand() % 20 + 50, 1.0f);
		break;

	case 2:
		Info.Position = Vector3(rand() % 20 + 99, 1.0f);
		break;
	case 3:
		Info.Position = Vector3(rand() % 20 + 1, 25.0f);
		break;

	case 4:
		Info.Position = Vector3(rand() % 20 + 99, 25.0f);
		break;

	case 5:
		Info.Position = Vector3(rand() % 20 + 1, 49.0f);
		break;

	case 6:
		Info.Position = Vector3(rand() % 20 + 50, 49.0f);
		break;

	case 7:
		Info.Position = Vector3(rand() % 20 + 99, 50.0f);
		break;
	}
}

int Enemy::Update(bool _Pause)
{
	Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
	Info.Position += Info.Direction * (Speed * 0.05f);
	if (Time + 400 < GetTickCount64())
	{
		Count++;

		if (Count >= 5)
		{
			Count = 0;
			ObjectManager::GetInstance()->CreateObject(1, Info.Position);
		}
		else
			ObjectManager::GetInstance()->CreateObject(0, Info.Position);

		Time = GetTickCount64();
	}

	return 0;
}

void Enemy::Render()
{
	switch (Rand)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"”î", 12);
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"šu", 12);
	case 2:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"Œà", 12);
	case 3:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"‚Q", 12);
	}
}

void Enemy::Release()
{
}