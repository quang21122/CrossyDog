#pragma once
#include <conio.h>
#include "Graphic.h"
#include "Console.h" 
#include <thread>
#include<mutex>
#include"BufferGraphic.h"

using namespace std;

class Tutorial
{
private:

	void TutorWASD();
	void TutorGoal();
	void TutorObstacle();
	void TutorTrafficLight();
	void CarCrashAnimation(int xStart, int xEnd, int y);
	void MainDisappearAnimation(int x, int y, int background);
	void CarStopAtTrafficLightAnimation(int xStart, int xEnd, int y);
	void ExitTutor(thread* t);

public:

	void ShowTutor();

};