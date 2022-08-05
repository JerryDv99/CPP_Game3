#include "Kirby.h"
#include "CursorManager.h"

Kirby::Kirby() : Time(0)
{
}

Kirby::~Kirby()
{
}


void Kirby::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(10.0f, 8.0f);

	Target = nullptr;
	Speed = 1.0f;

	Kirby1[0]  = (char*)":::";
	Kirby1[1]  = (char*)":::::";
	Kirby1[2]  = (char*)"::::::";
	Kirby1[3]  = (char*)":::********";
	Kirby1[4]  = (char*)"******* *****";
	Kirby1[5]  = (char*)"*******  ** ***";
	Kirby1[6]  = (char*)"******** **  ***";
	Kirby1[7]  = (char*)"***********  ****";
	Kirby1[8]  = (char*)"*********   *******";
	Kirby1[9]  = (char*)"********** *********";
	Kirby1[10] = (char*)"************     **";
	Kirby1[11] = (char*)"**********";
	Kirby1[12] = (char*)"*********";
	Kirby1[13] = (char*)"********";
	Kirby1[14] = (char*)"*******";
	Kirby1[15] = (char*)"A";
	Kirby1[16] = (char*)"$I";
	Kirby1[17] = (char*)"Q";
	Kirby1[18] = (char*)"N";
	Kirby1[19] = (char*)"IO";
	Kirby1[20] = (char*)"UI";
	Kirby1[21] = (char*)"VIV";
	Kirby1[22] = (char*)"V";
	Kirby1[23] = (char*)"VVVVV";
	Kirby1[24] = (char*)"VVVVVVVV";
	Kirby1[25] = (char*)"VVVVVVVFV";
	Kirby1[26] = (char*)"VVVVVFFIIV";
	Kirby1[27] = (char*)"VVFFIIMMV*";
	Kirby1[28] = (char*)"*VVVIIV*VFIMMI*";
	Kirby1[29] = (char*)"VVVIMV ******";
	Kirby1[30] = (char*)"*VVIM*";
	Kirby1[31] = (char*)"**V**";
	Kirby1[32] = (char*)"***";

	Kirby2[0] = (char*)":::::::::::";
	Kirby2[1] = (char*)"::::::::**::::::";
	Kirby2[2] = (char*)"::*:::::::V**::V*::::";
	Kirby2[3] = (char*)"::::::***:::::::MVF::V**::::";
	Kirby2[4] = (char*)":***:*****:::::::I$M::V$F::::::";
	Kirby2[5] = (char*)"*********::::***:*IV:::IF::::::*:";
	Kirby2[6] = (char*)"*********::::***::*::::**:***::**:";
	Kirby2[7] = (char*)"*********:::::::::::O:::::**:::**";
	Kirby2[8] = (char*)"********:::::::::::::::::::::**:";
	Kirby2[9] = (char*)"*********::::::::::::::::::::**:";
	Kirby2[10] = (char*)"**********:::::::::::::::::::**:";
	Kirby2[11] = (char*)"************::::::::::::::::***:";
	Kirby2[12] = (char*)"***************::::::::::******:";
	Kirby2[13] = (char*)"*******************************:";
	Kirby2[14] = (char*)"*******************************";
	Kirby2[15] = (char*)"*****************************:";
	Kirby2[16] = (char*)"****************************";
	Kirby2[17] = (char*)"***************************";
	Kirby2[18] = (char*)"*************************";
	Kirby2[19] = (char*)"*********************:";
	Kirby2[20] = (char*)"*****************:";
	Kirby2[21] = (char*)"::**********";
	Kirby2[22] = (char*)"**";
	Kirby2[23] = (char*)"V**";
	Kirby2[24] = (char*)"V*";
	Kirby2[25] = (char*)"V**";
	Kirby2[26] = (char*)"MVF";
	Kirby2[27] = (char*)"I$M";
	Kirby2[28] = (char*)"V$F";
	Kirby2[29] = (char*)"*IV";
	Kirby2[30] = (char*)"IF";
	Kirby2[31] = (char*)"*";
	Kirby2[32] = (char*)"**";
	Kirby2[33] = (char*)"***";
	Kirby2[34] = (char*)"O";
	Kirby2[35] = (char*)"*V";
	Kirby2[36] = (char*)"*M";
	Kirby2[37] = (char*)"*IM";
	Kirby2[38] = (char*)":IMMV";
	Kirby2[39] = (char*)"VIIIIV";
	Kirby2[40] = (char*)":VIIII*";
	Kirby2[41] = (char*)"VVFV*";
	Kirby2[42] = (char*)"*VFF*";

	Kirby3[0]  = (char*)":::::";
	Kirby3[1]  = (char*)"::********::::::";
	Kirby3[2]  = (char*)":****:*:::********:";
	Kirby3[3]  = (char*)":*****:**:::***::*:*******";
	Kirby3[4]  = (char*)"***::::**::::   :*  ******";
	Kirby3[5]  = (char*)"***::::*:::::   ::   :***";
	Kirby3[6]  = (char*)"****::*::::::*  ::* *****:";
	Kirby3[7]  = (char*)"******::***::**VIIV*:***:";
	Kirby3[8]  = (char*)"****::**:::VNNNNNM*****";
	Kirby3[9]  = (char*)"****:::::VMMMMMMNM****";
	Kirby3[10] = (char*)"*****::::IMIIIMMMNV**";
	Kirby3[11] = (char*)"******::*IIFVVFIMMV**";
	Kirby3[12] = (char*)"*******IVVVVVFIMV**";
	Kirby3[13] = (char*)"******IFVVVVIIMV*";
	Kirby3[14] = (char*)"*****IIIIIIIMV*";
	Kirby3[15] = (char*)"FVV";
	Kirby3[16] = (char*)"*MN";
	Kirby3[17] = (char*)"M$I";
	Kirby3[18] = (char*)"FNV";
	Kirby3[19] = (char*)"IV";
	Kirby3[20] = (char*)"V";
	Kirby3[21] = (char*)"IMIIIM";
	Kirby3[22] = (char*)"IIFVVFI";
	Kirby3[23] = (char*)"VV";
	Kirby3[24] = (char*)"IVVVVV";
	Kirby3[25] = (char*)"MTV";
	Kirby3[26] = (char*)"IFVVVV";
	Kirby3[27] = (char*)"MMIV";
	Kirby3[28] = (char*)"IIIIII";
	Kirby3[29] = (char*)"MIMMFVV";
	Kirby3[30] = (char*)"VMMMMMIVFV";
	Kirby3[31] = (char*)"FIIMMMIV*VVVFFFIMM*";
	Kirby3[32] = (char*)"*MIIMMM*     *MMM*";
	Kirby3[33] = (char*)"VMIII*";
	Kirby3[34] = (char*)"**";
}

int Kirby::Update(bool _Pause)
{
	return 0;
}

void Kirby::Render()
{
	RendKirby1(0.0f, 1.0f);
	RendKirby2(50.0f, 1.0f);
	RendKirby3(50.0f, 30.0f);
}

void Kirby::Release()
{
}

void Kirby::RendKirby1(float _x, float _y)
{
	CursorManager::GetInstance()->WriteBuffer(_x + 6, _y, Kirby1[0], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 5, _y + 1, Kirby1[1], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 2, Kirby1[2], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 3, Kirby1[3], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 4, Kirby1[4], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 5, Kirby1[5], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 6, Kirby1[6], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 7, Kirby1[7], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 7, Kirby1[7], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 8, Kirby1[8], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 9, Kirby1[9], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 10, Kirby1[10], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 11, Kirby1[11], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 12, Kirby1[12], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 13, Kirby1[13], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 14, Kirby1[14], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 10, _y + 4, Kirby1[15]);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 5, Kirby1[17]);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 5, Kirby1[16], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 6, Kirby1[18], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 12, _y + 6, Kirby1[19], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 12, _y + 7, Kirby1[20], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 8, Kirby1[21], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 10, _y + 9, Kirby1[22], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 10, _y + 9, Kirby1[22], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 10, Kirby1[23], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 11, _y + 11, Kirby1[24], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 10, _y + 12, Kirby1[25], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 13, Kirby1[26], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 14, Kirby1[27], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 15, Kirby1[28], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 16, Kirby1[29], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 17, Kirby1[30], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 18, Kirby1[31], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 5, _y + 19, Kirby1[32], 12);
}

void Kirby::RendKirby2(float _x, float _y)
{
	CursorManager::GetInstance()->WriteBuffer(_x + 12, _y, Kirby2[0], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 1, Kirby2[1], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 7, _y + 2, Kirby2[2], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 3, Kirby2[3], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 4, Kirby2[4], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 5, Kirby2[5], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 6, Kirby2[6], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 7, Kirby2[7], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 8, Kirby2[8], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 9, Kirby2[9], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 10, Kirby2[10], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 11, Kirby2[11], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 12, Kirby2[12], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 13, Kirby2[13], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 14, Kirby2[14], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 15, Kirby2[15], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 16, Kirby2[16], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 17, Kirby2[17], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 5, _y + 18, Kirby2[18], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 7, _y + 19, Kirby2[19], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 20, Kirby2[20], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 10, _y + 21, Kirby2[21], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 17, _y + 1, Kirby2[22]);
	CursorManager::GetInstance()->WriteBuffer(_x + 17, _y + 2, Kirby2[23]);
	CursorManager::GetInstance()->WriteBuffer(_x + 22, _y + 2, Kirby2[24]);
	CursorManager::GetInstance()->WriteBuffer(_x + 22, _y + 3, Kirby2[25]);
	CursorManager::GetInstance()->WriteBuffer(_x + 17, _y + 3, Kirby2[26], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 17, _y + 4, Kirby2[27], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 22, _y + 4, Kirby2[28], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 17, _y + 5, Kirby2[29], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 23, _y + 5, Kirby2[30], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 18, _y + 6, Kirby2[31], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 23, _y + 6, Kirby2[32], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 5, Kirby2[33], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 6, Kirby2[33], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 26, _y + 6, Kirby2[33], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 27, _y + 7, Kirby2[32], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 21, _y + 7, Kirby2[34], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 16, Kirby2[35], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 17, Kirby2[36], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 18, Kirby2[37], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 2, _y + 19, Kirby2[38], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 20, Kirby2[39], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 21, Kirby2[40], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 22, _y + 21, Kirby2[41], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 5, _y + 22, Kirby2[33], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 20, _y + 22, Kirby2[32], 12);
}

void Kirby::RendKirby3(float _x, float _y)
{
	CursorManager::GetInstance()->WriteBuffer(_x + 12, _y, Kirby3[0], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 1, Kirby3[1], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 7, _y + 2, Kirby3[2], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 3, Kirby3[3], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 4, Kirby3[4], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 5, Kirby3[5], 13);
	CursorManager::GetInstance()->WriteBuffer(_x, _y + 6, Kirby3[6], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 1, _y + 7, Kirby3[7], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 3, _y + 8, Kirby3[8], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 9, Kirby3[9], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 10, Kirby3[10], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 11, Kirby3[11], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 6, _y + 12, Kirby3[12], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 7, _y + 13, Kirby3[13], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 8, _y + 14, Kirby3[14], 13);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 4, Kirby3[15]);
	CursorManager::GetInstance()->WriteBuffer(_x + 17, _y + 4, Kirby3[16]);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 5, Kirby3[17], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 18, _y + 5, Kirby3[18], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 6, Kirby3[19], 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 18, _y + 6, (char*)"*V*", 11);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 7, (char*)"***", 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 9, _y + 8, (char*)"**", 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 21, _y + 7, (char*)"***", 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 22, _y + 8, (char*)"**", 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 10, Kirby3[21], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 11, Kirby3[22], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 11, Kirby3[23], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 11, Kirby3[24], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 12, Kirby3[25], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 12, Kirby3[26], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 13, Kirby3[27], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 13, Kirby3[28], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y + 14, Kirby3[29], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y + 14, Kirby3[30], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4 , _y + 15, Kirby3[31], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 4, _y +  16, Kirby3[32], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 5, _y +  17, Kirby3[33], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 6, _y +  18, Kirby3[34], 12);
	CursorManager::GetInstance()->WriteBuffer(_x + 13, _y +  14, (char*)"VMMMMM", 13);
}