#include "Kirby.h"

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

	Kirby2[0]  = (char*)":::::::::::";
	Kirby2[1]  = (char*)"::::::::  ::::::";
	Kirby2[2]  = (char*)"::*:::::::   ::  ::::";
	Kirby2[3]  = (char*)"::::::***:::::::   ::   ::::";
	Kirby2[4]  = (char*)":***:*****:::::::   ::   ::::::";
	Kirby2[5]  = (char*)"*********::::   :   :::  ::::::*:";
	Kirby2[6]  = (char*)"*********::::   :: ::::  :   ::**:";
	Kirby2[7]  = (char*)"*********::::::::::: :::::  :::**";
	Kirby2[8]  = (char*)"********:::::::::::::::::::::**:";
	Kirby2[9]  = (char*)"*********::::::::::::::::::::**:";
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
	Kirby2[20] = (char*)"*****************: ";
	Kirby2[21] = (char*)"*::********** ";
	Kirby2[22] = (char*)"**";
	Kirby2[23] = (char*)"V**";
	Kirby2[24] = (char*)"V*";
	Kirby2[25] = (char*)"MVF";
	Kirby2[26] = (char*)"V**";
	Kirby2[27] = (char*)"I$M";
	Kirby2[28] = (char*)"V$F";
	Kirby2[29] = (char*)"*IV";
	Kirby2[30] = (char*)"IF";
	Kirby2[31] = (char*)"*";
	Kirby2[32] = (char*)"**";
	Kirby2[33] = (char*)"***";
	Kirby2[34] = (char*)"V";
	Kirby2[35] = (char*)"*V";
	Kirby2[36] = (char*)"*M";
	Kirby2[37] = (char*)"*IM";
	Kirby2[38] = (char*)":IMMV";
	Kirby2[39] = (char*)"VIIIIV";
	Kirby2[40] = (char*)":VIIII";
	Kirby2[41] = (char*)"VVFV";
	Kirby2[41] = (char*)"*VFF*";

	Kirby3[0]  = (char*)":::::";
	Kirby3[1]  = (char*)"::********::::::";
	Kirby3[2]  = (char*)":****:*:::********:";
	Kirby3[3]  = (char*)":*****:**:::***::*:*******";
	Kirby3[4]  = (char*)"***::::**::::   :*  ******";
	Kirby3[5]  = (char*)"***::::*:::::   ::   :***";
	Kirby3[6]  = (char*)"****::*::::::*  ::* *****:";
	Kirby3[7]  = (char*)"******::***::** II *:***:";
	Kirby3[8]  = (char*)"****::**:::VNNNNNM*****";
	Kirby3[9]  = (char*)"****:::::VMMMMMMNM****";
	Kirby3[10] = (char*)"*****::::     MMMNV**";
	Kirby3[11] = (char*)"******::*       MMV**";
	Kirby3[12] = (char*)"*******        MV**";
	Kirby3[13] = (char*)"******        MV*";
	Kirby3[14] = (char*)"*****        V*";
	Kirby3[15] = (char*)"FVV";
	Kirby3[16] = (char*)"*MN";
	Kirby3[17] = (char*)"M$I";
	Kirby3[18] = (char*)"FNV";
	Kirby3[19] = (char*)"IV";
	Kirby3[20] = (char*)"V";
	Kirby3[21] = (char*)"IMIII";
	Kirby3[22] = (char*)"IIFVVFI";
	Kirby3[23] = (char*)"VV";
	Kirby3[24] = (char*)"IVVVVVFI";
	Kirby3[25] = (char*)"MTV";
	Kirby3[26] = (char*)"IFVVVVII";
	Kirby3[27] = (char*)"MIMMFVV";
	Kirby3[28] = (char*)"VMMMMMIVFV";
	Kirby3[29] = (char*)"FIIMMMIV*VVVFFFIMM*";
	Kirby3[30] = (char*)"*MIIMMM* ::::*MMM*";
	Kirby3[31] = (char*)"VMIII*";
	Kirby3[32] = (char*)"**";
}

int Kirby::Update(bool _Pause)
{
	return 0;
}

void Kirby::Render()
{
}

void Kirby::Release()
{
}

void Kirby::RendKirby1(float _x, float _y, ULONGLONG _Time)
{
}

void Kirby::RendKirby2(float _x, float _y, ULONGLONG _Time)
{
}

void Kirby::RendKirby3(float _x, float _y, ULONGLONG _Time)
{
}

