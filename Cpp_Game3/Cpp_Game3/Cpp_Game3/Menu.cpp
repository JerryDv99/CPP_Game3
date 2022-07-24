#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "UIManager.h"
#include "GuideManager.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Start()
{
	// 하늘 : 0 ~ 52, 나무 : 60 ~ 92, 땅 : 100 ~ 116
	BackGround[0] = (char*)"::::::::::::::::::::::::::::::::::::::::::..............................................................................";
	BackGround[1] = (char*)":::::::::::::::::::::::::::::::::::::..::...............................................................................";
	BackGround[2] = (char*)":::::::::::::::::::::::::::::::::::......:..............................................................................";
	BackGround[3] = (char*)"::::::::::::::::::::::::::::::::::..:...................................................................................";
	BackGround[4] = (char*)":::::::::::::::::::::::::::::.:::..:....................................................................................";
	BackGround[5] = (char*)"::::::::::::::::::::::::::::::..:::.....................................................................................";
	BackGround[6] = (char*)"::::::::::::::::::::::.:::.:..::........................................................................................";
	BackGround[7] = (char*)"::::::::::::::::.::::::.:...............................................................................................";
	BackGround[8] = (char*)":::::::::::::..:...:....................................................................................................";
	BackGround[9] = (char*)":::::::.::..:...........................................................................................................";
	BackGround[10] = (char*)":::::.::................................................................................................................";
	BackGround[11] = (char*)"::::::..................................................................................................................";
	BackGround[12] = (char*)"::......................................................................................................................";
	BackGround[13] = (char*)"........................................................................................................................";
	BackGround[14] = (char*)"........................................................................................................................";
	BackGround[15] = (char*)"........................................................................................................................";
	BackGround[16] = (char*)"........................................................................................................................";
	BackGround[17] = (char*)"........................................................................................................................";
	BackGround[18] = (char*)".................:.............................::.......................................................................";

	BackGround[20] = (char*)"..............";	// 14, (5), 25, (6), 70
	BackGround[21] = (char*)".........................";
	BackGround[22] = (char*)"......................................................................";
	BackGround[60] = (char*)":***:";
	BackGround[61] = (char*)"::***:";

	BackGround[23] = (char*)"............."; // 13, (8), 23, (6), 70
	BackGround[24] = (char*)".......................";
	BackGround[25] = (char*)"......................................................................";
	BackGround[63] = (char*)":*VVV*::";
	BackGround[64] = (char*)":**V*:";

	BackGround[26] = (char*)"............"; // 12, (9), 23, (7), 69
	BackGround[27] = (char*)".......................";
	BackGround[28] = (char*)".....................................................................";
	BackGround[66] = (char*)":*VVVV*::";
	BackGround[67] = (char*)":*VVV*:";

	BackGround[29] = (char*)".........."; // 10, (10), 23, (8), 69
	BackGround[30] = (char*)".......................";
	BackGround[31] = (char*)".....................................................................";
	BackGround[69] = (char*)":***VVVV*:";
	BackGround[70] = (char*)":*VVVVV*";

	BackGround[32] = (char*)".........."; // 10, (10), 23, (9), 68
	BackGround[33] = (char*)".......................";
	BackGround[34] = (char*)"...::...............................................................";
	BackGround[72] = (char*)":*VVVVVVV*";
	BackGround[73] = (char*)":*VVVVV*:";

	BackGround[35] = (char*)".........:"; // 10, (13), 19, (16), 62
	BackGround[36] = (char*)".........::::::....";
	BackGround[37] = (char*)"..............................................................";
	BackGround[75] = (char*)"****VVVV*::::";
	BackGround[76] = (char*)":**VVVV*:...:***";

	BackGround[38] = (char*)"........."; // 9, (49), 62
	BackGround[39] = (char*)"..............................................................";
	BackGround[78] = (char*)":***VVVVV****:.....:**********...:*VVVVV*:..:*VV*";

	BackGround[40] = (char*)"........."; // 9, (50), 61
	BackGround[41] = (char*)".............................................................";
	BackGround[80] = (char*)"***VVVVVVVVVVV*****************...*VVVVVV*:.:*VVV:";

	BackGround[42] = (char*)"........"; // 8, (51), 61
	BackGround[43] = (char*)".............................................................";
	BackGround[82] = (char*)":*VVVVVVVVVVVVV******************:***VVVVVV::*VVVV:";

	BackGround[44] = (char*)"........"; // 8, (50), 62
	BackGround[45] = (char*)"..............................................................";
	BackGround[84] = (char*)":*VVVVVVVVVVVVV******************VVVVVVVVVV**VVVVV";

	BackGround[46] = (char*)"......."; // 7, (52), 61
	BackGround[47] = (char*)".............................................................";
	BackGround[86] = (char*)":***VVVVVVVVVVVV***:*****:********VVVVVVVVVVVVVVVVV*";

	BackGround[48] = (char*)"........"; // 8, (52), 60
	BackGround[49] = (char*)"............................................................";
	BackGround[88] = (char*)":*********::::::::::::::::::*::**VVVVVVVVVVVVVVVVVV*";

	BackGround[50] = (char*)":................................................:::::::::"; // (62), 58
	BackGround[90] = (char*)".......:::::::::::::::::::::::::::::::::::..::::*****VVVVVVVV*";

	BackGround[51] = (char*)":................................................:::::::::"; // (62), 58
	BackGround[91] = (char*)".......:::::::::::::::::::::::::::::::::::..::::*****VVVVVVVV*";

	BackGround[52] = (char*)":..........................................::::::::::::::"; // (63), 57
	BackGround[92] = (char*)":::::::::::::::::::::::::::::::::::::::::::::::::::::::****VVVV";


	BackGround[100] = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::..............................::::::::::::::::::::::";
	BackGround[101] = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	BackGround[102] = (char*)"::::::::::::::::::::::::::::::::::::**************::::...:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	BackGround[103] = (char*)"::::::::::::::::::::::::::::::::**************:::....:::::::::::::::::::::::::::::::::::::::::::::::::::::::*:::::::::::";
	BackGround[104] = (char*)":::::::::::::::::::::::::::::::************::....::********************::::::::::::::::::::::::::::::::******:**:*:*****";
	BackGround[105] = (char*)":::::::::::::::::::::::::::**************:.::::::******************************::::::::::::***::::**:*******************";
	BackGround[106] = (char*)"**:::*::::::::::::::::*:******************:::::::****************VVVVVVV**********************************************VV";
	BackGround[107] = (char*)"::::**::*:::*:*:*:*::**********************::::::::::::::::::**********VVVVVVVVVV**********VVV******VVVVVVVVVVVVVVV***VV";
	BackGround[108] = (char*)"*******:*::****:*****************************:::::::::::::::::::::::::::*****************VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	BackGround[109] = (char*)"*******::***********::*******************************:::::************:::::::::::::::::::::::*************VVVVVVVVVVVVVV";
	BackGround[110] = (char*)"*:***:******************************************VV*VV**V******************:::::::::::::::::***********::::::::::********";
	BackGround[111] = (char*)"*****:**:**:************::*****************************************************:::::::::::*::::*****************::::::::";
	BackGround[112] = (char*)"************************************::*****************************V***************************::::::::*****************";
	BackGround[113] = (char*)"************************************::**********************************************************************************";
	BackGround[114] = (char*)"**************:*************:***:*********************************************************VVVVVVVVVVVVVV****V***********";
	BackGround[115] = (char*)"*****:********.:**************************************************************************VVVVVV*VVVVVVVVVVVVVVV********";
	BackGround[116] = (char*)"*******************************************************************************************************V****************";

	BColor1 = 11;
	BColor2 = 14;
	BColor3 = 10;
	Cursor = 12;
	Check = false;
	Guide = false;

	Time = GetTickCount64();
	UIManager::GetInstance()->Start();
	GuideManager::GetInstance()->Start();
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	
	GuideManager::GetInstance()->Update();

	if (Time + 100 < GetTickCount64() && Check)
		Check = false;

	if (Cursor > 12 && !Guide)
	{
		if (dwKey & KEY_AUP && !Check)
		{
			Cursor -= 4;
			Check = true;
			Time = GetTickCount64();
		}
	}

	if (Cursor < 20 && !Guide)
	{
		if (dwKey & KEY_ADOWN && !Check)
		{
			Cursor += 4;		
			Check = true;
			Time = GetTickCount64();
		}
	}

	if (dwKey & KEY_RETURN && Time + 200 < GetTickCount64())
	{
		switch (Cursor)
		{
		case 12:
			SceneManager::GetInstance()->SetScene(SCENEID::STORY);
			break;
		case 16:
			Guide = true;
			break;
		case 20:
			exit(NULL);
			break;
		}
	}

	if (dwKey & KEY_R)
		Guide = false;

	if (Cursor == 12 || Cursor == 20)
	{
		BColor1 = 8;
		BColor2 = 12;
		BColor3 = 6;
	}

	else if (Cursor == 16)
	{
		BColor1 = 11;
		BColor2 = 14;
		BColor3 = 10;
	}
}

void Menu::Render()
{
	for (int i = 0; i < 19; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f + i, BackGround[i], BColor1);
	}
	CursorManager::GetInstance()->WriteBuffer(0.0f, 19.0f, BackGround[20], BColor1);
	CursorManager::GetInstance()->WriteBuffer(19.0f, 19.0f, BackGround[21], BColor1);
	CursorManager::GetInstance()->WriteBuffer(50.0f, 19.0f, BackGround[22], BColor1);
	CursorManager::GetInstance()->WriteBuffer(14.0f, 19.0f, BackGround[60], BColor2);
	CursorManager::GetInstance()->WriteBuffer(44.0f, 19.0f, BackGround[61], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 20.0f, BackGround[23], BColor1);
	CursorManager::GetInstance()->WriteBuffer(21.0f, 20.0f, BackGround[24], BColor1);
	CursorManager::GetInstance()->WriteBuffer(50.0f, 20.0f, BackGround[25], BColor1);
	CursorManager::GetInstance()->WriteBuffer(13.0f, 20.0f, BackGround[63], BColor2);
	CursorManager::GetInstance()->WriteBuffer(44.0f, 20.0f, BackGround[64], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 21.0f, BackGround[26], BColor1);
	CursorManager::GetInstance()->WriteBuffer(21.0f, 21.0f, BackGround[27], BColor1);
	CursorManager::GetInstance()->WriteBuffer(51.0f, 21.0f, BackGround[28], BColor1);
	CursorManager::GetInstance()->WriteBuffer(12.0f, 21.0f, BackGround[66], BColor2);
	CursorManager::GetInstance()->WriteBuffer(44.0f, 21.0f, BackGround[67], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 22.0f, BackGround[29], BColor1);
	CursorManager::GetInstance()->WriteBuffer(20.0f, 22.0f, BackGround[30], BColor1);
	CursorManager::GetInstance()->WriteBuffer(51.0f, 22.0f, BackGround[31], BColor1);
	CursorManager::GetInstance()->WriteBuffer(10.0f, 22.0f, BackGround[69], BColor2);
	CursorManager::GetInstance()->WriteBuffer(43.0f, 22.0f, BackGround[70], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 23.0f, BackGround[32], BColor1);
	CursorManager::GetInstance()->WriteBuffer(20.0f, 23.0f, BackGround[33], BColor1);
	CursorManager::GetInstance()->WriteBuffer(52.0f, 23.0f, BackGround[34], BColor1);
	CursorManager::GetInstance()->WriteBuffer(10.0f, 23.0f, BackGround[72], BColor2);
	CursorManager::GetInstance()->WriteBuffer(43.0f, 23.0f, BackGround[73], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 24.0f, BackGround[35], BColor1);
	CursorManager::GetInstance()->WriteBuffer(23.0f, 24.0f, BackGround[36], BColor1);
	CursorManager::GetInstance()->WriteBuffer(58.0f, 24.0f, BackGround[37], BColor1);
	CursorManager::GetInstance()->WriteBuffer(10.0f, 24.0f, BackGround[75], BColor2);
	CursorManager::GetInstance()->WriteBuffer(42.0f, 24.0f, BackGround[76], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 25.0f, BackGround[38], BColor1);
	CursorManager::GetInstance()->WriteBuffer(58.0f, 25.0f, BackGround[39], BColor1);
	CursorManager::GetInstance()->WriteBuffer(9.0f, 25.0f, BackGround[78], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 26.0f, BackGround[40], BColor1);
	CursorManager::GetInstance()->WriteBuffer(59.0f, 26.0f, BackGround[41], BColor1);
	CursorManager::GetInstance()->WriteBuffer(9.0f, 26.0f, BackGround[80], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 27.0f, BackGround[42], BColor1);
	CursorManager::GetInstance()->WriteBuffer(59.0f, 27.0f, BackGround[43], BColor1);
	CursorManager::GetInstance()->WriteBuffer(8.0f, 27.0f, BackGround[82], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 28.0f, BackGround[44], BColor1);
	CursorManager::GetInstance()->WriteBuffer(58.0f, 28.0f, BackGround[45], BColor1);
	CursorManager::GetInstance()->WriteBuffer(8.0f, 28.0f, BackGround[84], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 29.0f, BackGround[46], BColor1);
	CursorManager::GetInstance()->WriteBuffer(59.0f, 29.0f, BackGround[47], BColor1);
	CursorManager::GetInstance()->WriteBuffer(7.0f, 29.0f, BackGround[86], BColor2);

	CursorManager::GetInstance()->WriteBuffer(0.0f, 30.0f, BackGround[48], BColor1);
	CursorManager::GetInstance()->WriteBuffer(60.0f, 30.0f, BackGround[49], BColor1);
	CursorManager::GetInstance()->WriteBuffer(8.0f, 30.0f, BackGround[88], BColor2);

	CursorManager::GetInstance()->WriteBuffer(62.0f, 31.0f, BackGround[50], BColor1);
	CursorManager::GetInstance()->WriteBuffer(0.0f, 31.0f, BackGround[90], BColor2);

	CursorManager::GetInstance()->WriteBuffer(62.0f, 32.0f, BackGround[51], BColor1);
	CursorManager::GetInstance()->WriteBuffer(0.0f, 32.0f, BackGround[91], BColor2);

	for (int i = 100; i < 117; ++i)
		CursorManager::GetInstance()->WriteBuffer(0.0f, 33.0f + (i - 100), BackGround[i], BColor3);
	UIManager::GetInstance()->Render();
	UIManager::GetInstance()->WriteUI(132, 6, (char*)"- 메 인 메 뉴 -", 14);
	UIManager::GetInstance()->WriteUI(132, 12, (char*)"[ 게 임 시 작 ]", 8);
	UIManager::GetInstance()->WriteUI(132, 16, (char*)"[ 조작 가이드 ]", 8);
	UIManager::GetInstance()->WriteUI(132, 20, (char*)"[ 게 임 종 료 ]", 8);
	UIManager::GetInstance()->WriteUI(128, 43, (char*)"Tip)", 8);
	UIManager::GetInstance()->WriteUI(128, 44, (char*)"키보드의 화살표로 움직이고", 8);
	UIManager::GetInstance()->WriteUI(128, 45, (char*)"엔터키로 선택합니다", 8);
	UIManager::GetInstance()->WriteUI(126, Cursor, (char*)"☞", 14);

	switch (Cursor)
	{
	case 12:
		UIManager::GetInstance()->WriteUI(132, 12, (char*)"[ 게 임 시 작 ]", 15);
		break;
	case 16:
		UIManager::GetInstance()->WriteUI(132, 16, (char*)"[ 조작 가이드 ]", 15);
		break;
	case 20:
		UIManager::GetInstance()->WriteUI(132, 20, (char*)"[ 게 임 종 료 ]", 15);
		break;
	}
	if (Guide)
		GuideManager::GetInstance()->Render();
}

void Menu::Release()
{
} 