#include "Stage.h"
#include "InputManager.h"
#include "GuideManager.h"
#include "ObjectManager.h"
#include "UIManager.h"
#include "CursorManager.h"

Stage::Stage() : Tuto(false), ITuto(false)
{
	Life = 0;
	Hit = 0;
	Kill = 0;
	Score = 0;
	Combo = 0;
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

	PlayerUI[0]  = (char*)"스코어 :";
	PlayerUI[1]  = (char*)"콤보 :";
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
	PlayerUI[12] = (char*)"스테이지 진행도 :";
	PlayerUI[13] = (char*)"★";

	Life = 5;
	Hit = 0;
	Kill = 0;
	Score = 0;
	Combo = 0.0f;
	ComboGauge = 0;
}

void Stage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	Hit = ObjectManager::GetInstance()->Update();
	Combo += ObjectManager::GetInstance()->GetKill();
	Kill += ObjectManager::GetInstance()->GetKill();
	Life = ObjectManager::GetInstance()->GetHP();

	if (Hit == 1)
		Combo = 0;
	if(Combo < 20)
		Score += ObjectManager::GetInstance()->GetScore();
	else if (Combo < 40)
		Score += ObjectManager::GetInstance()->GetScore() * 1.2;
	else if (Combo < 70)
		Score += ObjectManager::GetInstance()->GetScore() * 1.4;
	else if (Combo < 100)
		Score += ObjectManager::GetInstance()->GetScore() * 1.8;

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
	CursorManager::GetInstance()->WriteBuffer(126.0f, 8.0f, PlayerUI[0], 10);
	if(Score < 1000)
		CursorManager::GetInstance()->WriteBuffer(152.0f, 8.0f, Score, 10);
	else if (Score < 10000)
		CursorManager::GetInstance()->WriteBuffer(151.0f, 8.0f, Score, 10);
	else if (Score < 100000)
		CursorManager::GetInstance()->WriteBuffer(150.0f, 8.0f, Score, 10);
	else if (Score < 1000000)
		CursorManager::GetInstance()->WriteBuffer(149.0f, 8.0f, Score, 10);

	if (ObjectManager::GetInstance()->GetScore() != 0)
	{
		CursorManager::GetInstance()->WriteBuffer(126.0f, 10.0f, (char*)"+", 10);
		CursorManager::GetInstance()->WriteBuffer(151.0f, 10.0f, ObjectManager::GetInstance()->GetScore(), 10); 
	}

	CursorManager::GetInstance()->WriteBuffer(126.0f, 16.0f, PlayerUI[1], 14);
	if (Combo < 100)
	{
		switch (Combo % 10)
		{
		case 0:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[0], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[1], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[2], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[3], 14);
			break;
		case 1:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[4], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[5], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[6], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[7], 14);
			break;
		case 2:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[8], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[9], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[10], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[11], 14);
			break;
		case 3:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[12], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[13], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[14], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[15], 14);
			break;
		case 4:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[16], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[17], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[18], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[19], 14);
			break;											 
		case 5:												 
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[20], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[21], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[22], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[23], 14);
			break;
		case 6:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[24], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[25], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[26], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[27], 14);
			break;											  
		case 7:												  
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[28], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[29], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[30], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[31], 14);
			break;											 
		case 8:												 
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[32], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[33], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[34], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[35], 14);
			break;											 
		case 9:												 
			CursorManager::GetInstance()->WriteBuffer(144.0f, 16.0f, ComboUI[36], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 17.0f, ComboUI[37], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 18.0f, ComboUI[38], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 19.0f, ComboUI[39], 14);
			break;
		}
		switch (Combo / 10)
		{
		case 1:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[4], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[5], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[6], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[7], 14);
			break;
		case 2:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[8], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[9], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[10], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[11], 14);
			break;											  
		case 3:												  
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[12], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[13], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[14], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[15], 14);
			break;
		case 4:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[16], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[17], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[18], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[19], 14);
			break;											 
		case 5:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[20], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[21], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[22], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[23], 14);
			break;											 
		case 6:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[24], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[25], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[26], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[27], 14);
			break;
		case 7:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[28], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[29], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[30], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[31], 14);
			break;											 
		case 8:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[32], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[33], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[34], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[35], 14);
			break;											 
		case 9:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 16.0f, ComboUI[36], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 17.0f, ComboUI[37], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 18.0f, ComboUI[38], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, ComboUI[39], 14);
			break;
		}
	}
	
	if (Combo > 99)
	{
		CursorManager::GetInstance()->WriteBuffer(136.0f, 6.0f, ComboUI[36], 12);
		CursorManager::GetInstance()->WriteBuffer(136.0f, 7.0f, ComboUI[37], 12);
		CursorManager::GetInstance()->WriteBuffer(136.0f, 8.0f, ComboUI[38], 12);
		CursorManager::GetInstance()->WriteBuffer(136.0f, 9.0f, ComboUI[39], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 6.0f, ComboUI[36], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 7.0f, ComboUI[37], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 8.0f, ComboUI[38], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 9.0f, ComboUI[39], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 6.0f, ComboUI[40], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 7.0f, ComboUI[41], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 8.0f, ComboUI[42], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 9.0f, ComboUI[43], 12);
	}

	CursorManager::GetInstance()->WriteBuffer(126.0f, 26.0f, PlayerUI[7], 10);
	for (int i = 1; i <= Life; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(132.0f + 4 * i, 26.0f, PlayerUI[8], 10);
		if (Life <= 3)
			CursorManager::GetInstance()->WriteBuffer(132.0f + 4 * i, 26.0f, PlayerUI[8], 14);
		if (Life == 1)
			CursorManager::GetInstance()->WriteBuffer(132.0f + 4 * i, 26.0f, PlayerUI[8], 12);
	}

	CursorManager::GetInstance()->WriteBuffer(126.0f, 34.0f, PlayerUI[12], 11);
	if (Kill > 50)
	{
		for(int i = 0; i < 5; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 35.0f, PlayerUI[13], 11);
	}
	else if (Kill > 40)
	{
		for (int i = 0; i < 4; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 35.0f, PlayerUI[13], 11);
	}
	else if (Kill > 30)
	{
		for (int i = 0; i < 3; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 35.0f, PlayerUI[13], 11);
	}
	else if (Kill > 20)
	{
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 35.0f, PlayerUI[13], 11);
	}
	else if (Kill > 10)
		CursorManager::GetInstance()->WriteBuffer(136.0f, 34.0f, PlayerUI[13], 11);

	CursorManager::GetInstance()->WriteBuffer(142.0f, 40.0f, PlayerUI[9], 8);
}

void Stage::Release()
{
}