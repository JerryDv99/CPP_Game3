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