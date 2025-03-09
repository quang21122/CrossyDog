#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include <fstream>
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
#include "MiniGame.h"
#include <vector>
#include <mutex>
#include <thread>
#include <time.h>

using namespace std;


class CGAME {
	int sleepAmount;
	int score;
	char key;
	int level;
	vector<int> roadYCoordinate;
	vector<int> grassYCoordinate;
	vector<bool>visited;
	vector<CTRAFFICLIGHT> lightArr;
	vector<CTRUCK> truckArr;
	vector<CCAR> carArr;
	vector<CMOTORBIKE> motorbikeArr;
	vector<CDINOSAUR> dinoArr;
	vector<CBIRD> birdArr;
	CPEOPLE mainCharacter;
	Utility utility;
	
	void ShowGameScene();

	void SaveGameState(ofstream&);

	void SaveRoadYCoord(ofstream&);
	void SaveRoadState(ofstream&);
	void SaveGrassYCoord(ofstream&);
	void SaveTrafficLight(ofstream&);
	void SaveMainCharacterCoord(ofstream&);
	void SaveCars(ofstream&);
	void SaveMotorbikes(ofstream&);
	void SaveTrucks(ofstream&);
	void SaveDino(ofstream&);
	void SaveBird(ofstream&);
	void SaveSleepAmount(ofstream&);
	void SaveScore(ofstream&);
	void SaveLevel(ofstream&);

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

	void ShowMainCharacter();
	void ShowCars();
	void ShowTrucks();
	void ShowMotorbikes();
	void ShowDinosaurs();
	void ShowBirds();
	void ShowTrafficLights();
	void ShowScore();
	void ShowLevel();
	void ShowGameTutorial();
	void ShowGame();

	void ResetGame();
	void ExitGame(thread*);

	void StartGame(const char* saveFileName);
	void StartGame();

	void LoadGame(ifstream& fi);
	void SaveGame(const string&);
	string UpdateFileList(const string&);

	void PauseGame(HANDLE);
	void ResumeGame(HANDLE);
	void ProcessImpact();
	bool CheckCrossingRoad();
	void IncreaseScore();
	void ChangeTrafficLightsStatus();
	void UpdatePosPeople(char);
	void UpdatePosVehicle();
	bool InRoad();
	bool CheckInRedLight(const CVEHICLE&);
	void UpdatePosAnimal();
	void SubThreadForGame();
	void SubThreadForTrafficLights();

public:
	CGAME();	
	~CGAME();
	void PlayGame(const string&);
};

