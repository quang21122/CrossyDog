#include "Menu.h"

void Menu::DrawMenuScene() {//can add more items to decorate the menu screen
	Graphic::DrawLeaf(34,6,AQUA);
	Graphic::DrawLeaf(67, 6, AQUA);
	Graphic::DrawLeaf(2, 14, AQUA);
	Graphic::DrawLeaf(104, 14, AQUA);
	Graphic::DrawLeaf(34, 22, AQUA);
	Graphic::DrawLeaf(67, 22, AQUA);
}

void Menu::ShowTitleScreen() {
	system("color F0");
	Graphic::DrawTitle(4, 4, BRIGHT_WHITE);
	Sleep(2000);
	system("cls");
}

void Menu::ShowMenuTutorial(){
	Console::SetColor(BRIGHT_WHITE, AQUA);
	Console::GotoXY(100, 2);
	cout << "D: Go clockwise";
	Console::GotoXY(4, 2);
	cout << "A: Go counter-clockwise";
	Console::GotoXY(40, 2);
	cout << "ENTER: SELECT";
	Console::GotoXY(67, 2);
	cout << "H: Leaderboard";
}

void Menu::ShowMenu() {
	ShowTitleScreen();
	system("color 30");
	ShowMenuTutorial();
	//Graphic::DrawMenuChooseFrame(48, 13, AQUA);
	string saveFileName = ""; 
	char key;
	int prevChoice = 6;
	int choice = 1;
	void(*drawFunc[])(int,int,int) = {Graphic::DrawPlayGameIcon,Graphic::DrawLoadGameIcon,Graphic::DrawTutorialIcon,
	Graphic::DrawSettingsIcon,Graphic::DrawCreditsIcon,Graphic::DrawExitIcon};
	string options[] = { "NEW GAME", "LOAD GAME", "TUTORIAL", "SETTINGS", "CREDITS", "EXIT" };
	int nOptions = 6;
	int optionColors[] = { LIGHT_YELLOW, BLACK, BLACK, BLACK, BLACK, BLACK };
	COORD optionCoord[] = { {37,10}, {70,10}, {107,18}, {70,26}, {38,26}, {7,18} };
	COORD frogCoord[] = { {36,3}, {69,3}, {106,11}, {69,19}, {36,19}, {4,11} };
	COORD leafCoord[] = { {34,6},{67,6},{104,14},{67,22},{34,22},{2,14} };

	mciSendString(TEXT("play Sound/BackgroundSound.mp3 repeat"), NULL, 0, NULL);
	DrawMenuScene();
	for (int i = 0; i < nOptions; i++) {
		Console::GotoXY(optionCoord[i].X, optionCoord[i].Y);
		Console::SetColor(optionColors[i], LIGHT_GREEN);
		cout << options[i];
	}

	while (1) {
		Graphic::DeleteIcon(53, 14, AQUA);
		drawFunc[choice - 1](53, 14, AQUA);
		Graphic::DrawLeaf(leafCoord[choice - 1].X, leafCoord[choice - 1].Y, AQUA);
		Console::GotoXY(optionCoord[prevChoice - 1].X, optionCoord[prevChoice - 1].Y);
		Console::SetColor(optionColors[prevChoice - 1], LIGHT_GREEN);
		cout << options[prevChoice - 1];
		Graphic::DrawFrog(frogCoord[choice - 1].X, frogCoord[choice - 1].Y, LIGHT_GREEN);
		Console::GotoXY(optionCoord[choice - 1].X, optionCoord[choice - 1].Y);
		Console::SetColor(optionColors[choice - 1], LIGHT_GREEN);
		cout << options[choice - 1];
		key = toupper(_getch());
		Graphic::DeleteFrog(frogCoord[choice - 1].X, frogCoord[choice - 1].Y);
		for (int i = 0; i < nOptions; i++)
			optionColors[i] = BLACK;

		auto startMenu = [nOptions, optionCoord, optionColors, options, this]() {//lambda expression to start the menu (the right capturing point)
				Console::SetColor(BLACK, AQUA);
				system("cls");
				system("color 30");
				this->DrawMenuScene();
				for (int i = 0; i < nOptions; i++) {
					Console::GotoXY(optionCoord[i].X, optionCoord[i].Y);
					Console::SetColor(optionColors[i], LIGHT_GREEN);
					cout << options[i];
				}
				ShowMenuTutorial();
			};
		switch (key) {
		case 'A':
			prevChoice = choice;
			Graphic::DrawLeaf(leafCoord[prevChoice - 1].X, leafCoord[prevChoice - 1].Y, AQUA);
			choice--;
			if (choice < 1)
				choice = 6;
			PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			Graphic::DrawJumpingFrog((frogCoord[prevChoice - 1].X + frogCoord[choice - 1].X) / 2,
				(frogCoord[prevChoice - 1].Y + frogCoord[choice - 1].Y) / 2, AQUA);
			Sleep(150);
			Graphic::DeleteFrog((frogCoord[prevChoice - 1].X + frogCoord[choice - 1].X) / 2,
				(frogCoord[prevChoice - 1].Y + frogCoord[choice - 1].Y) / 2);
			break;

		case 'D':
			prevChoice = choice;
			Graphic::DrawLeaf(leafCoord[prevChoice - 1].X, leafCoord[prevChoice - 1].Y, AQUA);
			choice++;
			if (choice > 6)
				choice = 1;
			PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			Graphic::DrawJumpingFrog((frogCoord[prevChoice - 1].X + frogCoord[choice - 1].X) / 2,
				(frogCoord[prevChoice - 1].Y + frogCoord[choice - 1].Y) / 2, AQUA);
			Sleep(150);
			Graphic::DeleteFrog((frogCoord[prevChoice - 1].X + frogCoord[choice - 1].X) / 2,
				(frogCoord[prevChoice - 1].Y + frogCoord[choice - 1].Y) / 2);
			break;
		case 'H':
			PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			utility.ShowLeaderBoard();
			startMenu();
			break;
		case 13:
			prevChoice = choice;
			PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			switch (choice) {
			case 1:
				game.PlayGame("");
				startMenu();
				break;
			case 2:
				saveFileName = gameLoader.ShowGameLoader();
				if (saveFileName != "")
					game.PlayGame(saveFileName);
				startMenu();
				break;
			case 3:
				tutorial.ShowTutor();
				startMenu();
				break;
			case 4:
				settings.ShowSettings();
				startMenu();
				break;
			case 5:
				credits.ShowCredits();
				startMenu();
				break;
			case 6:
				return;
			}
			break;
		}
		optionColors[choice - 1] = LIGHT_YELLOW;
	}
}
