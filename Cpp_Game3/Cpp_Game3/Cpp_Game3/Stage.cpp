#include "Stage.h"
#include "InputManager.h"
#include "GuideManager.h"
#include "ObjectManager.h"
#include "UIManager.h"

Stage::Stage() : Tuto(false), ITuto(false)
{
	Life = 0;
	Score = 0;
	Combo = 0.0f;
	ComboGauge = 0;
}

Stage::~Stage()
{
}

void Stage::Start()
{
	ITuto = true;
	ObjectManager::GetInstance()->Start();

	ComboUI[0]  = (char*)" ___";
	ComboUI[1]  = (char*)"|   |";
	ComboUI[2]  = (char*)"| | |";
	ComboUI[3]  = (char*)"|___|";
	ComboUI[4]  = (char*)" __";
	ComboUI[5]  = (char*)"|  |";
	ComboUI[6]  = (char*)" | |";
	ComboUI[7]  = (char*)"|___|";
	ComboUI[8]  = (char*)" ___";
	ComboUI[9]  = (char*)"|_  |";
	ComboUI[10] = (char*)"|  _|";
	ComboUI[11] = (char*)"|___|";
	ComboUI[12] = (char*)" ___";
	ComboUI[13] = (char*)"|_  |";
	ComboUI[14] = (char*)"|_  |";
	ComboUI[15] = (char*)"|___|";
	ComboUI[16] = (char*)" ___";
	ComboUI[17] = (char*)"| | |";
	ComboUI[18] = (char*)"|_  |";
	ComboUI[19] = (char*)"  |_|";
	ComboUI[20] = (char*)" ___";
	ComboUI[21] = (char*)"|  _|";
	ComboUI[22] = (char*)"|_  |";
	ComboUI[23] = (char*)"|___|";
	ComboUI[24] = (char*)" ___";
	ComboUI[25] = (char*)"|  _|";
	ComboUI[26] = (char*)"| . |";
	ComboUI[27] = (char*)"|___|";
	ComboUI[28] = (char*)" ___";
	ComboUI[29] = (char*)"|_  |";
	ComboUI[30] = (char*)"  | |";
	ComboUI[31] = (char*)"  |_|";
	ComboUI[32] = (char*)" ___";
	ComboUI[33] = (char*)"| . |";
	ComboUI[34] = (char*)"| . |";
	ComboUI[35] = (char*)"|___|";
	ComboUI[36] = (char*)" ___";
	ComboUI[37] = (char*)"| . |";
	ComboUI[38] = (char*)"|_  |";
	ComboUI[39] = (char*)"|___|";
	ComboUI[40] = (char*)"   _";
	ComboUI[41] = (char*)" _| |_";
	ComboUI[42] = (char*)"|_   _|";
	ComboUI[43] = (char*)"  |_|";

	PlayerUI[0]  = (char*)"콤보 :";
	PlayerUI[1]  = (char*)"스코어 :";
	PlayerUI[2]  = (char*)"콤보 게이지 :";
	PlayerUI[3]  = (char*)"■";
	PlayerUI[4]  = (char*)"스킬 :";
	PlayerUI[5]  = (char*)"ON";
	PlayerUI[6]  = (char*)"OFF";
	PlayerUI[7]  = (char*)"라이프 :";
	PlayerUI[8]  = (char*)"♥";
	PlayerUI[9]  = (char*)"메뉴 : [ TAB ]";
	PlayerUI[10] = (char*)"알고 계셨나요?";
	PlayerUI[11] = (char*)"플레이어는 피격시 1초 동안 무적상태가 됩니다";
	PlayerUI[12] = (char*)"";
}

void Stage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	ObjectManager::GetInstance()->Update();
	if (ITuto)
	{
		ObjectManager::GetInstance()->SetPause(true);
		if (dwKey & KEY_R)
		{
			ITuto = false;
			ObjectManager::GetInstance()->SetPause(false);
		}
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	if (ITuto)
		GuideManager::GetInstance()->Render(2);
	UIManager::GetInstance()->Render();
}

void Stage::Release()
{
}