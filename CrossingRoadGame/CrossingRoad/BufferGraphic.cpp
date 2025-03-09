#include "BufferGraphic.h"

static CHAR_INFO screenBuffer[SCREEN_HEIGHT * SCREEN_WIDTH];

int BufferGraphic::GetColorCode(const int& colorText, const int& colorBackGround) {
	return colorText + 16 * colorBackGround;
}

void BufferGraphic::DrawPixel(wchar_t c, int x, int y, int colorText, int colorBackGround, wchar_t* const& pBuffer, WORD* const& pColor) {
	pBuffer[x + y * SCREEN_WIDTH] = c;
	pColor[x + y * SCREEN_WIDTH] = GetColorCode(colorText, colorBackGround);
}

void BufferGraphic::DrawGameFrame(wchar_t* const& pBuffer, WORD* const& pColor) {
	for (int y = 0; y <= 29; y++)
		DrawPixel(L'█', 100, y, BLACK, BLACK, pBuffer, pColor);

	for (int x = 101; x < 120; x++)
		DrawPixel(L'█', x, 15, BLACK, BLACK, pBuffer, pColor);
}

void BufferGraphic::PushPixelOnScreen(wchar_t* const& pBuffer, WORD* const& pColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwBytesWritten = 0;
	for (int j = 0; j < SCREEN_HEIGHT; j++) {
		for (int i = 0; i < SCREEN_WIDTH; i++) {
			COORD cPos;
			cPos.X = i;
			cPos.Y = j;
			//WriteConsoleOutputAttribute(hConsole, &pColor[j * SCREEN_WIDTH + i], 1, cPos, &dwBytesWritten);
			screenBuffer[j * SCREEN_WIDTH + i].Attributes = pColor[j * SCREEN_WIDTH + i];
			screenBuffer[j * SCREEN_WIDTH + i].Char.UnicodeChar = pBuffer[j * SCREEN_WIDTH + i];
		}
	}
	SMALL_RECT screen;
	screen.Top = 0;
	screen.Left = 0;
	screen.Right = 120;
	screen.Bottom = 30;
	//WriteConsoleOutputCharacter(hConsole, pBuffer, SCREEN_WIDTH * SCREEN_HEIGHT, { 0,0 }, &dwBytesWritten);
	WriteConsoleOutput(hConsole, screenBuffer, { 120,30 }, { 0,0 }, &screen);
}

void BufferGraphic::DrawBackgroundScreen(wchar_t* const& pBuffer, WORD* const& pColor, int color) {
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		for (int j = 0; j < SCREEN_HEIGHT; j++) {
			pBuffer[j * SCREEN_WIDTH + i] = L' ';
			pColor[j * SCREEN_WIDTH + i] = color * 16;
		}
	}
}

void BufferGraphic::DrawMainCharacter(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int outline = BLACK;
	int body = LIGHT_BLUE;
	int skin = LIGHT_YELLOW;

	DrawPixel(L'▄', x + 4, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y, outline, body, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y, outline, body, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y, outline, background, pBuffer, pColor);

	DrawPixel(L'▄', x, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 1, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 1, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 1, body, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 7, y + 1, BLACK, body, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y + 1, skin, outline, pBuffer, pColor);
	DrawPixel(L'▄', x + 9, y + 1, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 2, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 1, y + 2, outline, body, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, outline, body, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 2, outline, body, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y + 2, outline, body, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y + 2, outline, skin, pBuffer, pColor);
	DrawPixel(L'▀', x + 9, y + 2, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x + 1, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 3, body, skin, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 3, body, skin, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y + 3, body, outline, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 3, body, outline, pBuffer, pColor);
	DrawPixel(L'▀', x + 6, y + 3, body, outline, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y + 3, body, skin, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 3, outline, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 2, y + 4, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 4, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y + 4, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 8, y + 4, outline, background, pBuffer, pColor);
}


void BufferGraphic::DrawCarLeftFacing(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int outline = PURPLE;
	int body = LIGHT_PURPLE;
	int window = LIGHT_YELLOW;
	int tire = BLACK;

	DrawPixel(L'▄', x + 3, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 4, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 5, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 7, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y, outline, background, pBuffer, pColor);

	DrawPixel(L'▄', x + 1, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 1, outline, window, pBuffer, pColor);
	DrawPixel(L'█', x + 3, y + 1, window, window, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 1, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 1, window, window, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 1, window, window, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 1, window, window, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 1, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 9, y + 1, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 2, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 3, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 9, y + 2, outline, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 6, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 9, y + 3, outline, background, pBuffer, pColor);
}

void BufferGraphic::DrawGreenTrafficLight(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int body = BLACK;
	DrawPixel(L'█', x, y, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, body, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, body, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, body, GREEN, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, body, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, body, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 1, y + 3, body, background, pBuffer, pColor);
}

void BufferGraphic::DrawRedTrafficLight(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int body = BLACK;
	DrawPixel(L'█', x, y, body, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, body, RED, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, body, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 1, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, body, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 2, body, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, body, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 1, y + 3, body, background, pBuffer, pColor);
}

void BufferGraphic::DrawRoad(int xStart, int xEnd, int y, wchar_t* const& pBuffer, WORD* const& pColor) {
	int len = xEnd - xStart;
	len = round((float)len / 10) * 10;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (j != 2)
			{
				DrawPixel(L'█', xStart + i, y + j, GRAY, BLACK, pBuffer, pColor);
			}
			else {
				if (i % 6 > 2 && i % 6 < 6) {
					DrawPixel(L'█', xStart + i, y + j, WHITE, BLACK, pBuffer, pColor);
				}
				else {
					DrawPixel(L'█', xStart + i, y + j, GRAY, BLACK, pBuffer, pColor);
				}
			}
		}
	}
}

void BufferGraphic::DrawGrass(int xStart, int xEnd, int y, wchar_t* const& pBuffer, WORD* const& pColor) {
	int len = xEnd - xStart;
	len = round((float)len / 10) * 10;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			DrawPixel(L'█', xStart + i, y + j, LIGHT_GREEN, LIGHT_GREEN, pBuffer, pColor);

			if (i % 10 == 2 && j == 1)
				DrawPixel(L'▀', xStart + i, y + j, GREEN, LIGHT_GREEN, pBuffer, pColor);

			if (i % 10 == 4 && j == 3)
				DrawPixel(L'▄', xStart + i, y + j, GREEN, LIGHT_GREEN, pBuffer, pColor);

			if (i % 10 == 6 && j == 1)
				DrawPixel(L'▄', xStart + i, y + j, GREEN, LIGHT_GREEN, pBuffer, pColor);

			if (i % 10 == 8 && j == 1)
				DrawPixel(L'▄', xStart + i, y + j, GREEN, LIGHT_GREEN, pBuffer, pColor);

			if (i % 10 == 7 && j == 2)
				DrawPixel(L'▀', xStart + i, y + j, GREEN, LIGHT_GREEN, pBuffer, pColor);
		}
	}
}

void BufferGraphic::DrawTruckLeftFacing(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int outline = BLUE;
	int body = LIGHT_BLUE;
	int containerBox = WHITE;
	int window = LIGHT_YELLOW;
	int tire = BLACK;

	DrawPixel(L'▄', x + 3, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 4, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 5, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 7, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 9, y, outline, background, pBuffer, pColor);

	DrawPixel(L'▄', x + 1, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 1, outline, window, pBuffer, pColor);
	DrawPixel(L'█', x + 3, y + 1, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 1, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 1, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 1, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 1, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 1, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 9, y + 1, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 2, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, window, body, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, window, body, pBuffer, pColor);
	DrawPixel(L'█', x + 3, y + 2, body, body, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 2, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 2, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 2, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 2, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 2, containerBox, containerBox, pBuffer, pColor);
	DrawPixel(L'█', x + 9, y + 2, outline, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 6, y + 3, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 3, tire, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 9, y + 3, outline, background, pBuffer, pColor);
}

void BufferGraphic::DrawDinosaur(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int skin = LIGHT_RED;
	int scales = RED;
	int mouth = LIGHT_YELLOW;

	DrawPixel(L'█', x + 3, y, scales, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y, scales, skin, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y, skin, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y, BLACK, skin, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 9, y, skin, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 3, y + 1, skin, scales, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 1, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 1, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 1, skin, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y + 1, skin, mouth, pBuffer, pColor);
	DrawPixel(L'▀', x + 8, y + 1, skin, mouth, pBuffer, pColor);
	DrawPixel(L'▀', x + 9, y + 1, skin, mouth, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, scales, skin, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, scales, skin, pBuffer, pColor);
	DrawPixel(L'▄', x + 2, y + 2, scales, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 2, scales, skin, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 2, skin, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 5, y + 2, scales, skin, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 2, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 2, skin, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 1, y + 3, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 3, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 3, y + 3, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 3, skin, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 3, scales, skin, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 3, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 3, skin, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 3, y + 4, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 4, skin, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 4, skin, background, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 4, skin, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y + 4, skin, background, pBuffer, pColor);
}

void BufferGraphic::DrawCatWithMotorbike(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	int motorbikeBody = RED;
	int handle = WHITE;
	int light = LIGHT_YELLOW;
	int tire = BLACK;

	int outline = BLACK;
	int cat = BRIGHT_WHITE;


	DrawPixel(L'▄', x + 4, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y, outline, cat, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y, outline, cat, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y, outline, background, pBuffer, pColor);

	DrawPixel(L'▄', x + 3, y + 1, handle, background, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 1, outline, cat, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 1, cat, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y + 1, outline, cat, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 1, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 2, light, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 2, handle, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 2, y + 2, handle, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 2, handle, background, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 2, outline, background, pBuffer, pColor);
	DrawPixel(L'█', x + 6, y + 2, cat, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 2, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 9, y + 2, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x + 1, y + 3, handle, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 3, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'█', x + 3, y + 3, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 3, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 5, y + 3, motorbikeBody, outline, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y + 3, motorbikeBody, outline, pBuffer, pColor);
	DrawPixel(L'▄', x + 7, y + 3, motorbikeBody, outline, pBuffer, pColor);
	DrawPixel(L'▄', x + 8, y + 3, motorbikeBody, outline, pBuffer, pColor);
	DrawPixel(L'▄', x + 9, y + 3, motorbikeBody, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 4, tire, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 4, tire, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 4, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y + 4, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 5, y + 4, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 6, y + 4, motorbikeBody, background, pBuffer, pColor);
	DrawPixel(L'█', x + 7, y + 4, tire, background, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 4, tire, background, pBuffer, pColor);
}



void BufferGraphic::Draw0(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'█', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw1(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'▄', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw2(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'▀', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw3(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'▀', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw4(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'█', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw5(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'█', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw6(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'█', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw7(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'▀', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw8(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'█', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::Draw9(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	DrawPixel(L'█', x, y, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, color, background, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, color, background, pBuffer, pColor);

	DrawPixel(L'▀', x, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 2, color, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, color, background, pBuffer, pColor);
}

void BufferGraphic::DrawNumber(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor, int number) {
	void (*drawNum[])(int, int, int, int, wchar_t* const&, WORD* const&) = { Draw0,Draw1,Draw2,Draw3,Draw4,Draw5,Draw6,Draw7,Draw8,Draw9 };
	if (number / 10 == 0)
		drawNum[number % 10](x, y, color, background, pBuffer, pColor);
	else {
		int space = 4;
		for (; number > 0; number /= 10, space -= 4) {
			drawNum[number % 10](x + space, y, color, background, pBuffer, pColor);
		}
	}
}

void BufferGraphic::DrawLevelTitle(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	wchar_t level[] = { L'L',L'E',L'V',L'E',L'L' };
	int nLevel = sizeof(level) / sizeof(level[0]);
	for (int i = 0; i < nLevel; i++)
		DrawPixel(level[i], x + i, y, color, background, pBuffer, pColor);
}

void BufferGraphic::DrawScoreTitle(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	wchar_t score[] = { L'S',L'C',L'O',L'R',L'E' };
	int nScore = sizeof(score) / sizeof(score[0]);
	for (int i = 0; i < nScore; i++)
		DrawPixel(score[i], x + i, y, color, background, pBuffer, pColor);
}

void BufferGraphic::DrawTimeRemainingTitle(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {
	wchar_t score[] = { L'T',L'I',L'M',L'E',L' ', L'R', L'E', L'M', L'A', L'I', L'N', L'I', L'N', L'G'};
	int nScore = sizeof(score) / sizeof(score[0]);
	for (int i = 0; i < nScore; i++)
		DrawPixel(score[i], x + i, y, color, background, pBuffer, pColor);
}

void BufferGraphic::DrawGameTutorial(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor) {

	wchar_t goLeft[] = { L'A',L':',L' ',L'G',L'o',L' ',L'l',L'e',L'f',L't' };
	int nLeft = sizeof(goLeft) / sizeof(goLeft[0]);
	wchar_t goRight[] = { L'D',L':',L' ',L'G',L'o',L' ',L'r',L'i',L'g',L'h',L't' };
	int nRight = sizeof(goRight) / sizeof(goRight[0]);
	wchar_t goUp[] = { L'W',L':',L' ',L'G',L'o',L' ',L'u',L'p' };
	int nUp = sizeof(goUp) / sizeof(goUp[0]);
	wchar_t goDown[] = { L'S',L':',L' ',L'G',L'o',L' ',L'd',L'o',L'w',L'n' };
	int nDown = sizeof(goDown) / sizeof(goDown[0]);
	wchar_t pause[] = { L'P',L':',L' ',L'P',L'a',L'u',L's',L'e' };
	int nPause = sizeof(pause) / sizeof(pause[0]);
	wchar_t resume[] = { L'R',L':',L' ',L'R',L'e',L's',L'u',L'm',L'e' };
	int nResume = sizeof(resume) / sizeof(resume[0]);
	wchar_t save[] = { L'L',L':',L' ',L'S',L'a',L'v',L'e' };
	int nSave = sizeof(save) / sizeof(save[0]);
	wchar_t escape[] = { L'E',L'S',L'C',L' ',L'E',L'x',L'i',L't' };
	int nEscape = sizeof(escape) / sizeof(escape[0]);

	for (int i = 0; i < nLeft; i++)
		DrawPixel(goLeft[i], x + i, y, color, background, pBuffer, pColor);
	for (int i = 0; i < nRight; i++)
		DrawPixel(goRight[i], x + i, y + 1, color, background, pBuffer, pColor);
	for (int i = 0; i < nUp; i++)
		DrawPixel(goUp[i], x + i, y + 2, color, background, pBuffer, pColor);
	for (int i = 0; i < nDown; i++)
		DrawPixel(goDown[i], x + i, y + 3, color, background, pBuffer, pColor);
	for (int i = 0; i < nPause; i++)
		DrawPixel(pause[i], x + i, y + 4, color, background, pBuffer, pColor);
	for (int i = 0; i < nResume; i++)
		DrawPixel(resume[i], x + i, y + 5, color, background, pBuffer, pColor);
	for (int i = 0; i < nSave; i++)
		DrawPixel(save[i], x + i, y + 6, color, background, pBuffer, pColor);
	for (int i = 0; i < nEscape; i++)
		DrawPixel(escape[i], x + i, y + 7, color, background, pBuffer, pColor);
}

void BufferGraphic::DrawSquare(int x, int y, int xSize, int ySize, int color, wchar_t* const& pBuffer, WORD* const& pColor) {
	for (int j = 0; j < ySize; j++) {
		for (int i = 0; i < xSize; i++) {
			DrawPixel(L'█', x + i, y + j, color, color, pBuffer, pColor);
		}
	}
}

void BufferGraphic::DrawGoal(int xLeft, int xRight, int yUp, int yDown, int xSize, int ySize, wchar_t* const& pBuffer, WORD* const& pColor) {
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

			DrawSquare(xLeft + i, yUp + j, xSquare, ySquare, colorSquare, pBuffer, pColor);
			iStep++;
		}
		jStep++;
	}
}

void BufferGraphic::DrawCross(int color, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	for (int i = 0; i < 120; i++) {
		BufferGraphic::DrawPixel(L'▄',i,15,color,background,pBuffer,pColor);
	}
	for (int i = 0; i < 30; i++) {
		BufferGraphic::DrawPixel(L'█', 60, i, color, background, pBuffer, pColor);
	}
}

void BufferGraphic::DrawString(wstring c, int x, int y, int colorText, int colorBackGround, wchar_t* const& pBuffer, WORD* const& pColor)
{
	for (int i = 0; i < c.size(); i++) {
		DrawPixel(c[i], x + i, y, colorText, colorBackGround, pBuffer, pColor);
	}
}

void BufferGraphic::DrawWASDArrow(int color[5], int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	//up
	DrawString(L"▄██▄", 40, 5, color[0], background, pBuffer, pColor);
	DrawString(L"▀▀▀▀", 40, 6, color[0], background, pBuffer, pColor);

	//right
	DrawString(L"██▄", 45, 7, color[1], background, pBuffer, pColor);
	DrawString(L"██▀", 45, 8, color[1], background, pBuffer, pColor);

	//down
	DrawString(L"▄▄▄▄", 40, 9, color[2], background, pBuffer, pColor);
	DrawString(L"▀██▀", 40, 10, color[2], background, pBuffer, pColor);

	//left
	DrawString(L"▄██", 36, 7, color[3], background, pBuffer, pColor);
	DrawString(L"▀██", 36, 8, color[3], background, pBuffer, pColor);
}

void BufferGraphic::DeleteMainCharacter(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	DrawString(L"     ", x + 4, y, background, background, pBuffer, pColor);
	DrawString(L"  ", x, y + 1, background, background, pBuffer, pColor);
	DrawString(L"      ", x + 4, y + 1, background, background, pBuffer, pColor);
	DrawString(L"          ", x, y + 2, background, background, pBuffer, pColor);
	DrawString(L"        ", x + 1, y + 3, background, background, pBuffer, pColor);
	DrawString(L"  ", x + 2, y + 4, background, background, pBuffer, pColor);
	DrawString(L"  ", x + 7, y + 4, background, background, pBuffer, pColor);
}

void BufferGraphic::DrawUpArrow(int x, int y, int colorBot, int colorMid, int colorTop, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	//top
	DrawString(L".", x + 3, y + 1, colorTop, background, pBuffer, pColor);
	DrawString(L"/ \\", x + 2, y + 2, colorTop, background, pBuffer, pColor);
	DrawString(L"/   \\", x + 1, y + 3, colorTop, background, pBuffer, pColor);
	DrawString(L"/_   _\\", x, y + 4, colorTop, background, pBuffer, pColor);

	//mid
	DrawString(L"| |", x + 2, y + 5, colorMid, background, pBuffer, pColor);
	DrawString(L"| |", x + 2, y + 6, colorMid, background, pBuffer, pColor);

	//bot
	DrawString(L"|_|", x + 2, y + 7, colorBot, background, pBuffer, pColor);
}

void BufferGraphic::DrawCarRightFacing(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	//outside
	DrawString(L"▄▄▄▄▄▄", x + 1, y, PURPLE, background, pBuffer, pColor);
	DrawString(L"█", x, y + 1, PURPLE, background, pBuffer, pColor);
	DrawString(L"▄", x + 8, y + 1, PURPLE, background, pBuffer, pColor);
	DrawString(L"█        █", x, y + 2, PURPLE, background, pBuffer, pColor);
	DrawString(L"▀▀▀▀▀▀▀▀▀▀", x, y + 3, PURPLE, background, pBuffer, pColor);

	//window
	DrawString(L" ███ █", x + 1, y + 1, LIGHT_YELLOW, LIGHT_PURPLE, pBuffer, pColor);

	DrawString(L"▄", x + 7, y + 1, LIGHT_YELLOW, PURPLE, pBuffer, pColor);

	//body
	DrawString(L"████████", x + 1, y + 2, LIGHT_PURPLE, LIGHT_PURPLE, pBuffer, pColor);

	//tire
	DrawString(L"██", x + 1, y + 3, BLACK, background, pBuffer, pColor);
	DrawString(L"██", x + 7, y + 3, BLACK, background, pBuffer, pColor);
}

void BufferGraphic::DrawMainDisappear1(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor){
	DrawString(L"▄   ▄", x + 4, y, BLACK, background, pBuffer, pColor);
	DrawString(L"▄", x + 7, y, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▄   ▄   ▀", x, y + 1, BLACK, background, pBuffer, pColor);
	DrawString(L"█▄▀", x + 5, y + 1, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▄   ▀    ▀", x, y + 2, BLACK, background, pBuffer, pColor);
	DrawString(L"▄", x + 8, y + 2, BLACK, LIGHT_YELLOW, pBuffer, pColor);
	DrawString(L"▄▀", x + 1, y + 2, BLACK, LIGHT_BLUE, pBuffer, pColor);
	DrawString(L"▄", x + 3, y + 2, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▀▄", x + 5, y + 2, LIGHT_BLUE, background, pBuffer, pColor);	
	DrawString(L"▀  ▄   ▄", x + 1, y + 3, BLACK, background, pBuffer, pColor);	
	DrawString(L"▄", x + 6, y + 3, BLACK, LIGHT_YELLOW, pBuffer, pColor);
	DrawString(L"▄", x + 3, y + 3, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"▄", x + 5, y + 3, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"▄", x + 7, y + 3, LIGHT_YELLOW, LIGHT_BLUE, pBuffer, pColor);	
	DrawString(L"▀", x + 2, y + 3, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▄", x + 3, y + 3, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"▀", x + 5, y + 3, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"▀▀", x + 2, y + 4, BLACK, background, pBuffer, pColor);
	DrawString(L"▀▀", x + 7, y + 4, BLACK, background, pBuffer, pColor);
}

void BufferGraphic::DrawMainDisappear2(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	DrawString(L"▀ ", x + 5, y + 1, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"  ", x + 2, y + 2, BLACK, background, pBuffer, pColor);
	DrawString(L"▄ ", x + 8, y + 2, BLACK, background, pBuffer, pColor);
	DrawString(L" ", x + 3, y + 3, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▀ ", x + 7, y + 3, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L" ▀", x + 7, y + 3, BLACK, background, pBuffer, pColor);
}

void BufferGraphic::DrawMainDisappear3(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	DrawString(L"▄       ▀", x, y + 1, BLACK, background, pBuffer, pColor);
	DrawString(L"▀    ▀", x + 1, y + 2, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▀", x + 5, y + 3, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"▀", x + 6, y + 3, LIGHT_YELLOW, BLACK, pBuffer, pColor);
	DrawString(L"▀", x + 7, y + 3, LIGHT_BLUE, background, pBuffer, pColor);
	DrawString(L"▀", x + 2, y + 4, BLACK, background, pBuffer, pColor);
	DrawString(L"▀", x + 8, y + 4, BLACK, background, pBuffer, pColor);

}


void BufferGraphic::DrawBird(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	int outline = BLACK;
	int mouth = LIGHT_YELLOW;
	int body = LIGHT_GREEN;
	int wing = LIGHT_AQUA;

	DrawPixel(L'▄', x + 1, y, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y, outline, mouth, pBuffer, pColor);
	DrawString(L"▀▀▀", x + 3, y, outline, body, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y, outline, background, pBuffer, pColor);

	DrawPixel(L'█', x, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 1, y + 1, outline, mouth, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, mouth, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y + 1, BLACK, body, pBuffer, pColor);
	DrawPixel(L'█', x + 4, y + 1, body, background, pBuffer, pColor);
	DrawPixel(L'█', x + 5, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y + 1, outline, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 7, y + 1, outline, wing, pBuffer, pColor);
	DrawPixel(L'█', x + 8, y + 1, outline, background, pBuffer, pColor);


	DrawString(L"▀▀█", x, y + 2, outline, background, pBuffer, pColor);
	DrawString(L"███▄", x + 3, y + 2, body, outline, pBuffer, pColor);
	DrawString(L"▀▀█", x + 7, y + 2, outline, wing, pBuffer, pColor);

	DrawPixel(L'▀', x + 2, y + 3, outline, background, pBuffer, pColor);
	DrawString(L"▀██", x + 3, y + 3, body, outline, pBuffer, pColor);
	DrawPixel(L'▄', x + 6, y + 3, body, wing, pBuffer, pColor);
	DrawPixel(L'▄', x + 7, y + 3, outline, wing, pBuffer, pColor);
	DrawString(L"▀▀", x + 8, y + 3, outline, background, pBuffer, pColor);

	DrawString(L"▀▀▀", x + 4, y + 4, outline, background, pBuffer, pColor);
}

void BufferGraphic::DrawCoinFront(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	DrawString(L"▄██", x, y, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"████", x, y + 1, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawString(L"▀▀▀", x + 1, y + 2, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 3, y, BRIGHT_WHITE, LIGHT_YELLOW, pBuffer, pColor);
	DrawPixel(L'▄', x + 4, y, BRIGHT_WHITE, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 4, y + 1, BRIGHT_WHITE, LIGHT_YELLOW, pBuffer, pColor);
}

void BufferGraphic::DrawCoinSide(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor)
{
	DrawPixel(L'▀', x + 2, y, YELLOW, LIGHT_YELLOW, pBuffer, pColor);
	DrawPixel(L'█', x + 2, y + 1, LIGHT_YELLOW, background, pBuffer, pColor);
	DrawPixel(L'▀', x + 2, y + 2, YELLOW, background, pBuffer, pColor);
}

