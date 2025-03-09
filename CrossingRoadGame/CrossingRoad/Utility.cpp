#include "Utility.h"

bool Utility::IsInString(const string& str, char c){
	for (int i = 0; i < str.length(); i++)
		if (str[i] == c)
			return true;
	return false;
}

string Utility::GenerateLevelFileName(int level)
{
    string prefix = "GameLevels/Level";
    string suffix = ".bin";
    string fileName = to_string(level);

    return prefix+fileName+suffix;
}

string Utility::GenerateMiniGameFileName(int level)
{
	string prefix = "GameLevels/MiniGame";
	string suffix = ".bin";
	string fileName = to_string(level);

	return prefix + fileName + suffix;
}



string Utility::GenerateSaveFileName() {
	const string extension = ".bin";
	char str[26];
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(str, 26, "%d-%m-%y %H.%M.%S", &timeinfo);
	string currentTime = str;

	return currentTime + extension;
}

 vector<string> Utility::ReadFileList() {
	 ifstream fi;
	 fi.open("SaveFiles/FilesMenu.txt", ios::in);
	 
	string temp;
	vector<string> fileList;
	while (!fi.eof()) {
		getline(fi, temp);
		fileList.push_back(temp);
	}

	if (fi) fi.close();

	if (fileList[0] == "")
		fileList.erase(fileList.begin());

	return fileList;
}

 vector<Player> Utility::ReadBestPlayerList() {
	 ifstream fi;
	 fi.open("Leaderboard/BestUser.txt", ios::in);

	 Player temp("",0);
	 vector<Player> playerList;
	 while (fi.peek() != ifstream::traits_type::eof()) {
		 fi >> temp;
		 playerList.push_back(temp);
	 }

	 if (fi) fi.close();

	 return playerList;
 }

 void Utility::WriteFileList(const vector<string>& fileList) {
	 ofstream fo;
	 fo.open("SaveFiles/FilesMenu.txt", ios::out);

	 for (int i = 0; i < fileList.size(); i++) {
		 if (i == fileList.size() - 1)
			 fo << fileList[i];
		 else fo << fileList[i] << "\n";
	 }
	 if (fo) fo.close();
}

 void Utility::WriteBestPlayerList(const vector<Player>& playerList) {
	 ofstream fo;
	 fo.open("Leaderboard/BestUser.txt", ios::out);

	 for (int i = 0; i < playerList.size(); i++) {
		 if (i == playerList.size() - 1)
			 fo << playerList[i];
		 else fo << playerList[i] << "\n";
	 }
	 if (fo) fo.close();
 }

 bool Utility::IsValidUsername(const string& username, int length, const string& specialCharacters) {
	 if (username.length() == 0 || username.length() > length)
		 return false;
	 for (int i = 0; i < username.length(); i++)
		 if (IsInString(specialCharacters, username[i]))
			 return false;
	 return true;
 }

 bool Utility::IsValidFileName(const string& fileName, int length, const string& specialCharacters){
	 if (fileName.length() == 0 || fileName.length() > length)
		 return false;
	 for (int i = 0; i < fileName.length(); i++) 
		 if (IsInString(specialCharacters, fileName[i]))
			 return false;
	 return true;
 }

 bool Utility::IsExistent(const string& fileName, const vector<string>& fileList){
	 for (auto file : fileList)
		 if (fileName == file)
			 return true;
	 return false;
 }

 void Utility::SortPlayersList(vector<Player>& playerList) {

	 if (playerList.size() < 3) {
		 int tempSize = playerList.size();
		 Player temp("Empty", -1);
		 for (int i = 0; i < 3 - tempSize; i++)
			 playerList.push_back(temp);
	 }
	 for (int i = 0; i < playerList.size() - 1; i++)
		 for (int j = i + 1; j < playerList.size(); j++)
			 if (playerList[i] < playerList[j])
				 swap(playerList[i], playerList[j]);
	 swap(playerList[0], playerList[1]);
 }

 bool Utility::ShowGameOverDialog(int score) {
	 int choice = 1;
	 Graphic::ShowBigMainDie();
	 UpdateLeaderboard(score);
	 Graphic::DrawGameOverDialog(); 
	 Graphic::DrawNumber(110, 1, LIGHT_YELLOW, AQUA, score);

	 int frameColor[] = { LIGHT_YELLOW,BLACK };
	 int choiceColor[] = { BLUE,BLACK };

	 while (true) {
		 Graphic::DrawY(37, 25, choiceColor[0], AQUA);
		 Graphic::DrawN(78, 25, choiceColor[1], AQUA);
		 Graphic::DrawSelectBoxForDialog(35, 24, frameColor[0], AQUA);
		 Graphic::DrawSelectBoxForDialog(76, 24, frameColor[1], AQUA);

		 char key = toupper(_getch());
		 switch (key) {
		 case 'A':
			 PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			 if (choice > 1) {
				 swap(frameColor[0], frameColor[1]);
				 swap(choiceColor[0], choiceColor[1]);
				 choice--;
			 }
			 break;
		 case 'D':
			 PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			 if (choice < 2) {
				 swap(frameColor[0], frameColor[1]);
				 swap(choiceColor[0], choiceColor[1]);
				 choice++;
			 }
			 break;
		 case 13:
			 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			 switch (choice) {
			 case 1:
				 return true;
			 case 2:
				 return false;
			 }
		 }
	 }
 }

 bool Utility::ShowCongratsDialog(int score) {
	 system("cls");
	 UpdateLeaderboard(score);
	 int choice = 1;
	 Graphic::DrawCongratsDialog();
	 Graphic::DrawNumber(110, 1, LIGHT_YELLOW, AQUA, score);
	 int frameColor[] = { LIGHT_YELLOW,BLACK };
	 int choiceColor[] = { BLUE,BLACK };

	 while (true) {
		 Graphic::DrawY(37, 24, choiceColor[0], AQUA);
		 Graphic::DrawN(78, 24, choiceColor[1], AQUA);
		 Graphic::DrawSelectBoxForDialog(35, 23, frameColor[0], AQUA);
		 Graphic::DrawSelectBoxForDialog(76, 23, frameColor[1], AQUA);

		 char key = toupper(_getch());
		 switch (key) {
		 case 'A':
			 PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			 if (choice > 1) {
				 swap(frameColor[0], frameColor[1]);
				 swap(choiceColor[0], choiceColor[1]);
				 choice--;
			 }
			 break;
		 case 'D':
			 PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			 if (choice < 2) {
				 swap(frameColor[0], frameColor[1]);
				 swap(choiceColor[0], choiceColor[1]);
				 choice++;
			 }
			 break;
		 case 13:
			 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			 switch (choice) {
			 case 1:
				 return true;
			 case 2:
				 return false;
			 }
		 }
	 }
 }

 string Utility::ShowSaveGameDialog() {
	 const string extension = ".bin";

	 int maxLength = 8;
	 string specialChars = "!@~$`#%^&*()-+= :;\"<>?/";
	 int x = 37, y = 10;
	 string fileName;
	 Graphic::DrawSaveFileDialog(x, y);
	 Console::GotoXY(x + 8, y + 4);
	 getline(cin, fileName);
	 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
	 const vector<string> fileList = ReadFileList();

	 bool isValid = IsValidFileName(fileName, maxLength, specialChars);
	 bool isInFileList = IsExistent(fileName + extension, fileList);

	 while (!isValid || isInFileList) {
		 Console::GotoXY(x + 18, y + 5);
		 cout << "Failed to save";
		 if (!isValid) {
			 Console::GotoXY(x + 14, y + 6);
			 cout << "Input valid file name";
		 }
		 else {
			 Console::GotoXY(x + 2, y + 6);
			 Console::SetColor(RED, BRIGHT_WHITE);
			 cout << fileName;
			 Console::SetColor(BLACK, BRIGHT_WHITE);
			 cout << " is already in file list";
		 }

		 Sleep(1500);
		 Graphic::DrawSaveFileDialog(x, y);
		 Console::GotoXY(x + 8, y + 4);
		 getline(cin, fileName);
		 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
		 isValid = IsValidFileName(fileName, maxLength, specialChars);
		 isInFileList = IsExistent(fileName + extension, fileList);
	 }
	 Console::GotoXY(x + 16, y + 5);
	 cout << "Saved successfully";
	 Sleep(1000);
	 return fileName;
 }

 string Utility::ShowInputUsernameDialog(){
	 int maxLength = 8;
	 string specialChars = "!@~$`#%^&*()-+= :;\"<>?/";
	 int x = 37, y = 10;
	 string username;
	 Graphic::DrawInputUsernameDialog(x, y);
	 Console::GotoXY(x + 8, y + 4);
	 getline(cin, username);
	 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);

	 const vector<Player> playerList = ReadBestPlayerList();

	 bool isValid = IsValidUsername(username, maxLength, specialChars);

	 while (!isValid) {
		 Console::GotoXY(x + 18, y + 5);
		 cout << "Failed to store";
		 if (!isValid) {
			 Console::GotoXY(x + 14, y + 6);
			 cout << "Input valid username";
		 }
		 else {
			 Console::GotoXY(x + 2, y + 6);
			 Console::SetColor(RED, BRIGHT_WHITE);
			 cout << username;
			 Console::SetColor(BLACK, BRIGHT_WHITE);
			 cout << " is already in best players list";
		 }

		 Sleep(1500);
		 Graphic::DrawInputUsernameDialog(x, y);
		 Console::GotoXY(x + 8, y + 4);
		 getline(cin, username);
		 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
		 isValid = IsValidUsername(username, maxLength, specialChars);
	 }

	 Console::GotoXY(x + 16, y + 5);
	 cout << "Store successfully";
	 Sleep(1000);
	 return username;
 }

 void Utility::ShowFullFileContainerNotification() {
	 int x = 36, y = 10;
	 Graphic::DrawFullFileContainerNotification(x, y);
	 Sleep(1500);
 }

 bool Utility::ShowExitDialog() {
	 int choice = 1;
	 int x = 40, y = 10;
	 Graphic::DrawEscDialog(x, y);

	 int choiceColor[] = { RED, BLUE };
	 pair<int, int> frameCoord[] = { {x + 4,y + 3},{x + 22,y + 3} };

	 while (true) {
		 for (int i = 0; i < 2; i++)
			 Graphic::DrawBox(frameCoord[i].first, frameCoord[i].second, 7, 3, BRIGHT_WHITE, BRIGHT_WHITE);

		 Graphic::DrawBox(frameCoord[choice - 1].first, frameCoord[choice - 1].second, 7, 3, choiceColor[choice - 1], BRIGHT_WHITE);
		 Console::SetColor(RED, BRIGHT_WHITE);
		 Console::GotoXY(x + 6, y + 4);
		 cout << "Yes";

		 Console::GotoXY(x + 25, y + 4);
		 Console::SetColor(BLUE, BRIGHT_WHITE);
		 cout << "No";

		 char key = toupper(_getch());
		 switch (key) {
		 case 'A':
			 PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			 if (choice > 1)
				 choice--;
			 break;
		 case 'D':
			 PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
			 if (choice < 2)
				 choice++;
			 break;
		 case 13:
			 PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			 switch (choice) {
			 case 1:
				 return true;
			 case 2:
				 return false;
			 }
		 }
	 }
 }

 void Utility::UpdateLeaderboard(int score) {
	 string username = ShowInputUsernameDialog();
	 Player newPlayer(username, score);
	 vector<Player> playerList = ReadBestPlayerList();
	 playerList.push_back(newPlayer);
	 SortPlayersList(playerList);
	 if (playerList.size() > 3)
		 playerList.erase(playerList.begin() + 3);
	 WriteBestPlayerList(playerList);
 }

 void Utility::ShowLeaderBoard() {
	 system("cls");
	 vector<Player> playerList = ReadBestPlayerList();
	 Graphic::ShowLeaderBoard();
	 int space = 0;
	 int backgroundColor[] = { LIGHT_BLUE,RED,YELLOW };
	 int elevation[] = { 2,4,0 };
	 for (int i = 0; i < playerList.size(); i++) {
		 Console::GotoXY(space + 36 + (15 - playerList[i].GetUsername().length()) / 2, 24 - elevation[i]);
		 Console::SetColor(LIGHT_YELLOW, backgroundColor[i]);
		 cout << playerList[i].GetUsername();
		 Console::GotoXY(space + 35 + 7, 25 - elevation[i]);
		 Console::SetColor(BLACK, backgroundColor[i]);
		 cout << setw(3) << setfill('0') << playerList[i].GetScore();
		 space += 16;
	 }
	 _getch();
 }
