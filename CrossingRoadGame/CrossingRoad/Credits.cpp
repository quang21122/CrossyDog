#include "Credits.h"

void Credits::ShowFirstSlide() {
	system("color 30");
	Sleep(1000);
	Graphic::DrawSun(15, 2, AQUA);
	Sleep(600);
	Graphic::DrawGroupTitle(50, 2, AQUA);
	Sleep(600);
	Graphic::DrawCloud(20, 10, AQUA);
	Console::SetColor(BLACK, BRIGHT_WHITE);
	Console::GotoXY(26,12);
	cout << "22127090 - Van Diep Bao Duy";
	Sleep(600);
	Graphic::DrawCloud(70, 10, AQUA);
	Console::SetColor(BLACK, BRIGHT_WHITE);
	Console::GotoXY(77, 12);
	cout << "22127156 - Nguyen Phuc Huy";
	Sleep(600);
	Graphic::DrawCloud(10, 20, AQUA);
	Console::SetColor(BLACK, BRIGHT_WHITE);
	Console::GotoXY(13, 22);
	cout << "22127483 - Nguyen Huynh Minh Quang";
	Sleep(600);
	Graphic::DrawCloud(60, 20, AQUA);
	Console::SetColor(BLACK, BRIGHT_WHITE);
	Console::GotoXY(68, 22);
	cout << "22127399 - Vu Thai Thien";
	Sleep(2000);

	Graphic::DeleteCloud(20, 10, AQUA);
	Sleep(600);
	Graphic::DeleteCloud(70, 10, AQUA);
	Sleep(600);
	Graphic::DeleteCloud(10, 20, AQUA);
	Sleep(600);
	Graphic::DeleteCloud(60, 20, AQUA);
} 

void Credits::ShowSecondSlide() {
	system("color 30");
	Graphic::DrawCloud(10, 1, AQUA);
	Graphic::DrawCloud(70, 3, AQUA);
	/*Graphic::DrawPlaneWithThankBanner(54, 14, AQUA);
	Sleep(100);
	Graphic::DeletePlaneWithThankBanner(54, 14, AQUA);

	Graphic::DrawPlaneWithThankBanner(52, 12, AQUA);
	Sleep(100);
	Graphic::DeletePlaneWithThankBanner(52, 12, AQUA);

	Graphic::DrawPlaneWithThankBanner(50, 10, AQUA);
	Sleep(100);
	Graphic::DeletePlaneWithThankBanner(50, 10, AQUA);*/

	for (int i = 60; i >=0; i--) {
		Graphic::DrawPlaneWithThankBanner(i, 15, AQUA);
		Sleep(100);
		Graphic::DeletePlaneWithThankBanner(i, 15, AQUA);
	}

	Graphic::DrawPlaneWithThankBanner(0, 10, AQUA);
	Console::SetColor(RED, AQUA);
	Console::GotoXY(45, 25);
	cout << "Press ESC to go back to Menu";
	char key;
	do {
		key = _getch();
	} while (key != 27);
}

void Credits::ShowCredits() {
	system("cls");
	ShowFirstSlide();
	system("cls");
	ShowSecondSlide();
	system("cls");
}