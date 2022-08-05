#include "Stage.h"
#include "InputManager.h"
#include "GuideManager.h"
#include "ObjectManager.h"
#include "UIManager.h"
#include "CursorManager.h"
#include "SceneManager.h"

Stage::Stage() : Menu(false), ITuto(false), Guide(false)
{
	Life = 0;
	Hit = 0;
	Kill = 0;
	Score = 0;
	Combo = 0;
	SkillGauge = 0;
	Cursor = 0;
}

Stage::~Stage()
{
}

void Stage::Start()
{
	ITuto = true;
	Guide = false;
	Menu = false;
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
	PlayerUI[2]  = (char*)"스킬 게이지 :";
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
	PlayerUI[14] = (char*)"방향키와 엔터키를 사용하세요";

	Life = 5;
	Hit = 0;
	Kill = 0;
	Score = 0;
	Combo = 0.0f;
	SkillGauge = 0;
	Cursor = 21;
	Time = GetTickCount64();
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
	if (Combo < 20)
	{
		Score += ObjectManager::GetInstance()->GetScore();
		SkillGauge += ObjectManager::GetInstance()->GetScore() * 0.01;
	}
	else if (Combo < 40)
	{
		Score += ObjectManager::GetInstance()->GetScore() * 1.2;
		SkillGauge += ObjectManager::GetInstance()->GetScore() * 0.012;
	}
	else if (Combo < 70)
	{
		Score += ObjectManager::GetInstance()->GetScore() * 1.4;
		SkillGauge += ObjectManager::GetInstance()->GetScore() * 0.014;
	}
	else if (Combo < 100)
	{
		Score += ObjectManager::GetInstance()->GetScore() * 1.8;
		SkillGauge += ObjectManager::GetInstance()->GetScore() * 0.018;
	}

	if (SkillGauge >= 300)
	{
		ObjectManager::GetInstance()->SetSkill(true);
		if (ObjectManager::GetInstance()->GetActive() == true)
			SkillGauge = 0;
	}

	if (dwKey & KEY_TAB)
		Menu = true;

	if (ITuto)
	{
		ObjectManager::GetInstance()->SetPause(true);
		if (dwKey & KEY_R)
		{
			ITuto = false;
			if (!Menu)
				ObjectManager::GetInstance()->SetPause(false);
		}
	}

	if (Guide)
	{
		GuideManager::GetInstance()->Update();
		if (dwKey & KEY_R)
		{
			Guide = false;
		}
	}

	if (Menu)
	{
		ObjectManager::GetInstance()->SetPause(true);
		if (dwKey & KEY_AUP && Cursor > 21 && Time + 100 < GetTickCount64()
			&& !ITuto && !Guide)
		{
			Cursor -= 2;
			Time = GetTickCount64();
		}
		if (dwKey & KEY_ADOWN && Cursor < 29 && Time + 100 < GetTickCount64()
			&& !ITuto && !Guide)
		{
			Cursor += 2;
			Time = GetTickCount64();
		}
		if (dwKey & KEY_RETURN && Time + 100 < GetTickCount64() && Cursor == 21
			&& !ITuto && !Guide)
		{
			Menu = false;
			ObjectManager::GetInstance()->SetPause(false);
		}
		if (dwKey & KEY_RETURN && Time + 100 < GetTickCount64() && Cursor == 23
			&& !ITuto && !Guide)
		{
			Guide = true;
			Time = GetTickCount64();
		}
		if (dwKey & KEY_RETURN && Time + 100 < GetTickCount64() && Cursor == 25
			&& !ITuto && !Guide)
		{
			ITuto = true;
			Time = GetTickCount64();
		}	
		if (dwKey & KEY_RETURN && Time + 100 < GetTickCount64() && Cursor == 27
			&& !ITuto && !Guide)
		{
			ObjectManager::GetInstance()->SoftRelease();
			SceneManager::GetInstance()->SetScene(SCENEID::MENU);
		}			
		if (dwKey & KEY_RETURN && Time + 100 < GetTickCount64() && Cursor == 29
			&& !ITuto && !Guide)
		{
			exit(NULL);
		}		
	}
	if (Kill >= 50)
	{
		ObjectManager::GetInstance()->SoftRelease();
		SceneManager::GetInstance()->SetScene(SCENEID::BOSSSN);
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	
	UIManager::GetInstance()->Render();

	if (Menu)
	{
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 18.0f, (char*)"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 19.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 20.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 21.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 22.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 23.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 24.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 25.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 26.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 27.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 28.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 29.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 30.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 31.0f, (char*)"ㅣ                            ㅣ");
		CursorManager::GetInstance()->WriteBuffer(65 - strlen("└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐") / 2, 32.0f, (char*)"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘");
		if (Cursor != 21)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 21.0f, (char*)"[ 게임으로 돌아가기 ]", 8);
		else if (Cursor == 21)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 21.0f, (char*)"[ 게임으로 돌아가기 ]");
		if (Cursor != 23)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 23.0f, (char*)"[  조작가이드 보기  ]", 8);
		else if (Cursor == 23)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 23.0f, (char*)"[  조작가이드 보기  ]");
		if (Cursor != 25)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 25.0f, (char*)"[  아이템효과 보기  ]", 8);
		else if (Cursor == 25)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 25.0f, (char*)"[  아이템효과 보기  ]");
		if (Cursor != 27)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 27.0f, (char*)"[  메인메뉴로 가기  ]", 8);
		else if (Cursor == 27)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 27.0f, (char*)"[  메인메뉴로 가기  ]");
		if (Cursor != 29)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 29.0f, (char*)"[     게임 종료     ]", 8);
		else if (Cursor == 29)
			CursorManager::GetInstance()->WriteBuffer(65 - strlen("[ 게임으로 돌아가기 ]") / 2, 29.0f, (char*)"[     게임 종료     ]");
	}

	if (ITuto)
		GuideManager::GetInstance()->Render(2);
	if (Guide)
		GuideManager::GetInstance()->Render(1);
	CursorManager::GetInstance()->WriteBuffer(126.0f, 4.0f, PlayerUI[0], 10);
	if(Score < 1000)
		CursorManager::GetInstance()->WriteBuffer(152.0f, 4.0f, Score, 10);
	else if (Score < 10000)
		CursorManager::GetInstance()->WriteBuffer(151.0f, 4.0f, Score, 10);
	else if (Score < 100000)
		CursorManager::GetInstance()->WriteBuffer(150.0f, 4.0f, Score, 10);
	else if (Score < 1000000)
		CursorManager::GetInstance()->WriteBuffer(149.0f, 4.0f, Score, 10);

	if (ObjectManager::GetInstance()->GetScore() != 0)
	{
		CursorManager::GetInstance()->WriteBuffer(126.0f, 6.0f, (char*)"+", 10);
		CursorManager::GetInstance()->WriteBuffer(151.0f, 6.0f, ObjectManager::GetInstance()->GetScore(), 10); 
	}

	CursorManager::GetInstance()->WriteBuffer(126.0f, 8.0f, PlayerUI[1], 14);
	if (Combo < 100)
	{
		switch (Combo % 10)
		{
		case 0:
			CursorManager::GetInstance()->WriteBuffer(144.0f,  8.0f, ComboUI[0], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f,  9.0f, ComboUI[1], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[2], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[3], 14);
			break;
		case 1:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[4], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[5], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[6], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[7], 14);
			break;
		case 2:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[8], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[9], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[10], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[11], 14);
			break;
		case 3:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[12], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[13], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[14], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[15], 14);
			break;
		case 4:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[16], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[17], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[18], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[19], 14);
			break;											 
		case 5:												 
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[20], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[21], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[22], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[23], 14);
			break;
		case 6:
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[24], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[25], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[26], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[27], 14);
			break;											  
		case 7:												  
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[28], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[29], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[30], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[31], 14);
			break;											 
		case 8:												 
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[32], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[33], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[34], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[35], 14);
			break;											 
		case 9:												 
			CursorManager::GetInstance()->WriteBuffer(144.0f, 8.0f, ComboUI[36], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 9.0f, ComboUI[37], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 10.0f, ComboUI[38], 14);
			CursorManager::GetInstance()->WriteBuffer(144.0f, 11.0f, ComboUI[39], 14);
			break;
		}
		switch (Combo / 10)
		{
		case 1:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[4], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[5], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[6], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[7], 14);
			break;
		case 2:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[8], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[9], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[10], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[11], 14);
			break;											  
		case 3:												  
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[12], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[13], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[14], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[15], 14);
			break;
		case 4:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[16], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[17], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[18], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[19], 14);
			break;											 
		case 5:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[20], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[21], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[22], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[23], 14);
			break;											 
		case 6:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[24], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[25], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[26], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[27], 14);
			break;
		case 7:
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[28], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[29], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[30], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[31], 14);
			break;											 
		case 8:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[32], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[33], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[34], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[35], 14);
			break;											 
		case 9:												 
			CursorManager::GetInstance()->WriteBuffer(138.0f, 8.0f, ComboUI[36], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 9.0f, ComboUI[37], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 10.0f, ComboUI[38], 14);
			CursorManager::GetInstance()->WriteBuffer(138.0f, 11.0f, ComboUI[39], 14);
			break;
		}
	}
	
	if (Combo > 99)
	{
		CursorManager::GetInstance()->WriteBuffer(136.0f, 8.0f, ComboUI[36], 12);
		CursorManager::GetInstance()->WriteBuffer(136.0f, 9.0f, ComboUI[37], 12);
		CursorManager::GetInstance()->WriteBuffer(136.0f, 10.0f, ComboUI[38], 12);
		CursorManager::GetInstance()->WriteBuffer(136.0f, 11.0f, ComboUI[39], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 8.0f, ComboUI[36], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 9.0f, ComboUI[37], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 10.0f, ComboUI[38], 12);
		CursorManager::GetInstance()->WriteBuffer(142.0f, 11.0f, ComboUI[39], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 8.0f, ComboUI[40], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 9.0f, ComboUI[41], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 10.0f, ComboUI[42], 12);
		CursorManager::GetInstance()->WriteBuffer(148.0f, 11.0f, ComboUI[43], 12);
	}

	CursorManager::GetInstance()->WriteBuffer(126.0f, 30.0f, PlayerUI[7], 10);
	for (int i = 1; i <= Life; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(132.0f + 4 * i, 30.0f, PlayerUI[8], 10);
		if (Life <= 3)
			CursorManager::GetInstance()->WriteBuffer(132.0f + 4 * i, 30.0f, PlayerUI[8], 14);
		if (Life == 1)
			CursorManager::GetInstance()->WriteBuffer(132.0f + 4 * i, 30.0f, PlayerUI[8], 12);
	}

	CursorManager::GetInstance()->WriteBuffer(126.0f, 34.0f, PlayerUI[12], 11);
	if (Kill >= 50)
	{
		for(int i = 0; i < 5; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 36.0f, PlayerUI[13], 11);
	}
	else if (Kill >= 40)
	{
		for (int i = 0; i < 4; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 36.0f, PlayerUI[13], 11);
	}
	else if (Kill >= 30)
	{
		for (int i = 0; i < 3; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 36.0f, PlayerUI[13], 11);
	}
	else if (Kill >= 20)
	{
		for (int i = 0; i < 2; ++i)
			CursorManager::GetInstance()->WriteBuffer(130.0f + i * 4, 36.0f, PlayerUI[13], 11);
	}
	else if (Kill >= 10)
		CursorManager::GetInstance()->WriteBuffer(130.0f, 36.0f, PlayerUI[13], 11);

	CursorManager::GetInstance()->WriteBuffer(142.0f, 40.0f, PlayerUI[9], 8);
	CursorManager::GetInstance()->WriteBuffer(128.0f, 41.0f, PlayerUI[14], 8);
	CursorManager::GetInstance()->WriteBuffer(126.0f, 16.0f, PlayerUI[4], 13);
	CursorManager::GetInstance()->WriteBuffer(126.0f, 18.0f, PlayerUI[2], 13);
	if (Menu)
	{
		CursorManager::GetInstance()->WriteBuffer(142.0f, 40.0f, PlayerUI[9]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 41.0f, PlayerUI[14]);
	}
	if (SkillGauge < 300)
		CursorManager::GetInstance()->WriteBuffer(148.0f, 16.0f, PlayerUI[6], 12);
	if (SkillGauge >= 300)
		CursorManager::GetInstance()->WriteBuffer(148.0f, 16.0f, PlayerUI[5], 14);
	for (int i = 1; i <= SkillGauge / 60; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(154.0f, 25 - i, PlayerUI[3], 9);
		if(SkillGauge >= 120)
			CursorManager::GetInstance()->WriteBuffer(154.0f, 25 - i, PlayerUI[3], 11);
		if (SkillGauge >= 180)
			CursorManager::GetInstance()->WriteBuffer(154.0f, 25 - i, PlayerUI[3], 10);
		if (SkillGauge >= 240)
			CursorManager::GetInstance()->WriteBuffer(154.0f, 25 - i, PlayerUI[3], 14);
		if (SkillGauge >= 240)
			CursorManager::GetInstance()->WriteBuffer(154.0f, 25 - i, PlayerUI[3], 12);
	}
}

void Stage::Release()
{
}