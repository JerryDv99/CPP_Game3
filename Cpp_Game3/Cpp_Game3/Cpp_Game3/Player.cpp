#include "Player.h"
#include "InputManager.h"
#include "CursorManager.h"

Player::Player() : HP(0)
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
	HP = 5;
}

int Player::Update(bool _Pause)
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		if(Info.Position.y > 0)
			Info.Position.y--;

	if (dwKey & KEY_DOWN)
		if (Info.Position.y < 49)
			Info.Position.y++;

	if (dwKey & KEY_LEFT)
		if (Info.Position.x > 0)
			Info.Position.x -= 2;

	if (dwKey & KEY_RIGHT)
		if (Info.Position.x < 118)
			Info.Position.x += 2;

	if (dwKey & KEY_SPACE)
		return 1;

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¿Ê", 14);
}

void Player::Release()
{
}