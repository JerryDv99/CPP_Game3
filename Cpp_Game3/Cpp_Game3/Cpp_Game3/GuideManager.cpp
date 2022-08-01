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
	Border[0]  = (char*)"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
	Border[1]  = (char*)"ㅣ                                                                            ㅣ";
	Border[2]  = (char*)"ㅣ                                                                            ㅣ";
	Border[3]  = (char*)"ㅣ                                                                            ㅣ";
	Border[4]  = (char*)"ㅣ                                                                            ㅣ";
	Border[5]  = (char*)"ㅣ                                                                            ㅣ";
	Border[6]  = (char*)"ㅣ                                                                            ㅣ";
	Border[7]  = (char*)"ㅣ                                                                            ㅣ";
	Border[8]  = (char*)"ㅣ                                                                            ㅣ";
	Border[9]  = (char*)"ㅣ                                                                            ㅣ";
	Border[10] = (char*)"ㅣ                                                                            ㅣ";
	Border[11] = (char*)"ㅣ                                                                            ㅣ";
	Border[12] = (char*)"ㅣ                                                                            ㅣ";
	Border[13] = (char*)"ㅣ                                                                            ㅣ";
	Border[14] = (char*)"ㅣ                                                                            ㅣ";
	Border[15] = (char*)"ㅣ                                                                            ㅣ";
	Border[16] = (char*)"ㅣ                                                                            ㅣ";
	Border[17] = (char*)"ㅣ                                                                            ㅣ";
	Border[18] = (char*)"ㅣ                                                                            ㅣ";
	Border[19] = (char*)"ㅣ                                                                            ㅣ";
	Border[20] = (char*)"ㅣ                                                                            ㅣ";
	Border[21] = (char*)"ㅣ                                                                            ㅣ";
	Border[22] = (char*)"ㅣ                                                                            ㅣ";
	Border[23] = (char*)"ㅣ                                                                            ㅣ";
	Border[24] = (char*)"ㅣ                                                                            ㅣ";
	Border[25] = (char*)"ㅣ                                                                            ㅣ";
	Border[26] = (char*)"ㅣ                                                                            ㅣ";
	Border[27] = (char*)"ㅣ                                                                            ㅣ";
	Border[28] = (char*)"ㅣ                                                                            ㅣ";
	Border[29] = (char*)"ㅣ                                                                            ㅣ";
	Border[30] = (char*)"ㅣ                                                                            ㅣ";
	Border[31] = (char*)"ㅣ                                                                            ㅣ";
	Border[32] = (char*)"ㅣ                                                                            ㅣ";
	Border[33] = (char*)"ㅣ                                                                            ㅣ";
	Border[34] = (char*)"ㅣ                                                                            ㅣ";
	Border[35] = (char*)"ㅣ                                                                            ㅣ";
	Border[36] = (char*)"ㅣ                                                                            ㅣ";
	Border[37] = (char*)"ㅣ                                                                            ㅣ";
	Border[38] = (char*)"ㅣ                                                                            ㅣ";
	Border[39] = (char*)"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
	CtrlGuide[0] = (char*)"  _____          __            __  _____      _    __";
	CtrlGuide[1] = (char*)" / ___/__  ___  / /_________  / / / ___/__ __(_)__/ /__";
	CtrlGuide[2] = (char*)"/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)";
	CtrlGuide[3] = (char*)"|___/|___/_//_/＼__/_/  ＼__/_/  |___/|____/_/＼__/＼__/";
	CtrlGuide[4] = (char*)"        ┌ㅡㅡ┐";
	CtrlGuide[5] = (char*)"        ㅣ W  ㅣ";
	CtrlGuide[6] = (char*)"        └ㅡㅡ┘";
	CtrlGuide[7] = (char*)"┌ㅡㅡ┐┌ㅡㅡ┐┌ㅡㅡ┐";
	CtrlGuide[8] = (char*)"ㅣ A  ㅣㅣ S  ㅣㅣ D  ㅣ";
	CtrlGuide[9] = (char*)"└ㅡㅡ┘└ㅡㅡ┘└ㅡㅡ┘";
	CtrlGuide[10] = (char*)"        ┌ㅡㅡ┐";
	CtrlGuide[11] = (char*)"        ㅣ ▲ ㅣ";
	CtrlGuide[12] = (char*)"        └ㅡㅡ┘";
	CtrlGuide[13] = (char*)"┌ㅡㅡ┐┌ㅡㅡ┐┌ㅡㅡ┐";
	CtrlGuide[14] = (char*)"ㅣ ◀ ㅣㅣ ▼ ㅣㅣ ▶ ㅣ";
	CtrlGuide[15] = (char*)"└ㅡㅡ┘└ㅡㅡ┘└ㅡㅡ┘";
	CtrlGuide[16] = (char*)"┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
	CtrlGuide[17] = (char*)"ㅣ       SPACE        ㅣ";
	CtrlGuide[18] = (char*)"└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
	CtrlGuide[19] = (char*)"┌ㅡㅡ┐";
	CtrlGuide[20] = (char*)"ㅣ R  ㅣ";
	CtrlGuide[21] = (char*)"└ㅡㅡ┘";
	CtrlGuide[22] = (char*)"┌ㅡㅡㅡㅡ┐";
	CtrlGuide[23] = (char*)"ㅣ  TAB   ㅣ";
	CtrlGuide[24] = (char*)"└ㅡㅡㅡㅡ┘";
	CtrlGuide[25] = (char*)"옷";
	CtrlGuide[26] = (char*)"*";
	CtrlGuide[27] = (char*)"자판의 W, A, S, D 키는";
	CtrlGuide[28] = (char*)"각각 상, 하, 좌, 우로 이동합니다";
	CtrlGuide[29] = (char*)"방향키로 총구의 방향을 조작합니다";
	CtrlGuide[30] = (char*)"위,아래로는 상하각을,";
	CtrlGuide[31] = (char*)"좌,우는 방향을 조절합니다";
	CtrlGuide[32] = (char*)"스페이스 바를 누르면";
	CtrlGuide[33] = (char*)"총구의 방향으로 총알이 발사됩니다";
	CtrlGuide[34] = (char*)"적을 처치해 점수를 획득하고 스킬 게이지를 채울 수 있습니다";
	CtrlGuide[35] = (char*)"피격 없이 연속처치시 콤보 점수와 더 많은 게이지를 얻습니다";
	CtrlGuide[36] = (char*)"스킬 게이지를 꽉 채워 강력한 필살기를 사용해 보세요 !";
	CtrlGuide[37] = (char*)"게임중 TAB 키를 누르면 메뉴창을 불러옵니다";	
	CtrlGuide[38] = (char*)"[ R 키를 누르면 메뉴로 돌아갑니다 ]";

	ItemTuto[0]  = (char*)"아이템 튜토리얼";
	ItemTuto[1]  = (char*)"∠STATIC";
	ItemTuto[2]  = (char*)"／BULLET";
	ItemTuto[3]  = (char*)"∂MOLOTOV";
	ItemTuto[4]  = (char*)"∪!!!!!!!";
	ItemTuto[5]  = (char*)"⊂▤▤⊃";
	ItemTuto[6]  = (char*)"KF94MASK";
	ItemTuto[7]  = (char*)" ￡BUDDY";
	ItemTuto[8]  = (char*)"dl BUDDY";
	ItemTuto[9]  = (char*)"전투 중 일정 시간마다 바깥쪽 랜덤한 위치에서 아이템이 생성됩니다";
	ItemTuto[10] = (char*)"아이템은 중앙 부근을 가로질러 이동하며 획득시 고유효과가 적용됩니다";
	ItemTuto[11] = (char*)"정전기 탄 : 10초 동안 발사되는 탄이 적 추적 기능을 가집니다";
	ItemTuto[12] = (char*)"화염병 : 플레이어 중심 3x3의 필드 위 투사체와 적을 파괴합니다";
	ItemTuto[13] = (char*)"보스는 파괴되지 않고 데미지를 입습니다";
	ItemTuto[14] = (char*)"마스크 : 플레이어 HP를 대신해 파괴되는 1겹의 보호막을 얻습니다";
	ItemTuto[15] = (char*)"보호막 파괴시 피격때와 마찬가지로 1초간 무적상태가 됩니다";
	ItemTuto[16] = (char*)"버디버디 : 15초 동안 플레이어의 이동 속도가 증가합니다";
	ItemTuto[17] = (char*)"[ R ] 키를 눌러 확인 후 게임 시작";
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

void GuideManager::Render(int _Option)
{
	for (int i = 0; i < 40; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(40.0f, 5.0f + i, Border[i]);
	}
	

	switch (_Option)
	{
	case 1:
		for (int i = 0; i < 25; ++i)
		{
			if (i < 4)
				CursorManager::GetInstance()->WriteBuffer(80.0f - strlen("/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)") / 2, 6.0f + i, CtrlGuide[i], 14);
			else if (i < 10)
				CursorManager::GetInstance()->WriteBuffer(44.0f, 12.0f + i - 4, CtrlGuide[i]);
			else if (i < 16)
				CursorManager::GetInstance()->WriteBuffer(44.0f, 20.0f + i - 10, CtrlGuide[i]);
			else if (i < 19)
				CursorManager::GetInstance()->WriteBuffer(44.0f, 28.0f + i - 16, CtrlGuide[i]);
			else if (i < 22)
				CursorManager::GetInstance()->WriteBuffer(48.0f, 33.0f + i - 19, CtrlGuide[i]);
			else
				CursorManager::GetInstance()->WriteBuffer(46.0f, 38.0f + i - 22, CtrlGuide[i]);
		}

		CursorManager::GetInstance()->WriteBuffer(74.0f, 12.0f + Count * 0.1f, CtrlGuide[25], 14);

		CursorManager::GetInstance()->WriteBuffer(74.0f, 23.0f, CtrlGuide[25], 14);

		if (Count < 25)
			CursorManager::GetInstance()->WriteBuffer(77.0f, 23.0f - Count * 0.01, CtrlGuide[26], 10);
		else if (Count >= 25)
			CursorManager::GetInstance()->WriteBuffer(77.0f - Count * 0.03, 22.0f, CtrlGuide[26], 10);

		CursorManager::GetInstance()->WriteBuffer(74.0f, 28.0f, CtrlGuide[25], 14);
		CursorManager::GetInstance()->WriteBuffer(77.0f, 28.0f, CtrlGuide[26], 10);
		if (!Check)
			CursorManager::GetInstance()->WriteBuffer(77.0f + Count * 0.8, 28.0f, CtrlGuide[26], 11);

		CursorManager::GetInstance()->WriteBuffer(86.0f, 14.0f, CtrlGuide[27], 10);
		CursorManager::GetInstance()->WriteBuffer(82.0f, 15.0f, CtrlGuide[28], 10);

		CursorManager::GetInstance()->WriteBuffer(82.0f, 22.0f, CtrlGuide[29], 10);
		CursorManager::GetInstance()->WriteBuffer(88.0f, 23.0f, CtrlGuide[30], 10);
		CursorManager::GetInstance()->WriteBuffer(86.0f, 24.0f, CtrlGuide[31], 10);

		CursorManager::GetInstance()->WriteBuffer(88.0f, 29.0f, CtrlGuide[32], 10);
		CursorManager::GetInstance()->WriteBuffer(82.0f, 30.0f, CtrlGuide[33], 10);

		CursorManager::GetInstance()->WriteBuffer(58.0f, 33.0f, CtrlGuide[34], 10);
		CursorManager::GetInstance()->WriteBuffer(58.0f, 34.0f, CtrlGuide[35], 10);
		CursorManager::GetInstance()->WriteBuffer(60.0f, 35.0f, CtrlGuide[36], 10);

		CursorManager::GetInstance()->WriteBuffer(66.0f, 39.0f, CtrlGuide[37], 10);

		CursorManager::GetInstance()->WriteBuffer(66.0f, 42.0f, CtrlGuide[38], 14);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(80 - strlen("아이템 튜토리얼") / 2, 8, ItemTuto[0], 10);
		CursorManager::GetInstance()->WriteBuffer(80 - strlen(ItemTuto[9]) / 2, 12, ItemTuto[9]);
		CursorManager::GetInstance()->WriteBuffer(80 - strlen(ItemTuto[10]) / 2, 13, ItemTuto[10]);

		CursorManager::GetInstance()->WriteBuffer(44, 18, ItemTuto[1], 14);
		CursorManager::GetInstance()->WriteBuffer(44, 19, ItemTuto[2], 14);
		CursorManager::GetInstance()->WriteBuffer(54, 18, ItemTuto[11], 14);
	
		CursorManager::GetInstance()->WriteBuffer(44, 24, ItemTuto[3], 12);
		CursorManager::GetInstance()->WriteBuffer(44, 25, ItemTuto[4], 12);
		CursorManager::GetInstance()->WriteBuffer(54, 24, ItemTuto[12], 12);
		CursorManager::GetInstance()->WriteBuffer(54, 25, ItemTuto[13], 12);
	
		CursorManager::GetInstance()->WriteBuffer(44, 30, ItemTuto[5], 9);
		CursorManager::GetInstance()->WriteBuffer(44, 31, ItemTuto[6], 9);
		CursorManager::GetInstance()->WriteBuffer(54, 30, ItemTuto[14], 9);
		CursorManager::GetInstance()->WriteBuffer(54, 31, ItemTuto[15], 9);
	
		CursorManager::GetInstance()->WriteBuffer(44, 36, ItemTuto[7], 11);
		CursorManager::GetInstance()->WriteBuffer(44, 37, ItemTuto[8], 11);
		CursorManager::GetInstance()->WriteBuffer(54, 36, ItemTuto[16], 11);

		CursorManager::GetInstance()->WriteBuffer(80 - strlen(ItemTuto[17]) / 2, 42, ItemTuto[17]);
		break;
	}
	
}

void GuideManager::Release()
{
}