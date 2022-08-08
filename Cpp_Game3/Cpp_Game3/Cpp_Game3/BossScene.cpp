#include "BossScene.h"
#include "CursorManager.h"
#include "SceneManager.h"

BossScene::BossScene() : Time(0)
{
}

BossScene::~BossScene()
{
}

void BossScene::Start()
{
	Time = GetTickCount64();
}

void BossScene::Update()
{
	if (Time + 3000 < GetTickCount64())
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void BossScene::Render()
{
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 20, (char*)" .--.                               .-.       .-.         .-.  _                     .-.", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 21, (char*)": .--'                             .' `.      : :        .' `.:_;                    : :", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 22, (char*)": :    .--. ,-.,-. .--. .--.  .--. `. .'.-..-.: :   .--. `. .'.-. .--. ,-.,-. .--.   : :", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 23, (char*)": :__ ' .; :: ,. :' .; :: ..'' .; ; : : : :; :: :_ ' .; ; : : : :' .; :: ,. :`._-.'  :_;", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 24, (char*)"`.__.'`.__.':_;:_;`._. ;:_;  `.__,_;:_; `.__.'`.__;`.__,_;:_; :_;`.__.':_;:_;`.__.'  :_;", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 25, (char*)"                   .-. :                                                                ", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen(" .--.                               .-.       .-.         .-.  _                     .-.") / 2, 26, (char*)"                   `._.'                                                                ", 14);
	CursorManager::GetInstance()->WriteBuffer(80 - strlen("잠시 후 메인메뉴로 돌아갑니다") / 2, 29, (char*)"잠시 후 메인메뉴로 돌아갑니다");
}

void BossScene::Release()
{
}

