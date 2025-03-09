#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

class Console {
public:
	static void FixConsoleWindow();
	static void GotoXY(int x, int y);
	static void SetColor(const int& colorText, const int& colorBackGround);
	static void SetConsoleFont(const wchar_t* font);
	static void ShowConsoleCursor(const bool& flag);
};
