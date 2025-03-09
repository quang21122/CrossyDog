#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Console.h"

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15
using namespace std;

class Graphic {
public:
	static void DrawFrog(int x, int y, int background);
	static void DrawJumpingFrog(int x, int y, int background);
	static void DeleteFrog(int x, int y);
	static void DrawDuck(int x, int y, int background);
	static void DrawLotus(int x, int y, int background);
	static void DrawLeaf(int x, int y, int background);
	static void DrawTitle(int x, int y, int background);
	static void DrawMenuChooseFrame(int x, int y, int background);

	static void DrawSettingsWord(int x, int y, int background);
	static void DrawMuteIcon(int x, int y);
	static void DrawUnmuteIcon(int x, int y);
	static void DrawOnWord(int x, int y, int color, int background);
	static void DrawOffWord(int x, int y, int color, int background);
	static void DrawWhale(int x, int y, int background);
	static void DrawJellyFish(int x, int y, int background);
	static void DrawWaterSurface();
	static void DrawChooseFrame(int x, int y, int background);
	static void DeleteChooseFrame(int x, int y, int background);
	static void DeleteOnWord(int x, int y, int background);
	static void DeleteOffWord(int x, int y, int background);


	static void DrawCloud(int x, int y, int background);
	static void DeleteCloud(int x, int y, int background);
	static void DrawSun(int x, int y, int background);
	static void DrawGroupTitle(int x, int y, int background);
	static void DrawPlaneWithThankBanner(int x, int y, int background);
	static void DeletePlaneWithThankBanner(int x, int y, int background);


	static void DrawMainDisappear1(int x, int y, int background);
	static void DrawMainDisappear2(int x, int y, int background);
	static void DrawMainDisappear3(int x, int y, int background);

	static void DrawNameSign(int x, int y, int background);
	static void DrawMushroomHouse(int x, int y, int backgroundTop, int backgroundBot);
	static void DrawMound(int x, int y, int background);
	static void DrawTurtleRight(int x, int y, int background);
	static void DrawTurtleRightAnimation1(int x, int y, int background);
	static void DrawTurtleRightAnimation2(int x, int y, int background);
	static void DeleteTurtleRight(int x, int y, int background);
	static void DrawTurtleLeft(int x, int y, int background);
	static void DrawTurtleLeftAnimation1(int x, int y, int background);
	static void DrawTurtleLeftAnimation2(int x, int y, int background);
	static void DeleteTurtleLeft(int x, int y, int background);
	static void DrawPortal(int x, int y, int background);

	static void DrawLeafBlock(int x, int y);
	static void DrawWaterBlock(int x, int y);
	static void DrawWaterLine(int x, int y);

	static void DrawGrassBlock(int x, int y);
	static void DrawGrassLine(int x, int y, int length);
	static void DrawGameFrame();
	static void DrawTrafficLightBlock(int x, int y, bool status);
	static void DrawGameLoaderRoad(int background);

	static void DrawPlayGameIcon(int x, int y, int background);
	static void DrawLoadGameIcon(int x, int y, int background);
	static void DrawSettingsIcon(int x, int y, int background);
	static void DrawTutorialIcon(int x, int y, int bacground);
	static void DrawCreditsIcon(int x, int y, int background);
	static void DrawExitIcon(int x, int y, int background);
	static void DeleteIcon(int x, int y, int background);

	static void DrawDoYouWantToPlayAgain(int x, int y, int background);
	static void DrawGameOverDialog();
	static void DrawSelectBoxForDialog(int x, int y, int color, int background);
	static void DrawY(int x, int y, int color, int background);
	static void DrawN(int x, int y, int color, int background);
	static void DrawBox(int x, int y, int length, int height, int colorOutside, int colorBox);
	static void DrawEscDialog(int x, int y);

	static void DrawCongratsDialog();
	static void DrawCongratsFrog(int x, int y, int background);
	static void DrawWordCongrats(int x, int y, int background);
	static void DrawSaveFileDialog(int x, int y);
	static void DrawFullFileContainerNotification(int x, int y);
	static void DrawFileDeletionNotification(int x, int y, const string& fileName);


	static void DrawGameOverFrog(int x, int y, int background);
	static void DrawWordGameOver(int x, int y, int color, int background);



	static void DrawSquare(int x, int y, int xSize, int ySize, int color);
	static void DrawParallelogramBoxWithHorizontalAndDiagonal(int x, int y, int outlineColor, int color, int background);
	static void DrawGoal(int xLeft, int xRight, int yUp, int yDown, int xSize, int ySize);
	static void DrawLeaderBoardFigure(int x, int y, int backgroundTop, int backgroundBot);
	static void ShowLeaderBoard();
	static void DrawBigStar(int x, int y, int background);
	static void DrawSmallStar(int x, int y, int background);

	static void DrawBigMain(int x, int y, int background);
	static void DrawBigMainDie(int x, int y, int background);
	static void ShowBigMainDie();
	static void DrawInputUsernameDialog(int x, int y);

	static void Draw0(int x, int y, int color, int background);
	static void Draw1(int x, int y, int color, int background);
	static void Draw2(int x, int y, int color, int background);
	static void Draw3(int x, int y, int color, int background);
	static void Draw4(int x, int y, int color, int background);
	static void Draw5(int x, int y, int color, int background);
	static void Draw6(int x, int y, int color, int background);
	static void Draw7(int x, int y, int color, int background);
	static void Draw8(int x, int y, int color, int background);
	static void Draw9(int x, int y, int color, int background);
	static void DrawNumber(int x, int y, int color, int background, int number);
	static void DrawMiniGameWelcome();
	static void DrawWordMiniGame(int x,int y,int color,int background);

	static void DrawGameOverDecoration(int x, int y, int background);
};

