#include "Ending.h"
#include "InputManager.h"

Ending::Ending()
{
}

Ending::~Ending()
{
}

void Ending::Start()
{
}

void Ending::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
}

void Ending::Render()
{
}

void Ending::Release()
{
}