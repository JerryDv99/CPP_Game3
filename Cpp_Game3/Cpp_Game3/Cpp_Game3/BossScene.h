#pragma once
#include "Scene.h"

class BossScene : public Scene
{
private:
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	BossScene();
	virtual ~BossScene();
};

// .--.                               .-.       .-.         .-.  _                     .-.
//: .--'                             .' `.      : :        .' `.:_;                    : :
//: :    .--. ,-.,-. .--. .--.  .--. `. .'.-..-.: :   .--. `. .'.-. .--. ,-.,-. .--.   : :
//: :__ ' .; :: ,. :' .; :: ..'' .; ; : : : :; :: :_ ' .; ; : : : :' .; :: ,. :`._-.'  :_;
//`.__.'`.__.':_;:_;`._. ;:_;  `.__,_;:_; `.__.'`.__;`.__,_;:_; :_;`.__.':_;:_;`.__.'  :_;
//                   .-. :                                                                
//                   `._.'                                                                