#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	Info.Position = Vector3(60.0f, 25.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;
	Speed = 1.0f;
}

int Player::Update(bool _Pause)
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (!Buddy && !_Pause)
	{
		if (dwKey & KEY_UP)
			if (Info.Position.y > 1)
				Info.Position.y--;

		if (dwKey & KEY_DOWN)
			if (Info.Position.y < 48)
				Info.Position.y++;

		if (dwKey & KEY_LEFT)
			if (Info.Position.x > 2)
				Info.Position.x -= 2;

		if (dwKey & KEY_RIGHT)
			if (Info.Position.x < 116)
				Info.Position.x += 2;

		if (dwKey & KEY_SPACE)
			return 1;
	}
	
	else if (Buddy && !_Pause)
	{
		if (dwKey & KEY_UP)
			if (Info.Position.y > 2)
				Info.Position.y -= 1.5;

		if (dwKey & KEY_DOWN)
			if (Info.Position.y < 48)
				Info.Position.y += 1.5;

		if (dwKey & KEY_LEFT)
			if (Info.Position.x >= 4.5)
				Info.Position.x -= 3;

		if (dwKey & KEY_RIGHT)
			if (Info.Position.x <= 114.5)
				Info.Position.x += 3;

		if (dwKey & KEY_SPACE)
			return 1;
	}

	return 0;
}

void Player::Render()
{
	if (!Shield)
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¿Ê", 14);
	else if (Shield)
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"Èª", 9);
}

void Player::Release()
{
}