#include "ObjectManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{
	for (int i = 0; i < 256; ++i)
		pBullet[i] = nullptr;
	for (int i = 0; i < 32; ++i)
		pEnemy[i] = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::CreateObject(int _StateIndex, Vector3 _Position)
{
	for (int i = 0; i < 256; ++i)
	{
		if (pBullet[i] == nullptr)
			pBullet[i] = ObjectFactory::CreateBullet(_Position);

		switch (_StateIndex)
		{
		case 0:
		{
			Vector3 Direction = MathManager::GetDirection(pBullet[i]->GetPosition(), pPlayer->GetPosition());
			pBullet[i]->SetDirection(Direction);
			((Bullet*)pBullet[i])->SetIndex(_StateIndex);
			break;
		}
		case 1:
		{
			pBullet[i]->SetTarget(pPlayer);
			((Bullet*)pBullet[i])->SetIndex(_StateIndex);
			break;
		}
		}
		break;
	}	
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();
}

void ObjectManager::Update()
{
	pPlayer->Update();

	if (Time + 2500 < GetTickCount64())
	{
		Time = GetTickCount64();
		for (int i = 0; i < 32; ++i)
		{
			if (pEnemy[i] == nullptr)
			{
				pEnemy[i] = ObjectFactory::CreateEnemy();
				pEnemy[i]->SetTarget(pPlayer);
			}
			break;
		}
	}

	for (int i = 0; i < 32; ++i)
	{
		if (pEnemy[i])
			pEnemy[i]->Update();
	}
	
	int result = 0;


}

void ObjectManager::Render()
{
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
	
	for (int i = 0; i < 32; ++i)
	{
		delete pEnemy[i];
		pEnemy[i] = nullptr;
	}

	for (int i = 0; i < 256; ++i)
	{
		delete pBullet[i];
		pBullet[i] = nullptr;
	}
}
