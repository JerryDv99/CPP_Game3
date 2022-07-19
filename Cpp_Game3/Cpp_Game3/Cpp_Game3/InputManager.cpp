#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;

InputManager::InputManager() : dwKey(0)
{
}

InputManager::~InputManager()
{
}

void InputManager::CheckKey()
{
	dwKey = 0;

	if (GetAsyncKeyState('W'))
		dwKey |= KEY_UP;

	if (GetAsyncKeyState('S'))
		dwKey |= KEY_DOWN;

	if (GetAsyncKeyState('A'))
		dwKey |= KEY_LEFT;

	if (GetAsyncKeyState('D'))
		dwKey |= KEY_RIGHT;

	if (GetAsyncKeyState('R'))
		dwKey |= KEY_R;



	if (GetAsyncKeyState(VK_UP))
		dwKey |= KEY_AUP;

	if (GetAsyncKeyState(VK_DOWN))
		dwKey |= KEY_ADOWN;

	if (GetAsyncKeyState(VK_LEFT))
		dwKey |= KEY_ALEFT;

	if (GetAsyncKeyState(KEY_RIGHT))
		dwKey |= KEY_ARIGHT;



	if (GetAsyncKeyState(VK_SPACE))
		dwKey |= KEY_SPACE;

	if (GetAsyncKeyState(KEY_RETURN))
		dwKey |= KEY_RETURN;

	if (GetAsyncKeyState(KEY_TAP))
		dwKey |= KEY_TAP;
}