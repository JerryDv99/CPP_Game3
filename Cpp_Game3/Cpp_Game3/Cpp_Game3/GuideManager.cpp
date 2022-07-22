#include "GuideManager.h"
#include "CursorManager.h"

GuideManager* GuideManager::Instance = nullptr;

GuideManager::GuideManager()
{
}

GuideManager::~GuideManager()
{
}

void GuideManager::Start()
{
	GuideScene[0]  = (char*)"忙天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天忖";
	GuideScene[1]  = (char*)"太                                                                            太";
	GuideScene[2]  = (char*)"太                                                                            太";
	GuideScene[3]  = (char*)"太                                                                            太";
	GuideScene[4]  = (char*)"太                                                                            太";
	GuideScene[5]  = (char*)"太                                                                            太";
	GuideScene[6]  = (char*)"太                                                                            太";
	GuideScene[7]  = (char*)"太                                                                            太";
	GuideScene[8]  = (char*)"太                                                                            太";
	GuideScene[9]  = (char*)"太                                                                            太";
	GuideScene[10] = (char*)"太                                                                            太";
	GuideScene[11] = (char*)"太                                                                            太";
	GuideScene[12] = (char*)"太                                                                            太";
	GuideScene[13] = (char*)"太                                                                            太";
	GuideScene[14] = (char*)"太                                                                            太";
	GuideScene[15] = (char*)"太                                                                            太";
	GuideScene[16] = (char*)"太                                                                            太";
	GuideScene[17] = (char*)"太                                                                            太";
	GuideScene[18] = (char*)"太                                                                            太";
	GuideScene[19] = (char*)"太                                                                            太";
	GuideScene[20] = (char*)"太                                                                            太";
	GuideScene[21] = (char*)"太                                                                            太";
	GuideScene[22] = (char*)"太                                                                            太";
	GuideScene[23] = (char*)"太                                                                            太";
	GuideScene[24] = (char*)"太                                                                            太";
	GuideScene[25] = (char*)"太                                                                            太";
	GuideScene[26] = (char*)"太                                                                            太";
	GuideScene[27] = (char*)"太                                                                            太";
	GuideScene[28] = (char*)"太                                                                            太";
	GuideScene[29] = (char*)"太                                                                            太";
	GuideScene[30] = (char*)"太                                                                            太";
	GuideScene[31] = (char*)"太                                                                            太";
	GuideScene[32] = (char*)"太                                                                            太";
	GuideScene[33] = (char*)"太                                                                            太";
	GuideScene[34] = (char*)"太                                                                            太";
	GuideScene[35] = (char*)"太                                                                            太";
	GuideScene[36] = (char*)"太                                                                            太";
	GuideScene[37] = (char*)"太                                                                            太";
	GuideScene[38] = (char*)"太                                                                            太";
	GuideScene[39] = (char*)"戌天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天戎";
}

void GuideManager::Update()
{
}

void GuideManager::Render()
{
	for (int i = 0; i < 40; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(40.0f, 5.0f + i, GuideScene[i]);
	}
}

void GuideManager::Release()
{
}