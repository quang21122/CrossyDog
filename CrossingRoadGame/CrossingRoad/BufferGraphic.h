#pragma once
#include "Graphic.h"

#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 30


class BufferGraphic
{
private:
	static int GetColorCode(const int& colorText, const int& colorBackGround);
	static void DrawPixel(wchar_t c, int x, int y,int colorText, int colorBackGround,  wchar_t*const& pBuffer, WORD*const& pColor);
	
public:
	static void DrawBackgroundScreen(wchar_t*const& pBuffer, WORD*const& pColor,int color);
	static void DrawGameFrame(wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawMainCharacter(int x, int y, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawCarLeftFacing( int x, int y, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawGreenTrafficLight( int x, int y, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawRedTrafficLight(int x, int y, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawRoad(int xStart, int xEnd, int y, wchar_t*const& pBuffer, WORD*const& pColor);
	static void PushPixelOnScreen(wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawGrass(int xStart, int xEnd, int y, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawTruckLeftFacing(int x, int y, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawDinosaur(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawCatWithMotorbike(int x, int y, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw0(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw1(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw2(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw3(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw4(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw5(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw6(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw7(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw8(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void Draw9(int x, int y, int color, int background, wchar_t*const& pBuffer, WORD*const& pColor);
	static void DrawNumber(int x,int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor, int number);
	static void DrawLevelTitle(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawScoreTitle(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawTimeRemainingTitle(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawGameTutorial(int x, int y, int color, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawSquare(int x, int y, int xSize, int ySize, int color, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawGoal(int xLeft, int xRight, int yUp, int yDown, int xSize, int ySize, wchar_t* const& pBuffer, WORD* const& pColor);

	static void DrawCross(int color, int backfround, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawString(wstring c, int x, int y, int colorText, int colorBackGround, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawWASDArrow(int color[5], int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DeleteMainCharacter(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawUpArrow(int x, int y, int colorBot, int colorMid, int colorTop, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawCarRightFacing(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawMainDisappear1(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawMainDisappear2(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawMainDisappear3(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);

	static void DrawBird(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawCoinFront(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
	static void DrawCoinSide(int x, int y, int background, wchar_t* const& pBuffer, WORD* const& pColor);
};

