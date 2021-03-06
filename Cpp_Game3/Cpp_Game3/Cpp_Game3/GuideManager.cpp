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
	Border[0]  = (char*)"忙天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天忖";
	Border[1]  = (char*)"太                                                                            太";
	Border[2]  = (char*)"太                                                                            太";
	Border[3]  = (char*)"太                                                                            太";
	Border[4]  = (char*)"太                                                                            太";
	Border[5]  = (char*)"太                                                                            太";
	Border[6]  = (char*)"太                                                                            太";
	Border[7]  = (char*)"太                                                                            太";
	Border[8]  = (char*)"太                                                                            太";
	Border[9]  = (char*)"太                                                                            太";
	Border[10] = (char*)"太                                                                            太";
	Border[11] = (char*)"太                                                                            太";
	Border[12] = (char*)"太                                                                            太";
	Border[13] = (char*)"太                                                                            太";
	Border[14] = (char*)"太                                                                            太";
	Border[15] = (char*)"太                                                                            太";
	Border[16] = (char*)"太                                                                            太";
	Border[17] = (char*)"太                                                                            太";
	Border[18] = (char*)"太                                                                            太";
	Border[19] = (char*)"太                                                                            太";
	Border[20] = (char*)"太                                                                            太";
	Border[21] = (char*)"太                                                                            太";
	Border[22] = (char*)"太                                                                            太";
	Border[23] = (char*)"太                                                                            太";
	Border[24] = (char*)"太                                                                            太";
	Border[25] = (char*)"太                                                                            太";
	Border[26] = (char*)"太                                                                            太";
	Border[27] = (char*)"太                                                                            太";
	Border[28] = (char*)"太                                                                            太";
	Border[29] = (char*)"太                                                                            太";
	Border[30] = (char*)"太                                                                            太";
	Border[31] = (char*)"太                                                                            太";
	Border[32] = (char*)"太                                                                            太";
	Border[33] = (char*)"太                                                                            太";
	Border[34] = (char*)"太                                                                            太";
	Border[35] = (char*)"太                                                                            太";
	Border[36] = (char*)"太                                                                            太";
	Border[37] = (char*)"太                                                                            太";
	Border[38] = (char*)"太                                                                            太";
	Border[39] = (char*)"戌天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天天戎";
	CtrlGuide[0] = (char*)"  _____          __            __  _____      _    __";
	CtrlGuide[1] = (char*)" / ___/__  ___  / /_________  / / / ___/__ __(_)__/ /__";
	CtrlGuide[2] = (char*)"/ /__/ _ |/ _ |/  __/ __/ _ |/ / / (_ // // / / _  / -_)";
	CtrlGuide[3] = (char*)"|___/|___/_//_/′__/_/  ′__/_/  |___/|____/_/′__/′__/";
	CtrlGuide[4] = (char*)"        忙天天忖";
	CtrlGuide[5] = (char*)"        太 W  太";
	CtrlGuide[6] = (char*)"        戌天天戎";
	CtrlGuide[7] = (char*)"忙天天忖忙天天忖忙天天忖";
	CtrlGuide[8] = (char*)"太 A  太太 S  太太 D  太";
	CtrlGuide[9] = (char*)"戌天天戎戌天天戎戌天天戎";
	CtrlGuide[10] = (char*)"        忙天天忖";
	CtrlGuide[11] = (char*)"        太 ∼ 太";
	CtrlGuide[12] = (char*)"        戌天天戎";
	CtrlGuide[13] = (char*)"忙天天忖忙天天忖忙天天忖";
	CtrlGuide[14] = (char*)"太 ９ 太太 ∪ 太太 Ⅱ 太";
	CtrlGuide[15] = (char*)"戌天天戎戌天天戎戌天天戎";
	CtrlGuide[16] = (char*)"忙天天天天天天天天天天忖";
	CtrlGuide[17] = (char*)"太       SPACE        太";
	CtrlGuide[18] = (char*)"戌天天天天天天天天天天戎";
	CtrlGuide[19] = (char*)"忙天天忖";
	CtrlGuide[20] = (char*)"太 R  太";
	CtrlGuide[21] = (char*)"戌天天戎";
	CtrlGuide[22] = (char*)"忙天天天天忖";
	CtrlGuide[23] = (char*)"太  TAB   太";
	CtrlGuide[24] = (char*)"戌天天天天戎";
	CtrlGuide[25] = (char*)"褡";
	CtrlGuide[26] = (char*)"*";
	CtrlGuide[27] = (char*)"濠っ曖 W, A, S, D 酈朝";
	CtrlGuide[28] = (char*)"陝陝 鼻, ж, 謝, 辦煎 檜翕м棲棻";
	CtrlGuide[29] = (char*)"寞щ酈煎 識掘曖 寞щ擊 褻濛м棲棻";
	CtrlGuide[30] = (char*)"嬪,嬴楚煎朝 鼻ж陝擊,";
	CtrlGuide[31] = (char*)"謝,辦朝 寞щ擊 褻瞰м棲棻";
	CtrlGuide[32] = (char*)"蝶む檜蝶 夥蒂 援腦賊";
	CtrlGuide[33] = (char*)"識掘曖 寞щ戲煎 識憲檜 嫦餌腌棲棻";
	CtrlGuide[34] = (char*)"瞳擊 籀纂п 薄熱蒂 ?僱磈炾? 蝶鑒 啪檜雖蒂 瓣選 熱 氈蝗棲棻";
	CtrlGuide[35] = (char*)"Я問 橈檜 翱樓籀纂衛 巍爾 薄熱諦 渦 號擎 啪檜雖蒂 橢蝗棲棻";
	CtrlGuide[36] = (char*)"蝶鑒 啪檜雖蒂 粕 瓣錶 鬼溘и в髦晦蒂 餌辨п 爾撮蹂 !";
	CtrlGuide[37] = (char*)"啪歜醞 TAB 酈蒂 援腦賊 詭景璽擊 碳楝褫棲棻";	
	CtrlGuide[38] = (char*)"[ R 酈蒂 援腦賊 詭景煎 給嬴骨棲棻 ]";

	ItemTuto[0]  = (char*)"嬴檜蠱 ぅ饜葬橡";
	ItemTuto[1]  = (char*)"－STATIC";
	ItemTuto[2]  = (char*)"ㄞBULLET";
	ItemTuto[3]  = (char*)"±MOLOTOV";
	ItemTuto[4]  = (char*)"↙!!!!!!!";
	ItemTuto[5]  = (char*)"↖〥〥↗";
	ItemTuto[6]  = (char*)"KF94MASK";
	ItemTuto[7]  = (char*)" ﹟BUDDY";
	ItemTuto[8]  = (char*)"dl BUDDY";
	ItemTuto[9]  = (char*)"瞪癱 醞 橾薑 衛除葆棻 夥梨薹 楠渾и 嬪纂縑憮 嬴檜蠱檜 儅撩腌棲棻";
	ItemTuto[10] = (char*)"嬴檜蠱擎 醞懈 睡斬擊 陛煎韓楝 檜翕ж貊 ?僱瞏? 堅嶸?膩?陛 瞳辨腌棲棻";
	ItemTuto[11] = (char*)"薑瞪晦 驕 : 10蟾 翕寰 嫦餌腎朝 驕檜 瞳 蹺瞳 晦棟擊 陛餵棲棻";
	ItemTuto[12] = (char*)"?倍偕? : Ы溯檜橫 醞褕 3x3曖 в萄 嬪 癱餌羹諦 瞳擊 だ惚м棲棻";
	ItemTuto[13] = (char*)"爾蝶朝 だ惚腎雖 彊堅 等嘐雖蒂 殮蝗棲棻";
	ItemTuto[14] = (char*)"葆蝶觼 : Ы溯檜橫 HP蒂 渠褐п だ惚腎朝 1啜曖 爾?ㄧ滅? 橢蝗棲棻";
	ItemTuto[15] = (char*)"爾?ㄧ? だ惚衛 Я問陽諦 葆雙陛雖煎 1蟾除 鼠瞳鼻鷓陛 腌棲棻";
	ItemTuto[16] = (char*)"幗蛤幗蛤 : 15蟾 翕寰 Ы溯檜橫曖 檜翕 樓紫陛 隸陛м棲棻";
	ItemTuto[17] = (char*)"[ R ] 酈蒂 揚楝 ?挫? ?? 啪歜 衛濛";
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
		CursorManager::GetInstance()->WriteBuffer(80 - strlen("嬴檜蠱 ぅ饜葬橡") / 2, 8, ItemTuto[0], 10);
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