#include "ObjectManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Cursor.h"
#include "Item.h"
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
	Molotov = false;
	Shield = false;
	Buddy = false;
	Hit = false;
	Time = 0;
	iTime = 0;
	BuffTime = 0;
	SuperArmor = 0;
	Angle = 0;
	FnB = 0;
	Score = 0;
	Kill = 0;
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;
	for (int i = 0; i < 128; ++i)
		eBullet[i] = nullptr;
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
				for (int j = 0; j < 32; ++j)
				{
					if (pEnemy[j])
					{						
						((Bullet*)pBullet[i])->SetT(GetTickCount64());
						pBullet[i]->SetTarget(pEnemy[j]);
						((Bullet*)pBullet[i])->SetIndex(_StateIndex);
						break;
					}
				}
			}
			}
			break;
		}

	}	
}

void ObjectManager::CreateEBullet(int _StateIndex, Vector3 _Position)
{
	Vector3 Direction;

	for (int i = 0; i < 256; ++i)
	{
		if (eBullet[i] == nullptr)
		{
			eBullet[i] = new Bullet;
			eBullet[i]->Start();
			switch (_StateIndex)
			{
			case 2: // 에너미
			{
				eBullet[i]->SetPosition(_Position);
				Direction = MathManager::GetDirection(_Position, pPlayer->GetPosition());
				eBullet[i]->SetDirection(Direction);
				((Bullet*)eBullet[i])->SetIndex(_StateIndex);
				break;
			}
			case 3:
			{
				//pBullet[i]->SetTarget(pPlayer);
				//((Bullet*)eBullet[i])->SetIndex(_StateIndex);
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

int ObjectManager::Update()
{
	int fire = 0;

	Score = 0;
	Kill = 0;
	fire = pPlayer->Update(Pause);
	pCursor->SetPosition(pPlayer->GetPosition());
	pCursor->Update(Pause);
	Angle = ((Cursor*)pCursor)->GetAngle();
	FnB = ((Cursor*)pCursor)->GetFnB();

	if (fire == 1)
	{
		if(!Static)
			CreateObject(0, pPlayer->GetPosition());
		else if (Static && pEnemy[0] != nullptr)
			CreateObject(1, pPlayer->GetPosition());
	}

	if (Time + 2500 < GetTickCount64())
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
	}

	if (iTime + 5000 < GetTickCount64())
	{
		iTime = GetTickCount64();
		srand(GetTickCount64());
		if (pItem == nullptr)
		{
			pItem = new Item;
			pItem->SetOption(rand() % 4);
			pItem->Start();			
		}
	}

	int resulti = 0;
	if (pItem)
	{
		resulti = pItem->Update(Pause);
		if (CollisionManager::RectCollision(
			pPlayer->GetTransform(),
			pItem->GetTransform()))
		{
			Score += 1000;
			switch (pItem->GetOption())
			{
			case 0:
				Static = true;
				BuffTime = GetTickCount64();
				resulti = 1;
				break;
			case 1:
				Molotov = true;
				BuffTime = GetTickCount64();
				resulti = 1;
				break;
			case 2:
				Shield = true;
				resulti = 1;
				break;
			case 3:
				Buddy = true;
				BuffTime = GetTickCount64();
				resulti = 1;
				break;
			}
		}
		if (resulti == 1)
		{
			delete pItem;
			pItem = nullptr;
		}
	}

	if (Static && BuffTime + 10000 <= GetTickCount64())
	{
		Static = false;
	}

	if (Molotov && BuffTime + 1000 <= GetTickCount64())
	{
		Molotov = false;
	}

	((Player*)pPlayer)->SetShield(Shield);
	((Player*)pPlayer)->SetBuddy(Buddy);

	if (Static && BuffTime + 15000 <= GetTickCount64())
	{
		Buddy = false;
	}

	if (SuperArmor + 1000 < GetTickCount64())
		SA = false;

	for (int i = 0; i < 32; ++i)
	{
		if (pEnemy[i])
		{
			pEnemy[i]->Update(Pause);
			if (Molotov)
			{
				if ((pPlayer->GetTransform().Position.y + 1.5f >= pEnemy[i]->GetTransform().Position.y
					&& pPlayer->GetTransform().Position.y - 1.5f <= pEnemy[i]->GetTransform().Position.y) || 
					(pPlayer->GetTransform().Position.x + 2.5f >= pEnemy[i]->GetTransform().Position.y
					&& pPlayer->GetTransform().Position.x - 2.5f <= pEnemy[i]->GetTransform().Position.y))
				{
					Kill++;
					Score += 1000;
					delete pEnemy[i];
					pEnemy[i] = nullptr;
				}
			}			
		}
	}
	
	int result = 0;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{			
			result = pBullet[i]->Update(Pause);

			for (int j = 0; j < 32; ++j)
			{
				if (pEnemy[j])
				{
					if (CollisionManager::RectCollision(
						pEnemy[j]->GetTransform(),
						pBullet[i]->GetTransform()))
					{
						Kill++;
						Score += 500;
						result = 1;
						delete pEnemy[j];
						pEnemy[j] = nullptr;
					}
				}
			}
		}		
		
		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}

	int eresult = 0;

	for (int i = 0; i < 128; ++i)
	{
		if (eBullet[i])
		{
			eresult = eBullet[i]->Update(Pause);
			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				eBullet[i]->GetTransform()) && !SA)
			{
				if (Shield)
				{
					Shield = false;
					SA = true;
					SuperArmor = GetTickCount64();
				}
				else if (!Shield)
				{
					((Player*)pPlayer)->HPDown();
					SA = true;
					SuperArmor = GetTickCount64();
					return 1;
				}
				eresult = 1;
			}
			if (Molotov)
			{
				if ((pPlayer->GetTransform().Position.y + 1.5f >= eBullet[i]->GetTransform().Position.y
					&& pPlayer->GetTransform().Position.y - 1.5f <= eBullet[i]->GetTransform().Position.y) ||
					(pPlayer->GetTransform().Position.x + 2.5f >= eBullet[i]->GetTransform().Position.y
						&& pPlayer->GetTransform().Position.x - 2.5f <= eBullet[i]->GetTransform().Position.y))
					eresult = 1;
			}
		}
		
		if (eresult == 1)
		{
			delete eBullet[i];
			eBullet[i] = nullptr;
		}
	}
	return 0;
}

void ObjectManager::Render()
{
	if(pItem)
		pItem->Render();
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
	
	for (int i = 0; i < 128; ++i)
	{
		if (eBullet[i])
			eBullet[i]->Render();
	}
	for (int i = 0; i < 32; ++i)
	{
		if (pEnemy[i])
			pEnemy[i]->Render();
	}
	if(!SA)
		pPlayer->Render();
	else if (SA)
	{
		if(SuperArmor + 100 < GetTickCount64() && SuperArmor + 400 > GetTickCount64())
			pPlayer->Render();
		if(SuperArmor + 500 < GetTickCount64() && SuperArmor + 800 > GetTickCount64())
			pPlayer->Render();
	}

	pCursor->Render();
	if (BuffTime + 1000 >= GetTickCount64() && Molotov)
	{
		CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 12);
		CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y - 1, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 12);
		CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y + 1, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 12);
		for (int i = 0; i < 50; ++i)
		{
			CursorManager::GetInstance()->WriteBuffer(pPlayer->GetPosition().x - 2, i, (char*)"■■■", 12);
		}		
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

	for (int i = 0; i < 128; ++i)
	{
		delete pBullet[i];
		pBullet[i] = nullptr;
	}

	for (int i = 0; i < 128; ++i)
	{
		delete eBullet[i];
		eBullet[i] = nullptr;
	}
}
