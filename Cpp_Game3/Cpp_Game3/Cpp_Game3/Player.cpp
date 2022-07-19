#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_AUP)
		

	if (dwKey & KEY_ADOWN)


	if (dwKey & KEY_ALEFT)


	if (dwKey & KEY_ARIGHT)


	if (dwKey & KEY_UP)
		Info.Position.y--;

	if (dwKey & KEY_DOWN)
		Info.Position.y++;

	if (dwKey & KEY_LEFT)
		Info.Position.x--;

	if (dwKey & KEY_RIGHT)
		Info.Position.x++;

	if (dwKey & KEY_R)
	
	if (dwKey & KEY_SPACE)
}

void Player::Render()
{
}

void Player::Release()
{
}