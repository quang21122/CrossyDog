#include "GameLoader.h"
const vector<COORD> nameSignCoords = { {99, 7}, {2, 18} };
const vector<COORD> turtleStartingCoords = { {28, 1}, {33, 15} };
const vector<COORD> turtleStoppingCoords = { {61, 6}, {44, 15}, {73, 20} };
const vector<COORD> portalCoords = { {15, 4}, {90, 19} };

string GameLoader::ShowGameLoader() {
	ShowGameLoaderScreen();
	size_t nOnScreenOptions = 2;

	string file = "";

	ifstream fi;
	fi.open("SaveFiles/FilesMenu.txt", ios::in);
	SetFileList(utility.ReadFileList());
	if (fi) fi.close();

	if (fileList.size() == 0) {
		_getch();
		return file;
	}

	// Set color vector
	vector<int> color(nOnScreenOptions);
	color[0] = LIGHT_YELLOW;
	for (int i = 1; i < nOnScreenOptions; i++) {
		color[i] = BLACK;
	}

	Console::SetColor(WHITE, AQUA);
	char key;
	int counter = 0, prevCounter = counter;
	int page = 1;
	ShowTurtleAppearFromFirstGate();
	while (1) {
		if (this->fileList.size() == 0) return file;
		// Reset Name Sign
		for (auto& nameSignCoord : nameSignCoords) {
			Graphic::DrawNameSign(nameSignCoord.X, nameSignCoord.Y, AQUA);
		}

		ShowSaveFiles(page); 

		key = toupper(_getch());
		switch (key) {
		case 'W':
			PlaySound(TEXT("Sound/characterMovingSound.wav"), NULL, SND_ASYNC);
			if (counter <= 1) break;
			counter--;
			TurtleNavigator(prevCounter, key);
			break;
		case 'S':
			PlaySound(TEXT("Sound/characterMovingSound.wav"), NULL, SND_ASYNC);
			if (counter >= fileList.size()) break;
			counter++;
			TurtleNavigator(prevCounter, key);
			break;
		case 'X': {
			PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			if (counter == 0) break;
			const string delFile = fileList[counter - 1];
			UpdateLoadMenu(delFile);
			if (counter == fileList.size() + 1) {
				TurtleNavigator(counter, 'W');
				counter--;
			}
			break;
		}
		case 27:
			system("cls");
			return "";
		case 13:
			PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			if (counter == 0) break;
			file = fileList[counter - 1];
			return file;
		}

		if (counter != 0) page = (counter + 1) / 2;

		prevCounter = counter;
	}

	_getch();
	return file;
}

void GameLoader::ShowGameLoaderScreen() {
	system("cls");
	system("color 30");

	ShowGameLoaderTutorials();

	Graphic::DrawMound(70, 9, AQUA);
	Graphic::DrawMushroomHouse(78, 1, AQUA, LIGHT_GREEN);

	Graphic::DrawMound(14, 20, AQUA);
	Graphic::DrawMushroomHouse(20, 12, AQUA, LIGHT_GREEN);
	Graphic::DrawGameLoaderRoad(AQUA);


	for (auto& nameSignCoord : nameSignCoords) {
		Graphic::DrawNameSign(nameSignCoord.X, nameSignCoord.Y, AQUA);
	}

	Graphic::DrawPortal(portalCoords[0].X, portalCoords[0].Y, AQUA);
	Graphic::DrawPortal(portalCoords[1].X, portalCoords[1].Y, AQUA);
}

void GameLoader::ShowTurtleAppearFromFirstGate() {
	Graphic::DrawTurtleRightAnimation1(portalCoords[0].X, portalCoords[0].Y + 2, WHITE);
	Sleep(500);

	Graphic::DeleteTurtleRight(portalCoords[0].X, portalCoords[0].Y + 2, AQUA);
	Graphic::DrawPortal(portalCoords[0].X, portalCoords[0].Y, AQUA);

	Graphic::DrawTurtleRightAnimation2(turtleStartingCoords[0].X, turtleStartingCoords[0].Y, WHITE);
	Sleep(500);

	Graphic::DeleteTurtleRight(turtleStartingCoords[0].X, turtleStartingCoords[0].Y, WHITE);
	Graphic::DrawTurtleRight(turtleStartingCoords[0].X, turtleStartingCoords[0].Y, WHITE);
}

void GameLoader::ShowTurtleAppearFromSecondGate() {
	Graphic::DrawTurtleLeftAnimation1(portalCoords[1].X, portalCoords[1].Y + 2, WHITE);
	Sleep(500);

	Graphic::DeleteTurtleLeft(portalCoords[1].X, portalCoords[1].Y + 2, AQUA);
	Graphic::DrawPortal(portalCoords[1].X, portalCoords[1].Y, AQUA);

	Graphic::DrawTurtleLeftAnimation2(turtleStoppingCoords[2].X, turtleStoppingCoords[2].Y, WHITE);
	Sleep(500);

	Graphic::DeleteTurtleLeft(turtleStoppingCoords[2].X, turtleStoppingCoords[2].Y, WHITE);
	Graphic::DrawTurtleLeft(turtleStoppingCoords[2].X, turtleStoppingCoords[2].Y, WHITE);
}

void GameLoader::ShowGameLoaderTutorials() {
	Console::SetColor(BRIGHT_WHITE, AQUA);

	int X = 105, Y = 21;
	Console::GotoXY(X, Y);
	cout << "W: Last file";
	Console::GotoXY(X, Y + 1);
	cout << "S: Next file";
	Console::GotoXY(X, Y + 2);
	cout << "X: Delete file";
	Console::GotoXY(X, Y + 3);
	cout << "Enter: Load";
	Console::GotoXY(X, Y + 4);
	cout << "Esc: Menu";
	
	Console::SetColor(BLACK, AQUA);
}

void GameLoader::SetFileList(const vector<string>& fileList) {
	this->fileList = fileList;
}

void GameLoader::UpdateLoadMenu(const string& delFile) {
	if (this->fileList.size() == 0) {
		Sleep(200);
		return;
	}

	string fileName = "SaveFiles/" + delFile;
	if (remove((char*)(fileName.c_str())) == 0) {
		size_t n = fileList.size();
		size_t i = 0;
		for (; i < n; i++)
		{
			if (fileList[i] == delFile)
				break;
		}
		for (; i < n - 1; i++)
		{
			//menu[i] = "";
			fileList[i] = fileList[i + 1];
		}
		fileList.resize(n - 1);

		utility.WriteFileList(fileList);
	}
	else return;
	
}

void GameLoader::ShowSaveFiles(const int& page) {
	Console::SetColor(BLACK, WHITE);
	int index = (page - 1) * 2;
	int space = 12;

	for (int i = 0; i < 2; i++) {
		if (index >= fileList.size()) break;
		Console::GotoXY(nameSignCoords[i].X + 3 + (space - fileList[index].length()) / 2, nameSignCoords[i].Y + 2);
		cout << fileList[index];
		index++;
	}
}

void GameLoader::TurtleNavigator(const int& prevCounter, const char& key) {
	if (key != 'W' && key != 'S' || fileList.size() == 0) return;

	if (prevCounter == 0) {
		TurtleGoFromStartToFirstHouse();
		return;
	}

	switch (prevCounter % 2) {
	case 1:
		switch (key) {
		case 'W':
			if (prevCounter > 1)
				TurtleGoFromFirstHouseToLastPage();
			break;
		case 'S':
			TurtleGoFromFirstToSecondHouse();
			break;
		}
		
		break;
	case 0:
		switch (key) {
		case 'W':
			TurtleGoFromSecondToFirstHouse();
			break;
		case 'S':
			TurtleGoFromSecondHouseToNextPage();
			break;
		}
		
		break;
	}
}

void GameLoader::TurtleGoFromStartToFirstHouse() {
	int X = turtleStartingCoords[0].X, Y = turtleStartingCoords[0].Y;

	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleRight(X += 5, Y += 2, WHITE);
	
	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 5, Y += 1, WHITE);
	}

	for (int i = 0; i < 5; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleRight(X += 4, Y += 1, WHITE);

	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y, WHITE);
	}
	
}

void GameLoader::TurtleGoFromFirstToSecondHouse() {
	int X = turtleStoppingCoords[0].X, Y = turtleStoppingCoords[0].Y;
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleLeft(X, Y, WHITE);

	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
	}

	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 1, Y += 1, WHITE);
	}

	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X, Y += 1, WHITE);

		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 1, Y, WHITE);
	}

	for (int i = 0; i < 4; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 1, Y += 1, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
}

void GameLoader::TurtleGoFromSecondToFirstHouse() {
	int X = turtleStoppingCoords[1].X, Y = turtleStoppingCoords[1].Y;
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleRight(X, Y, WHITE);

	Sleep(100);
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleRight(X += 2, Y, WHITE);

	for (int i = 0; i < 4; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 1, Y -= 1, WHITE);
	}

	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 1, Y, WHITE);

		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X, Y -= 1, WHITE);
	}

	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 1, Y -= 1, WHITE);
	}

	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y, WHITE);
	}
}

void GameLoader::TurtleGoFromSecondHouseToNextPage() {
	int X = turtleStoppingCoords[1].X, Y = turtleStoppingCoords[1].Y;
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleRight(X, Y, WHITE);
	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y, WHITE);
	}

	for (int i = 0; i < 4; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y += 1, WHITE);
	}

	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleRight(X += 1, Y += 1, WHITE);

	for (int i = 0; i < 5; i++) {
		Sleep(100);
		Graphic::DeleteTurtleRight(X, Y, WHITE);
		Graphic::DrawTurtleRight(X += 2, Y, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleRightAnimation2(X, Y, WHITE);
	Sleep(500);
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	X = portalCoords[1].X; Y = portalCoords[1].Y;
	Graphic::DrawTurtleRightAnimation1(X, Y + 2, WHITE);
	PlaySound(TEXT("Sound/teleport.wav"), NULL, SND_ASYNC);
	Sleep(500);
	Graphic::DeleteTurtleRight(X, Y + 2, AQUA);
	Graphic::DrawPortal(X, Y, AQUA);

	ShowTurtleAppearFromFirstGate();

	X = turtleStartingCoords[0].X; Y = turtleStartingCoords[0].Y;
	Graphic::DrawTurtleRight(X, Y, WHITE);

	TurtleGoFromStartToFirstHouse();
}

void GameLoader::TurtleGoFromFirstHouseToLastPage() {
	int X = turtleStoppingCoords[0].X, Y = turtleStoppingCoords[0].Y;
	Graphic::DeleteTurtleRight(X, Y, WHITE);
	Graphic::DrawTurtleLeft(X, Y, WHITE);

	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleLeft(X -= 4, Y -= 1, WHITE);

	for (int i = 0; i < 5; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
	}

	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 5, Y -= 1, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleLeft(X -= 5, Y -= 2, WHITE);

	Sleep(100);
	
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleLeftAnimation2(X, Y, WHITE);
	Sleep(500);

	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleLeftAnimation1(portalCoords[0].X, portalCoords[0].Y + 2, WHITE);
	PlaySound(TEXT("Sound/teleport.wav"), NULL, SND_ASYNC);
	Sleep(500);

	Graphic::DeleteTurtleLeft(portalCoords[0].X, portalCoords[0].Y + 2, AQUA);
	Graphic::DrawPortal(portalCoords[0].X, portalCoords[0].Y, AQUA);
	
	ShowTurtleAppearFromSecondGate();
	Sleep(500);

	TurtleGoFromEndToSecondHouse();
}

void GameLoader::TurtleGoFromEndToSecondHouse() {
	int X = turtleStoppingCoords[2].X, Y = turtleStoppingCoords[2].Y;

	for (int i = 0; i < 5; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
	}

	Sleep(100);
	Graphic::DeleteTurtleLeft(X, Y, WHITE);
	Graphic::DrawTurtleLeft(X -= 1, Y -= 1, WHITE);

	for (int i = 0; i < 2; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
	}

	for (int i = 0; i < 4; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y -= 1, WHITE);
	}

	for (int i = 0; i < 3; i++) {
		Sleep(100);
		Graphic::DeleteTurtleLeft(X, Y, WHITE);
		Graphic::DrawTurtleLeft(X -= 2, Y, WHITE);
	}
	
}