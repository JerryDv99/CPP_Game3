#include "BossStage.h"
#include "InputManager.h"

BossStage::BossStage()
{
}

BossStage::~BossStage()
{
}

void BossStage::Start()
{
}

void BossStage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
}

void BossStage::Render()
{
}

void BossStage::Release()
{
}