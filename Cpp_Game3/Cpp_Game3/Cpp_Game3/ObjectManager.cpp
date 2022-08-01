#include "ObjectManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Cursor.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() 
{
	pPlayer = nullptr;
	pCursor = nullptr;
	pItem = nullptr;
	Pause = false;
	Static = false;
	Shield = false;
	Buddy = false;
	Time = 0;
	Angle = 0;
	FnB = 0;
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
		{
			pBullet[i] = ObjectFactory::CreateBullet(_Position);

			switch (_StateIndex)
			{
			case 0:
			{
				switch (Angle)
				{
				case 0:
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(0.0, 1.0));
					pBullet[i]->SetDirection(Vector3(0.0f, 1.0f));
					((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					break;				
				case 1:
					if (!FnB)
					{
						pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(-2.0, 1.0));
						pBullet[i]->SetDirection(Vector3(-1.0f, 1.0f));
					}
					else if (FnB)
					{
						pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, 1.0));
						pBullet[i]->SetDirection(Vector3(1.0f, 1.0f));
					}
					((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					break;
				case 2:
					if (!FnB)
					{
						pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(-2.0, 0.0));
						pBullet[i]->SetDirection(Vector3(-1.0f, 0.0f));
					}
					else if (FnB)
					{
						pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, 0.0));
						pBullet[i]->SetDirection(Vector3(1.0f, 0.0f));
					}
					((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					break;
				case 3:
					if (!FnB)
					{
						pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(-2.0, -1.0));
						pBullet[i]->SetDirection(Vector3(-1.0f, -1.0f));
					}
					else if (FnB)
					{
						pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, -1.0));
						pBullet[i]->SetDirection(Vector3(1.0f, -1.0f));
					}
					((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					break;
				case 4:
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(0.0, -1.0));
					pBullet[i]->SetDirection(Vector3(0.0f, -1.0f));
					((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					break;
				}
				break;
			}
			case 1: // 정전기탄
			{
				for (int i = 0; i < 32; ++i)
				{
					if (pEnemy[i])
					{
						pBullet[i]->SetTarget(pEnemy[i]);
						((Bullet*)pBullet[i])->SetIndex(_StateIndex);
						break;
					}
				}
				break;
			}
			case 2: // 에너미
			{
				Vector3 Direction = MathManager::GetDirection(pBullet[i]->GetPosition(), pPlayer->GetPosition());
				pBullet[i]->SetDirection(Direction);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				break;
			}
			case 3:
			{
				pBullet[i]->SetTarget(pPlayer);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				break;
			}
			}
			break;
		}

	}	
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();
	pCursor = ObjectFactory::CreateCursor();
	Time = GetTickCount64();
}

void ObjectManager::Update()
{
	int fire = 0;
	fire = pPlayer->Update(Pause);
	pCursor->SetPosition(pPlayer->GetPosition());
	pCursor->Update(Pause);
	Angle = ((Cursor*)pCursor)->GetAngle();
	FnB = ((Cursor*)pCursor)->GetFnB();

	if (fire == 1)
	{
		if(!Static)
			CreateObject(0, pPlayer->GetPosition());
		else if (Static)
			CreateObject(1, pPlayer->GetPosition());
	}

	/*if (Time + 2500 < GetTickCount64())
	{
		Time = GetTickCount64();
		for (int i = 0; i < 32; ++i)
		{
			if (pEnemy[i] == nullptr)
			{
				pEnemy[i] = ObjectFactory::CreateEnemy();
				pEnemy[i]->SetTarget(pPlayer);
				break;
			}
			
		}
	}*/

	if (Time + 15000 < GetTickCount64())
	{
		Time = GetTickCount64();
		srand(GetTickCount64() % 4);
		if (pItem == nullptr)
			pItem = ObjectFactory::CreateItem();

	}
	for (int i = 0; i < 32; ++i)
	{
		if (pEnemy[i])
			pEnemy[i]->Update(Pause);
	}
	
	int result = 0;

	for (int i = 0; i < 256; ++i)
	{
		if (pBullet[i])
		{
			result = pBullet[i]->Update(Pause);

		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}


}

void ObjectManager::Render()
{
	pPlayer->Render();
	pCursor->Render();
	for (int i = 0; i < 256; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
	for (int i = 0; i < 32; ++i)
	{
		if (pEnemy[i])
			pEnemy[i]->Render();
	}
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
