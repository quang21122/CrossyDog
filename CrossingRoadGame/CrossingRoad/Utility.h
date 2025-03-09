#pragma once
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "Console.h"
#include "Graphic.h"
#include "Player.h"
using namespace std;

class Utility
{
	bool IsInString(const string&, char);
public:
	string GenerateLevelFileName(int);
	string GenerateMiniGameFileName(int);
	string GenerateSaveFileName();
	vector<string> ReadFileList();
	vector<Player> ReadBestPlayerList();
	void WriteFileList(const vector<string>&);
	void WriteBestPlayerList(const vector<Player>&);
	bool IsValidUsername(const string&, int, const string&);
	bool IsValidFileName(const string&, int, const string&);
	bool IsExistent(const string&, const vector<string>&);

	void SortPlayersList(vector<Player>&);
	//dialog
	bool ShowGameOverDialog(int);
	bool ShowCongratsDialog(int);
	string ShowSaveGameDialog();
	string ShowInputUsernameDialog();
	void ShowFullFileContainerNotification();
	bool ShowExitDialog();
	//leaderboard
	void UpdateLeaderboard(int);
	void ShowLeaderBoard();
};

