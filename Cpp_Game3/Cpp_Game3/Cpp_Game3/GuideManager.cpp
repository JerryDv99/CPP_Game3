#include "GuideManager.h"
#include "CursorManager.h"

GuideManager* GuideManager::Instance = nullptr;

GuideManager::GuideManager() : Count(0), Check(false)
{
}

GuideManager::~GuideManager()
{
}


 


void GuideManager::Start()
{
	GuideScene[0]  = (char*)"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
	GuideScene[1]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[2]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[3]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[4]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[5]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[6]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[7]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[8]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[9]  = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[10] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[11] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[12] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[13] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[14] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[15] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[16] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[17] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[18] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[19] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[20] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[21] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[22] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[23] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[24] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[25] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[26] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[27] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[28] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[29] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[30] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[31] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[32] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[33] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[34] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[35] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[36] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[37] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[38] = (char*)"ㅣ                                                                            ㅣ";
	GuideScene[39] = (char*)"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
	GuideScene[40] = (char*)"  _____          __            __  _____      _    __";
	GuideScene[41] = (char*)" / ___/__  ___  / /_________  / / / ___/__ __(_)__/ /__";
	GuideScene[42] = (char*)"/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)";
	GuideScene[43] = (char*)"|___/|___/_//_/＼__/_/  ＼__/_/  |___/|____/_/＼__/＼__/";
	GuideScene[44] = (char*)"        ┌ㅡㅡ┐";
	GuideScene[45] = (char*)"        ㅣ W  ㅣ";
	GuideScene[46] = (char*)"        └ㅡㅡ┘";
	GuideScene[47] = (char*)"┌ㅡㅡ┐┌ㅡㅡ┐┌ㅡㅡ┐";
	GuideScene[48] = (char*)"ㅣ A  ㅣㅣ S  ㅣㅣ D  ㅣ";
	GuideScene[49] = (char*)"└ㅡㅡ┘└ㅡㅡ┘└ㅡㅡ┘";
	GuideScene[50] = (char*)"        ┌ㅡㅡ┐";
	GuideScene[51] = (char*)"        ㅣ ▲ ㅣ";
	GuideScene[52] = (char*)"        └ㅡㅡ┘";
	GuideScene[53] = (char*)"┌ㅡㅡ┐┌ㅡㅡ┐┌ㅡㅡ┐";
	GuideScene[54] = (char*)"ㅣ ◀ ㅣㅣ ▼ ㅣㅣ ▶ ㅣ";
	GuideScene[55] = (char*)"└ㅡㅡ┘└ㅡㅡ┘└ㅡㅡ┘";
	GuideScene[56] = (char*)"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
	GuideScene[57] = (char*)"ㅣ       SPACE        ㅣ";
	GuideScene[58] = (char*)"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
	GuideScene[59] = (char*)"┌ㅡㅡ┐";
	GuideScene[60] = (char*)"ㅣ R  ㅣ";
	GuideScene[61] = (char*)"└ㅡㅡ┘";
	GuideScene[62] = (char*)"┌ㅡㅡㅡㅡ┐";
	GuideScene[63] = (char*)"ㅣ  TAB   ㅣ";
	GuideScene[64] = (char*)"└ㅡㅡㅡㅡ┘";
	GuideScene[65] = (char*)"옷";
	GuideScene[66] = (char*)"*";
	GuideScene[67] = (char*)"자판의 W, A, S, D 키는";
	GuideScene[68] = (char*)"각각 상, 하, 좌, 우로 이동합니다";
	GuideScene[69] = (char*)"방향키로 총구의 방향을 조작합니다";
	GuideScene[70] = (char*)"위,아래로는 상하각을,";
	GuideScene[71] = (char*)"좌,우는 방향을 조절합니다";
	GuideScene[72] = (char*)"스페이스 바를 누르면";
	GuideScene[73] = (char*)"총구의 방향으로 총알이 발사됩니다";
	GuideScene[74] = (char*)"적을 처치해 점수를 획득하고 스킬 게이지를 채울 수 있습니다";
	GuideScene[75] = (char*)"피격 없이 연속처치시 콤보 점수와 더 많은 게이지를 얻습니다";
	GuideScene[76] = (char*)"스킬 게이지를 꽉 채워 강력한 필살기를 사용해 보세요 !";
	GuideScene[77] = (char*)"게임중 TAB 키를 누르면 메뉴창을 불러옵니다";	
	GuideScene[78] = (char*)"[ R 키를 누르면 메뉴로 돌아갑니다 ]";
}

void GuideManager::Update()
{
	if (!Check)
		Count++;
	else if (Check)
		Count--;



	if (Count >= 50)
		Check = true;
	
	if (Count <= 0)
		Check = false;

}

void GuideManager::Render()
{
	for (int i = 0; i < 65; ++i)
	{
		if (i < 40)
			CursorManager::GetInstance()->WriteBuffer(40.0f, 5.0f + i, GuideScene[i]);
		else if (i < 44)
			CursorManager::GetInstance()->WriteBuffer(80.0f - strlen("/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)") / 2, 6.0f + i - 40, GuideScene[i], 14);
		else if (i < 50)
			CursorManager::GetInstance()->WriteBuffer(44.0f, 12.0f + i - 44 , GuideScene[i]);
		else if (i < 56)
			CursorManager::GetInstance()->WriteBuffer(44.0f, 20.0f + i - 50 , GuideScene[i]);
		else if (i < 59)
			CursorManager::GetInstance()->WriteBuffer(44.0f, 28.0f + i - 56 , GuideScene[i]);
		else if (i < 62)
			CursorManager::GetInstance()->WriteBuffer(48.0f, 33.0f + i - 59 , GuideScene[i]);
		else
			CursorManager::GetInstance()->WriteBuffer(46.0f, 38.0f + i - 62 , GuideScene[i]);
	}

	CursorManager::GetInstance()->WriteBuffer(74.0f, 12.0f + Count * 0.1f , GuideScene[65], 14);

	CursorManager::GetInstance()->WriteBuffer(74.0f, 23.0f, GuideScene[65], 14);

	if (Count < 25)
		CursorManager::GetInstance()->WriteBuffer(77.0f, 23.0f - Count * 0.01, GuideScene[66], 10);
	else if (Count >= 25)
		CursorManager::GetInstance()->WriteBuffer(77.0f - Count * 0.03, 22.0f, GuideScene[66], 10);

	CursorManager::GetInstance()->WriteBuffer(74.0f, 28.0f, GuideScene[65], 14);
	CursorManager::GetInstance()->WriteBuffer(77.0f, 28.0f, GuideScene[66], 10);
	if (!Check)
		CursorManager::GetInstance()->WriteBuffer(77.0f + Count * 0.8, 28.0f, GuideScene[66], 11);

	CursorManager::GetInstance()->WriteBuffer(86.0f, 14.0f, GuideScene[67], 10);
	CursorManager::GetInstance()->WriteBuffer(82.0f, 15.0f, GuideScene[68], 10);

	CursorManager::GetInstance()->WriteBuffer(82.0f, 22.0f, GuideScene[69], 10);
	CursorManager::GetInstance()->WriteBuffer(88.0f, 23.0f, GuideScene[70], 10);
	CursorManager::GetInstance()->WriteBuffer(86.0f, 24.0f, GuideScene[71], 10);

	CursorManager::GetInstance()->WriteBuffer(88.0f, 29.0f, GuideScene[72], 10);
	CursorManager::GetInstance()->WriteBuffer(82.0f, 30.0f, GuideScene[73], 10);

	CursorManager::GetInstance()->WriteBuffer(58.0f, 33.0f, GuideScene[74], 10);
	CursorManager::GetInstance()->WriteBuffer(58.0f, 34.0f, GuideScene[75], 10);
	CursorManager::GetInstance()->WriteBuffer(60.0f, 35.0f, GuideScene[76], 10);

	CursorManager::GetInstance()->WriteBuffer(66.0f, 39.0f, GuideScene[77], 10);

	CursorManager::GetInstance()->WriteBuffer(66.0f, 42.0f, GuideScene[78], 14);
}

void GuideManager::Release()
{
}