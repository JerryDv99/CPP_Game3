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
	Border[0]  = (char*)"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�";
	Border[1]  = (char*)"��                                                                            ��";
	Border[2]  = (char*)"��                                                                            ��";
	Border[3]  = (char*)"��                                                                            ��";
	Border[4]  = (char*)"��                                                                            ��";
	Border[5]  = (char*)"��                                                                            ��";
	Border[6]  = (char*)"��                                                                            ��";
	Border[7]  = (char*)"��                                                                            ��";
	Border[8]  = (char*)"��                                                                            ��";
	Border[9]  = (char*)"��                                                                            ��";
	Border[10] = (char*)"��                                                                            ��";
	Border[11] = (char*)"��                                                                            ��";
	Border[12] = (char*)"��                                                                            ��";
	Border[13] = (char*)"��                                                                            ��";
	Border[14] = (char*)"��                                                                            ��";
	Border[15] = (char*)"��                                                                            ��";
	Border[16] = (char*)"��                                                                            ��";
	Border[17] = (char*)"��                                                                            ��";
	Border[18] = (char*)"��                                                                            ��";
	Border[19] = (char*)"��                                                                            ��";
	Border[20] = (char*)"��                                                                            ��";
	Border[21] = (char*)"��                                                                            ��";
	Border[22] = (char*)"��                                                                            ��";
	Border[23] = (char*)"��                                                                            ��";
	Border[24] = (char*)"��                                                                            ��";
	Border[25] = (char*)"��                                                                            ��";
	Border[26] = (char*)"��                                                                            ��";
	Border[27] = (char*)"��                                                                            ��";
	Border[28] = (char*)"��                                                                            ��";
	Border[29] = (char*)"��                                                                            ��";
	Border[30] = (char*)"��                                                                            ��";
	Border[31] = (char*)"��                                                                            ��";
	Border[32] = (char*)"��                                                                            ��";
	Border[33] = (char*)"��                                                                            ��";
	Border[34] = (char*)"��                                                                            ��";
	Border[35] = (char*)"��                                                                            ��";
	Border[36] = (char*)"��                                                                            ��";
	Border[37] = (char*)"��                                                                            ��";
	Border[38] = (char*)"��                                                                            ��";
	Border[39] = (char*)"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�";
	CtrlGuide[0] = (char*)"  _____          __            __  _____      _    __";
	CtrlGuide[1] = (char*)" / ___/__  ___  / /_________  / / / ___/__ __(_)__/ /__";
	CtrlGuide[2] = (char*)"/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)";
	CtrlGuide[3] = (char*)"|___/|___/_//_/��__/_/  ��__/_/  |___/|____/_/��__/��__/";
	CtrlGuide[4] = (char*)"        ���ѤѦ�";
	CtrlGuide[5] = (char*)"        �� W  ��";
	CtrlGuide[6] = (char*)"        ���ѤѦ�";
	CtrlGuide[7] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	CtrlGuide[8] = (char*)"�� A  �Ӥ� S  �Ӥ� D  ��";
	CtrlGuide[9] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	CtrlGuide[10] = (char*)"        ���ѤѦ�";
	CtrlGuide[11] = (char*)"        �� �� ��";
	CtrlGuide[12] = (char*)"        ���ѤѦ�";
	CtrlGuide[13] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	CtrlGuide[14] = (char*)"�� �� �Ӥ� �� �Ӥ� �� ��";
	CtrlGuide[15] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	CtrlGuide[16] = (char*)"���ѤѤѤѤѤѤѤѤѤѦ�";
	CtrlGuide[17] = (char*)"��       SPACE        ��";
	CtrlGuide[18] = (char*)"���ѤѤѤѤѤѤѤѤѤѦ�";
	CtrlGuide[19] = (char*)"���ѤѦ�";
	CtrlGuide[20] = (char*)"�� R  ��";
	CtrlGuide[21] = (char*)"���ѤѦ�";
	CtrlGuide[22] = (char*)"���ѤѤѤѦ�";
	CtrlGuide[23] = (char*)"��  TAB   ��";
	CtrlGuide[24] = (char*)"���ѤѤѤѦ�";
	CtrlGuide[25] = (char*)"��";
	CtrlGuide[26] = (char*)"*";
	CtrlGuide[27] = (char*)"������ W, A, S, D Ű��";
	CtrlGuide[28] = (char*)"���� ��, ��, ��, ��� �̵��մϴ�";
	CtrlGuide[29] = (char*)"����Ű�� �ѱ��� ������ �����մϴ�";
	CtrlGuide[30] = (char*)"��,�Ʒ��δ� ���ϰ���,";
	CtrlGuide[31] = (char*)"��,��� ������ �����մϴ�";
	CtrlGuide[32] = (char*)"�����̽� �ٸ� ������";
	CtrlGuide[33] = (char*)"�ѱ��� �������� �Ѿ��� �߻�˴ϴ�";
	CtrlGuide[34] = (char*)"���� óġ�� ������ ȹ���ϰ� ��ų �������� ä�� �� �ֽ��ϴ�";
	CtrlGuide[35] = (char*)"�ǰ� ���� ����óġ�� �޺� ������ �� ���� �������� ����ϴ�";
	CtrlGuide[36] = (char*)"��ų �������� �� ä�� ������ �ʻ�⸦ ����� ������ !";
	CtrlGuide[37] = (char*)"������ TAB Ű�� ������ �޴�â�� �ҷ��ɴϴ�";	
	CtrlGuide[38] = (char*)"[ R Ű�� ������ �޴��� ���ư��ϴ� ]";

	ItemTuto[0]  = (char*)"������ Ʃ�丮��";
	ItemTuto[1]  = (char*)"��STATIC";
	ItemTuto[2]  = (char*)"��BULLET";
	ItemTuto[3]  = (char*)"��MOLOTOV";
	ItemTuto[4]  = (char*)"��!!!!!!!";
	ItemTuto[5]  = (char*)"���Ǣǡ�";
	ItemTuto[6]  = (char*)"KF94MASK";
	ItemTuto[7]  = (char*)" ��BUDDY";
	ItemTuto[8]  = (char*)"dl BUDDY";
	ItemTuto[9]  = (char*)"���� �� ���� �ð����� �ٱ��� ������ ��ġ���� �������� �����˴ϴ�";
	ItemTuto[10] = (char*)"�������� �߾� �α��� �������� �̵��ϸ� ȹ��� ����ȿ���� ����˴ϴ�";
	ItemTuto[11] = (char*)"������ ź : 10�� ���� �߻�Ǵ� ź�� �� ���� ����� �����ϴ�";
	ItemTuto[12] = (char*)"ȭ���� : �÷��̾� �߽� 3x3�� �ʵ� �� ����ü�� ���� �ı��մϴ�";
	ItemTuto[13] = (char*)"������ �ı����� �ʰ� �������� �Խ��ϴ�";
	ItemTuto[14] = (char*)"����ũ : �÷��̾� HP�� ����� �ı��Ǵ� 1���� ��ȣ���� ����ϴ�";
	ItemTuto[15] = (char*)"��ȣ�� �ı��� �ǰݶ��� ���������� 1�ʰ� �������°� �˴ϴ�";
	ItemTuto[16] = (char*)"������� : 15�� ���� �÷��̾��� �̵� �ӵ��� �����մϴ�";
	ItemTuto[17] = (char*)"[ R ] Ű�� ���� Ȯ�� �� ���� ����";
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
		CursorManager::GetInstance()->WriteBuffer(80 - strlen("������ Ʃ�丮��") / 2, 8, ItemTuto[0], 10);
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