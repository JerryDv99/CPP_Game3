#include "Logo.h"
#include "InputManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
}

void Logo::Render()
{
}

void Logo::Release()
{
}