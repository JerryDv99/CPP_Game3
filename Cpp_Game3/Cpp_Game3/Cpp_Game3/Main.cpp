#include "MainUpdate.h"

int main(void)
{
	system("title ������ : �����̸�");
	system("mode con cols=160 lines=50");
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time <= GetTickCount64())
		{
			system("cls");

			Main.Update();
			Main.Render();

			Time = GetTickCount64();
		}

	}

	return 0;
}