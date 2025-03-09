#include "Graphic.h"
static const int xSizeOfBlock = 10;
static const int ySizeOfBlock = 5;
static const int lengthOfMainGameScreen = 90;
static const int lengthOfGameInfoScreen = 20;


void Graphic::DrawFrog(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(WHITE, AQUA);
    Console::GotoXY(X, Y);
    cout << u8"   ▄   ▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"  ▀▄▀ ▀▄▀";
    Console::SetColor(GREEN, AQUA);
    Console::GotoXY(X, Y + 2);
    cout << u8" █████████";
    Console::GotoXY(X, Y + 3);
    Console::SetColor(GREEN, GRAY);
    cout << u8"████▀▀▀▄███";
    Console::GotoXY(X, Y + 4);
    Console::SetColor(GREEN, background);
    cout << u8" █████████";
    Console::GotoXY(X, Y + 5);
    cout << u8" ▀▀█▀▀▀█▀▀";
    Console::GotoXY(X, Y + 6);
    cout << u8"  ▀ ▀ ▀ ▀";
    Console::GotoXY(X + 3, Y + 1);
    Console::SetColor(WHITE, BLACK);
    cout << u8"▄";
    Console::GotoXY(X + 7, Y + 1);
    cout << u8"▄";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawJumpingFrog(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(WHITE, AQUA);
    Console::GotoXY(X, Y);
    cout << u8"   ▄   ▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"  ▀▄▀ ▀▄▀";
    Console::SetColor(GREEN, AQUA);
    Console::GotoXY(X, Y + 2);
    cout << u8" █████████";
    Console::GotoXY(X, Y + 3);
    Console::SetColor(GREEN, GRAY);
    cout << u8"████▀▀▀▄███";
    Console::GotoXY(X, Y + 4);
    Console::SetColor(GREEN, background);
    cout << u8" █████████";
    Console::GotoXY(X, Y + 5);
    cout << u8" ▀███▀███▀";
    Console::GotoXY(X + 3, Y + 1);
    Console::SetColor(WHITE, BLACK);
    cout << u8"▄";
    Console::GotoXY(X + 7, Y + 1);
    cout << u8"▄";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DeleteFrog(int x, int y) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(WHITE, AQUA);
    Console::GotoXY(X, Y);
    cout << u8"         ";
    Console::GotoXY(X, Y + 1);
    cout << u8"         ";
    Console::SetColor(GREEN, AQUA);
    Console::GotoXY(X, Y + 2);
    cout << u8"          ";
    Console::GotoXY(X, Y + 3);
    Console::SetColor(GREEN, AQUA);
    cout << u8"           ";
    Console::GotoXY(X, Y + 4);
    Console::SetColor(GREEN, AQUA);
    cout << u8"           ";
    Console::GotoXY(X, Y + 5);
    cout << u8"           ";
    Console::GotoXY(X, Y + 6);
    cout << u8"          ";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawDuck(int x, int y, int background)
{
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(YELLOW, background);
    Console::GotoXY(X, Y);
    cout << u8"    ▄▄▄▄▄▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"   ██▄█████";
    Console::GotoXY(X, Y + 2);
    cout << u8" ▀▀███████▀";
    Console::GotoXY(X, Y + 3);
    cout << u8"    ███████████";
    Console::GotoXY(X, Y + 4);
    cout << u8"   ████████▀█████▄";
    Console::GotoXY(X, Y + 5);
    cout << u8"   ▀███▄▄▄▄██████▀";
    Console::GotoXY(X, Y + 6);
    cout << u8"    ▀▀▀▀▀▀▀▀▀▀▀▀";

    Console::GotoXY(X + 5, Y + 1);
    Console::SetColor(YELLOW, BLACK);
    cout << u8"▄";
    Console::SetColor(YELLOW, GRAY);
    Console::GotoXY(X + 11, Y + 4);
    cout << u8"▀";
    Console::GotoXY(X + 7, Y + 5);
    cout << u8"▄▄▄▄";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawLotus(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(LIGHT_RED, background);
    Console::GotoXY(X, Y);
    cout << u8"           ▄█▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"          █████";
    Console::GotoXY(X, Y + 2);
    cout << u8"     ██▄▄ █████ ▄▄██";
    Console::GotoXY(X, Y + 3);
    cout << u8" ▄▄  ███████████████  ▄▄";
    Console::GotoXY(X, Y + 4);
    cout << u8"█████████████████████████";
    Console::GotoXY(X, Y + 5);
    cout << u8" ███████████████████████";
    Console::GotoXY(X, Y + 6);
    cout << u8"  █████████████████████";
    Console::GotoXY(X, Y + 7);
    cout << u8"    █████████████████";
    Console::GotoXY(X, Y + 8);
    Console::SetColor(GREEN, background);
    cout << u8"▄▄████████████████████▄▄";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawLeaf(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(GREEN, LIGHT_GREEN);
    Console::GotoXY(X, Y);
    cout << u8" ▄▄▄█▀▀▀▀▀▀▀█▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"▄█           ▀█";
    Console::GotoXY(X, Y + 2);
    cout << u8"█             █";
    Console::GotoXY(X, Y + 3);
    cout << u8"█             █";
    Console::GotoXY(X, Y + 4);
    cout << u8"█            █▀";
    Console::GotoXY(X, Y + 5);
    cout << u8"▀█▄▄▄▄▄    ▄█▀";
    Console::GotoXY(X, Y + 6);
    cout << u8"      ▀▀▀▀▀▀";

    Console::SetColor(GREEN, background);
    Console::GotoXY(X, Y);
    cout << u8" ▄▄▄";
    Console::GotoXY(X + 13, Y);
    cout << u8"▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"▄";
    Console::GotoXY(X + 14, Y + 4);
    cout << u8"▀";
    Console::GotoXY(X, Y + 5);
    cout << u8"▀";
    Console::GotoXY(X + 13, Y + 5);
    cout << u8"▀";
    Console::GotoXY(X, Y + 6);
    cout << u8"      ▀▀▀▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTitle(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_RED, background);
    Console::GotoXY(X + 2, Y);
    cout << u8"████████    ███████████     ████████      ███████████    ███████████  ██████  █████      █████    ███████████";
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"█        █   █          █   █        █    █          █   █          █  █    █  █    █     █   █   █          █";
    Console::GotoXY(X, Y + 2);
    cout << u8"█   ████   █  █   ████   █  █    ██    █  █    ████████  █    ████████  █    █  █     █    █   █  █   █████████";
    Console::GotoXY(X, Y + 3);
    cout << u8"█  █    ████  █   ████   █  █   █  █   █  █   █          █   █          █    █  █   █  █   █   █  █   █";
    Console::GotoXY(X, Y + 4);
    cout << u8"█  █          █   ████   █  █   █  █   █  █    ███████   █    ███████   █    █  █   ██  █  █   █  █   █";
    Console::GotoXY(X, Y + 5);
    cout << u8"█  █          █         █   █   █  █   █   █          █   █          █  █    █  █   █ █  █ █   █  █   █  ██████";
    Console::GotoXY(X, Y + 6);
    cout << u8"█  █          █   ████   █  █   █  █   █    ███████    █   ███████    █ █    █  █   █  █  ██   █  █   █  █    █";
    Console::GotoXY(X, Y + 7);
    cout << u8"█  █    ████  █   █  █   █  █   █  █   █           █   █          █   █ █    █  █   █   █  █   █  █   █   █   █";
    Console::GotoXY(X, Y + 8);
    cout << u8"█   ████   █  █   █  █   █  █    ██    █  █████████    █ █████████    █ █    █  █   █    █     █  █   █████   █";
    Console::GotoXY(X + 1, Y + 9);
    cout << u8"█        █   █   █  █   █   █        █   █           █  █           █  █    █  █   █     █    █   █          █";
    Console::GotoXY(X + 2, Y + 10);
    cout << u8"████████    █████  █████    ████████    ████████████   ████████████   ██████  █████      █████    ███████████";
    Console::GotoXY(X + 28, Y + 12);
    cout << u8"███████████     ████████       ███████████  ███████████";
    Console::GotoXY(X + 28, Y + 13);
    cout << u8"█          █   █        █     █          █  █         ██ ";
    Console::GotoXY(X + 28, Y + 14);
    cout << u8"█   ████   █  █    ██    █   █   █████   █  █   ████    █";
    Console::GotoXY(X + 28, Y + 15);
    cout << u8"█   ████   █  █   █  █   █  █   ██████   █  █   █   █   █";
    Console::GotoXY(X + 28, Y + 16);
    cout << u8"█   ████   █  █   █  █   █  █   ██████   █  █   █   █   █";
    Console::GotoXY(X + 28, Y + 17);
    cout << u8"█         █   █   █  █   █  █            █  █   █   █   █";
    Console::GotoXY(X + 28, Y + 18);
    cout << u8"█   ████   █  █   █  █   █  █    ████    █  █   █   █   █";
    Console::GotoXY(X + 28, Y + 19);
    cout << u8"█   █  █   █  █   █  █   █  █    █  █    █  █   █   █   █";
    Console::GotoXY(X + 28, Y + 20);
    cout << u8"█   █  █   █  █    ██    █  █    █  █    █  █   ████    █";
    Console::GotoXY(X + 28, Y + 21);
    cout << u8"█   █  █   █   █        █   █    █  █    █  █         ██";
    Console::GotoXY(X + 28, Y + 22);
    cout << u8"█████  █████    ████████    ██████  ██████  ███████████";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawMenuChooseFrame(int x, int y, int background){
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"██████";
    Console::GotoXY(X + 14, Y);
    cout << u8"██████";
    Console::GotoXY(X, Y + 1);
    cout << u8"█";
    Console::GotoXY(X, Y + 2);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 1);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 2);
    cout << u8"█";
    Console::GotoXY(X, Y + 4);
    cout << u8"█";
    Console::GotoXY(X, Y + 5);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 4);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 5);
    cout << u8"█";
    Console::GotoXY(X, Y + 6);
    cout << u8"██████";
    Console::GotoXY(X + 14, Y + 6);
    cout << u8"██████";

    SetConsoleOutputCP(oldcp);
}


void Graphic::DrawSettingsWord(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(PURPLE, background);
    Console::GotoXY(X + 2, Y);
    cout << u8"███████████     ███████████  ██████████████  ██████████████  ██████  █████      █████    ███████████    ███████████";
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"█          █    █          █  █            █  █            █  █    █  █    █     █   █   █          █   █          █";
    Console::GotoXY(X, Y + 2);
    cout << u8"█    ████████   █   █████████  █            █  █            █  █    █  █     █    █   █  █   █████████  █    ████████";
    Console::GotoXY(X, Y + 3);
    cout << u8"█   █           █   █          █████    █████  █████    █████  █    █  █   █  █   █   █  █   █          █   █";
    Console::GotoXY(X, Y + 4);
    cout << u8"█    ███████    █   █████████      █    █          █    █      █    █  █   ██  █  █   █  █   █          █    ███████";
    Console::GotoXY(X + 1, Y + 5);
    cout << u8"█          █   █           █      █    █          █    █      █    █  █   █ █  █ █   █  █   █  ██████   █          █";
    Console::GotoXY(X + 2, Y + 6);
    cout << u8"███████    █  █   █████████      █    █          █    █      █    █  █   █  █  ██   █  █   █  █    █    ███████    █";
    Console::GotoXY(X + 9, Y + 7);
    cout << u8"█   █  █   █              █    █          █    █      █    █  █   █   █  █   █  █   █   █   █           █   █";
    Console::GotoXY(X, Y + 8);
    cout << u8"█████████    █  █   █████████      █    █          █    █      █    █  █   █    █     █  █   █████   █  █████████    █";
    Console::GotoXY(X, Y + 9);
    cout << u8"█           █    █          █      █    █          █    █      █    █  █   █     █    █   █          █  █           █";
    Console::GotoXY(X, Y + 10);
    cout << u8"████████████      ███████████      ██████          ██████      ██████  █████      █████    ███████████  ████████████";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawMuteIcon(int x, int y) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, RED);
    Console::GotoXY(X + 9, Y);
    cout << u8"██";
    Console::GotoXY(X + 8, Y + 1);
    cout << u8"█ █";
    Console::GotoXY(X + 7, Y + 2);
    cout << u8"█  █";
    Console::GotoXY(X, Y + 3);
    cout << u8"███████   █";
    Console::GotoXY(X, Y + 4);
    cout << u8"█         █";
    Console::GotoXY(X, Y + 5);
    cout << u8"█         █";
    Console::GotoXY(X, Y + 6);
    cout << u8"█         █";
    Console::GotoXY(X, Y + 7);
    cout << u8"███████   █";
    Console::GotoXY(X + 7, Y + 8);
    cout << u8"█  █";
    Console::GotoXY(X + 8, Y + 9);
    cout << u8"█ █";
    Console::GotoXY(X + 9, Y + 10);
    cout << u8"██";

    Console::GotoXY(X + 15, Y + 2);
    cout << u8"█";
    Console::GotoXY(X + 14, Y + 3);
    cout << u8"█ █";
    Console::GotoXY(X + 15, Y + 4);
    cout << u8"█ █ █";
    Console::GotoXY(X + 16, Y + 5);
    cout << u8"█ █";
    Console::GotoXY(X + 15, Y + 6);
    cout << u8"█ █ █";
    Console::GotoXY(X + 14, Y + 7);
    cout << u8"█ █";
    Console::GotoXY(X + 15, Y + 8);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 2);
    cout << u8"█";
    Console::GotoXY(X + 18, Y + 3);
    cout << u8"█ █";
    Console::GotoXY(X + 18, Y + 7);
    cout << u8"█ █";
    Console::GotoXY(X + 19, Y + 8);
    cout << u8"█";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawUnmuteIcon(int x, int y) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, GREEN);
    Console::GotoXY(X + 9, Y);
    cout << u8"██";
    Console::GotoXY(X + 8, Y + 1);
    cout << u8"█ █";
    Console::GotoXY(X + 7, Y + 2);
    cout << u8"█  █";
    Console::GotoXY(X, Y + 3);
    cout << u8"███████   █";
    Console::GotoXY(X, Y + 4);
    cout << u8"█         █";
    Console::GotoXY(X, Y + 5);
    cout << u8"█         █";
    Console::GotoXY(X, Y + 6);
    cout << u8"█         █";
    Console::GotoXY(X, Y + 7);
    cout << u8"███████   █";
    Console::GotoXY(X + 7, Y + 8);
    cout << u8"█  █";
    Console::GotoXY(X + 8, Y + 9);
    cout << u8"█ █";
    Console::GotoXY(X + 9, Y + 10);
    cout << u8"██";

    Console::GotoXY(X + 13, Y + 2);
    cout << u8"██";
    Console::GotoXY(X + 13, Y + 3);
    cout << u8"█ █";
    Console::GotoXY(X + 14, Y + 4);
    cout << u8"█ █";
    Console::GotoXY(X + 14, Y + 5);
    cout << u8"█ █";
    Console::GotoXY(X + 14, Y + 6);
    cout << u8"█ █";
    Console::GotoXY(X + 13, Y + 7);
    cout << u8"█ █";
    Console::GotoXY(X + 13, Y + 8);
    cout << u8"██";

    Console::GotoXY(X + 18, Y + 1);
    cout << u8"███";
    Console::GotoXY(X + 18, Y + 2);
    cout << u8"█  █";
    Console::GotoXY(X + 19, Y + 3);
    cout << u8"█  █";
    Console::GotoXY(X + 20, Y + 4);
    cout << u8"█  █";
    Console::GotoXY(X + 20, Y + 5);
    cout << u8"█  █";
    Console::GotoXY(X + 20, Y + 6);
    cout << u8"█  █";
    Console::GotoXY(X + 19, Y + 7);
    cout << u8"█  █";
    Console::GotoXY(X + 18, Y + 8);
    cout << u8"█  █";
    Console::GotoXY(X + 18, Y + 9);
    cout << u8"███";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawOnWord(int x, int y, int color, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(X, Y);
    cout << u8" ██  █  █";
    Console::GotoXY(X, Y + 1);
    cout << u8"█  █ ██ █";
    Console::GotoXY(X, Y + 2);
    cout << u8"█  █ █ ██";
    Console::GotoXY(X, Y + 3);
    cout << u8" ██  █  █";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawOffWord(int x, int y, int color, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(X, Y);
    cout << u8" ██  ████ ████";
    Console::GotoXY(X, Y + 1);
    cout << u8"█  █ █    █   ";
    Console::GotoXY(X, Y + 2);
    cout << u8"█  █ █▀▀▀ █▀▀▀";
    Console::GotoXY(X, Y + 3);
    cout << u8" ██  █    █   ";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawWhale(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, LIGHT_AQUA);
    Console::GotoXY(X + 2, Y);
    cout << u8"████████████";
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"█            █████";
    Console::GotoXY(X, Y + 2);
    cout << u8"█                  █";
    Console::GotoXY(X, Y + 3);
    cout << u8"█    ██             █";
    Console::GotoXY(X, Y + 4);
    cout << u8"█                    █";
    Console::GotoXY(X, Y + 5);
    cout << u8"█                    █████    █";
    Console::GotoXY(X + 1, Y + 6);
    cout << u8"█                            █";
    Console::GotoXY(X + 2, Y + 7);
    cout << u8"████████████ ███████████████";
    Console::GotoXY(X + 4, Y + 8);
    cout << u8"███";
    Console::GotoXY(X + 14, Y + 8);
    cout << u8"███";
    Console::GotoXY(X + 26, Y + 1);
    cout << u8"██";
    Console::GotoXY(X + 29, Y + 1);
    cout << u8"██";
    Console::GotoXY(X + 25, Y + 2);
    cout << u8"█  █  █";
    Console::GotoXY(X + 25, Y + 3);
    cout << u8"█     █";
    Console::GotoXY(X + 26, Y + 4);
    cout << u8"█   █";
    Console::GotoXY(X + 12, Y + 6);
    cout << u8"█";

    Console::SetColor(BRIGHT_WHITE, background);
    Console::GotoXY(X + 1, Y + 5);
    cout << u8"███████████";
    Console::GotoXY(X + 2, Y + 6);
    cout << u8"██████████";
    Console::GotoXY(X + 16, Y + 6);
    cout << u8"████";

    SetConsoleOutputCP(oldcp);
}


void Graphic::DrawJellyFish(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_RED, background);
    Console::GotoXY(X, Y);
    cout << u8"  █████████";
    Console::GotoXY(X, Y + 1);
    cout << u8" ███████████";
    Console::GotoXY(X, Y + 2);
    cout << u8"█████████████";
    Console::GotoXY(X, Y + 3);
    cout << u8"█████████████";
    Console::GotoXY(X, Y + 4);
    cout << u8"█████████████";
    Console::GotoXY(X, Y + 5);
    cout << u8" ███████████";
    Console::GotoXY(X, Y + 6);
    cout << u8" █  █  █  █";
    Console::GotoXY(X, Y + 7);
    cout << u8"██  █  █ █";
    Console::GotoXY(X, Y + 8);
    cout << u8"█  █  █   █";
    Console::GotoXY(X, Y + 9);
    cout << u8" █ █  ██  █";
    Console::GotoXY(X, Y + 10);
    cout << u8" █     █ █";

    Console::SetColor(BLACK, background);
    Console::GotoXY(X + 3, Y + 2);
    cout << u8"█";
    Console::GotoXY(X + 9, Y + 2);
    cout << u8"█";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(X + 2, Y + 3);
    cout << u8"██";
    Console::GotoXY(X + 9, Y + 3);
    cout << u8"██";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawWaterSurface() {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_AQUA, AQUA);
    Console::GotoXY(50, 1);
    cout << u8"████████";
    Console::GotoXY(58, 2);
    cout << u8"██████";
    Console::GotoXY(74, 5);
    cout << u8"████████";
    Console::GotoXY(82, 6);
    cout << u8"██████";
    Console::GotoXY(65, 9);
    cout << u8"████████";
    Console::GotoXY(34, 11);
    cout << u8"██████";
    Console::GotoXY(99, 3);
    cout << u8"████████";
    Console::GotoXY(7, 16);
    cout << u8"██████";
    Console::GotoXY(15, 23);
    cout << u8"████████";
    Console::GotoXY(98, 26);
    cout << u8"██████";
    Console::GotoXY(57, 19);
    cout << u8"████████";
    Console::GotoXY(104, 27);
    cout << u8"████████";
    Console::GotoXY(53, 25);
    cout << u8"██████";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawChooseFrame(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"██████";
    Console::GotoXY(X + 14, Y);
    cout << u8"██████";
    Console::GotoXY(X, Y + 1);
    cout << u8"█";
    Console::GotoXY(X, Y + 2);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 1);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 2);
    cout << u8"█";
    Console::GotoXY(X, Y + 5);
    cout << u8"█";
    Console::GotoXY(X, Y + 6);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 5);
    cout << u8"█";
    Console::GotoXY(X + 19, Y + 6);
    cout << u8"█";
    Console::GotoXY(X, Y + 7);
    cout << u8"██████";
    Console::GotoXY(X + 14, Y + 7);
    cout << u8"██████";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DeleteChooseFrame(int x, int y, int background) {
    int X = x, Y = y;
    Console::SetColor(background, background);

    Console::GotoXY(X, Y);
    cout << u8"      ";
    Console::GotoXY(X + 14, Y);
    cout << u8"      ";
    Console::GotoXY(X, Y + 1);
    cout << u8" ";
    Console::GotoXY(X, Y + 2);
    cout << u8" ";
    Console::GotoXY(X + 19, Y + 1);
    cout << u8" ";
    Console::GotoXY(X + 19, Y + 2);
    cout << u8" ";
    Console::GotoXY(X, Y + 5);
    cout << u8" ";
    Console::GotoXY(X, Y + 6);
    cout << u8" ";
    Console::GotoXY(X + 19, Y + 5);
    cout << u8" ";
    Console::GotoXY(X + 19, Y + 6);
    cout << u8" ";
    Console::GotoXY(X, Y + 7);
    cout << u8"      ";
    Console::GotoXY(X + 14, Y + 7);
    cout << u8"      ";
}

void Graphic::DeleteOnWord(int x, int y, int background) {
    int X = x, Y = y;
    Console::SetColor(background, background);

    Console::GotoXY(X, Y);
    cout << u8"         ";
    Console::GotoXY(X, Y + 1);
    cout << u8"         ";
    Console::GotoXY(X, Y + 2);
    cout << u8"         ";
    Console::GotoXY(X, Y + 3);
    cout << u8"         ";
}

void Graphic::DeleteOffWord(int x, int y, int background) {
    int X = x, Y = y;
    Console::SetColor(background, background);

    Console::GotoXY(X, Y);
    cout << u8"              ";
    Console::GotoXY(X, Y + 1);
    cout << u8"              ";
    Console::GotoXY(X, Y + 2);
    cout << u8"              ";
    Console::GotoXY(X, Y + 3);
    cout << u8"              ";
}

void Graphic::DrawCloud(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(BRIGHT_WHITE, background);
    Console::GotoXY(X, Y);
    cout << u8"            █████████████████████       ";
    Console::GotoXY(X, Y + 1);
    cout << u8"   ██████████████████████████████████   ";
    Console::GotoXY(X, Y + 2);
    cout << u8"████████████████████████████████████████";
    Console::GotoXY(X, Y + 3);
    cout << u8"  █████████████████████████████████████ ";
    Console::GotoXY(X, Y + 4);
    cout << u8"    ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀       ";

    Console::SetColor(WHITE, background);
    Console::GotoXY(X + 11, Y);
    cout << u8"▄";
    Console::GotoXY(X + 33, Y);
    cout << u8"▄";
    Console::GotoXY(X + 2, Y + 1);
    cout << u8"▄";
    Console::GotoXY(X + 37, Y + 1);
    cout << u8"▄";
    Console::GotoXY(X + 1, Y + 3);
    cout << u8"▀";
    Console::GotoXY(X + 3, Y + 4);
    cout << u8"▀";
    Console::GotoXY(X + 33, Y + 4);
    cout << u8"▀";
    Console::SetColor(WHITE, BRIGHT_WHITE);
    Console::GotoXY(X + 5, Y + 4);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DeleteCloud(int x, int y, int background) {
    int X = x, Y = y;
    Console::SetColor(background, background);
    Console::GotoXY(X, Y);
    cout << "                                        ";
    Console::GotoXY(X, Y + 1);
    cout << "                                        ";
    Console::GotoXY(X, Y + 2);
    cout << "                                        ";
    Console::GotoXY(X, Y + 3);
    cout << "                                        ";
    Console::GotoXY(X, Y + 4);
    cout << "                                        ";
}

void Graphic::DrawSun(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(X, Y);
    cout << u8"  ▄██████▄  ";
    Console::GotoXY(X, Y + 1);
    cout << u8" ██████████ ";
    Console::GotoXY(X, Y + 2);
    cout << u8"████████████";
    Console::GotoXY(X, Y + 3);
    cout << u8" ██████████ ";
    Console::GotoXY(X, Y + 4);
    cout << u8"  ▀██████▀  ";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawGroupTitle(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(LIGHT_RED, background);
    Console::GotoXY(X, Y);
    cout << u8" ██████  ██████   ██████  ██    ██ ██████       ██";
    Console::GotoXY(X, Y + 1);
    cout << u8"██       ██   ██ ██    ██ ██    ██ ██   ██     ███";
    Console::GotoXY(X, Y + 2);
    cout << u8"██   ███ ██████  ██    ██ ██    ██ ██████       ██";
    Console::GotoXY(X, Y + 3);
    cout << u8"██    ██ ██   ██ ██    ██ ██    ██ ██           ██";
    Console::GotoXY(X, Y + 4);
    cout << u8" ██████  ██   ██  ██████   ██████  ██           ██";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawPlaneWithThankBanner(int x, int y, int background) {
    int X = x, Y = y;
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(RED, background);
    Console::GotoXY(X, Y);
    cout << u8"                              ▄█                           ";
    Console::GotoXY(X, Y + 1);
    cout << u8"                            ▄███                           ";
    Console::GotoXY(X, Y + 2);
    cout << u8"                          ▄█████ ██████████████████████████";
    Console::GotoXY(X, Y + 3);
    cout << u8"    ▄▄█████████████████████████▄▄██████████████████████████";
    Console::GotoXY(X, Y + 4);
    cout << u8" ▄▄████████████████████████████  ██████████████████████████";
    Console::GotoXY(X, Y + 5);
    cout << u8"█████████████████████████▀▀▀                               ";
    Console::GotoXY(X, Y + 6);
    cout << u8" ▀▀██████████████████▀▀                                    ";
    Console::GotoXY(X, Y + 6);
    cout << u8"           ▀█████▄                                         ";
    Console::GotoXY(X, Y + 7);
    cout << u8"             ▀████▄                                        ";
    Console::GotoXY(X, Y + 8);
    cout << u8"               ▀▀▀▀▀                                       ";

    Console::SetColor(WHITE, background);
    Console::GotoXY(X + 4, Y + 3);
    cout << u8"▄▄";
    Console::SetColor(WHITE, RED);
    Console::GotoXY(X + 3, Y + 4);
    cout << u8"▀▀▀";

    Console::SetColor(WHITE, RED);
    for (int i = 9; i <= 23; i += 2) {
        Console::GotoXY(X + i, Y + 3);
        cout << u8"▄";
    }

    Console::SetColor(WHITE, RED);
    Console::GotoXY(X, Y + 5);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y + 6);
    cout << u8" ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀                                    ";

    Console::SetColor(RED, BLACK);
    Console::GotoXY(X + 11, Y + 6);
    cout << u8"▄▄▄▄▄▄";

    Console::SetColor(BRIGHT_WHITE, RED);
    Console::GotoXY(X + 12, Y + 4);
    cout << "ToanThinhAir";

    Console::SetColor(GRAY, background);
    Console::GotoXY(X + 31, Y + 3);
    cout << u8"▄▄";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(X + 33, Y + 2);
    cout << u8"██████████████████████████";
    Console::GotoXY(X + 33, Y + 3);
    cout << u8"██████████████████████████";
    Console::GotoXY(X + 33, Y + 4);
    cout << u8"██████████████████████████";

    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(X + 37, Y + 2);
    cout << "Special Thanks To";
    Console::GotoXY(X + 40, Y + 3);
    cout << "Our Teacher";
    Console::GotoXY(X + 36, Y + 4);
    cout << "Dr. Truong Toan Thinh";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DeletePlaneWithThankBanner(int x, int y, int background) {
    int X = x, Y = y;
    Console::SetColor(background, background);
    Console::GotoXY(X, Y);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 1);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 2);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 3);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 4);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 5);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 6);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 6);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 7);
    cout << u8"                                                           ";
    Console::GotoXY(X, Y + 8);
    cout << u8"                                                           ";
}

void Graphic::DrawMainDisappear1(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 4, y);
    cout << u8"▄   ▄";

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 7, y);
    cout << u8"▄";

    Console::SetColor(BLACK, background);
    Console::GotoXY(x, y + 1);
    cout << u8"▄   ▄   ▀";

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 5, y + 1);
    cout << u8"█▄▀";

    Console::SetColor(BLACK, background);
    Console::GotoXY(x, y + 2);
    cout << u8"▄   ▀    ▀";

    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(x + 8, y + 2);
    cout << u8"▄";

    Console::SetColor(BLACK, LIGHT_BLUE);
    Console::GotoXY(x + 1, y + 2);
    cout << u8"▄▀";

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 3, y + 2);
    cout << u8"▄";
    Console::GotoXY(x + 5, y + 2);
    cout << u8"▀▄";

    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 1, y + 3);
    cout << u8"▀  ▄   ▄";

    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(x + 6, y + 3);
    cout << u8"▄";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(x + 3, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 5, y + 3);
    cout << u8"▄";

    Console::SetColor(LIGHT_YELLOW, LIGHT_BLUE);
    Console::GotoXY(x + 7, y + 3);
    cout << u8"▄";

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 2, y + 3);
    cout << u8"▀";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(x + 3, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 5, y + 3);
    cout << u8"▀";

    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 2, y + 4);
    cout << u8"▀▀";
    Console::GotoXY(x + 7, y + 4);
    cout << u8"▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawMainDisappear2(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 5, y + 1);
    cout << u8"▀ ";

    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 2, y + 2);
    cout << u8"  ";
    Console::GotoXY(x + 8, y + 2);
    cout << u8"▄ ";


    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 3, y + 3);
    cout << u8" ";
    Console::GotoXY(x + 7, y + 3);
    cout << u8"▀ ";


    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 7, y + 4);
    cout << u8" ▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawMainDisappear3(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, background);
    Console::GotoXY(x, y + 1);
    cout << u8"▄       ▀";

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 1, y + 2);
    cout << u8"▀    ▀";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(x + 5, y + 3);
    cout << u8"▀";

    Console::SetColor(LIGHT_YELLOW, BLACK);
    Console::GotoXY(x + 6, y + 3);
    cout << u8"▀";

    Console::SetColor(LIGHT_BLUE, background);
    Console::GotoXY(x + 7, y + 3);
    cout << u8"▀";

    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 2, y + 4);
    cout << u8"▀";
    Console::GotoXY(x + 8, y + 4);
    cout << u8"▀";
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawNameSign(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    int X = x, Y = y;
    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(X, Y + 4);
    cout << u8"▀▀▀▀▀▀▀▀██▀▀▀▀▀▀▀▀";
    Console::GotoXY(X + 8, Y + 5);
    cout << u8"██";
    Console::GotoXY(X + 8, Y + 6);
    cout << u8"██";


    Console::SetColor(BLACK, WHITE);
    Console::GotoXY(X, Y + 1);
    cout << u8"█                █";
    Console::GotoXY(X, Y + 2);
    cout << u8"█                █";
    Console::GotoXY(X, Y + 3);
    cout << u8"█                █";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawGrassBlock(int x, int y) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_GREEN, LIGHT_GREEN);
    for (int i = 0; i < ySizeOfBlock; i++) {
        Console::GotoXY(x, y + i);
        int tempY = y + i;
        for (int j = 0; j < xSizeOfBlock; j++) {
            Console::GotoXY(x + j, tempY);
            cout << u8"█";
        }
    }

    Console::SetColor(GREEN, LIGHT_GREEN);
    Console::GotoXY(x + 2, y + 3);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 7, y + 3);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 1, y + 1);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 6, y + 1);
    cout << u8"▄▀▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawGrassLine(int x, int y, int length) {
    for (int i = 0; i < length; i++)
        DrawGrassBlock(x + 10 * i, y);
}

void Graphic::DrawGameFrame() {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(BLACK, BLACK);
    for (int i = 0; i < 30; i++) {
        Console::GotoXY(100, i);
        cout << u8"█";
    }

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTrafficLightBlock(int x, int y, bool status) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(WHITE, WHITE);
    for (int i = 0; i < ySizeOfBlock; i++) {
        Console::GotoXY(x, y + i);
        int tempY = y + i;
        for (int j = 0; j < xSizeOfBlock; j++) {
            Console::GotoXY(x + j, tempY);
            cout << u8"█";
        }
        if (i < ySizeOfBlock - 1)
            cout << endl;
    }
    int trafficLightHeight = 3;
    Console::SetColor(BLACK, BLACK);
    for (int i = 0; i < trafficLightHeight - 1; i++) {
        Console::GotoXY(x + 3, y + i + 1);
        cout << u8"█████";
    }
    Console::GotoXY(x + 5, y + 3);
    cout << u8"█";

    if (status) {
        Console::SetColor(RED, BLACK);
        Console::GotoXY(x + 5, y + 1);
        cout << u8"▄";
    }
    else {
        Console::SetColor(LIGHT_GREEN, BLACK);
        Console::GotoXY(x + 5, y + 2);
        cout << u8"▀";
    }
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawMushroomHouse(int x, int y, int backgroundTop, int backgroundBot) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, RED);
    Console::GotoXY(x + 8, y);
    cout << u8"▄▄▄▄▄";
    Console::GotoXY(x + 5, y + 1);
    cout << u8"▄█▀    ▀▀█▄";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"▄█▀▀         ▀▀█▄";
    Console::GotoXY(x, y + 3);
    cout << u8"▄█▀               ▀█▄";
    Console::GotoXY(x, y + 4);
    cout << u8"▀█▄▄▄           ▄▄▄█▀";

    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(x + 4, y + 5);
    cout << u8"▀▀█▀▀▀▀▀▀█▀▀▀";
    Console::GotoXY(x + 4, y + 6);
    cout << u8"▄█▀       █";
    Console::GotoXY(x + 3, y + 7);
    cout << u8"▄█         ▀█";
    Console::GotoXY(x + 3, y + 8);
    cout << u8"█           █▄";
    Console::GotoXY(x + 3, y + 9);
    cout << u8"█            █";
    Console::GotoXY(x + 3, y + 10);
    cout << u8"▀█           █";
    Console::GotoXY(x + 4, y + 11);
    cout << u8"▀▀█▄▄▄▄▄▄▄▄█▀";


    Console::SetColor(BRIGHT_WHITE, RED);
    Console::GotoXY(x + 7, y + 2);
    cout << u8"▄▄   ██";
    Console::GotoXY(x + 5, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 11, y + 4);
    cout << u8"▀";


    //Window
    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(x + 10, y + 6);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 10, y + 7);
    cout << u8"█▄█";

    Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(x + 11, y + 7);
    cout << u8"▄";

    //door
    Console::SetColor(BLACK, LIGHT_RED);
    Console::GotoXY(x + 6, y + 9);
    cout << u8"█▀▀█";
    Console::GotoXY(x + 6, y + 10);
    cout << u8"█  █";
    Console::GotoXY(x + 6, y + 11);
    cout << u8"█▄▄█";

    Console::SetColor(BRIGHT_WHITE, LIGHT_RED);
    Console::GotoXY(x + 8, y + 10);
    cout << u8"▄";


    //outsideTop
    Console::SetColor(BLACK, backgroundTop);
    Console::GotoXY(x + 8, y);
    cout << u8"▄▄▄▄▄";
    Console::GotoXY(x + 5, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 15, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"▄";
    Console::GotoXY(x + 18, y + 2);
    cout << u8"▄";
    Console::GotoXY(x, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 20, y + 3);
    cout << u8"▄";
    Console::GotoXY(x, y + 4);
    cout << u8"▀";
    Console::GotoXY(x + 20, y + 4);
    cout << u8"▀";
    Console::GotoXY(x + 4, y + 5);
    cout << u8"▀▀";
    Console::GotoXY(x + 14, y + 5);
    cout << u8"▀▀▀";
    Console::GotoXY(x + 4, y + 6);
    cout << u8"▄";
    Console::GotoXY(x + 3, y + 7);
    cout << u8"▄";
    Console::GotoXY(x + 16, y + 8);
    cout << u8"▄";


    //outsideBot
    Console::SetColor(BLACK, backgroundBot);
    Console::GotoXY(x + 3, y + 10);
    cout << u8"▀";
    Console::GotoXY(x + 4, y + 11);
    cout << u8"▀▀";
    Console::GotoXY(x + 16, y + 11);
    cout << u8"▀";
}
void Graphic::DrawLeafBlock(int x, int y) { //DrawMain(x+2,y) 
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(LIGHT_GREEN, AQUA);
    Console::GotoXY(X + 4, Y);
    cout << u8"▄▄█████";
    Console::GotoXY(X + 2, Y + 1);
    cout << u8"██████████";
    Console::GotoXY(X + 2, Y + 2);
    cout << u8"███████████";
    Console::GotoXY(X + 3, Y + 3);
    cout << u8"█████████";
    Console::GotoXY(X + 4, Y + 4);
    cout << u8"▀▀▀▀▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawMound(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(x + 10, y);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(x + 7, y + 1);
    cout << u8"▄█▀▀           ▀▀█▄";
    Console::GotoXY(x + 5, y + 2);
    cout << u8"▄▄█                 ▀█▄";
    Console::GotoXY(x + 4, y + 3);
    cout << u8"█▀                     █▄▄";
    Console::GotoXY(x, y + 4);
    cout << u8"▄▄▄██▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄██▄▄▄";


    //grass
    Console::SetColor(GREEN, LIGHT_GREEN);
    Console::GotoXY(x + 12, y + 1);
    cout << u8"▄   ▄";
    Console::GotoXY(x + 17, y + 2);
    cout << u8"▄  ▀";
    Console::GotoXY(x + 9, y + 3);
    cout << u8"▀▄   ▄ ▀       ▄";


    //outside
    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 10, y);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(x + 7, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 25, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 5, y + 2);
    cout << u8"▄▄";
    Console::GotoXY(x + 27, y + 2);
    cout << u8"▄";
    Console::GotoXY(x + 28, y + 3);
    cout << u8"▄▄";
    Console::GotoXY(x, y + 4);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 31, y + 4);
    cout << u8"▄▄▄";

    SetConsoleOutputCP(oldcp);
}
void Graphic::DrawWaterBlock(int x, int y) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(AQUA, AQUA);
    for (int i = 0; i < 5; i++) {
        Console::GotoXY(X, Y + i);
        cout << u8"██████████";
    }

    Console::SetColor(LIGHT_AQUA, AQUA);
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"▀▀▀▄▄";
    Console::GotoXY(X + 5, Y + 3);
    cout << u8"▄▄▄▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawWaterLine(int x, int y) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    for (int i = 0; i < 12; i++) {
        Graphic::DrawWaterBlock(X + 10 * i, Y);
    }

    SetConsoleOutputCP(oldcp);
}


void Graphic::DrawGameLoaderRoad(int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, WHITE);
    Console::GotoXY(21, 1);
    cout << u8"█▄            ▀█▄▄";
    Console::GotoXY(22, 2);
    cout << u8"▀█              ▀█▄";
    Console::GotoXY(23, 3);
    cout << u8"▀█▄              ▀█▄▄";
    Console::GotoXY(25, 4);
    cout << u8"▀█▄               ▀▀▀▄▄▄▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(27, 5);
    cout << u8"▀█▄                            ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
    Console::GotoXY(29, 6);
    cout << u8"▀█▄▄                                        ";
    Console::GotoXY(32, 7);
    cout << u8"▀█▄▄                                     ";
    Console::GotoXY(35, 8);
    cout << u8"▀▀█▄▄                                 ";
    Console::GotoXY(40, 9);
    cout << u8"▀▀█▄▄▄▄▄▄                        ";
    Console::GotoXY(49, 10);
    cout << u8"▀▀█             █▀▀▀▀▀▀▀";

    Console::GotoXY(50, 11);
    cout << u8"█            ▄█";
    Console::GotoXY(48, 12);
    cout << u8"█▀            ▄▀";
    Console::GotoXY(46, 13);
    cout << u8"█▀             ▄▀";
    Console::GotoXY(44, 14);
    cout << u8"▄▀              █";
    Console::GotoXY(43, 15);
    cout << u8"▀                ▀▄";
    Console::GotoXY(43, 16);
    cout << u8"                   █▄";
    Console::GotoXY(43, 17);
    cout << u8"                     ▀▄▄";
    Console::GotoXY(43, 18);
    cout << u8"                        █▄▄▄▄";
    Console::GotoXY(43, 19);
    cout << u8"    ▄▄                      ▀▀▀▀▀▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(43, 20);
    cout << u8"  ▄█";
    Console::GotoXY(43, 21);
    cout << u8"▄█";

    Console::GotoXY(49, 20);
    cout << u8"▀▄                                  ";
    Console::GotoXY(51, 21);
    cout << u8"█▄                                ";
    Console::GotoXY(53, 22);
    cout << u8"▀▄▄                             ";
    Console::GotoXY(56, 23);
    cout << u8"█▄▄▄▄                        ";
    Console::GotoXY(61, 24);
    cout << u8"▀▄▄▄▄▄▄                 ";
    Console::GotoXY(67, 25);
    cout << u8"▀▀▀▀▄▄▄▄▄▄        ";
    Console::GotoXY(76, 26);
    cout << u8"▀▀▀▀▀▀▀▀▀";


    //outside
    Console::SetColor(BLACK, background);
    Console::GotoXY(37, 1);
    cout << u8"▄▄";
    Console::GotoXY(22, 2);
    cout << u8"▀";
    Console::GotoXY(40, 2);
    cout << u8"▄";
    Console::GotoXY(23, 3);
    cout << u8"▀";
    Console::GotoXY(42, 3);
    cout << u8"▄▄";
    Console::GotoXY(25, 4);
    cout << u8"▀";
    Console::GotoXY(46, 4);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(27, 5);
    cout << u8"▀";
    Console::GotoXY(29, 6);
    cout << u8"▀";
    Console::GotoXY(32, 7);
    cout << u8"▀";
    Console::GotoXY(35, 8);
    cout << u8"▀▀";
    Console::GotoXY(40, 9);
    cout << u8"▀▀";
    Console::GotoXY(49, 10);
    cout << u8"▀▀";
    Console::GotoXY(66, 10);
    cout << u8"▀▀▀▀▀▀▀";
    Console::GotoXY(63, 12);
    cout << u8"▀";
    Console::GotoXY(62, 13);
    cout << u8"▀";
    Console::GotoXY(44, 14);
    cout << u8"▄";
    Console::GotoXY(61, 15);
    cout << u8"▄";
    Console::GotoXY(63, 16);
    cout << u8"▄";
    Console::GotoXY(65, 17);
    cout << u8"▄▄";
    Console::GotoXY(68, 18);
    cout << u8"▄▄▄▄";
    Console::GotoXY(76, 19);
    cout << u8"▄▄▄▄▄▄▄▄▄";

    Console::GotoXY(49, 20);
    cout << u8"▀";
    Console::GotoXY(53, 22);
    cout << u8"▀";
    Console::GotoXY(61, 24);
    cout << u8"▀";
    Console::GotoXY(67, 25);
    cout << u8"▀▀▀▀";
    Console::GotoXY(76, 26);
    cout << u8"▀▀▀▀▀▀▀▀▀";
}


void Graphic::DrawTurtleRight(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(GREEN, background);
    Console::GotoXY(X + 3, Y);
    cout << u8"▄▄";
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"▄████▄";
    Console::GotoXY(X + 1, Y + 2);
    cout << u8"██████";

    Console::SetColor(LIGHT_GREEN, background);
    Console::GotoXY(X + 1, Y + 3);
    cout << u8"██▀▀██";
    Console::GotoXY(X, Y + 2);
    cout << u8"▄";
    Console::GotoXY(X + 7, Y + 1);
    cout << u8"██▄";
    Console::GotoXY(X + 7, Y + 2);
    cout << u8"██▀";

    Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(X + 8, Y + 1);
    cout << u8"▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTurtleRightAnimation1(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(GREEN, background);
    Console::GotoXY(X + 3, Y);
    cout << u8"▄"; 
    Console::GotoXY(X + 1, Y + 2);
    cout << u8"██";

    Console::SetColor(LIGHT_GREEN, background);
    Console::GotoXY(X, Y + 2);
    cout << u8"▄";
    Console::GotoXY(X + 7, Y + 1);
    cout << u8"█";
    Console::GotoXY(X + 7, Y + 2);
    cout << u8"▀";

    /*Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(X + 8, Y + 1);
    cout << u8"▄";*/

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTurtleRightAnimation2(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(GREEN, background);
    Console::GotoXY(X + 3, Y);
    cout << u8"▄▄";
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"▄ ██ ▄";
    Console::GotoXY(X + 1, Y + 2);
    cout << u8"██  ██";

    Console::SetColor(LIGHT_GREEN, background);
    Console::GotoXY(X + 1, Y + 3);
    cout << u8"█    █";
    Console::GotoXY(X, Y + 2);
    cout << u8"▄";
    Console::GotoXY(X + 7, Y + 1);
    cout << u8"██▄";
    Console::GotoXY(X + 7, Y + 2);
    cout << u8"█ ▀";

    Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(X + 8, Y + 1);
    cout << u8"▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DeleteTurtleRight(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(background, background);
    Console::GotoXY(X + 3, Y);
    cout << u8"  ";
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"      ";
    Console::GotoXY(X + 1, Y + 2);
    cout << u8"      ";

    Console::SetColor(background, background);
    Console::GotoXY(X + 1, Y + 3);
    cout << u8"      ";
    Console::GotoXY(X, Y + 2);
    cout << u8" ";
    Console::GotoXY(X + 7, Y + 1);
    cout << u8"   ";
    Console::GotoXY(X + 7, Y + 2);
    cout << u8"   ";

    Console::SetColor(background, background);
    Console::GotoXY(X + 8, Y + 1);
    cout << u8" ";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTurtleLeft(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(GREEN, background);
    Console::GotoXY(X + 5, Y);
    cout << u8"▄▄";
    Console::GotoXY(X + 3, Y + 1);
    cout << u8"▄████▄";
    Console::GotoXY(X + 3, Y + 2);
    cout << u8"██████";

    Console::SetColor(LIGHT_GREEN, background);
    Console::GotoXY(X + 3, Y + 3);
    cout << u8"██▀▀██";
    Console::GotoXY(X + 9, Y + 2);
    cout << u8"▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"▄██";
    Console::GotoXY(X, Y + 2);
    cout << u8"▀██";

    Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTurtleLeftAnimation1(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(GREEN, background);
    Console::GotoXY(X + 5, Y);
    cout << u8"▄";
    Console::GotoXY(X + 3, Y + 2);
    cout << u8"██";

    Console::SetColor(LIGHT_GREEN, background);
    Console::GotoXY(X + 9, Y + 2);
    cout << u8"▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"▄";
    Console::GotoXY(X, Y + 2);
    cout << u8"  █";

    SetConsoleOutputCP(oldcp);
}
void Graphic::DrawTurtleLeftAnimation2(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(GREEN, background);
    Console::GotoXY(X + 5, Y);
    cout << u8"▄▄";
    Console::GotoXY(X + 3, Y + 1);
    cout << u8"▄█  █▄";
    Console::GotoXY(X + 3, Y + 2);
    cout << u8"██  ██";

    Console::SetColor(LIGHT_GREEN, background);
    Console::GotoXY(X + 3, Y + 3);
    cout << u8"█ ▀▀ █";
    Console::GotoXY(X + 9, Y + 2);
    cout << u8"▄";
    Console::GotoXY(X, Y + 1);
    cout << u8"▄ █";
    Console::GotoXY(X, Y + 2);
    cout << u8"▀ █";

    Console::SetColor(BLACK, LIGHT_GREEN);
    Console::GotoXY(X + 1, Y + 1);
    cout << u8"▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DeleteTurtleLeft(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(background, background);
    Console::GotoXY(X + 5, Y);
    cout << u8"  ";
    Console::GotoXY(X + 3, Y + 1);
    cout << u8"      ";
    Console::GotoXY(X + 3, Y + 2);
    cout << u8"      ";

    Console::SetColor(background, background);
    Console::GotoXY(X + 3, Y + 3);
    cout << u8"      ";
    Console::GotoXY(X + 9, Y + 2);
    cout << u8" ";
    Console::GotoXY(X, Y + 1);
    cout << u8"   ";
    Console::GotoXY(X, Y + 2);
    cout << u8"   ";

    Console::SetColor(background, background);
    Console::GotoXY(X + 1, Y + 1);
    cout << u8" ";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawPlayGameIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x+3, Y = y;

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"▄▄";
    Console::GotoXY(X+3, Y+1);
    cout << u8"▄";
    Console::GotoXY(X+3, Y+3);
    cout << u8"▀";
    Console::GotoXY(X, Y+4);
    cout << u8"▀▀";

    Console::SetColor(BLACK, GREEN);
    Console::GotoXY(X, Y+1);
    cout << u8"█ ▀";
    Console::GotoXY(X, Y+2);
    cout << u8"█   █";
    Console::GotoXY(X, Y+3);
    cout << u8"█ ▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawLoadGameIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"▄";
    Console::GotoXY(X+5, Y);
    cout << u8"▄";
    Console::GotoXY(X + 9, Y+1);
    cout << u8"▄";
    Console::GotoXY(X + 1, Y + 4);
    cout << u8"▀▀▀▀▀▀▀▀";


    Console::SetColor(BLACK, BRIGHT_WHITE);
    Console::GotoXY(X+1, Y);
    cout << u8"▀▀▀▀";

    Console::SetColor(BLACK, YELLOW);
    Console::GotoXY(X, Y+1);
    cout << u8"█▀▀▀▀▀▀▀▀";
    Console::GotoXY(X, Y + 2);
    cout << u8"█        █";
    Console::GotoXY(X, Y + 3);
    cout << u8"█        █";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawTutorialIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"▄";
    Console::GotoXY(X, Y+4);
    cout << u8"▀";

    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(X+1, Y);
    cout << u8"▀█";
    Console::GotoXY(X, Y+1);
    cout << u8"█ █";
    Console::GotoXY(X, Y+2);
    cout << u8"█ █";
    Console::GotoXY(X, Y+3);
    cout << u8"█ █";
    Console::GotoXY(X+1, Y + 4);
    cout << u8"▄█";

    Console::SetColor(BLACK, RED);
    Console::GotoXY(X+3, Y);
    cout << u8"▀▀▀▀▀▀█";
    Console::GotoXY(X+3, Y+1);
    cout << u8"      █";
    Console::GotoXY(X+3, Y+2);
    cout << u8"      █";
    Console::GotoXY(X+3, Y+3);
    cout << u8"      █";
    Console::GotoXY(X+3, Y+4);
    cout << u8"▄▄▄▄▄▄█";
    
    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawSettingsIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8" ▄    ▄";
    Console::GotoXY(X+1, Y+3);
    cout << u8"▀";
    Console::GotoXY(X+6, Y+3);
    cout << u8"▀";

    Console::SetColor(BLACK, GRAY);
    Console::GotoXY(X, Y+1);
    cout << u8"█ █";
    Console::GotoXY(X+5, Y+1);
    cout << u8"█ █";
    Console::GotoXY(X, Y+2);
    cout << u8"█  ▀▀  █";
    Console::GotoXY(X+2, Y+3);
    cout << u8"▄  ▄";
    Console::GotoXY(X + 2, Y + 4);
    cout << u8"█▄▄█";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawCreditsIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8"▄";
    Console::GotoXY(X, Y+3);
    cout << u8"▀▀";
    Console::GotoXY(X+6, Y+3);
    cout << u8"▀▀▀▀";
    Console::GotoXY(X+2, Y+4);
    cout << u8"▀▀";

    Console::SetColor(BLACK, WHITE);
    Console::GotoXY(X+1, Y);
    cout << u8"▀▀▀▀▀▀▀▀█";
    Console::GotoXY(X, Y+1);
    cout << u8"█   ▀    █";
    Console::GotoXY(X, Y+2);
    cout << u8"█   █    █";
    Console::GotoXY(X+2, Y+3);
    cout << u8"█ ▄▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawExitIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(BLACK, background);
    Console::GotoXY(X, Y);
    cout << u8" ▄     ▄";
    Console::GotoXY(X, Y+1);
    cout << u8"▀";
    Console::GotoXY(X+3, Y+1);
    cout << u8"▄ ▄";
    Console::GotoXY(X+8, Y+1);
    cout << u8"▀";
    Console::GotoXY(X, Y+2);
    cout << u8"  ▀";
    Console::GotoXY(X+6, Y+2);
    cout << u8"▀";
    Console::GotoXY(X, Y+3);
    cout << u8" ▄";
    Console::GotoXY(X+4, Y+3);
    cout << u8"▀";
    Console::GotoXY(X+7, Y+3);
    cout << u8"▄";
    Console::GotoXY(X, Y+4);
    cout << u8"▀";
    Console::GotoXY(X+2, Y+4);
    cout << u8"▀   ▀";
    Console::GotoXY(X+8, Y+4);
    cout << u8"▀";

    Console::SetColor(BLACK, RED);
    Console::GotoXY(X + 1, Y+1);
    cout << u8"▄▀";
    Console::GotoXY(X+6, Y+1);
    cout << u8"▀▄";
    Console::GotoXY(X+3, Y+2);
    cout << u8"▄▀▄";
    Console::GotoXY(X+2, Y+3);
    cout << u8"▀▄";
    Console::GotoXY(X+5, Y+3);
    cout << u8"▄▀";
    Console::GotoXY(X+1, Y+4);
    cout << u8"▄";
    Console::GotoXY(X+7, Y+4);
    cout << u8"▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DeleteIcon(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    int X = x, Y = y;

    Console::SetColor(background, background);
    Console::GotoXY(X, Y);
    cout << u8" ";
    Console::GotoXY(X, Y + 4);
    cout << u8" ";
    Console::GotoXY(X + 1, Y);
    cout << u8"  ";
    Console::GotoXY(X, Y + 1);
    cout << u8"   ";
    Console::GotoXY(X, Y + 2);
    cout << u8"   ";
    Console::GotoXY(X, Y + 3);
    cout << u8"   ";
    Console::GotoXY(X + 1, Y + 4);
    cout << u8"  ";
    Console::GotoXY(X + 3, Y);
    cout << u8"       ";
    Console::GotoXY(X + 3, Y + 1);
    cout << u8"       ";
    Console::GotoXY(X + 3, Y + 2);
    cout << u8"       ";
    Console::GotoXY(X + 3, Y + 3);
    cout << u8"       ";
    Console::GotoXY(X + 3, Y + 4);
    cout << u8"       ";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawDoYouWantToPlayAgain(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, background);
    Console::GotoXY(x, y);
    cout << u8"█▀▄ █▀█   █ █ █▀█ █ █   █ █ █ ▄▀▄ █▄ █ ▀█▀   ▀█▀ █▀█   █▀▄ █   ▄▀▄ █ █   ▄▀▄ █▀  ▄▀▄ █ █▄ █";
    Console::GotoXY(x, y + 1);
    cout << u8"█▄▀ █▄█    █  █▄█ █▄█   ▀▄▀▄▀ █▀█ █ ▀█  █     █  █▄█   █▀  █▄▄ █▀█  █    █▀█ █▄█ █▀█ █ █ ▀█";
    SetConsoleOutputCP(oldcp);
}



void Graphic::DrawGameOverDialog() {
    Sleep(700);
    Console::SetColor(BLACK, AQUA);
    system("cls");
    DrawGameOverFrog(5, 2, AQUA);
    DrawWordGameOver(40, 1, BRIGHT_WHITE, AQUA);
    DrawGameOverDecoration(100, 6, AQUA);
    DrawDoYouWantToPlayAgain(16, 20, AQUA);

    DrawY(37, 25, BLUE, AQUA);
    DrawN(78, 25, BLACK, AQUA);
}

void Graphic::DrawSelectBoxForDialog(int x, int y, int color, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▀";
    Console::GotoXY(x + 7, y);
    cout << u8"▀█";
    Console::GotoXY(x, y + 3);
    cout << u8"▄";
    Console::GotoXY(x, y + 4);
    cout << u8"▀▀";
    Console::GotoXY(x + 8, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 7, y + 4);
    cout << u8"▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawY(int x, int y, int color, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█   █";
    Console::GotoXY(x + 1, y + 1);
    cout << u8"▀▄▀";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawN(int x, int y, int color, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▄  █";
    Console::GotoXY(x, y + 1);
    cout << u8"█ ▀▄█";
    Console::GotoXY(x, y + 2);
    cout << u8"▀   ▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawBox(int x, int y, int length, int height, int colorOutside, int colorBox) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < length; i++) {
            if (i == 0 || i == length - 1) {
                Console::SetColor(colorOutside, colorBox);
                Console::GotoXY(x + i, y + j);
                cout << u8"█";
            }
            else if (j == 0) {
                Console::SetColor(colorOutside, colorBox);
                Console::GotoXY(x + i, y + j);
                cout << u8"▀";
            }
            else if (j == height - 1) {
                Console::SetColor(colorOutside, colorBox);
                Console::GotoXY(x + i, y + j);
                cout << u8"▄";
            }
            else {
                Console::SetColor(colorBox, colorBox);
                Console::GotoXY(x + i, y + j);
                cout << u8"█";
            }
        }
    }

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawEscDialog(int x, int y) {
    DrawBox(x, y, 34, 7, BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 2, y + 1);
    cout << "Are you sure you want to exit?";
    
    Console::GotoXY(x + 6, y + 4);
    cout << "Yes";
   
    Console::GotoXY(x + 25, y + 4);
    cout << "No";
}

void Graphic::DrawCongratsDialog() {
    Console::SetColor(BLACK, AQUA);
    system("cls");

    DrawCongratsFrog(5, 5, AQUA);
    DrawWordCongrats(38, 1, AQUA);
    DrawDoYouWantToPlayAgain(15, 18, AQUA);

    DrawY(37, 24, BLUE, AQUA);
    DrawN(78, 24, BLACK, AQUA);
}

void Graphic::DrawCongratsFrog(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    //body
    Console::SetColor(BLACK, GREEN);
    Console::GotoXY(x + 15, y);
    cout << u8"▄▀▀▀▄▄▄▀▀▀▄";
    Console::GotoXY(x + 10, y + 1);
    cout << u8"▄▄▄█▀        ▀█▄";
    Console::GotoXY(x + 4, y + 2);
    cout << u8"▄▄▄█▀▀▀  █           █";
    Console::GotoXY(x + 1, y + 3);
    cout << u8"▄▀▀                      █";
    Console::GotoXY(x, y + 4);
    cout << u8"▄▀                       ▀";
    Console::GotoXY(x, y + 5);
    cout << u8"█                        ";
    Console::GotoXY(x, y + 6);
    cout << u8"█▄   ▀▀▀█▄▄             ▄";
    Console::GotoXY(x + 1, y + 7);
    cout << u8"▀█▄▄▄▄   ▀█    █   █▄█▀";
    Console::GotoXY(x + 3, y + 8);
    cout << u8"█▀      █▄▄▄▄█▄   ▀▀▀▀▄";
    Console::GotoXY(x + 1, y + 9);
    cout << u8"▄█▄▄▄▄▄▀▀▀";
    Console::GotoXY(x + 17, y + 9);
    cout << u8"▀▄▄▄▄▄▄▀";

    //eye
    Console::SetColor(BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 16, y);
    cout << u8"▀▀▀▄▄▄▀▀▀";
    Console::GotoXY(x + 14, y + 1);
    cout << u8"▀ ▄██▄";
    Console::GotoXY(x + 25, y + 1);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 14, y + 2);
    cout << u8"  ████ ";
    Console::GotoXY(x + 25, y + 2);
    cout << u8"█ █";
    Console::GotoXY(x + 17, y + 3);
    cout << u8"▀▀";

    Console::SetColor(BRIGHT_WHITE, GREEN);
    Console::GotoXY(x + 20, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 15, y + 3);
    cout << u8"▀▀";
    Console::GotoXY(x + 19, y + 3);
    cout << u8"▀";

    //gum
    Console::SetColor(LIGHT_RED, GREEN);
    Console::GotoXY(x + 23, y + 3);
    cout << u8"▄▄▄";
    Console::SetColor(LIGHT_RED, RED);
    Console::GotoXY(x + 20, y + 4);
    cout << u8"▀▀▀▀▀";

    //light yellow skin
    Console::SetColor(LIGHT_YELLOW, GREEN);
    Console::GotoXY(x + 18, y + 5);
    cout << u8"██";
    Console::GotoXY(x + 19, y + 6);
    cout << u8"▀▀██";
    Console::SetColor(LIGHT_YELLOW, RED);
    Console::GotoXY(x + 20, y + 5);
    cout << u8"▄";
    Console::GotoXY(x + 23, y + 6);
    cout << u8"▄";

    Console::SetColor(LIGHT_YELLOW, GREEN);
    Console::GotoXY(x + 12, y + 7);
    cout << u8"▄▄▄▄";
    Console::SetColor(LIGHT_YELLOW, BLACK);
    Console::GotoXY(x + 12, y + 8);
    cout << u8"▀▀▀▀";

    //tounge
    Console::SetColor(RED, GREEN);
    Console::GotoXY(x + 19, y + 4);
    cout << u8"▄";
    Console::SetColor(RED, background);
    Console::GotoXY(x + 21, y + 5);
    cout << u8"███████████████████████████████████████████████████████████████████████████████████▀▀▀";
    Console::SetColor(RED, LIGHT_YELLOW);
    Console::GotoXY(x + 23, y + 6);
    cout << u8"▀";
    Console::SetColor(RED, BLACK);
    Console::GotoXY(x + 24, y + 6);
    cout << u8"▀";
    Console::SetColor(RED, background);
    Console::GotoXY(x + 25, y + 6);
    cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
    Console::GotoXY(x + 107, y + 4);
    cout << u8"▄";

    //outline
    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 15, y);
    cout << u8"▄";
    Console::GotoXY(x + 19, y);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 25, y);
    cout << u8"▄";
    Console::GotoXY(x + 10, y + 1);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 27, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 4, y + 2);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 1, y + 3);
    cout << u8"▄";
    Console::GotoXY(x, y + 4);
    cout << u8"▄";
    Console::GotoXY(x + 1, y + 7);
    cout << u8"▀";
    Console::GotoXY(x + 23, y + 7);
    cout << u8"▀";
    Console::GotoXY(x + 25, y + 8);
    cout << u8"▄";
    Console::GotoXY(x + 1, y + 9);
    cout << u8"▄";
    Console::GotoXY(x + 8, y + 9);
    cout << u8"▀▀▀";
    Console::GotoXY(x + 17, y + 9);
    cout << u8"▀";
    Console::GotoXY(x + 24, y + 9);
    cout << u8"▀";


    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawWordCongrats(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(x, y);
    cout << u8"▄█▀▀▀▀▀▄";
    Console::GotoXY(x, y + 1);
    cout << u8"█      ▀                                        █     ▄▀▄";
    Console::GotoXY(x, y + 2);
    cout << u8"█         ▄█▀▀▀█▄  █▄▀▀▄  ▄▀▀▄█  █▄▀▄  ▄▀▀▄█  ▀▀█▀▀    ▀█▄";
    Console::GotoXY(x, y + 3);
    cout << u8"█         █     █  █   █  █   █  █  ▀  █   █    █      ▄▀ ▀▄";
    Console::GotoXY(x, y + 4);
    cout << u8"█         █▄   ▄█  █   █  █  ▄█▄ █     █   █  ▄▀█  ▄  ▄▀    █";
    Console::GotoXY(x, y + 5);
    cout << u8"█▄     █    ▀▀▀    ▀   ▀   ▀▀▄█  ▀      ▀▀▀ ▀    ▀▀  ▀    ▀▀";
    Console::GotoXY(x, y + 6);
    cout << u8"  ▀▀▀▀▀                    ▄▀ █";
    Console::GotoXY(x, y + 7);
    cout << u8"                          ▀▄▄▄▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawSaveFileDialog(int x, int y) {
    DrawBox(x, y, 50, 9, BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 21, y + 1);
    cout << "Save Game";
    Console::GotoXY(x + 6, y + 2);
    cout << "File name must be less than 8 letters";
    Console::GotoXY(x + 2, y + 3);
    cout << "No space and no special charactes is allowed";
    Console::GotoXY(x + 2, y + 4);
    cout << "Name: ";
}

void Graphic::DrawFullFileContainerNotification(int x, int y) {
    DrawBox(x, y, 41, 5, BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 9, y + 1);
    cout << "File container is full";
    Console::GotoXY(x + 12, y + 2);
    cout << "Go back to menu";
    Console::GotoXY(x + 2, y + 3);
    cout << "Delete some files to have more space";
}

void Graphic::DrawFileDeletionNotification(int x, int y, const string& fileName){
    DrawBox(x, y, 35, 5, RED, BRIGHT_WHITE);
    Console::SetColor(RED, BRIGHT_WHITE);
    Console::GotoXY(x + 2, y + 1);
    cout << fileName;
    Console::SetColor(BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 2, y + 3);
    cout << "has been deleted successfully";
}


void Graphic::DrawPortal(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BRIGHT_WHITE, background);
    Console::GotoXY(x + 1, y);
    cout << u8"▄▄▀▀▀▄▄";
    Console::GotoXY(x, y + 1);
    cout << u8"█       █";
    Console::GotoXY(x, y + 2);
    cout << u8"█       █";
    Console::GotoXY(x, y + 3);
    cout << u8"█       █";
    Console::GotoXY(x, y + 4);
    cout << u8"█       █";
    Console::GotoXY(x, y + 5);
    cout << u8"█       █";
    Console::GotoXY(x, y + 6);
    cout << u8"▀▄▄   ▄▄▀";
    Console::GotoXY(x + 3, y + 7);
    cout << u8"▀▀▀";

    Console::SetColor(BLUE, AQUA);
    Console::GotoXY(x + 2, y + 1);
    cout << u8"▄█▀█▄";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"█   █";
    Console::GotoXY(x + 2, y + 3);
    cout << u8"█   █";
    Console::GotoXY(x + 2, y + 4);
    cout << u8"█   █";
    Console::GotoXY(x + 2, y + 5);
    cout << u8"█▄ ▄█";
    Console::GotoXY(x + 3, y + 6);
    cout << u8"▀▀▀";

    Console::SetColor(BLACK, BLUE);
    Console::GotoXY(x + 4, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 3, y + 2);
    cout << u8"███";
    Console::GotoXY(x + 3, y + 3);
    cout << u8"███";
    Console::GotoXY(x + 3, y + 4);
    cout << u8"███";
    Console::GotoXY(x + 3, y + 5);
    cout << u8"▀█▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawGameOverFrog(int x, int y, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    //face
    Console::SetColor(BLACK, GREEN);
    Console::GotoXY(x + 8, y);
    cout << u8"▄▀▀▀▀▀▀▄";
    Console::GotoXY(x + 17, y);
    cout << u8"▄▀▀▀▀▄▄";
    Console::GotoXY(x + 6, y + 1);
    cout << u8"▄▀  ▄▄▄▄▄▄▀  ▄▄▄▄▄█";
    Console::GotoXY(x + 5, y + 2);
    cout << u8"▄▀  ▀    ▄▄▀▄▀   ▄▄▄█▀▄";
    Console::GotoXY(x + 3, y + 3);
    cout << u8"▄▀▀    ▄▄▀▀▄▄█▄▄▄▀█▄▄▄▄▄▄█";
    Console::GotoXY(x + 2, y + 4);
    cout << u8"█      ▀";
    Console::GotoXY(x, y + 5);
    cout << u8"▄█        ▀▀▀███▄▄█▀ ▀▀▀▀▀█▀";
    Console::GotoXY(x, y + 6);
    cout << u8"█             ▄▄▀▀  ▀▀▄▀▀▀▄";
    Console::GotoXY(x, y + 7);
    cout << u8"█       ▄▄▄▄▄▄▄▄▄▄       ▄▄█";
    Console::GotoXY(x, y + 8);
    cout << u8"█      ";
    Console::GotoXY(x, y + 9);
    cout << u8"█      ▀";
    Console::GotoXY(x, y + 10);
    cout << u8"▀█▄               ▀▀▀▀▀▀▀██▀";
    Console::GotoXY(x + 3, y + 11);
    cout << u8"▀▀▄▄▄            ▄▄▄▀▀";
    Console::GotoXY(x + 8, y + 12);
    cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

    //eye
    Console::SetColor(BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 10, y + 4);
    cout << u8"▄▀▀▀▄▀██▄ █  ▄▀▄█ ▄▀";
    Console::GotoXY(x + 16, y + 5);
    cout << u8"▄▄";

    //mouth
    Console::SetColor(BLACK, RED);
    Console::GotoXY(x + 7, y + 8);
    cout << u8"█▄▄▄▄▄▄▄▄▄▄▀▀▀▀▀▀▀  ▀█";
    Console::GotoXY(x + 8, y + 9);
    cout << u8"▄▄▄▄▄▄▄▄▄▄▀▀▀▀▀▀▀▀▀█";

    //outline
    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 8, y);
    cout << u8"▄";
    Console::GotoXY(x + 15, y);
    cout << u8"▄";
    Console::GotoXY(x + 17, y);
    cout << u8"▄";
    Console::GotoXY(x + 22, y);
    cout << u8"▄▄";
    Console::GotoXY(x + 6, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 5, y + 2);
    cout << u8"▄";
    Console::GotoXY(x + 27, y + 2);
    cout << u8"▄";
    Console::GotoXY(x + 3, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 29, y + 4);
    cout << u8"▀";
    Console::GotoXY(x, y + 5);
    cout << u8"▄";
    Console::GotoXY(x + 27, y + 5);
    cout << u8"▀";
    Console::GotoXY(x + 26, y + 6);
    cout << u8"▄";
    Console::GotoXY(x, y + 10);
    cout << u8"▀";
    Console::GotoXY(x + 27, y + 10);
    cout << u8"▀";
    Console::GotoXY(x + 3, y + 11);
    cout << u8"▀▀";
    Console::GotoXY(x + 23, y + 11);
    cout << u8"▀▀";
    Console::GotoXY(x + 8, y + 12);
    cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawWordGameOver(int x, int y, int color, int background) {
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x + 1, y);
    cout << u8"▄█▀▀▀▀▀▀▀▄";
    Console::GotoXY(x, y + 1);
    cout << u8"█▀        ▀";
    Console::GotoXY(x, y + 2);
    cout << u8"█";
    Console::GotoXY(x, y + 3);
    cout << u8"█";
    Console::GotoXY(x, y + 4);
    cout << u8"█                 ▄▀▀▀▄█    █▄▀▀▄▀▀▀▄    ▄█▀▀▄";
    Console::GotoXY(x, y + 5);
    cout << u8"█        ▄▄▄▄▄    █    █    █   █   █  ▄▄█▄▄▄▀";
    Console::GotoXY(x, y + 6);
    cout << u8"█          █      █   ▄█    █   █   █    █     ▄";
    Console::GotoXY(x, y + 7);
    cout << u8"▀█▄      ▄▄█       ▀▀▀ ▀▀   ▀   ▀   ▀     ▀▀▀▀▀";
    Console::GotoXY(x + 2, y + 8);
    cout << u8"▀█▄▄▄▄█▀ ▀";


    Console::GotoXY(x-23 + 33, y + 10);
    cout << u8"▄▄▄▄";
    Console::GotoXY(x-23 + 31, y + 11);
    cout << u8"▄█   ▀▀█▄";
    Console::GotoXY(x-23 + 30, y + 12);
    cout << u8"█        ▀█   ▄     ▄     ▄▄▄     ▄▀▄";
    Console::GotoXY(x-23 + 30, y + 13);
    cout << u8"█         █   █     █    █▀  █     ▀█▀▀▀▄";
    Console::GotoXY(x-23 + 30, y + 14);
    cout << u8"█         █   █     █  ▀▀█▀▀▀       █   █";
    Console::GotoXY(x-23 + 30, y + 15);
    cout << u8"█         █    ▀▄ ▄▀     █▄    ▄   ▄█   █";
    Console::GotoXY(x-23 + 31, y + 16);
    cout << u8"▀▀▄▄▄▄▄▄█▀      ▀        ▀▀▀▀▀   ▀▀     ▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawSquare(int x, int y, int xSize, int ySize, int color)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, color);
    for (int j = 0; j < ySize; j++) {
        for (int i = 0; i < xSize; i++) {
            Console::GotoXY(x + i, y + j);
            cout << u8"█";
        }
    }

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawParallelogramBoxWithHorizontalAndDiagonal(int x, int y, int outlineColor, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(outlineColor, color);
    Console::GotoXY(x + 5, y);
    cout << u8"▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█▀";
    Console::GotoXY(x + +3, y + 1);
    cout << u8"▄▀              ▄▀";
    Console::GotoXY(x + 1, y + 2);
    cout << u8"▄▀              ▄▀";
    Console::GotoXY(x, y + 3);
    cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀";

    Console::SetColor(outlineColor, background);
    Console::GotoXY(x + 5, y);
    cout << u8"▄";
    Console::GotoXY(x + 22, y);
    cout << u8"▀";
    Console::GotoXY(x + 3, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 20, y + 1);
    cout << u8"▀";
    Console::GotoXY(x + 1, y + 2);
    cout << u8"▄";
    Console::GotoXY(x + 18, y + 2);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw0(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▀█";
    Console::GotoXY(x, y + 1);
    cout << u8"█ █";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw1(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"▄█";
    Console::GotoXY(x + 1, y + 1);
    cout << u8"█";
    Console::GotoXY(x + 1, y + 2);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw2(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"▀▀█";
    Console::GotoXY(x, y + 1);
    cout << u8"█▀▀";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw3(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"▀▀█";
    Console::GotoXY(x + 1, y + 1);
    cout << u8"▀█";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw4(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█ █";
    Console::GotoXY(x, y + 1);
    cout << u8"▀▀█";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw5(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▀▀";
    Console::GotoXY(x, y + 1);
    cout << u8"▀▀█";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw6(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▀▀";
    Console::GotoXY(x, y + 1);
    cout << u8"█▀█";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw7(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"▀▀█";
    Console::GotoXY(x + 2, y + 1);
    cout << u8"█";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw8(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▀█";
    Console::GotoXY(x, y + 1);
    cout << u8"█▀█";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::Draw9(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color, background);
    Console::GotoXY(x, y);
    cout << u8"█▀█";
    Console::GotoXY(x, y + 1);
    cout << u8"▀▀█";
    Console::GotoXY(x, y + 2);
    cout << u8"▀▀▀";

    SetConsoleOutputCP(oldcp);
}
void Graphic::DrawGoal(int xLeft, int xRight, int yUp, int yDown, int xSize, int ySize)
{
    int height = yDown - yUp + 1;
    int width = xRight - xLeft + 1;
    int xSquare, ySquare, colorSquare;

    int  jStep = 0;
    for (int j = 0; j < height; j += ySize) {
        int iStep = 0;
        for (int i = 0; i < width; i += xSize) {

            if (i + xSize > width)
                xSquare = width - i;
            else xSquare = xSize;

            if (j + ySize > height)
                ySquare = height - j;
            else ySquare = ySize;

            if ((iStep + jStep) % 2 == 0)
                colorSquare = BLACK;
            else colorSquare = BRIGHT_WHITE;

            DrawSquare(xLeft + i, yUp + j, xSquare, ySquare, colorSquare);
            iStep++;
        }
        jStep++;
    }
}

void Graphic::DrawLeaderBoardFigure(int x, int y, int backgroundTop, int backgroundBot)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    DrawParallelogramBoxWithHorizontalAndDiagonal(x, y + 4, BLACK, LIGHT_AQUA, backgroundTop);
    DrawParallelogramBoxWithHorizontalAndDiagonal(x + 16, y, BLACK, LIGHT_RED, backgroundTop);
    DrawParallelogramBoxWithHorizontalAndDiagonal(x + 32, y + 7, BLACK, LIGHT_YELLOW, backgroundTop);

    DrawBox(x, y + 7, 17, 12, BLACK, LIGHT_BLUE);
    DrawBox(x + 16, y + 3, 17, 16, BLACK, RED);
    DrawBox(x + 32, y + 10, 17, 9, BLACK, YELLOW);

    Console::SetColor(BLACK, LIGHT_RED);
    Console::GotoXY(x + 38, y);
    cout << u8"█";
    Console::GotoXY(x + 35, y + 1);
    cout << u8"▄▀ █";
    Console::GotoXY(x + 33, y + 2);
    cout << u8"▄▀   █";
    Console::GotoXY(x + 33, y + 3);
    cout << u8"     █";
    Console::GotoXY(x + 33, y + 4);
    cout << u8"     █";
    Console::GotoXY(x + 33, y + 5);
    cout << u8"     █";
    Console::GotoXY(x + 33, y + 6);
    cout << u8"     █";
    Console::GotoXY(x + 33, y + 7);
    cout << u8"    ▄";
    Console::GotoXY(x + 33, y + 8);
    cout << u8"  ▄";
    Console::GotoXY(x + 33, y + 9);
    cout << u8"▄";

    Console::SetColor(BLACK, LIGHT_YELLOW);
    Console::GotoXY(x + 54, y + 7);
    cout << u8"█";
    Console::GotoXY(x + 51, y + 8);
    cout << u8"▄▀ █";
    Console::GotoXY(x + 49, y + 9);
    cout << u8"▄▀   █";
    Console::GotoXY(x + 49, y + 10);
    cout << u8"     █";
    Console::GotoXY(x + 49, y + 11);
    cout << u8"     █";
    Console::GotoXY(x + 49, y + 12);
    cout << u8"     █";
    Console::GotoXY(x + 49, y + 13);
    cout << u8"     █";
    Console::GotoXY(x + 49, y + 14);
    cout << u8"     █";
    Console::GotoXY(x + 49, y + 15);
    cout << u8"     █";
    Console::GotoXY(x + 49, y + 16);
    cout << u8"    ▄";
    Console::GotoXY(x + 49, y + 17);
    cout << u8"  ▄";
    Console::GotoXY(x + 49, y + 18);
    cout << u8"▄";


    Console::SetColor(BLACK, backgroundBot);
    Console::GotoXY(x + 54, y + 16);
    cout << u8"▀";
    Console::GotoXY(x + 52, y + 17);
    cout << u8"▀";
    Console::GotoXY(x + 50, y + 18);
    cout << u8"▀";

    Draw1(x + 23, y + 5, BRIGHT_WHITE, RED);
    Draw2(x + 7, y + 9, BRIGHT_WHITE, LIGHT_BLUE);
    Draw3(x + 39, y + 12, BRIGHT_WHITE, YELLOW);

    SetConsoleOutputCP(oldcp);
}

void Graphic::ShowLeaderBoard()
{
    Graphic::DrawBigStar(5, 2, AQUA);
    Graphic::DrawBigStar(36, 5, AQUA);
    Graphic::DrawBigStar(95, 3, AQUA);
    Graphic::DrawBigStar(105, 10, AQUA);

    Graphic::DrawSmallStar(15, 12, AQUA);
    Graphic::DrawSmallStar(54, 1, AQUA);
    Graphic::DrawSmallStar(85, 9, AQUA);
    Graphic::DrawSmallStar(113, 1, AQUA);

    Graphic::DrawGoal(0, 119, 20, 29, 10, 5);
    Graphic::DrawLeaderBoardFigure(35, 8, AQUA, BRIGHT_WHITE);
}

void Graphic::DrawBigStar(int x, int y, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_YELLOW, BRIGHT_WHITE);
    Console::GotoXY(x + 2, y);
    cout << u8"▀";
    Console::GotoXY(x + 1, y + 1);
    cout << u8"▀ ▀";
    Console::GotoXY(x + 1, y + 2);
    cout << u8"█ █";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(x + 1, y);
    cout << u8"▄";
    Console::GotoXY(x + 3, y);
    cout << u8"▄";
    Console::GotoXY(x, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 4, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 2, y + 3);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawSmallStar(int x, int y, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(LIGHT_YELLOW, BRIGHT_WHITE);
    Console::GotoXY(x + 2, y);
    cout << u8"▀";
    Console::GotoXY(x + 1, y + 1);
    cout << u8"▄ ▄";

    Console::SetColor(LIGHT_YELLOW, background);
    Console::GotoXY(x + 1, y);
    cout << u8"▄";
    Console::GotoXY(x + 3, y);
    cout << u8"▄";
    Console::GotoXY(x, y + 1);
    cout << u8"▀";
    Console::GotoXY(x + 4, y + 1);
    cout << u8"▀";
    Console::GotoXY(x + 2, y + 2);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawBigMain(int x, int y, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(BLACK, LIGHT_BLUE);
    Console::GotoXY(x + 20, y);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 31, y);
    cout << u8"▄";
    Console::GotoXY(x + 20, y+1);
    cout << u8"█  ▀▄";
    Console::GotoXY(x + 29, y + 1);
    cout << u8"▄▀ █";
    Console::GotoXY(x + 20, y + 2);
    cout << u8"█    █▄▄█▄▄ █";
    Console::GotoXY(x + 20, y + 3);
    cout << u8"▀▄         ▀█";
    Console::GotoXY(x + 20, y + 4);
    cout << u8"▄▀     █   █ ▀▀▀▀▄▄";
    Console::GotoXY(x, y + 5);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 19, y + 5);
    cout << u8"▄▀                  █";
    Console::GotoXY(x , y + 6);
    cout << u8"█  █";
    Console::GotoXY(x + 17, y + 6);
    cout << u8"▄▀           ▄       ▄▀";
    Console::GotoXY(x , y + 7);
    cout << u8"█  ▄▀▀▀▀▀▀▀▀▀▀▀▀▀              ▀▀▀▄▄▀▀";
    Console::GotoXY(x+1, y + 8);
    cout << u8"█▀                             ▄▀";
    Console::GotoXY(x, y + 9);
    cout << u8"█                              █";
    Console::GotoXY(x, y + 10);
    cout << u8"█                             ▄▀";
    Console::GotoXY(x, y + 11);
    cout << u8"█                             █";
    Console::GotoXY(x, y + 12);
    cout << u8"▀▄                ▄     ▄   ▄█";
    Console::GotoXY(x, y + 13);
    cout << u8"▄▀    █▄▄▄▄▄▄▄▄▄▄▄▄█   █▄▄▄▀ █";
    Console::GotoXY(x, y + 14);
    cout << u8"█   ▄▀█   ▄▀";
    Console::GotoXY(x+19, y + 14);
    cout << u8"█   █ █   █";
    Console::GotoXY(x+1, y + 15);
    cout << u8"▀▀▀▀  ▀▀▀▀";
    Console::GotoXY(x + 20, y + 15);
    cout << u8"▀▀▀▀  ▀▀▀▀";



    //skin
    Console::SetColor(LIGHT_YELLOW,LIGHT_BLUE);
    Console::GotoXY(x + 22, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 22, y + 2);
    cout << u8"██";
    Console::GotoXY(x + 22, y + 3);
    cout << u8"▀";
    Console::GotoXY(x + 28, y + 5);
    cout << u8"▄▄█████████";
    Console::GotoXY(x + 27, y + 6);
    cout << u8"███";
    Console::GotoXY(x + 27, y + 7);
    cout << u8"▀███";
    Console::GotoXY(x + 28, y + 10);
    cout << u8"▄";
    Console::GotoXY(x + 26, y + 11);
    cout << u8"▄███";
    Console::GotoXY(x + 8, y + 12);
    cout << u8"▄▄▄▄▄▄▄▄▄▄";
    Console::GotoXY(x + 5, y + 13);
    cout << u8"▄";
    Console::GotoXY(x + 1, y + 14);
    cout << u8"▄▄█";
    Console::GotoXY(x + 7, y + 14);
    cout << u8"▄▄▄";


    Console::SetColor(LIGHT_YELLOW,BLACK);
    Console::GotoXY(x + 33, y + 4);
    cout << u8"▄▄▄▄";
    Console::GotoXY(x + 30, y + 6);
    cout << u8"▀███████▀";
    Console::GotoXY(x + 31, y + 7);
    cout << u8"▄▄▄▀▀";
    Console::GotoXY(x + 29, y + 8);
    cout << u8"███▀";
    Console::GotoXY(x + 29, y + 9);
    cout << u8"██";
    Console::GotoXY(x + 29, y + 10);
    cout << u8"█▀";
    Console::GotoXY(x + 25, y + 12);
    cout << u8"███▀";
    Console::GotoXY(x + 7, y + 13);
    cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀";
    Console::GotoXY(x + 24, y + 13);
    cout << u8"▀▀▀";
    Console::GotoXY(x + 4, y + 14);
    cout << u8"▀";
    Console::GotoXY(x + 10, y + 14);
    cout << u8"▀";
    Console::GotoXY(x + 20, y + 14);
    cout << u8"███";
    Console::GotoXY(x + 26, y + 14);
    cout << u8"███";


    //nose
    Console::SetColor(LIGHT_RED, LIGHT_YELLOW);
    Console::GotoXY(x + 35, y + 5);
    cout << u8"▀█▀";


    //outline
    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 20, y);
    cout << u8"▄";
    Console::GotoXY(x + 22, y);
    cout << u8"▄";
    Console::GotoXY(x + 31, y);
    cout << u8"▄";
    Console::GotoXY(x + 24, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 29, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 26, y + 2);
    cout << u8"▄▄";
    Console::GotoXY(x + 20, y + 3);
    cout << u8"▀";
    Console::GotoXY(x + 20, y + 4);
    cout << u8"▄";
    Console::GotoXY(x + 37, y + 4);
    cout << u8"▄▄";
    Console::GotoXY(x, y + 5);
    cout << u8"▄";
    Console::GotoXY(x+2, y + 5);
    cout << u8"▄";
    Console::GotoXY(x + 19, y + 5);
    cout << u8"▄";
    Console::GotoXY(x + 17, y + 6);
    cout << u8"▄";
    Console::GotoXY(x + 39, y + 6);
    cout << u8"▀";
    Console::GotoXY(x+36, y + 7);
    cout << u8"▀▀";
    Console::GotoXY(x + 33, y + 8);
    cout << u8"▀";
    Console::GotoXY(x+31, y + 10);
    cout << u8"▀";
    Console::GotoXY(x, y + 12);
    cout << u8"▀";
    Console::GotoXY(x, y + 13);
    cout << u8"▄";
    Console::GotoXY(x+5, y + 14);
    cout << u8"▀";
    Console::GotoXY(x+11, y + 14);
    cout << u8"▀";
    Console::GotoXY(x + 24, y + 14);
    cout << u8" ";
    Console::GotoXY(x + 1, y + 15);
    cout << u8"▀▀▀▀  ▀▀▀▀";
    Console::GotoXY(x + 20, y + 15);
    cout << u8"▀▀▀▀  ▀▀▀▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawBigMainDie(int x, int y, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);


    //draw blood
    Console::SetColor(RED, background);
    Console::GotoXY(x + 12, y + 5);
    cout << u8"▄▄████████████▄";
    Console::GotoXY(x + 9, y + 6);
    cout << u8"▄██████████████████";
    Console::GotoXY(x + 10, y + 13);
    cout << u8"▀███████████████████████";
    Console::GotoXY(x + 13, y + 14);
    cout << u8"▀█████████████▀";
    Console::GotoXY(x + 18, y + 15);
    cout << u8"▀▀▀▀▀▀▀▀";


    Console::SetColor(BLACK, LIGHT_BLUE);
    Console::GotoXY(x + 27, y + 3);
    cout << u8"▄▀▄";
    Console::GotoXY(x + 38, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 27, y + 4);
    cout << u8"█  ▀▄";
    Console::GotoXY(x + 36, y + 4);
    cout << u8"▄▀ █";
    Console::GotoXY(x + 27, y + 5);
    cout << u8"█    █▄▄█▄▄ █";
    Console::GotoXY(x + 27, y + 6);
    cout << u8"▀▄         ▀█";
    Console::GotoXY(x + 1, y + 6);
    cout << u8"▄▄▄";
    Console::GotoXY(x, y + 7);
    cout << u8"█   ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀    ▀▄▀ ▀▄▀ ▀▀▀▀▄▄";
    Console::GotoXY(x, y + 8);
    cout << u8"▀▄▄  ▄▄                         ▀ ▀ ▀ ▀       █";
    Console::GotoXY(x + 3, y + 9);
    cout << u8"██  █                                     ▄▀";
    Console::GotoXY(x + 3, y + 10);
    cout << u8"██  █                              ▀   █▀▀";
    Console::GotoXY(x + 3, y + 11);
    cout << u8"█ ▀▀                        ▀▄████▀▀";
    Console::GotoXY(x + 1, y + 12);
    cout << u8"▄▄▄▀     ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄          █";
    Console::GotoXY(x, y + 13);
    cout << u8"█     ▄▄▄▀";
    Console::GotoXY(x + 27, y + 13);
    cout << u8"▀▄▄▄     ▄▀";
    Console::GotoXY(x, y + 14);
    cout << u8"▀▄▄▄▀▀";
    Console::GotoXY(x + 31, y + 14);
    cout << u8"▀▀▀▀▀";


    //skin
    Console::SetColor(LIGHT_YELLOW, LIGHT_BLUE);
    Console::GotoXY(x + 29, y + 4);
    cout << u8"▄";
    Console::GotoXY(x + 29, y + 5);
    cout << u8"██";
    Console::GotoXY(x + 29, y + 6);
    cout << u8"▀";
    Console::GotoXY(x + 1, y + 7);
    cout << u8"██";
    Console::GotoXY(x + 37, y + 8);
    cout << u8"▄";
    Console::GotoXY(x + 34, y + 9);
    cout << u8"▄";
    Console::GotoXY(x + 34, y + 10);
    cout << u8"▀";



    Console::SetColor(LIGHT_YELLOW, BLACK);
    Console::GotoXY(x + 40, y + 7);
    cout << u8"▄▄▄▄";
    Console::GotoXY(x + 1, y + 8);
    cout << u8"▀▀";
    Console::GotoXY(x + 36, y + 8);
    cout << u8"▄";
    Console::GotoXY(x + 38, y + 8);
    cout << u8"▄███████";
    Console::GotoXY(x + 35, y + 9);
    cout << u8"██████████▀";
    Console::GotoXY(x + 35, y + 10);
    cout << u8"███▄";
    Console::GotoXY(x + 11, y + 12);
    cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀";
    Console::GotoXY(x + 35, y + 12);
    cout << u8"██";
    Console::GotoXY(x + 1, y + 13);
    cout << u8"██";
    Console::GotoXY(x + 35, y + 13);
    cout << u8"█▀";
    Console::GotoXY(x + 1, y + 14);
    cout << u8"▀▀";



    //nose
    Console::SetColor(LIGHT_RED, LIGHT_YELLOW);
    Console::GotoXY(x + 42, y + 8);
    cout << u8"▀█▀";

    //tounge
    Console::SetColor(RED, background);
    Console::GotoXY(x + 39, y + 10);
    cout << u8"███";
    Console::GotoXY(x + 39, y + 11);
    cout << u8"▀█▀";

    //outlineDog
    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 27, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 29, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 38, y + 3);
    cout << u8"▄";
    Console::GotoXY(x + 31, y + 4);
    cout << u8"▄";
    Console::GotoXY(x + 36, y + 4);
    cout << u8"▄";
    Console::GotoXY(x + 33, y + 5);
    cout << u8"▄▄";
    Console::GotoXY(x + 27, y + 6);
    cout << u8"▀";
    Console::GotoXY(x + 1, y + 6);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 44, y + 7);
    cout << u8"▄▄";
    Console::GotoXY(x, y + 8);
    cout << u8"▀";
    Console::GotoXY(x + 46, y + 9);
    cout << u8"▀";
    Console::GotoXY(x + 43, y + 10);
    cout << u8"▀▀";
    Console::GotoXY(x + 37, y + 11);
    cout << u8"▀▀";
    Console::GotoXY(x + 1, y + 12);
    cout << u8"▄▄▄";
    Console::GotoXY(x + 9, y + 13);
    cout << u8"▀";
    Console::GotoXY(x + 27, y + 13);
    cout << u8"▀";
    Console::GotoXY(x + 37, y + 13);
    cout << u8"▀";
    Console::GotoXY(x, y + 14);
    cout << u8"▀";
    Console::GotoXY(x + 4, y + 14);
    cout << u8"▀▀";
    Console::GotoXY(x + 31, y + 14);
    cout << u8"▀▀▀▀▀";

    //Ghost
    Console::SetColor(BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 19, y);
    cout << u8"▄▄▄▄▄▄";
    Console::GotoXY(x + 17, y + 1);
    cout << u8"▄▀      ▀▄";
    Console::GotoXY(x + 17, y + 2);
    cout << u8"█  █  █  █";
    Console::GotoXY(x + 17, y + 3);
    cout << u8"█   ▄▄   █";
    Console::GotoXY(x + 17, y + 4);
    cout << u8"▀▄ ▀  ▀ █";
    Console::GotoXY(x + 18, y + 5);
    cout << u8"█     █";
    Console::GotoXY(x + 18, y + 6);
    cout << u8"▀▄   ▄▀";
    Console::GotoXY(x + 19, y + 7);
    cout << u8"█ ▄█";

    Console::SetColor(BLACK, LIGHT_BLUE);
    Console::GotoXY(x + 19, y + 8);
    cout << u8"▀▀";

    //outlineGhost
    Console::SetColor(BLACK, background);
    Console::GotoXY(x + 19, y);
    cout << u8"▄▄▄▄▄▄";
    Console::GotoXY(x + 17, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 26, y + 1);
    cout << u8"▄";
    Console::GotoXY(x + 17, y + 4);
    cout << u8"▀";

    //outline blood
    Console::SetColor(BLACK, RED);
    Console::GotoXY(x + 18, y + 6);
    cout << u8"▀";
    Console::GotoXY(x + 24, y + 6);
    cout << u8"▀";
    Console::GotoXY(x + 27, y + 6);
    cout << u8"▀";
    Console::GotoXY(x + 27, y + 13);
    cout << u8"▀";

    SetConsoleOutputCP(oldcp);
}

void Graphic::ShowBigMainDie() {
    Console::SetColor(AQUA, AQUA);
    system("cls");
    PlaySound(TEXT("Sound/characterDie.wav"), NULL, SND_ASYNC);
    DrawBigMain(43, 7, AQUA);
    Sleep(500);
    system("cls");
    DrawBigMainDie(40, 7, AQUA);
    Sleep(200);
    system("cls");
}

void Graphic::DrawInputUsernameDialog(int x, int y) {
    DrawBox(x, y, 50, 9, BLACK, BRIGHT_WHITE);
    Console::GotoXY(x + 21, y + 1);
    cout << "Username";
    Console::GotoXY(x + 6, y + 2);
    cout << "Username must be less than 8 letters";
    Console::GotoXY(x + 2, y + 3);
    cout << "No space and no special charactes is allowed";
    Console::GotoXY(x + 2, y + 4);
    cout << "Name: ";
}

void Graphic::DrawNumber(int x, int y, int color, int background, int number)
{
    void (*drawNum[])(int, int, int, int) = { Draw0,Draw1,Draw2,Draw3,Draw4,Draw5,Draw6,Draw7,Draw8,Draw9 };
    if (number / 10 == 0)
        drawNum[number % 10](x, y, color, background);
    else {
        int space = 4;
        for (; number > 0; number /= 10, space -= 4) {
            drawNum[number % 10](x + space, y, color, background);
        }
    }
}

void Graphic::DrawMiniGameWelcome()
{
    Console::SetColor(BLACK, LIGHT_YELLOW);
    system("cls");
    DrawWordMiniGame(20, 4, BLACK, LIGHT_YELLOW);
    Console::GotoXY(10, 15);
    cout << "- Your objective in this minigame is collecting all the coins visible, further increasing your points.";
    Console::GotoXY(10, 17);
    cout << "- If the main character is hit during the minigame, the game will be considered over.";
    Console::GotoXY(10, 19);
    cout << "- No save / load is available in the minigame, but you can still pause the game whenever you want.";
    Console::GotoXY(10, 21);
    cout << "- You have 50 seconds to complete the minigame.";
    Console::GotoXY(10, 23);
    cout << "- If the main character is alive after 50 seconds or cross the finish line, you successfully finish the game.";
    Console::GotoXY(40, 25);
    cout << "Press any key to continue";
}

void Graphic::DrawWordMiniGame(int x, int y, int color, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);

    Console::SetColor(color,background);
    Console::GotoXY(x, y);
    cout << u8"██      ██                              ▄█████▄";
    Console::GotoXY(x, y+1);
    cout << u8"████  ████   ▄▄             ▄▄         ██    ▀▀";
    Console::GotoXY(x, y+2);
    cout << u8"██  ██  ██   ▀▀             ▀▀         ██";
    Console::GotoXY(x, y+3);
    cout << u8"██      ██   ██   ██▄███▄   ██         ██    ▄▄▄▄   ▄████▄██   ██▄▀██▄▀██    ▄███▄";
    Console::GotoXY(x, y+4);
    cout << u8"██      ██   ██   ██▀  ██   ██         ██▄    ██    ██   ███   ██  ██  ██   ██▄▄▄▀";
    Console::GotoXY(x, y+5);
    cout << u8"██      ██   ██   ██   ██   ██          ▀█████▀▀    ▀████▀██   ██  ██  ██   ▀█▄▄▄▄";

    SetConsoleOutputCP(oldcp);
}

void Graphic::DrawGameOverDecoration(int x, int y, int background)
{
    UINT oldcp = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    Console::SetColor(BLACK, background);
    Console::GotoXY(x+6, y);
    cout << u8"▄▀";

    Console::SetColor(LIGHT_RED, background);
    Console::GotoXY(x + 4, y);
    cout << u8"▄";
    Console::GotoXY(x + 4, y+1);
    cout << u8"██▄";
    Console::GotoXY(x + 5, y + 2);
    cout << u8"▀";

    Console::SetColor(LIGHT_RED, BRIGHT_WHITE);
    Console::GotoXY(x + 3, y+1);
    cout << u8"▀";
    
    Console::SetColor(BRIGHT_WHITE, background);
    Console::GotoXY(x + 1, y + 2);
    cout << u8"▄██▀";
    Console::GotoXY(x, y + 3);
    cout << u8"██▀";

    Console::SetColor(RED,BRIGHT_WHITE);
    Console::GotoXY(x + 1, y + 3);
    cout << u8"▄";

    Console::SetColor(RED, background);
    Console::GotoXY(x-4, y + 2);
    cout << u8"▀";
    Console::GotoXY(x+2, y + 4);
    cout << u8"▄";
    Console::GotoXY(x + 2, y + 5);
    cout << u8"▀   █";
    Console::GotoXY(x + 4, y + 6);
    cout << u8"█";


    SetConsoleOutputCP(oldcp);
}
