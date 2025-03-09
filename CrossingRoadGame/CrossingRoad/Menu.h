#pragma once
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include "Graphic.h"
#include "Console.h"
#include "GameLoader.h"
#include "Tutorial.h"
#include "Settings.h"
#include "Credits.h"
#include "CGAME.h"
#include "Utility.h"
#include <string>

using namespace std;
class Menu
{
private:
	CGAME game;
	GameLoader gameLoader;
	Tutorial tutorial;
	Settings settings;
	Credits credits;
	Utility utility;
	void DrawMenuScene();
	void ShowTitleScreen();
	void ShowMenuTutorial();

public:
	void ShowMenu();
};

