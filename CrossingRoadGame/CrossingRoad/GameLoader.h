#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Utility.h"
#include "Graphic.h"
class GameLoader
{
private:
	Utility utility;

	vector<string> fileList;
	void SetFileList(const vector<string>& fileList);

	void ShowGameLoaderScreen();
	void ShowGameLoaderTutorials();
	void ShowTurtleAppearFromFirstGate();
	void ShowTurtleAppearFromSecondGate();

	void ShowSaveFiles(const int& page);
	
	void TurtleNavigator(const int& prevCounter, const char& key);
	void TurtleGoFromStartToFirstHouse();
	void TurtleGoFromFirstToSecondHouse();
	void TurtleGoFromSecondToFirstHouse();
	void TurtleGoFromSecondHouseToNextPage();
	void TurtleGoFromFirstHouseToLastPage();
	void TurtleGoFromEndToSecondHouse();

	void UpdateLoadMenu(const string& delFile);
public:
	string ShowGameLoader();
};

