#include "UIManager.h"
#include "InputManager.h"
#include "CursorManager.h"


UIManager* UIManager::Instance = nullptr;

UIManager::UIManager()
{

}

UIManager::~UIManager()
{
}

void UIManager::WriteUI(float _x, float _y, char* _str, int _Color)
{
	CursorManager::GetInstance()->WriteBuffer(_x, _y, _str, _Color);
}

void UIManager::Start()
{
	Border[0]  = (char*)"__________________________________";
	Border[1]  = (char*)"-�� ______________________________ ��-";
	Border[2]  = (char*)"�� -��                            ��- ��";
	Border[3]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[4]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[5]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[6]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[7]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[8]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[9]  = (char*)"�Ӥ�                                �Ӥ�";
	Border[10] = (char*)"�Ӥ�                                �Ӥ�";
	Border[11] = (char*)"�Ӥ�                                �Ӥ�";
	Border[12] = (char*)"�Ӥ�                                �Ӥ�";
	Border[13] = (char*)"�Ӥ�                                �Ӥ�";
	Border[14] = (char*)"�Ӥ�                                �Ӥ�";
	Border[15] = (char*)"�Ӥ�                                �Ӥ�";
	Border[16] = (char*)"�Ӥ�                                �Ӥ�";
	Border[17] = (char*)"�Ӥ�                                �Ӥ�";
	Border[18] = (char*)"�Ӥ�                                �Ӥ�";
	Border[19] = (char*)"�Ӥ�                                �Ӥ�";
	Border[20] = (char*)"�Ӥ�                                �Ӥ�";
	Border[21] = (char*)"�Ӥ�                                �Ӥ�";
	Border[22] = (char*)"�Ӥ�                                �Ӥ�";
	Border[23] = (char*)"�Ӥ�                                �Ӥ�";
	Border[24] = (char*)"�Ӥ�                                �Ӥ�";
	Border[25] = (char*)"�Ӥ�                                �Ӥ�";
	Border[26] = (char*)"�Ӥ�                                �Ӥ�";
	Border[27] = (char*)"�Ӥ�                                �Ӥ�";
	Border[28] = (char*)"�Ӥ�                                �Ӥ�";
	Border[29] = (char*)"�Ӥ�                                �Ӥ�";
	Border[30] = (char*)"�Ӥ�                                �Ӥ�";
	Border[31] = (char*)"�Ӥ�                                �Ӥ�";
	Border[32] = (char*)"�Ӥ�                                �Ӥ�";
	Border[33] = (char*)"�Ӥ�                                �Ӥ�";
	Border[34] = (char*)"�Ӥ�                                �Ӥ�";
	Border[35] = (char*)"�Ӥ�                                �Ӥ�";
	Border[36] = (char*)"�Ӥ�                                �Ӥ�";
	Border[37] = (char*)"�Ӥ�                                �Ӥ�";
	Border[38] = (char*)"�Ӥ�                                �Ӥ�";
	Border[39] = (char*)"�Ӥ�                                �Ӥ�";
	Border[40] = (char*)"�Ӥ�                                �Ӥ�";
	Border[41] = (char*)"�Ӥ�                                �Ӥ�";
	Border[42] = (char*)"�Ӥ�                                �Ӥ�";
	Border[43] = (char*)"�Ӥ�                                �Ӥ�";
	Border[44] = (char*)"�Ӥ�                                �Ӥ�";
	Border[45] = (char*)"�Ӥ�                                �Ӥ�";
	Border[46] = (char*)"�Ӥ�                                �Ӥ�";
	Border[47] = (char*)"�� -��                            ��- ��";
	Border[48] = (char*)"-�� ------------------------------ ��-";
	Border[49] = (char*)"----------------------------------";
}

void UIManager::Update()
{
}

void UIManager::Render()
{
	for (int i = 0; i < 50; ++i)
	{
		if (i == 0 || i == 49)
			CursorManager::GetInstance()->WriteBuffer(123, 0 + i, Border[i]);
		else if (i == 1 || i == 48)
			CursorManager::GetInstance()->WriteBuffer(121, 0 + i, Border[i]);
		else
			CursorManager::GetInstance()->WriteBuffer(120, 0 + i, Border[i]);
	}
}

void UIManager::Release()
{
}