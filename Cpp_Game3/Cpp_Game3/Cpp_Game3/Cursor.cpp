#include "Cursor.h"
#include "CursorManager.h"
#include "InputManager.h"

Cursor::Cursor() : Angle(0), FnB(0)
{
}

Cursor::~Cursor()
{
}

void Cursor::Start() 
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);

	Angle = 2;
	FnB = 1;
	Target = nullptr;
	Time = GetTickCount64();
}

int Cursor::Update(bool _Pause)
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_AUP)
	{
		if (Angle < 4 && Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			Angle++;
		}
	}
		
	if (dwKey & KEY_ADOWN)	
	{
		if (Angle > 0 && Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			Angle--;
		}
	}

	if (dwKey & KEY_ALEFT)
		FnB = 0;
	if (dwKey & KEY_ARIGHT)
		FnB = 1;

	return 0;
}

void Cursor::Render()
{
	if (Angle != 0 && Angle != 4)
	{
		if (!FnB)
		{
			switch (Angle)
			{
			case 1:
				CursorManager::GetInstance()->WriteBuffer(Info.Position.x - 2, Info.Position.y + 1, (char*)"*", 10);
				break;
			case 2:
				CursorManager::GetInstance()->WriteBuffer(Info.Position - Vector3(2.0f, 0.0f), (char*)"*", 10);
				break;
			case 3:
				CursorManager::GetInstance()->WriteBuffer(Info.Position - Vector3(2.0f, 1.0f), (char*)"*", 10);
				break;
			}
		}
		if (FnB)
		{
			switch (Angle)
			{
			case 1:
				CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(2.0f, 1.0f), (char*)"*", 10);
				break;
			case 2:
				CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(2.0f, 0.0f), (char*)"*", 10);
				break;
			case 3:
				CursorManager::GetInstance()->WriteBuffer(Info.Position.x + 2, Info.Position.y - 1, (char*)"*", 10);
				break;
			}
		}
	}
	else if (Angle == 0)
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 1.0f), (char*)"*", 10);
	else if (Angle == 4)
		CursorManager::GetInstance()->WriteBuffer(Info.Position - Vector3(0.0f, 1.0f), (char*)"*", 10);
	
}

void Cursor::Release()
{
}