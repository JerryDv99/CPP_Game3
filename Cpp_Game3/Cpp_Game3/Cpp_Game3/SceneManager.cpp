#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Boss.h"
#include "Ending.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(SCENEID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case SCENEID::LOGO:
		SceneState = new ;
		break;
	
	case SCENEID::MENU:
		SceneState = new ;
		break;
	
	case SCENEID::STAGE:
		SceneState = new ;
		break;
	
	case SCENEID::BOSS:
		SceneState = new ;
		break;

	case SCENEID::ENDING:
		SceneState = new ;
		break;

	case SCENEID::EXIT:
		SceneState = new ;
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	delete SceneState;
	SceneState = nullptr;
}