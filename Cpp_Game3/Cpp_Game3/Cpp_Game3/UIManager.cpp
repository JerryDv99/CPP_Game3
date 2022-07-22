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
	Border[1]  = (char*)"-Ε ______________________________ Ζ-";
	Border[2]  = (char*)"び -Ε                            Ζ- び";
	Border[3]  = (char*)"びび                                びび";
	Border[4]  = (char*)"びび                                びび";
	Border[5]  = (char*)"びび                                びび";
	Border[6]  = (char*)"びび                                びび";
	Border[7]  = (char*)"びび                                びび";
	Border[8]  = (char*)"びび                                びび";
	Border[9]  = (char*)"びび                                びび";
	Border[10] = (char*)"びび                                びび";
	Border[11] = (char*)"びび                                びび";
	Border[12] = (char*)"びび                                びび";
	Border[13] = (char*)"びび                                びび";
	Border[14] = (char*)"びび                                びび";
	Border[15] = (char*)"びび                                びび";
	Border[16] = (char*)"びび                                びび";
	Border[17] = (char*)"びび                                びび";
	Border[18] = (char*)"びび                                びび";
	Border[19] = (char*)"びび                                びび";
	Border[20] = (char*)"びび                                びび";
	Border[21] = (char*)"びび                                びび";
	Border[22] = (char*)"びび                                びび";
	Border[23] = (char*)"びび                                びび";
	Border[24] = (char*)"びび                                びび";
	Border[25] = (char*)"びび                                びび";
	Border[26] = (char*)"びび                                びび";
	Border[27] = (char*)"びび                                びび";
	Border[28] = (char*)"びび                                びび";
	Border[29] = (char*)"びび                                びび";
	Border[30] = (char*)"びび                                びび";
	Border[31] = (char*)"びび                                びび";
	Border[32] = (char*)"びび                                びび";
	Border[33] = (char*)"びび                                びび";
	Border[34] = (char*)"びび                                びび";
	Border[35] = (char*)"びび                                びび";
	Border[36] = (char*)"びび                                びび";
	Border[37] = (char*)"びび                                びび";
	Border[38] = (char*)"びび                                びび";
	Border[39] = (char*)"びび                                びび";
	Border[40] = (char*)"びび                                びび";
	Border[41] = (char*)"びび                                びび";
	Border[42] = (char*)"びび                                びび";
	Border[43] = (char*)"びび                                びび";
	Border[44] = (char*)"びび                                びび";
	Border[45] = (char*)"びび                                びび";
	Border[46] = (char*)"びび                                びび";
	Border[47] = (char*)"び -Δ                            Γ- び";
	Border[48] = (char*)"-Δ ------------------------------ Γ-";
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