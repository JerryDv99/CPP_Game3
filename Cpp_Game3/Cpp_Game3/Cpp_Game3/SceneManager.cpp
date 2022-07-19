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
		SceneState = new Logo;
		break;
	
	case SCENEID::MENU:
		SceneState = new Menu;
		break;
	
	case SCENEID::STAGE:
		SceneState = new Stage;
		break;
	
	case SCENEID::BOSS:
		SceneState = new Boss;
		break;

	case SCENEID::ENDING:
		SceneState = new Ending;
		break;

	case SCENEID::EXIT:
		exit(NULL);
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