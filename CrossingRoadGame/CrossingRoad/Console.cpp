#include "Console.h"

void Console::FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Console::GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::SetColor(const int& colorText, const int& colorBackGround) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorText + 16 * colorBackGround);
}

void Console::SetConsoleFont(const wchar_t* font) {
    static CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 18;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = 1000;
    (errno_t)wcscpy_s(cfi.FaceName, 32, font); //Change font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Console::ShowConsoleCursor(const bool& flag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInf;
    GetConsoleCursorInfo(out, &cursorInf);
    cursorInf.bVisible = flag;
    SetConsoleCursorInfo(out, &cursorInf);
}

