#include "Story.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Story::Story() : Count(0.0f) , Time1(0)
{
	Line1 = 0.0f;
	Line2 = 0.0f;
	Line3 = 0.0f;
}

Story::~Story()
{
}


void Story::Start()
{
	Prologue[0]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[1]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[2]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[3]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[4]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[5]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::     :::::::::::";
	Prologue[6]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::         :::::::::";
	Prologue[7]  = (char*)":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::            :::::::";
	Prologue[8]  = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                 :::::";
	Prologue[9]  = (char*)":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                    :::::";
	Prologue[10] = (char*)":::::::::::::::::::::::::::::::::::: :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                            ::::";
	Prologue[11] = (char*)"::::::::::::::::::::::::::::::::       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                               :::";
	Prologue[12] = (char*)"::::::::::::::::::::::::::::::::           ::                ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                              :::";
	Prologue[13] = (char*)":::::::::::::::::::::::::::::::                               ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                          ::::";
	Prologue[14] = (char*)"::::::::::::::::::::::::::::::                                :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::         ::     ::   ::::::";
	Prologue[15] = (char*)"::::::::::::::::::::::::::::::                              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::        ::::::::::::::::::::";
	Prologue[16] = (char*)"::::::::::::::::::::::::::                               :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::          ::::::::::::::::::::";
	Prologue[17] = (char*)"::::::::::::::::::::::::                             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::    :::::::::::::::::::::::::::";
	Prologue[18] = (char*)"::::::::::::::::::::::                             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: :::::::::::::::::::::::::::::";
	Prologue[19] = (char*)"::::::::::::::::::::::                           ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::           ::::::";
	Prologue[20] = (char*)"::::::::::::::::::::::::                  :   ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::     :::::::              ::::::";
	Prologue[21] = (char*)"::::::::::::::::::::::::         :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::    ::::::::           :::::::::";
	Prologue[22] = (char*)"::::::::::::::::::::::       ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  :::::::::    ::::   :::::::::";
	Prologue[23] = (char*)":::::::::::::::::::::  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: :::::::::::::::::::";
	Prologue[24] = (char*)"::::::::::::::::::::  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[25] = (char*)":::::::::::::::::::   :::::::     ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
	Prologue[26] = (char*)"::::::::::::::::::::::::::::              ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*VVVVV*::****VVV::::::::::::::::";
	Prologue[27] = (char*)":::::::::::::::::  :::::::                ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::VMMMN$F::*MMMNNI::::::::::::::::";
	Prologue[28] = (char*)":::::::::::::::::  :::::                ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*FFVFIV::*VFVIMF::::::::::::::::";
	Prologue[29] = (char*)"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::***::::::***::::::::::::::::";
	Prologue[30] = (char*)":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::********:::::::::::::::::::::*:***::::::***::::::::::::::::";
	Prologue[31] = (char*)":::::::::::::::::**V*::****::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::***************::::::::::::VMMMM$M::VMMMNNM::::::::::::::::";
	Prologue[32] = (char*)"::::::::::::::::*MMNF:*MMNM::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::***************::::::::::::VIIIMMI::VFIIMMM::::::::::::::::";
	Prologue[33] = (char*)":::::::::::::::::**V*::****::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::********:******::::::::::::::::***::::::***::::::::::::::::";
	Prologue[34] = (char*)"::::::::::::::::***V*::**VV:::::::::::::::::::*******::::::::::::::::::::::::::::::::::::::::::::::::***************::::::::::::::::***::::::***::::::::::::::::";
	Prologue[35] = (char*)"::::::::::::::::VMMNI:*MMMM:::::::::::::::::::*******::::::::::::::::::::::::::::::::::::::::::::::::***************::::::::::::IMMMNN$::VMMMNNN::::::::::::::::";
	Prologue[36] = (char*)":::::::::::::::::****::****::::::**********:::*******::::::::::::::::::::::::::::::::::::::::::::::::*******::*********VVV***:::IMMMNN$::FMMMNN$::::::::::::::::";
	Prologue[37] = (char*)"::::::::::::::::*VVVV:*VVVV::::::*::::::::*:::*******::::::::::::::::::::::::::::::::::::::::::::::::************************V::*******::******V::::::::::::::::";
	Prologue[38] = (char*)"::::::::::::::::VFIMI:*FIMM:::::::::::::::::::*******::*****VV*******::::::::::::::::::::::::::::::::***********************VV::::::***::::::***::::::::::::::::";
	Prologue[39] = (char*)":::::::::::::::::::**::::**:::::::::::::::::::*******::MMMMMMMMMMMMMM::::::::::::::::::::::::::****::***********************VV::VVVVVII::VVVVIII::::::::::::::::";
	Prologue[40] = (char*)"::::::::::::::::*VVFF:*VVFI:::::::::::::::::::*******::MMMMMMMMMMMMMM:::::::::::::::::::::::::*******************************V::MMMMNN$::MMMMNNN::::::::::::::::";
	Prologue[41] = (char*)"::::::::::::::::VVVIM:*VFIM:::::::::::::::::::*******::VVVVVVVVVVVVVV:::::::::::::::::::::::::*************************V****V*::*****VV::****VVV::::::::::::::::";
	Prologue[42] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[43] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[44] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[45] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[46] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[47] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[48] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[49] = (char*)"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV";
	Prologue[50] = (char*)":::::::"; // Å« ±¼¶Ò Èò ºÎºÐ
	Prologue[51] = (char*)"*VVVVV*"; // Å« ±¼¶Ò »¡°£ ºÎºÐ
	Prologue[52] = (char*)"*****";	// ÀÛÀº ±¼¶Ò Èò
	Prologue[53] = (char*)"MMMMM";  // ÀÛÀº ±¼¶Ò »¡°­
	Prologue[54] = (char*)":::::::";	// »çÀÏ·Î
	Prologue[55] = (char*)":**********:";	// ²ÀÁö
	Prologue[56] = (char*)":::*:::";	// ²ÀÁö ¹Ø
	Prologue[57] = (char*)"*******"; // Áß¾Ó ¿ÞÂÊ ³ôÀÌ 8 ±âµÕ 
	Prologue[58] = (char*)"MMMMMMMMMMMMMM"; // ±âµÕ ¿· °Ç¹°
	Prologue[59] = (char*)"********"; // Áß¾Ó ¿À¸¥ÂÊ °Ç¹° ²À´ë±â
	Prologue[60] = (char*)"***************"; // ²À´ë±â2
	Prologue[61] = (char*)"************************V"; // ¸öÅë 1 
	Prologue[62] = (char*)".****::***********************VV"; // ¸öÅë 2
	Prologue[70] = (char*)"20XX³â, ¹«ºÐº°ÇÑ °³¹ß°ú È¯°æÆÄ±«·Î Áö±¸´Â È²ÆóÇØÁö°í ÀÖ½À´Ï´Ù.";
	Prologue[71] = (char*)"´ç½ÅÀº Áö±¸ ¸ê¸ÁÀ» ¹èÈÄ¿¡¼­ Á¶Á¾ÇÏ°í ÀÖ´Â µÎ ¸¶³àÀÇ Á¸Àç¸¦ ÆÄ¾ÇÇß½À´Ï´Ù.";
	Prologue[72] = (char*)"»ç¾ÇÇÑ ¸¶³à¿Í ±×µéÀÇ ¼öÇÏ ¹Ì¼¼¸ÕÁöµéÀ» ¹°¸®Ä¡°í Áö±¸¸¦ ÁöÄÑÁÖ¼¼¿ä.";
	Prologue[80] = (char*)" ";

	Count = 0;
	Line1 = 62;
	Line2 = 73;
	Line3 = 66;
	Time1 = GetTickCount64();
}

void Story::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if ((dwKey & KEY_RETURN && Time1 + 100 < GetTickCount64()) || (Line3 == 0 && Time1 + 12000 < GetTickCount64()))
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);

	if (Time1 + 1500 <= GetTickCount64() && Count < 12)
		Count += 0.5;
	
	if (Time1 + 1500 <= GetTickCount64() && Count == 12 && Line1 > 0)
		Line1--;

	if (Time1 + 1500 <= GetTickCount64() && Line1 == 0 && Line2 > 0)
		Line2--;

	if (Time1 + 1500 <= GetTickCount64() && Line2 == 0 && Line3 > 0)
		Line3--;
}

void Story::Render()
{
	if (Time1 + 1500 > GetTickCount64())
	{
		for (int i = 0; i < 50; ++i)
			CursorManager::GetInstance()->WriteBuffer(0.0f, 1.0f + i, Prologue[i], 8);
		for (int i = 42; i < 50; ++i)
			CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f + i, Prologue[i], 6);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 24.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 24.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 25.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 25.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 26.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 26.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 27.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 27.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 28.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 28.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 29.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 29.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 30.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 30.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 31.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 31.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 32.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 32.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 33.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 33.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 34.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 34.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 35.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 35.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 36.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 36.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 37.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 37.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 38.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 38.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 39.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 39.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 40.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 40.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 41.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 41.0f, Prologue[51], 12);

		CursorManager::GetInstance()->WriteBuffer(16.0f, 30.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 30.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 31.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 31.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 32.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 32.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 33.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 33.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 34.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 34.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 35.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 35.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 36.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 36.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 37.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 37.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 38.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 38.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 39.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 39.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 40.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 40.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 41.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 41.0f, Prologue[53], 12);

		CursorManager::GetInstance()->WriteBuffer(32.0f, 36.0f, Prologue[55], 7);
		CursorManager::GetInstance()->WriteBuffer(30.0f, 37.0f, Prologue[56], 7);
		CursorManager::GetInstance()->WriteBuffer(39.0f, 37.0f, Prologue[56], 7);
		CursorManager::GetInstance()->WriteBuffer(30.0f, 38.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(39.0f, 38.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(30.0f, 39.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(39.0f, 39.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(30.0f, 40.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(39.0f, 40.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(30.0f, 41.0f, Prologue[54], 7);
		CursorManager::GetInstance()->WriteBuffer(39.0f, 41.0f, Prologue[54], 7);

		CursorManager::GetInstance()->WriteBuffer(46.0f, 34.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 35.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 36.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 37.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 38.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 39.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 40.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 41.0f, Prologue[57], 14);

		CursorManager::GetInstance()->WriteBuffer(55.0f, 38.0f, Prologue[58], 14);
		CursorManager::GetInstance()->WriteBuffer(55.0f, 39.0f, Prologue[58], 14);
		CursorManager::GetInstance()->WriteBuffer(55.0f, 40.0f, Prologue[58], 14);
		CursorManager::GetInstance()->WriteBuffer(55.0f, 41.0f, Prologue[58], 14);

		CursorManager::GetInstance()->WriteBuffer(101.0f, 30.0f, Prologue[59], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 31.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 32.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 33.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 34.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 35.0f, Prologue[60], 14);

		CursorManager::GetInstance()->WriteBuffer(101.0f, 36.0f, Prologue[61], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 37.0f, Prologue[61], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 38.0f, Prologue[61], 14);

		CursorManager::GetInstance()->WriteBuffer(94.0f, 39.0f, Prologue[62], 14);
		CursorManager::GetInstance()->WriteBuffer(94.0f, 40.0f, Prologue[62], 14);
		CursorManager::GetInstance()->WriteBuffer(94.0f, 41.0f, Prologue[62], 14);
	}
		
	if (Time1 + 1500 <= GetTickCount64())
	{
		for (int i = Count; i < 50 - Count; ++i)
			CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f + i, Prologue[i], 8);
		for (int i = Count; i < 8; ++i)
			CursorManager::GetInstance()->WriteBuffer(0.0f, 49.0f - i, Prologue[49], 6);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 24.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 24.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 25.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 25.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 26.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 26.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 27.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 27.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 28.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 28.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 29.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 29.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 30.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 30.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 31.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 31.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 32.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 32.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 33.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 33.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 34.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 34.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 35.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 35.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 36.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 36.0f, Prologue[51], 12);
		CursorManager::GetInstance()->WriteBuffer(128.0f, 37.0f, Prologue[50]);
		CursorManager::GetInstance()->WriteBuffer(137.0f, 37.0f, Prologue[50]);

		CursorManager::GetInstance()->WriteBuffer(16.0f, 30.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 30.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 31.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 31.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 32.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 32.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 33.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 33.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 34.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 34.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 35.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 35.0f, Prologue[52]);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 36.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 36.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(16.0f, 37.0f, Prologue[53], 12);
		CursorManager::GetInstance()->WriteBuffer(22.0f, 37.0f, Prologue[53], 12);

		CursorManager::GetInstance()->WriteBuffer(32.0f, 36.0f, Prologue[55], 7);
		CursorManager::GetInstance()->WriteBuffer(30.0f, 37.0f, Prologue[56], 7);
		CursorManager::GetInstance()->WriteBuffer(39.0f, 37.0f, Prologue[56], 7);

		CursorManager::GetInstance()->WriteBuffer(46.0f, 34.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 35.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 36.0f, Prologue[57], 14);
		CursorManager::GetInstance()->WriteBuffer(46.0f, 37.0f, Prologue[57], 14);		

		CursorManager::GetInstance()->WriteBuffer(101.0f, 30.0f, Prologue[59], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 31.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 32.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 33.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 34.0f, Prologue[60], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 35.0f, Prologue[60], 14);

		CursorManager::GetInstance()->WriteBuffer(101.0f, 36.0f, Prologue[61], 14);
		CursorManager::GetInstance()->WriteBuffer(101.0f, 37.0f, Prologue[61], 14);	

		if (Count < 12)
		{
			CursorManager::GetInstance()->WriteBuffer(128.0f, 38.0f, Prologue[50]);
			CursorManager::GetInstance()->WriteBuffer(137.0f, 38.0f, Prologue[50]);

			CursorManager::GetInstance()->WriteBuffer(16.0f, 38.0f, Prologue[52]);
			CursorManager::GetInstance()->WriteBuffer(22.0f, 38.0f, Prologue[52]);

			CursorManager::GetInstance()->WriteBuffer(30.0f, 38.0f, Prologue[54], 7);
			CursorManager::GetInstance()->WriteBuffer(39.0f, 38.0f, Prologue[54], 7);
			
			CursorManager::GetInstance()->WriteBuffer(46.0f, 38.0f, Prologue[57], 14);
			CursorManager::GetInstance()->WriteBuffer(55.0f, 38.0f, Prologue[58], 14);

			CursorManager::GetInstance()->WriteBuffer(101.0f, 38.0f, Prologue[61], 14);
		}
		if (Count < 11)
		{
			CursorManager::GetInstance()->WriteBuffer(128.0f, 39.0f, Prologue[51], 12);
			CursorManager::GetInstance()->WriteBuffer(137.0f, 39.0f, Prologue[51], 12);

			CursorManager::GetInstance()->WriteBuffer(16.0f, 39.0f, Prologue[52]);
			CursorManager::GetInstance()->WriteBuffer(22.0f, 39.0f, Prologue[52]);

			CursorManager::GetInstance()->WriteBuffer(30.0f, 39.0f, Prologue[54], 7);
			CursorManager::GetInstance()->WriteBuffer(39.0f, 39.0f, Prologue[54], 7);			

			CursorManager::GetInstance()->WriteBuffer(46.0f, 39.0f, Prologue[57], 14);
			CursorManager::GetInstance()->WriteBuffer(55.0f, 39.0f, Prologue[58], 14);

			CursorManager::GetInstance()->WriteBuffer(94.0f, 39.0f, Prologue[62], 14);
		}
		if (Count < 10)
		{
			CursorManager::GetInstance()->WriteBuffer(128.0f, 40.0f, Prologue[51], 12);
			CursorManager::GetInstance()->WriteBuffer(137.0f, 40.0f, Prologue[51], 12);

			CursorManager::GetInstance()->WriteBuffer(16.0f, 40.0f, Prologue[53], 12);
			CursorManager::GetInstance()->WriteBuffer(22.0f, 40.0f, Prologue[53], 12);

			CursorManager::GetInstance()->WriteBuffer(30.0f, 40.0f, Prologue[54], 7);
			CursorManager::GetInstance()->WriteBuffer(39.0f, 40.0f, Prologue[54], 7);
			
			CursorManager::GetInstance()->WriteBuffer(46.0f, 40.0f, Prologue[57], 14);
			CursorManager::GetInstance()->WriteBuffer(55.0f, 40.0f, Prologue[58], 14);

			CursorManager::GetInstance()->WriteBuffer(94.0f, 40.0f, Prologue[62], 14);
		}
		if (Count < 9)
		{
			CursorManager::GetInstance()->WriteBuffer(128.0f, 41.0f, Prologue[51], 12);
			CursorManager::GetInstance()->WriteBuffer(137.0f, 41.0f, Prologue[51], 12);

			CursorManager::GetInstance()->WriteBuffer(16.0f, 41.0f, Prologue[53], 12);
			CursorManager::GetInstance()->WriteBuffer(22.0f, 41.0f, Prologue[53], 12);

			CursorManager::GetInstance()->WriteBuffer(30.0f, 41.0f, Prologue[54], 7);
			CursorManager::GetInstance()->WriteBuffer(39.0f, 41.0f, Prologue[54], 7);
			
			CursorManager::GetInstance()->WriteBuffer(46.0f, 41.0f, Prologue[57], 14);
			CursorManager::GetInstance()->WriteBuffer(55.0f, 41.0f, Prologue[58], 14);

			CursorManager::GetInstance()->WriteBuffer(94.0f, 41.0f, Prologue[62], 14);
		}
		
		if (Count > 11)
		{
			CursorManager::GetInstance()->WriteBuffer(80 - strlen(Prologue[70]) / 2, 40.0f, Prologue[70]);
			CursorManager::GetInstance()->WriteBuffer(80 - strlen(Prologue[71]) / 2, 43.0f, Prologue[71]);
			CursorManager::GetInstance()->WriteBuffer(80 - strlen(Prologue[72]) / 2, 46.0f, Prologue[72]);

			for (int i = 0; i < Line1; i++)
				CursorManager::GetInstance()->WriteBuffer(110 - i, 40.0f, Prologue[80]);
		
			for (int i = 0; i < Line2; i++)
				CursorManager::GetInstance()->WriteBuffer(115 - i, 43.0f, Prologue[80]);
		
			for (int i = 0; i < Line3; i++)
				CursorManager::GetInstance()->WriteBuffer(112 - i, 46.0f, Prologue[80]);	

		}	
		CursorManager::GetInstance()->WriteBuffer(134.0f, 49.0f, (char*)"Press [ Enter ] to Skip");
	}
}

void Story::Release()
{
}