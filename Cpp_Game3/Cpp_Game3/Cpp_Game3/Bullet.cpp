#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale= Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;

	Target = nullptr;	
}

int Bullet::Update(bool _Pause)
{
	if (!_Pause)
	{
		switch (Index)
		{
		case 0:
			Info.Position += Info.Direction * Speed;
			break;
		case 1:
		{
			Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
			Info.Position += Info.Direction * (Speed * 0.5f);
			break;
		}
		}
	}	

	if (Info.Position.x <= 0 || Info.Position.x >= 120 ||
		Info.Position.y <= 0 || Info.Position.y >= 50)
		return 1;

	return 0;
}

void Bullet::Render()
{
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 11);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 14);
		break;
	}
}

void Bullet::Release()
{
}