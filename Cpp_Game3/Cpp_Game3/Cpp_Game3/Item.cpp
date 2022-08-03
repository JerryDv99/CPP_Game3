#include "Item.h"
#include "CursorManager.h"
#include "MathManager.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::Start()
{
	srand(GetTickCount64() * GetTickCount64());
	switch (rand() % 4)
	{
	case 0:
		Info.Position = Vector3(rand() % 10, 0.0f);
		break;
	case 1:
		Info.Position = Vector3(rand() % 10 + 100, 0.0f);
		break;
	case 2:
		Info.Position = Vector3(rand() % 10, 47.0f);
		break;
	case 3:
		Info.Position = Vector3(rand() % 10 + 100, 47.0f);
		break;
	}
	
	Info.Rotation = Vector3(0.0f, 0.0f);

	Vector3 Direction = Vector3(0.0f, 0.0f);
	switch (Option)
	{
	case 0:
		Direction = MathManager::GetDirection(Info.Position, Vector3(rand() % 10 + 55, rand() % 5 + 23));
		Info.Direction = Direction;
		Info.Scale = Vector3(8.0f, 2.0f);
		break;
	case 1:
		Direction = MathManager::GetDirection(Info.Position, Vector3(rand() % 10 + 55, rand() % 5 + 23));
		Info.Direction = Direction;
		Info.Scale = Vector3(9.0f, 2.0f);
		break;
	case 2:
		Direction = MathManager::GetDirection(Info.Position, Vector3(rand() % 10 + 55, rand() % 5 + 23));
		Info.Direction = Direction;
		Info.Scale = Vector3(8.0f, 2.0f);
		break;
	case 3:
		Direction = MathManager::GetDirection(Info.Position, Vector3(rand() % 10 + 55, rand() % 5 + 23));
		Info.Direction = Direction;
		Info.Scale = Vector3(9.0f, 2.0f);
		break;
	}
	Speed = 0.8;
	
}

int Item::Update(bool _Pause)
{
	Info.Position += Info.Direction * Speed;

	if (Info.Position.x <= 0 || Info.Position.x >= 111 || Info.Position.y <= 0 || Info.Position.y >= 47)
		return 1;
	return 0;
}

void Item::Render()
{
	switch (Option)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡ÐSTATIC", 14);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 1.0f), (char*)"£¯BULLET", 14);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡ÓMOLOTOV", 12);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 1.0f), (char*)"¡ú!!!!!!!", 12);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡ø¢Ç¢Ç¡ù", 9);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 1.0f), (char*)"KF94MASK", 9);
		break;
	case 3:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)" ¡ÌBUDDY", 11);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 1.0f), (char*)"dl BUDDY", 11);
		break;
	}
}

void Item::Release()
{
}