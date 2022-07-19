#include "ObjectManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "ObjectFactory.h"

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

void ObjectManager::CreateObject(int _StateIndex)
{
	for (int i = 0; i < 256; ++i)
	{
		if (pBullet[i] == nullptr)
			pBullet[i] = ObjectFactory::CreateBullet();
	}

	switch (_StateIndex)
	{
	case 0:
	{
		break;
	}
	case 1:
	{
		break;
	}
	}
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();
}

void ObjectManager::Update()
{
	pPlayer->Update();
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
