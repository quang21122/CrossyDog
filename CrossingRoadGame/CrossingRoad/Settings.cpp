#include "Settings.h"

void Settings::DrawSettingsScene() {
	system("color F0");
	Graphic::DrawSettingsWord(1, 10, BRIGHT_WHITE);
	Sleep(1000);
	system("cls");
	system("color 30");
	
	Graphic::DrawWaterSurface();
	Graphic::DrawMuteIcon(70, 10);
	Graphic::DrawUnmuteIcon(25, 10);
	Graphic::DrawOnWord(32, 24, BLACK, AQUA);//27, 22
	Graphic::DrawOffWord(74, 24,BLACK, AQUA); //71, 22
	Graphic::DrawWhale(1, 2, AQUA);
	Graphic::DrawJellyFish(100, 10, AQUA);
	Console::GotoXY(54, 4);
	cout << "A: GO LEFT";
	Console::GotoXY(54, 5);
	cout << "D: GO RIGHT";
	Console::GotoXY(53, 6);
	cout << "ENTER: SELECT";
	Console::GotoXY(50, 7);
	cout << "ESC: BACK TO MENU";
}

void Settings::ShowSettings() {
	system("cls");
	DrawSettingsScene();

	char key;
	int choice = 1;
	int nOptions = 2;
	int optionColor[] = { LIGHT_YELLOW, BLACK };
	void(*draw[])(int, int, int, int) = {Graphic::DrawOnWord, Graphic::DrawOffWord};
	COORD optionCoord[] = { {27,22}, {71,22} };
	COORD wordCoord[] = { {32,24}, {74,24} };
	while (1) {	
		Graphic::DeleteOffWord(wordCoord[1].X, wordCoord[1].Y, AQUA);
		Graphic::DeleteOnWord(wordCoord[0].X, wordCoord[0].Y, AQUA);
		for (int i = 0; i < 2; i++) {
			
			draw[i](wordCoord[i].X, wordCoord[i].Y, optionColor[i], AQUA);
			Graphic::DrawChooseFrame(optionCoord[choice - 1].X, optionCoord[choice - 1].Y, AQUA);
		}
		
		key = _getch();

		Graphic::DeleteChooseFrame(optionCoord[choice - 1].X, optionCoord[choice - 1].Y, AQUA);
		for (int i = 0; i < nOptions; i++)
			optionColor[i] = BLACK;

		switch (key) {
		case 'a':
			PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			choice--;
			if (choice < 1)
				choice = 2;
			break;
		case 'd':
			PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			choice++;
			if (choice > 2)
				choice = 1;
			break;
		case 27:
			system("cls");
			return;
		case 13:
			PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			switch (choice) {
			case 1:
				mciSendString(TEXT("play Sound/BackgroundSound.mp3 repeat"), NULL, 0, NULL);
				break;
			case 2:
				mciSendString(TEXT("stop Sound/BackgroundSound.mp3"), NULL, 0, NULL);
				break;
			}
		}
		optionColor[choice - 1] = LIGHT_YELLOW;
	}
}
