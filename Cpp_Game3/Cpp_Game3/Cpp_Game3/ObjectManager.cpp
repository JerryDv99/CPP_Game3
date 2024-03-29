#include "ObjectManager.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"
#include "Kirby.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "InputManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;


ObjectManager::ObjectManager()
{
	pPlayer = nullptr;

	Pause = false;
	Static = false;
	Molotov = false;
	Shield = false;
	Buddy = false;
	Hit = false;
	Skill = false;
	AtvSkill = false;
	Bounce = false;
	Inhale = false;
	M = false;
	Active = 0;
	TKirby = 0;
	Time = 0;
	iTime = 0;
	BuffTime = 0;
	SuperArmor = 0;
	Score = 0;
	Kill = 0;
	HP = 0;
	Rend = 0;
	KWidth = 0.0f;
	KHeight = 0.0f;
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> Temp;

		Temp.push_back(_Object);

		ObjectList.insert(make_pair(_Object->GetKey(), Temp));
	}
	else
		iter->second.push_back(_Object);
	/*
	for (int i = 0; i < 256; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = ObjectFactory::CreateBullet(_Position);
			pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, 0.0));
			pBullet[i]->SetDirection(Vector3(1.0f, 0.0f));

			switch (_StateIndex)
			{
			case 0:
			{
				if (_dwKey & KEY_AUP)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(0.0, -1.0));
					pBullet[i]->SetDirection(Vector3(0.0f, -1.0f));
				}
				
				if (_dwKey & KEY_ADOWN)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(0.0, -1.0));
					pBullet[i]->SetDirection(Vector3(0.0f, 1.0f));
				}

				if (_dwKey & KEY_ALEFT)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(-2.0, 0.0));
					pBullet[i]->SetDirection(Vector3(-1.0f, 0.0f));
				}

				if (_dwKey & KEY_ARIGHT)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, 0.0));
					pBullet[i]->SetDirection(Vector3(1.0f, 0.0f));
				}
				
				if (_dwKey & KEY_AUP && _dwKey & KEY_ALEFT)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(-2.0, -1.0));
					pBullet[i]->SetDirection(Vector3(-1.0f, -1.0f));
				}
				
				if (_dwKey & KEY_AUP && _dwKey & KEY_ARIGHT)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, -1.0));
					pBullet[i]->SetDirection(Vector3(1.0f, -1.0f));
				}
				
				if (_dwKey & KEY_ADOWN && _dwKey & KEY_ALEFT)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(-2.0, 1.0));
					pBullet[i]->SetDirection(Vector3(-1.0f, -1.0f));
				}
				
				if (_dwKey & KEY_ADOWN && _dwKey & KEY_ARIGHT)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition() + Vector3(2.0, 1.0));
					pBullet[i]->SetDirection(Vector3(1.0f, -1.0f));
				}

				((Bullet*)pBullet[i])->SetIndex(_StateIndex);				
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
	*/
}
/*
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
*/

void ObjectManager::Start()
{
	KWidth = 0.0f;
	KHeight = 29.0f;
	Bounce = false;
	Inhale = false;
	iTime = GetTickCount64();
	Time = GetTickCount64();
	HP = 5;	
}

int ObjectManager::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	int fire = 0;

	Score = 0;
	Kill = 0;
	fire = pPlayer->Update(Pause);

	if (Time + 1000 < GetTickCount64())
		Skill = true;

	if (Pause)
	{
		Time = GetTickCount64();
		iTime = GetTickCount64();
	}
	if (fire == 1)
	{
		if(!Static)
			ObjectFactory<Bullet>::CreateObject(pPlayer->GetPosition());
		else if (Static && pEnemy[0] != nullptr)
			CreateObject(1, pPlayer->GetPosition(), dwKey);
	}

	/*
	if (Time + 1500 < GetTickCount64())
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
	*/

	if (iTime + 10000 < GetTickCount64())
	{
		iTime = GetTickCount64();
		srand(GetTickCount64());
		if (pItem == nullptr && !Pause)
		{
			pItem = new Item;
			pItem->SetOption(rand() % 4);
			pItem->Start();			
		}
	}

	int resulti = 0;
	if (pItem && !Pause)
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
			if (!Inhale)
			{
				pEnemy[i]->SetTarget(pPlayer);
				((Enemy*)pEnemy[i])->SetInhale(Inhale);
				pEnemy[i]->Update(Pause);
			}
			if (Inhale)
			{
				pEnemy[i]->SetTarget(pKirby);
				pEnemy[i]->Update(false);
				((Enemy*)pEnemy[i])->SetInhale(Inhale);
			}
			if (Molotov && !Inhale)
			{
				if ((pPlayer->GetTransform().Position.y + 1.5f >= pEnemy[i]->GetTransform().Position.y
					&& pPlayer->GetTransform().Position.y - 1.5f <= pEnemy[i]->GetTransform().Position.y) || 
					(pPlayer->GetTransform().Position.x + 2.5f >= pEnemy[i]->GetTransform().Position.x
					&& pPlayer->GetTransform().Position.x - 2.5f <= pEnemy[i]->GetTransform().Position.x))
				{
					Kill++;
					Score += 1000;
					delete pEnemy[i];
					pEnemy[i] = nullptr;
				}
			}
			if (Inhale && CollisionManager::RectCollision(
				pEnemy[i]->GetTransform(),
				pKirby->GetTransform()))
			{
				Kill++;
				Score += 2000;
				delete pEnemy[i];
				pEnemy[i] = nullptr;
			}
		}
	}
	
	int result = 0;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{			
			result = pBullet[i]->Update(Pause);

			if (pBullet[i]->GetTarget() == nullptr)
			{				
				for (int j = 0; j < 32; ++j)
				{
					if (pEnemy[j])
					{
						pBullet[i]->SetTarget(pEnemy[j]);
						break;
					}
				}
			}
			for (int j = 0; j < 32; ++j)
			{
				if (pEnemy[j] && !Inhale)
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
			if (!Inhale)
			{
				((Bullet*)eBullet[i])->SetInhale(Inhale);
				eresult = eBullet[i]->Update(Pause);
			}
			if (Inhale)
			{
				eBullet[i]->SetTarget(pKirby);
				((Bullet*)eBullet[i])->SetInhale(Inhale);
				eresult = eBullet[i]->Update(false);				
			}
			if (Inhale && CollisionManager::RectCollision(
				pKirby->GetTransform(),
				eBullet[i]->GetTransform()))
			{
				Score += 100;
				eresult = 1;
			}
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
					HP--;
					SA = true;
					SuperArmor = GetTickCount64();
					return 1;
				}
				eresult = 1;
			}
			if (Molotov && !Inhale)
			{
				if ((pPlayer->GetTransform().Position.y + 1.5f >= eBullet[i]->GetTransform().Position.y
					&& pPlayer->GetTransform().Position.y - 1.5f <= eBullet[i]->GetTransform().Position.y) ||
					(pPlayer->GetTransform().Position.x + 2.5f >= eBullet[i]->GetTransform().Position.y
						&& pPlayer->GetTransform().Position.x - 2.5f <= eBullet[i]->GetTransform().Position.y))
				{
					Score += 50;
					eresult = 1;
				}
			}
			
		}
		
		if (eresult == 1)
		{
			delete eBullet[i];
			eBullet[i] = nullptr;
		}
	}

	if (Skill)
	{
		if (dwKey & KEY_R && Time + 100 < GetTickCount64())
		{
			Active = GetTickCount64();
			TKirby = GetTickCount64();
			AtvSkill = true;
		}
	}

	if (AtvSkill)
	{
		if (Active + 1200 > GetTickCount64())
		{
			if (TKirby + 50 < GetTickCount64())
			{
				if (KWidth < 30)
					KWidth += 2;
				if (KHeight > 14 && !Bounce)
					KHeight -= 2;
				if (KHeight <= 14)
					Bounce = true;
				if (Bounce && KHeight < 29)
					KHeight += 2;

				TKirby = GetTickCount64();
			}
		}
		if (Active + 2500 <= GetTickCount64())
		{
			Inhale = true;
		}
		if (Active + 2500 <= GetTickCount64() && Active + 10000 > GetTickCount64())
		{
			if (TKirby + 750 < GetTickCount64())
			{
				TKirby = GetTickCount64();
				if (Rend == 0)
					Rend = 1;
				else if (Rend == 1)
					Rend = 0;
			}
		}
		if (Active + 10000 <= GetTickCount64())
		{
			for (int i = 0; i < 128; ++i)
			{
				if (eBullet[i])
				{
					delete eBullet[i];
					eBullet[i] = nullptr;
				}
			}
			KWidth = 0.0f;
			KHeight = 29.0f;
			Skill = false;
			AtvSkill = false;
			Bounce = false;
			Inhale = false; 
		}
	}

	
	return 0;
}

void ObjectManager::Render()
{
	if (AtvSkill)
	{		
		if (Active + 2500 <= GetTickCount64() && Active + 10000 > GetTickCount64())
		{
			if (Rend == 0)
				((Kirby*)pKirby)->RendInhale1(KWidth + 36, KHeight - 12);
			if (Rend == 1)
				((Kirby*)pKirby)->RendInhale2(KWidth + 36, KHeight - 12);
		}
	}
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
	if (BuffTime + 1000 >= GetTickCount64() && Molotov)
	{
		M = !M;
		if (M)
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 12);
			CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y - 1, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 12);
			CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y + 1, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 12);
			for (int i = 0; i < 50; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(pPlayer->GetPosition().x - 2, i, (char*)"■■■", 12);
			}
		}
		else if (!M)
		{
			CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 14);
			CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y - 1, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 14);
			CursorManager::GetInstance()->WriteBuffer(0.0f, pPlayer->GetPosition().y + 1, (char*)"■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", 14);
			for (int i = 0; i < 50; ++i)
			{
				CursorManager::GetInstance()->WriteBuffer(pPlayer->GetPosition().x - 2, i, (char*)"■■■", 14);
			}
		}
	}
	if (AtvSkill)
	{
		if (Active + 1200 > GetTickCount64())
			((Kirby*)pKirby)->RendKirby1(KWidth, KHeight);

		if (Active + 1200 <= GetTickCount64() && Active + 2500 > GetTickCount64())
			((Kirby*)pKirby)->RendKirby2(KWidth, KHeight - 2);
		if (Active + 2500 <= GetTickCount64() && Active + 10000 > GetTickCount64())
		{			
			((Kirby*)pKirby)->RendKirby3(KWidth, KHeight);
		}
	}
}

void ObjectManager::SoftRelease()
{
	delete pItem;
	pItem = nullptr;

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
	iTime = GetTickCount64();
	Time = GetTickCount64();
	HP = 5;
	pPlayer->SetPosition(Vector3(60.0f, 25.0f));
	KWidth = 0.0f;
	KHeight = 29.0f;
	Skill = false;
	AtvSkill = false;
	Bounce = false;
	Inhale = false;
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pItem;
	pItem = nullptr;

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