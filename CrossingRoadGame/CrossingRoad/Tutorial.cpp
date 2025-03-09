#include "Tutorial.h"

mutex mtx;
bool TUTOR_IS_RUNNING;
WORD pColorTutor[SCREEN_WIDTH * SCREEN_HEIGHT];
wchar_t pBufferTutor[SCREEN_WIDTH * SCREEN_HEIGHT];


void Tutorial::ShowTutor() {
    BufferGraphic::DrawBackgroundScreen(pBufferTutor, pColorTutor, AQUA);
    BufferGraphic::DrawCross(BLACK, AQUA, pBufferTutor, pColorTutor);
    BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
    TUTOR_IS_RUNNING = true;

    thread t1(&Tutorial::TutorWASD, this);
    thread t2(&Tutorial::TutorGoal, this);
    thread t3(&Tutorial::TutorObstacle, this);
    thread t4(&Tutorial::TutorTrafficLight, this);

    int key;
    do {
        key = _getch();
    } while (key != 27);

    ExitTutor(&t1);
    ExitTutor(&t2);
    ExitTutor(&t3);
    ExitTutor(&t4);
    system("cls");

    Console::SetColor(BLACK, AQUA);
    system("cls");
}


void Tutorial::ExitTutor(thread* t) {
    TUTOR_IS_RUNNING = false;
    t->join();
}


void Tutorial::TutorWASD() {
    mtx.lock();
    BufferGraphic::DrawString(L"USE WASD TO MOVE", 3, 1, LIGHT_YELLOW, AQUA, pBufferTutor, pColorTutor);

    COORD mainPos[] = { {10,6},{10,2},{17,6},{10,10},{3,6} };

    BufferGraphic::DrawMainCharacter(mainPos[0].X, mainPos[0].Y, AQUA, pBufferTutor, pColorTutor);
    mtx.unlock();

    int status = 0, chose = 0;
    int nOptions = 4;
    int optionColors[] = { BLACK, BLACK, BLACK, BLACK };

    while (TUTOR_IS_RUNNING) {
        if (chose > nOptions)
            chose = 1;
        if (status > 1)
            status = 0;

        for (int i = 0; i < nOptions; i++) {
            optionColors[i] = BLACK;
        }
        if (status == 1)
            optionColors[chose - 1] = RED;

        mtx.lock();
        BufferGraphic::DrawWASDArrow(optionColors, AQUA, pBufferTutor, pColorTutor);

        if (status == 1) {
            BufferGraphic::DeleteMainCharacter(mainPos[0].X, mainPos[0].Y, AQUA, pBufferTutor, pColorTutor);
            BufferGraphic::DrawMainCharacter(mainPos[chose].X, mainPos[chose].Y, AQUA, pBufferTutor, pColorTutor);
        }
        else {
            BufferGraphic::DeleteMainCharacter(mainPos[chose].X, mainPos[chose].Y, AQUA, pBufferTutor, pColorTutor);
            BufferGraphic::DrawMainCharacter(mainPos[0].X, mainPos[0].Y, AQUA, pBufferTutor, pColorTutor);
        }
        mtx.unlock();

        status++;
        if (status == 1)
            chose++;

        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        Sleep(500);
    }
}

void Tutorial::TutorGoal() {
    mtx.lock();
    BufferGraphic::DrawString(L"REACH THE GOAL TO WIN", 65, 1, LIGHT_YELLOW, AQUA, pBufferTutor, pColorTutor);
    BufferGraphic::DrawGoal(65, 116, 2, 5, 2, 1, pBufferTutor, pColorTutor);
    mtx.unlock();

    int i = 0;
    int background = AQUA;
    int colorArrow[] = { BLUE,BLACK,BLACK };
    while (TUTOR_IS_RUNNING) {
        if (i > 2)
            i = 0;

        if (i == 2)
            background = BRIGHT_WHITE;
        else background = AQUA;

        for (int j = 0; j < 3; j++) {
            colorArrow[j] = BLACK;
        }
        colorArrow[i] = RED;

        mtx.lock();
        BufferGraphic::DrawMainCharacter(75, 10 - (i * 4), background, pBufferTutor, pColorTutor);
        if (i == 2) {
            BufferGraphic::DrawString(L"▀▀", 75 + 2, 10 - (i * 4) + 4, BLACK, AQUA, pBufferTutor, pColorTutor);
            BufferGraphic::DrawString(L"▀▀", 75 + 7, 10 - (i * 4) + 4, BLACK, AQUA, pBufferTutor, pColorTutor);
        }
        background = AQUA;
        BufferGraphic::DrawUpArrow(97, 6, colorArrow[0], colorArrow[1], colorArrow[2], background, pBufferTutor, pColorTutor);
        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        mtx.unlock();
        Sleep(500);

        mtx.lock();
        BufferGraphic::DeleteMainCharacter(75, 10 - (i * 4), background, pBufferTutor, pColorTutor);
        if (i == 2)
            BufferGraphic::DrawGoal(65, 116, 2, 5, 2, 1,pBufferTutor,pColorTutor);
        mtx.unlock();
        i++;
    }
}

void Tutorial::TutorObstacle() {
    mtx.lock();
    BufferGraphic::DrawString(L"TRY TO DODGE OBSTACLES", 3, 17, LIGHT_YELLOW, AQUA, pBufferTutor, pColorTutor);
    mtx.unlock();

    while (TUTOR_IS_RUNNING) {
        mtx.lock();
        BufferGraphic::DrawRoad(5, 55, 19, pBufferTutor, pColorTutor);
        BufferGraphic::DrawMainCharacter(8, 25, AQUA, pBufferTutor, pColorTutor);
        BufferGraphic::DrawCarLeftFacing(45, 19, AQUA, pBufferTutor, pColorTutor);
        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        mtx.unlock();
        CarCrashAnimation(45, 18, 19);
    }
}

void Tutorial::MainDisappearAnimation(int x, int y, int background) {
    mtx.lock();
    BufferGraphic::DeleteMainCharacter(x, y, background, pBufferTutor,pColorTutor);
    BufferGraphic::DrawMainDisappear1(x, y, background, pBufferTutor, pColorTutor);
    BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
    mtx.unlock();

    Sleep(40);

    mtx.lock();
    BufferGraphic::DrawMainDisappear2(x, y, background, pBufferTutor, pColorTutor);
    BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
    mtx.unlock();

    Sleep(40);
    mtx.lock();
    BufferGraphic::DeleteMainCharacter(x, y, background, pBufferTutor, pColorTutor);
    BufferGraphic::DrawMainDisappear3(x, y, background, pBufferTutor, pColorTutor);
    BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
    mtx.unlock();
}

void Tutorial::CarCrashAnimation(int xStart, int xEnd, int y) {
    int background = GRAY;
    int step = 0;

    for (int i = 0; i < abs(xEnd - xStart) + 1; i++) {
        mtx.lock();
        if (xStart - i == 20) {
            BufferGraphic::DeleteMainCharacter(8, 25, AQUA, pBufferTutor, pColorTutor);
            BufferGraphic::DrawMainCharacter(8, 19, background, pBufferTutor, pColorTutor);
            step++;
        }

        BufferGraphic::DrawCarLeftFacing(xStart - i, y,background,pBufferTutor,pColorTutor);
        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        mtx.unlock();
        Sleep(25);

        if (xStart - i == xEnd) {
            break;
        }

        mtx.lock();
        BufferGraphic::DrawRoad(5, 55, 19, pBufferTutor, pColorTutor);

        if (step == 1)
        BufferGraphic::DrawMainCharacter(8, 19, background, pBufferTutor, pColorTutor);
        mtx.unlock();
    }
    MainDisappearAnimation(8, 19, GRAY);
    Sleep(500);
}

void Tutorial::TutorTrafficLight() {
    mtx.lock();
    BufferGraphic::DrawString(L"GREEN LIGHT, RED LIGHT!", 65, 17, LIGHT_YELLOW, AQUA, pBufferTutor, pColorTutor);
    mtx.unlock();

    while (TUTOR_IS_RUNNING) {
        mtx.lock();
        BufferGraphic::DrawGreenTrafficLight(102, 19, AQUA, pBufferTutor, pColorTutor);
        BufferGraphic::DrawRoad(66, 116, 23, pBufferTutor, pColorTutor);
        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        mtx.unlock();
        CarStopAtTrafficLightAnimation(67, 106, 23);
    }
}

void Tutorial::CarStopAtTrafficLightAnimation(int xStart, int xEnd, int y) {
    int background = GRAY;
    int step = 0;

    for (int i = 0; i < abs(xEnd - xStart) + 1; i++) {
        mtx.lock();
        BufferGraphic::DrawCarRightFacing(xStart + i, y, background, pBufferTutor, pColorTutor);
        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        mtx.unlock();

        if (xStart + i == 92) {
            mtx.lock();
            BufferGraphic::DrawRedTrafficLight(102, 19, AQUA, pBufferTutor, pColorTutor);
            BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
            mtx.unlock();

            Sleep(1000);

            mtx.lock();
            BufferGraphic::DrawGreenTrafficLight(102, 19, AQUA, pBufferTutor, pColorTutor);
            BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
            mtx.unlock();
        }

        Sleep(25);

        if (xStart + i == xEnd) {
            break;
        }

        mtx.lock();
        BufferGraphic::DrawRoad(66, 116, 23, pBufferTutor, pColorTutor);
        BufferGraphic::PushPixelOnScreen(pBufferTutor, pColorTutor);
        mtx.unlock();
    }
    Sleep(500);
}