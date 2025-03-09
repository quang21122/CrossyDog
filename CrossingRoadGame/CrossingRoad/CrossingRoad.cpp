#include "Graphic.h"
#include "Menu.h"
#include "BufferGraphic.h"
#include "MiniGame.h"

int main()
{
	wchar_t font[] = L"Consolas";
	Console::FixConsoleWindow();
	Console::SetConsoleFont(font);
	Console::ShowConsoleCursor(false);

	Console::SetColor(AQUA, AQUA);
	system("cls");

	Menu* menu = new Menu();
	menu->ShowMenu();
	delete menu;
	Console::SetColor(AQUA, AQUA);
	system("cls");
	Console::GotoXY(120, 28);

	return 0;
}
