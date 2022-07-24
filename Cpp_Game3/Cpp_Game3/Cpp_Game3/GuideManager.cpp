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
	GuideScene[0]  = (char*)"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�";
	GuideScene[1]  = (char*)"��                                                                            ��";
	GuideScene[2]  = (char*)"��                                                                            ��";
	GuideScene[3]  = (char*)"��                                                                            ��";
	GuideScene[4]  = (char*)"��                                                                            ��";
	GuideScene[5]  = (char*)"��                                                                            ��";
	GuideScene[6]  = (char*)"��                                                                            ��";
	GuideScene[7]  = (char*)"��                                                                            ��";
	GuideScene[8]  = (char*)"��                                                                            ��";
	GuideScene[9]  = (char*)"��                                                                            ��";
	GuideScene[10] = (char*)"��                                                                            ��";
	GuideScene[11] = (char*)"��                                                                            ��";
	GuideScene[12] = (char*)"��                                                                            ��";
	GuideScene[13] = (char*)"��                                                                            ��";
	GuideScene[14] = (char*)"��                                                                            ��";
	GuideScene[15] = (char*)"��                                                                            ��";
	GuideScene[16] = (char*)"��                                                                            ��";
	GuideScene[17] = (char*)"��                                                                            ��";
	GuideScene[18] = (char*)"��                                                                            ��";
	GuideScene[19] = (char*)"��                                                                            ��";
	GuideScene[20] = (char*)"��                                                                            ��";
	GuideScene[21] = (char*)"��                                                                            ��";
	GuideScene[22] = (char*)"��                                                                            ��";
	GuideScene[23] = (char*)"��                                                                            ��";
	GuideScene[24] = (char*)"��                                                                            ��";
	GuideScene[25] = (char*)"��                                                                            ��";
	GuideScene[26] = (char*)"��                                                                            ��";
	GuideScene[27] = (char*)"��                                                                            ��";
	GuideScene[28] = (char*)"��                                                                            ��";
	GuideScene[29] = (char*)"��                                                                            ��";
	GuideScene[30] = (char*)"��                                                                            ��";
	GuideScene[31] = (char*)"��                                                                            ��";
	GuideScene[32] = (char*)"��                                                                            ��";
	GuideScene[33] = (char*)"��                                                                            ��";
	GuideScene[34] = (char*)"��                                                                            ��";
	GuideScene[35] = (char*)"��                                                                            ��";
	GuideScene[36] = (char*)"��                                                                            ��";
	GuideScene[37] = (char*)"��                                                                            ��";
	GuideScene[38] = (char*)"��                                                                            ��";
	GuideScene[39] = (char*)"���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѦ�";
	GuideScene[40] = (char*)"  _____          __            __  _____      _    __";
	GuideScene[41] = (char*)" / ___/__  ___  / /_________  / / / ___/__ __(_)__/ /__";
	GuideScene[42] = (char*)"/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)";
	GuideScene[43] = (char*)"|___/|___/_//_/��__/_/  ��__/_/  |___/|____/_/��__/��__/";
	GuideScene[44] = (char*)"        ���ѤѦ�";
	GuideScene[45] = (char*)"        �� W  ��";
	GuideScene[46] = (char*)"        ���ѤѦ�";
	GuideScene[47] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	GuideScene[48] = (char*)"�� A  �Ӥ� S  �Ӥ� D  ��";
	GuideScene[49] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	GuideScene[50] = (char*)"        ���ѤѦ�";
	GuideScene[51] = (char*)"        �� �� ��";
	GuideScene[52] = (char*)"        ���ѤѦ�";
	GuideScene[53] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	GuideScene[54] = (char*)"�� �� �Ӥ� �� �Ӥ� �� ��";
	GuideScene[55] = (char*)"���ѤѦ����ѤѦ����ѤѦ�";
	GuideScene[56] = (char*)"���ѤѤѤѤѤѤѤѤѤѦ�";
	GuideScene[57] = (char*)"��       SPACE        ��";
	GuideScene[58] = (char*)"���ѤѤѤѤѤѤѤѤѤѦ�";
	GuideScene[59] = (char*)"���ѤѦ�";
	GuideScene[60] = (char*)"�� R  ��";
	GuideScene[61] = (char*)"���ѤѦ�";
	GuideScene[62] = (char*)"���ѤѤѤѦ�";
	GuideScene[63] = (char*)"��  TAB   ��";
	GuideScene[64] = (char*)"���ѤѤѤѦ�";
	GuideScene[65] = (char*)"��";
	GuideScene[66] = (char*)"*";
	GuideScene[67] = (char*)"������ W, A, S, D Ű��";
	GuideScene[68] = (char*)"���� ��, ��, ��, ��� �̵��մϴ�";
	GuideScene[69] = (char*)"����Ű�� �ѱ��� ������ �����մϴ�";
	GuideScene[70] = (char*)"��,�Ʒ��δ� ���ϰ���,";
	GuideScene[71] = (char*)"��,��� ������ �����մϴ�";
	GuideScene[72] = (char*)"�����̽� �ٸ� ������";
	GuideScene[73] = (char*)"�ѱ��� �������� �Ѿ��� �߻�˴ϴ�";
	GuideScene[74] = (char*)"���� óġ�� ������ ȹ���ϰ� ��ų �������� ä�� �� �ֽ��ϴ�";
	GuideScene[75] = (char*)"�ǰ� ���� ����óġ�� �޺� ������ �� ���� �������� ����ϴ�";
	GuideScene[76] = (char*)"��ų �������� �� ä�� ������ �ʻ�⸦ ����� ������ !";
	GuideScene[77] = (char*)"������ TAB Ű�� ������ �޴�â�� �ҷ��ɴϴ�";	
	GuideScene[78] = (char*)"[ R Ű�� ������ �޴��� ���ư��ϴ� ]";
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