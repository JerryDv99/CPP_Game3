#include "Logo.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
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
    
    Length = 100 - strlen("#r#<#*bbdbbZ3a$i$ig*  *Brgx0}MH3qIyDxBL8`           ~#(Bxo    Mk0!@x8    `#r#xy0L Qx#?DaciiTh3L:-  iPHOR9b0M$PGP! #r#<MW#PPPGPPPu -#uOggPG333PPPdLQlB^") / 2;

    MaxSize = 26;

    ColorP1 = 7;
    ColorP2 = 12;
    Time = GetTickCount64();

    Buffer[26] = (char*)"           Yr<);}";
    Buffer[27] = (char*)"             rPex*";
    Buffer[28] = (char*)"             !IcqT*";
    Buffer[29] = (char*)"             |G 3 m`";
    Buffer[30] = (char*)"            `Gqa qqu";
    Buffer[31] = (char*)"            IqqP}q5qv";
    Buffer[32] = (char*)"        =3qrh5qU W5qu";
    Buffer[33] = (char*)"          y3}5qkiqqU";
    Buffer[34] = (char*)"`y;`        uqqWP5qPe";
    Buffer[35] = (char*)" (qqWu.       cqqqqqWh`   mx";
    Buffer[36] = (char*)" 3GWqq)^.       VWq5qqG, ^xk";
    Buffer[37] = (char*)"!'  *}}vq}`       v-LWqGWqqT";
    Buffer[38] = (char*)"    |Wqq5qqV_         ^XUx *";
    Buffer[39] = (char*)"     3q5555qWu-        ~'VGW";
    Buffer[40] = (char*)"     .aWq5qz}iv";
    Buffer[41] = (char*)"       xWqqqqqqV";

    Buffer[42] = (char*)"       ,)}Lxx ";
    Buffer[43] = (char*)"     rixxxxxY      =";
    Buffer[44] = (char*)"   ^xxxxxx}u!  X X  Y,";   
    Buffer[45] = (char*)"  |xxxxuPM3m    O    V^";        
    Buffer[46] = (char*)" )xxxx]z`            uL=";        
    Buffer[47] = (char*)".xxxxxxxx-          <xxu";         
    Buffer[48] = (char*)"=  !>xxxxxx'         <xx*";        
    Buffer[49] = (char*)",     :]xxxxx,        ~LV";
    Buffer[50] = (char*)".       :]xxxxx_       -T";         
    Buffer[51] = (char*)"`:x*      :ixxxxx- , ";         
    Buffer[52] = (char*)"LxxY        _xxxxx}PI~";         
    Buffer[53] = (char*)"xxxx<         ,xxxxxxxL";         
    Buffer[54] = (char*)"'ixxx:         y3}xxxxxV";         
    Buffer[55] = (char*)" ^xxxx^         uM]xxxT.";         
    Buffer[56] = (char*)"  ~]xxx]?_    `~Lxxxx}`";         
    Buffer[57] = (char*)"   .Lxxxxxxxxxxxxxx]x";         
    Buffer[58] = (char*)"     !}xxxxxxxxxxYL-";         
    Buffer[59] = (char*)"       `=?YuuuLr:";          
}

void Logo::Update()
{
    if (Time + 500 < GetTickCount64())
    {
        Time = GetTickCount64();
        ColorL1 = rand() % 3 + 7;
        ColorL2 = rand() % 5 + 11;
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
            CursorManager::GetInstance()->WriteBuffer(Length, 11.0f + i, Buffer[i], ColorL1);
        else
            CursorManager::GetInstance()->WriteBuffer(Length, 11.0f + i, Buffer[i], ColorL2);
    }
}

void Logo::Release()
{
}