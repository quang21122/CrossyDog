#pragma once
#include <iostream>
#include <Windows.h>
#include <mutex>
#include <thread>
#include <time.h>
#include <conio.h>
#include "CPEOPLE.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CCAR.h"
#include "CTRUCK.h"
#include "CMOTORBIKE.h"
#include "CDINOSAUR.h"
#include "CBIRD.h"
#include "CTRAFFICLIGHT.h"
#include "Graphic.h"
#include "BufferGraphic.h"
#include "Utility.h"
#include "Coin.h"
#include "Timer.h"

using namespace std;

class MiniGame
{
	int defaultStartSeconds = 50;
	int defaultStartMinutes = 0;
	int remainingMinutes = 0, remainingSeconds = 0;
	int sleepAmount;
	char key;
	int score;
	int level;
	int coinRecv;
	vector<Coin> coinList;
	//Clock remain;
	vector<int> roadYCoordinate;
	vector<int> grassYCoordinate;
	vector<bool> visited;
	vector<bool> visitedCoin;
	vector<CTRAFFICLIGHT> lightArr;
	vector<CCAR> carArr;
	vector<CTRUCK> truckArr;
	vector<CMOTORBIKE> motorbikeArr;
	vector<CDINOSAUR> dinoArr;
	vector<CBIRD> birdArr;
	CPEOPLE mainCharacter;
	Utility utility;

	bool CheckOverlapCoinPosition(const Coin&);
	void GenerateCoinList();

	void ShowMiniGameScene();
	void ShowMainCharacter();
	void ShowTimeRemain();
	void ShowCoins();
	void ShowCars();
	void ShowTrucks();
	void ShowMotorbikes();
	void ShowDinosaurs();
	void ShowTrafficLights();
	void ShowScore();
	void ShowGameTutorial();
	void ShowMiniGame();

	void ExitMiniGame(thread*);
	void StartMiniGame();
	void SubThreadForMiniGame();
	void PauseGame(HANDLE);
	void ResumeGame(HANDLE);

	void ResetMiniGame();

	void ReadRoadYCoord(ifstream&);
	void ReadRoadState(ifstream&);
	void ReadGrassYCoord(ifstream&);
	void ReadTrafficLight(ifstream&);
	void ReadMainCharacterCoord(ifstream&);
	void ReadCars(ifstream&);
	void ReadMotorbikes(ifstream&);
	void ReadTrucks(ifstream&);
	void ReadDino(ifstream&);
	void ReadBird(ifstream&);
	void ReadSleepAmount(ifstream&);
	void ReadScore(ifstream&);
	void ReadLevel(ifstream&);

	void ReadLevelFile(const char*);

	void IncreaseScore();
	void ProcessImpact();
	bool CheckCrossingRoad();
	void ChangeTrafficLightsStatus();
	bool InRoad();
	bool CoinInRoad(const Coin&);
	bool CheckInRedLight(const CVEHICLE&);
	void SubThreadForTrafficLights();

	void UpdatePosAnimal();
	void UpdatePosPeople(char);
	void UpdatePosVehicle();
	void UpdateCoinStatus();
	void UpdateCoinList();
	void UpdateTime();
	void SubThreadForTimer();

	bool CheckEndMiniGame();
public:
	MiniGame(int);
	~MiniGame();
	bool PlayMiniGame();
};

