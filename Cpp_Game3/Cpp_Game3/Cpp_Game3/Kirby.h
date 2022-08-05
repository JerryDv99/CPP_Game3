#pragma once
#include "Object.h"

class Kirby : public Object
{
private:
	char* Kirby1[64];
	char* Kirby2[64];
	char* Kirby3[64];
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual int Update(bool _Pause)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void RendKirby1(float _x, float _y);
	void RendKirby2(float _x, float _y);
	void RendKirby3(float _x, float _y);
public:
	Kirby();
	virtual ~Kirby();
};
/*
"      :::           "
"     :::::          "
"    ::::::          "
"   :::********      "
"   *******A*****    "
"  *******$I**Q***   "
" ********N**IO***   "
" ***********UI****  "
"*********VIV******* "
"**********V*********"
" ************VVVVV**"
" **********VVVVVVVV "
" *********VVVVVVVFV "
" ********VVVVVFFIIV "
"  *******VVFFIIMMV* "
"  *VVVIIV*VFIMMI*   "
"   VVVIMV ******    "
"   *VVIM*           "
"    **V**           "
"     ***"


"            :::::::::::           "
"         ::::::::**::::::         "
"       ::*:::::::V**::V*::::      "
" ::::::***:::::::MVF::V**::::     "
":***:*****:::::::I$M::V$F::::::   "
"*********::::***:*IV:::IF::::::*: "
"*********::::***::*::::**:***::**:"
" *********:::::::::::O:::::**:::**"
"  ********:::::::::::::::::::::**:"
"  *********::::::::::::::::::::**:"
"  **********:::::::::::::::::::**:"
"  ************::::::::::::::::***:"
"  ***************::::::::::******:"
"  *******************************:"
"  ******************************* "
"   *****************************: "
"  *V****************************  "
"  *M***************************   "
"  *IM*************************    "
"  :IMMV*********************:     "
"   VIIIIV*****************:       "
"   :VIIII*::**********VVFV        "
"     ***            *VFF*         "

"            :::::         "
"         ::********:::::: "
"       :****:*:::********:"
":*****:**:::***::*:*******"
"***::::**::::FVV:*MN******"
"***::::*:::::M$I::FNV:*** "
"****::*::::::*IV::*V*****:"
" ******::***::**VIIV*:***:"
"   ****::**:::VNNNNNM*****"
"    ****:::::VMMMMMMNM****"
"    *****::::IMIIIMMMNV** "
"    ******::*IIFVVFIMMV** "
"    VV*******IVVVVVFIMV** "
"    MIV******IFVVVVIIMV*  "
"    MMIV*****IIIIIIIMV*   "
"    MIMMFVV**VMMMMMIVFV   "
"    FIIMMMIV*VVVFFFIMM*   "
"    *MIIMMM* ::::*MMM*    "
"     VMIII*               "
"       **                 "
*/