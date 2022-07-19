#include "Stage.h"
#include "InputManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Start()
{
}

void Stage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
}

void Stage::Render()
{
}

void Stage::Release()
{
}