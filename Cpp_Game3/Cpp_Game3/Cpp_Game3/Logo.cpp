#include "Logo.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
    Release();
}

void Logo::Start()
{
	Time = GetTickCount64();	
	
				
	
    Buffer[0]  = (char*)"ZdmmmmmmmmmaPHo~                                                         ";
    Buffer[1]  = (char*)"#r3mKsssKsss3qsH0^                           `~xyssVx~`    ~===~====~===`";
    Buffer[2]  = (char*)"#r#:6HPPHHHPPam$VD3   B?#~#mH    .@L0yx#r  !MMG5MZZM5GWMc` qbbbZbbbbZZbb:";
    Buffer[3]  = (char*)"#r#<#:GmKmm3Pz8uZVMY  B?#~#3G    .@L0yx#) ^8YbqqMMZM5GMau~ qMMMZMMMMZMMM:";
    Buffer[4]  = (char*)"#r#<#?q'.''.^gvQT#?@_ B(#~#3H    .@L0yx#r`#^#?EsuxiVs3v!`  KPPR6DM$d0PPP,";
    Buffer[5]  = (char*)"#r#<#?m      `#~#}8Ey B(#~#mH    .@L0yx#r`#)B(D               My0!@x8    ";
    Buffer[6]  = (char*)"#r#<#?m       #!#^#aM B?#~#3G    .@L0yx#) VmV0K5M5MMGWdL`     Mk0!@x8    ";
    Buffer[7]  = (char*)"#r#<#?m      _#^#VD$T B?#~#mW    .@LDyx#r  yEPPMMMMW3MyhQ`    My0!@x8    ";
    Buffer[8]  = (char*)"#r#<#(0^^^^^lQ|Bv#*#. Ru8~#rB,   VgWKZ*#!   `=caammmGIZHUx    My0!@x8    ";
    Buffer[9]  = (char*)"#r#<#*bbdbbZ3a$i$ig*  *Brgx0}MH3qIyDxBL8`           ~#(Bxo    Mk0!@x8    ";
    Buffer[10] = (char*)"#r#!qMMMMMMMqmMR}Ql    u8c8uWqam3ZXGDvQ_  `xWKPmmKma3kQvQ:    My0!@x8    ";
    Buffer[11] = (char*)"#iyMMMMMMMMMMGGdK'      :DPI5PP33qPkRH`  `VbPPq3Pm33HmME~     My0!@x8    ";
    Buffer[12] = (char*)"}GPPPPPPPPPPau!           ;HHKywkPWT-      `~c33aH3a3y:       Mk0!@x8    ";
    Buffer[13] = (char*)"GKUssUUsUUssm3U(     My0!@x8                                                                                 ";
    Buffer[14] = (char*)"#:MssKssmamsmPPsDc`  My0!@x8                 '=rxx?<-                                                        ";
    Buffer[15] = (char*)"#!B~MMMMMMMMMHX9koa  dug!@L0     B*Qvcdx  `VZHqMMZM5PHGv  xmmmmmmmmmmmm! Q*B;PmBmmmmmmm} -@mmmmmmmmmmmKP5Y`  ";
    Buffer[16] = (char*)"#!BL0iPmmKmm3IMDz9Rc Ou8!@L0    `#r#xy0L !BY55qMMMZ5W53u* }MbMMMZMMMMZM= #r#<ZW@MMMZMMMy -#u@MMMZMMMMZH5qlg) ";
    Buffer[17] = (char*)"#!BL0Q}     -B}Q!#i$ Ou8!@L0    `#r#xy0L Qx#?DaciiTh3L:-  iPHOR9b0M$PGP! #r#<MW#PPPGPPPu -#uOggPG333PPPdLQlB^";
    Buffer[18] = (char*)"#!BL08jHPPPPPMx#x$dk Ou8!@L0     #r#xy0L B^#<Q<              yMHr#~#     #r#<MHd         -#uOB|DammmmKEv#~#i8";
    Buffer[19] = (char*)"#!BL0QkUsmssmB@^#<#' Ou8!@L0    `#r#xy0L V8w$IMMWWGHq5r`     wZH)#~#     #r#<ZW#WGW5WGG! -#uOB?B)     Qx#~#xQ";
    Buffer[20] = (char*)"#!BL08oHPHHPH3c#LgdV Ou8!@L0     #r#xy0L  LDU3Pmmma3qVHg`    yZHr#~#     #r#<ZH#mmmmmmm: -#uOB?#xMMMMMq6}0kBx";
    Buffer[21] = (char*)"#!BL08l      #iQ=#}0 m3Mr#^#=   vByEkxQ)    :uK3mmsPHXR}y    yZHr#~#     #r#<ZH#mmmmmmm: -#uOB|#vWWWWWPqHTQi ";
    Buffer[22] = (char*)"#!BL08XbbdbbZadM53Q} :#rQ|8}MHPW3u8?#?B`           !@~#^Z    wZH)#~#     #r#<ZWd         -#uOB|BxWGGGMM5#$=  ";
    Buffer[23] = (char*)"#!BL08XMMMMMMWUOzhO`  vQY8cPM3m3MsmgvB!   :5mHKmKma3w8L0^    wZHr#~#     #r#<MG@MMMMMMMV -#uOB|#'~~BZ@y#IE   ";
    Buffer[24] = (char*)"#!BL08jPPPPP3H3mQm`    =ghKMGqWWWMyP$    udm3H3Pm33PaUg}     yZHr#~#     #r#<MG#PPPPPPPu -#uOB?#`  :#yRmTQx  ";
    Buffer[25] = (char*)"s_k<TVxPPPPPPPKv`       `vMGqZbMGG3^      `vm3aKH3m33|`      rix!X,o     X!I'ixRPPPPPPPu 's*Yk!o`   x=U!U!s  ";
    
    Buffer[26] = (char*)"       ,)}Lxx ";
    Buffer[27] = (char*)"     rixxxxxY      =";
    Buffer[28] = (char*)"   ^xxxxxx}u!       Y,";
    Buffer[29] = (char*)"  |xxxxuPM3m         V^";
    Buffer[30] = (char*)" )xxxx]z`            uL=";
    Buffer[31] = (char*)".xxxxxxxx-          <xxu";
    Buffer[32] = (char*)"=  !>xxxxxx'         <xx*";
    Buffer[33] = (char*)",     :]xxxxx,        ~LV";
    Buffer[34] = (char*)".       :]xxxxx_       -T";
    Buffer[35] = (char*)"`:x*      :ixxxxx- , ";
    Buffer[36] = (char*)"LxxY        _xxxxx}PI~";
    Buffer[37] = (char*)"xxxx<         ,xxxxxxxL";
    Buffer[38] = (char*)"'ixxx:         y3}xxxxxV";
    Buffer[39] = (char*)" ^xxxx^         uM]xxxT.";
    Buffer[40] = (char*)"  ~]xxx]?_    `~Lxxxx}`";
    Buffer[41] = (char*)"   .Lxxxxxxxxxxxxxx]x";
    Buffer[42] = (char*)"     !}xxxxxxxxxxYL-";
    Buffer[43] = (char*)"       `=?YuuuLr:";


    Buffer[44] = (char*)"Yr<);}";
    Buffer[45] = (char*)"rPex*"; 
    Buffer[46] = (char*)"!IcqT*";
    Buffer[47] = (char*)"|G 3 m`"; 
    Buffer[48] = (char*)"`Gqa qqu";
    Buffer[49] = (char*)"IqqP}q5qv";
    Buffer[50] = (char*)"=3qrh5qU W5qu";
    Buffer[51] = (char*)"y3}5qkiqqU";

    Buffer[52] = (char*)"`y;`"; //(4), 8, (9)
    Buffer[53] = (char*)"uqqWP5qPe";

    Buffer[54] = (char*)"(qqWu."; //1, (6), 7, (9), 3, (2)
    Buffer[55] = (char*)"cqqqqqWh`";
    Buffer[56] = (char*)"mx";

    Buffer[57] = (char*)"3GWqq)^."; //1, (8), 7, (8), 1, (3)
    Buffer[58] = (char*)"VWq5qqG,";
    Buffer[59] = (char*)"^xk";
  

    Buffer[60] = (char*)"!'"; //(2), 2, (7), 7, (10)
    Buffer[61] = (char*)"*}}vq}`";
    Buffer[62] = (char*)" v-LWqGWqqT";
              
    Buffer[63] = (char*)"!'"; //(2), 2, (7), 7, (12)
    Buffer[64] = (char*)"*}}vq}`";
    Buffer[65] = (char*)"v-LWqGWqqT";

    Buffer[66] = (char*)"|Wqq5qqV_"; //4, (9), 9, (4), 1, (1)
    Buffer[67] = (char*)"^XUx";
    Buffer[68] = (char*)"*";

    Buffer[69] = (char*)"3q5555qWu-";// 5, (10), 8, (5)
    Buffer[70] = (char*)"~'VGW";

    Buffer[71] = (char*)".aWq5qz}iv";// 5,
    Buffer[72] = (char*)"xWqqqqqqV";// 7,

    Buffer[73] = (char*)"X";
    Buffer[74] = (char*)"X";
    Buffer[75] = (char*)"O";
   

    Length = 100 - strlen("#r#<#*bbdbbZ3a$i$ig*  *Brgx0}MH3qIyDxBL8`           ~#(Bxo    Mk0!@x8    `#r#xy0L Qx#?DaciiTh3L:-  iPHOR9b0M$PGP! #r#<MW#PPPGPPPu -#uOggPG333PPPdLQlB^") / 2;

    MaxSize = 76;

    ColorL1 = rand() % 6 + 3;
    ColorL2 = rand() % 5 + 10;
    ColorP1 = 12;
    ColorP2 = 6;
    Time = GetTickCount64();
}

void Logo::Update()
{
    if (Time + 1000 < GetTickCount64())
    {
        Time = GetTickCount64();
        ColorL1 = rand() % 3 + 7;
        ColorL2 = rand() % 5 + 10;
    }
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN || Time + 5000 <= GetTickCount64())
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
    for (int i = 0; i < MaxSize; ++i)
    {
        if (i < 13)
            CursorManager::GetInstance()->WriteBuffer(Length - 20, 11.0f + i, Buffer[i], ColorL1);
        else if (i < 26)
            CursorManager::GetInstance()->WriteBuffer(Length + 21, 11.0f + i, Buffer[i], ColorL2);
        else if (i < 44)
            CursorManager::GetInstance()->WriteBuffer(111.0f, -18 + i, Buffer[i], ColorP1);
        else if (i == 44)
            CursorManager::GetInstance()->WriteBuffer(122.0f, -38 + i, Buffer[i], ColorP2);
        else if (i < 48)
            CursorManager::GetInstance()->WriteBuffer(124.0f, -38 + i, Buffer[i], ColorP2);
        else if (i < 50)
            CursorManager::GetInstance()->WriteBuffer(123.0f, -38 + i, Buffer[i], ColorP2);
        else if (i == 50)
            CursorManager::GetInstance()->WriteBuffer(119.0f, -38 + i, Buffer[i], ColorP2);
        else if (i == 51)
            CursorManager::GetInstance()->WriteBuffer(121.0f, -38 + i, Buffer[i], ColorP2);
        else if (i == 52)
            CursorManager::GetInstance()->WriteBuffer(111.0f, 14.0f, Buffer[i], ColorP2);
        else if (i == 53)
            CursorManager::GetInstance()->WriteBuffer(123.0f, 14.0f, Buffer[i], ColorP2);
        else if (i == 54)
            CursorManager::GetInstance()->WriteBuffer(112.0f, 15.0f, Buffer[i], ColorP2);
        else if (i == 55)
            CursorManager::GetInstance()->WriteBuffer(125.0f, 15.0f, Buffer[i], ColorP2);
        else if (i == 56)
            CursorManager::GetInstance()->WriteBuffer(137.0f, 15.0f, Buffer[i], ColorP2);
        else if (i == 57)
            CursorManager::GetInstance()->WriteBuffer(112.0f, 16.0f, Buffer[i], ColorP2);
        else if (i == 58)
            CursorManager::GetInstance()->WriteBuffer(127.0f, 16.0f, Buffer[i], ColorP2);
        else if (i == 59)
            CursorManager::GetInstance()->WriteBuffer(136.0f, 16.0f, Buffer[i], ColorP2);
        else if (i == 60)
            CursorManager::GetInstance()->WriteBuffer(111.0f, 17.0f, Buffer[i], ColorP2);
        else if (i == 61)
            CursorManager::GetInstance()->WriteBuffer(115.0f, 17.0f, Buffer[i], ColorP2);
        else if (i == 62)
            CursorManager::GetInstance()->WriteBuffer(129.0f, 17.0f, Buffer[i], ColorP2);
        else if (i == 63)
            CursorManager::GetInstance()->WriteBuffer(111.0f, 18.0f, Buffer[i], ColorP2);
        else if (i == 64)
            CursorManager::GetInstance()->WriteBuffer(115.0f, 18.0f, Buffer[i], ColorP2);
        else if (i == 65)
            CursorManager::GetInstance()->WriteBuffer(129.0f, 18.0f, Buffer[i], ColorP2);
        else if (i == 66)
            CursorManager::GetInstance()->WriteBuffer(115.0f, 19.0f, Buffer[i], ColorP2);
        else if (i == 67)
            CursorManager::GetInstance()->WriteBuffer(133.0f, 19.0f, Buffer[i], ColorP2);
        else if (i == 68)
            CursorManager::GetInstance()->WriteBuffer(138.0f, 19.0f, Buffer[i], ColorP2);
        else if (i == 69)
            CursorManager::GetInstance()->WriteBuffer(116.0f, 20.0f, Buffer[i], ColorP2);
        else if (i == 70)
            CursorManager::GetInstance()->WriteBuffer(134.0f, 20.0f, Buffer[i], ColorP2);
        else if (i == 71)
            CursorManager::GetInstance()->WriteBuffer(116.0f, 21.0f, Buffer[i], ColorP2);
        else if (i == 72)
            CursorManager::GetInstance()->WriteBuffer(118.0f, 21.0f, Buffer[i], ColorP2);
        else if (i == 73)
            CursorManager::GetInstance()->WriteBuffer(126.0f, 9.0f, Buffer[i], ColorP1);
        else if (i == 74)
            CursorManager::GetInstance()->WriteBuffer(128.0f, 9.0f, Buffer[i], ColorP1);
        else
            CursorManager::GetInstance()->WriteBuffer(127.0f, 10.0f, Buffer[i], ColorP1);
    }
}

void Logo::Release()
{
}