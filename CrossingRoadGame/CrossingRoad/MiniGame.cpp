#include "MiniGame.h"

static WORD pColor[SCREEN_WIDTH * SCREEN_HEIGHT];
static wchar_t pBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

static const int step = 1;
static const int maxLevel = 3;
static char MOVING = ' ';
static mutex key_locker;
static bool IS_RUNNING = true;
static bool IS_COMPLETE = false;



bool MiniGame::CheckOverlapCoinPosition(const Coin& coin) {
	for (auto& temp : coinList) {
		if (abs(temp.GetX() - coin.GetX()) < 8 && coin.GetY() == temp.GetY()) {
			return true;
		}
	}
	return false;
}

void MiniGame::GenerateCoinList() {
	while (coinList.size() < 5) {
		Coin coin;
		if (!CheckOverlapCoinPosition(coin)  && (coin.GetX() != mainCharacter.GetX() && coin.GetY() != mainCharacter.GetY() + 1))
			coinList.push_back(coin);
	}
}

void MiniGame::ShowMiniGameScene() {
	BufferGraphic::DrawBackgroundScreen(pBuffer, pColor, WHITE);
	BufferGraphic::DrawGameFrame(pBuffer, pColor);
	for (int i = 0; i < roadYCoordinate.size(); i++)
		BufferGraphic::DrawRoad(10, 100, roadYCoordinate[i], pBuffer, pColor);
	for (int i = 0; i < grassYCoordinate.size(); i++)
		BufferGraphic::DrawGrass(10, 100, grassYCoordinate[i], pBuffer, pColor);
	for (int i = 0; i < lightArr.size(); i++) {
		if (lightArr[i].GetStatus())
			BufferGraphic::DrawGreenTrafficLight(lightArr[i].GetX(), lightArr[i].GetY(), WHITE, pBuffer, pColor);
		else
			BufferGraphic::DrawRedTrafficLight(lightArr[i].GetX(), lightArr[i].GetY(), WHITE, pBuffer, pColor);
	}
	if (level == maxLevel - 1 || level == maxLevel)
		BufferGraphic::DrawGoal(10, 99, 0, 4, 2, 1, pBuffer, pColor);
}

void MiniGame::ShowMainCharacter() {
	int color;
	if (InRoad())
		color = GRAY;
	else if (level == maxLevel - 1 && mainCharacter.GetY() == 0)
		color = BRIGHT_WHITE;
	else
		color = LIGHT_GREEN;
	BufferGraphic::DrawMainCharacter(mainCharacter.GetX(), mainCharacter.GetY(), color, pBuffer, pColor);
}

void MiniGame::ShowTimeRemain() {
	BufferGraphic::DrawTimeRemainingTitle(102, 3, BLACK, WHITE, pBuffer, pColor);
	BufferGraphic::DrawNumber(110, 5, BLACK, WHITE, pBuffer, pColor, remainingSeconds);
}

void MiniGame::ShowCoins() {
	for (auto& c : coinList) {
		int X = c.GetX();
		int Y = c.GetY();
		int color;
		if (CoinInRoad(c))
			color = GRAY;
		else
			color = LIGHT_GREEN;
		if (c.GetStatus())
			BufferGraphic::DrawCoinFront(X, Y, color, pBuffer, pColor);
		else
			BufferGraphic::DrawCoinSide(X, Y, color, pBuffer, pColor);
	}
}

void MiniGame::ShowCars() {
	for (const auto& car : carArr)
		BufferGraphic::DrawCarLeftFacing(car.GetX(), car.GetY(), GRAY, pBuffer, pColor);
}

void MiniGame::ShowTrucks()
{
	for (const auto& truck : truckArr)
		BufferGraphic::DrawTruckLeftFacing(truck.GetX(), truck.GetY(), GRAY, pBuffer, pColor);
}

void MiniGame::ShowMotorbikes() {
	for (const auto& motorbike : motorbikeArr)
		BufferGraphic::DrawCatWithMotorbike(motorbike.GetX(), motorbike.GetY(), GRAY, pBuffer, pColor);
}

void MiniGame::ShowDinosaurs() {
	for (const auto& dino : dinoArr)
		BufferGraphic::DrawDinosaur(dino.GetX(), dino.GetY(), GRAY, pBuffer, pColor);
}

void MiniGame::ShowTrafficLights() {
	for (const auto& l : lightArr) {
		if (l.GetStatus())
			BufferGraphic::DrawGreenTrafficLight(l.GetX(), l.GetY(), WHITE, pBuffer, pColor);
		else BufferGraphic::DrawRedTrafficLight(l.GetX(), l.GetY(), WHITE, pBuffer, pColor);
	}
}

void MiniGame::ShowScore() {
	BufferGraphic::DrawScoreTitle(102, 8, BLACK, WHITE, pBuffer, pColor);
	BufferGraphic::DrawNumber(110, 10, BLACK, WHITE, pBuffer, pColor, score);
}

void MiniGame::ShowGameTutorial() {
	BufferGraphic::DrawGameTutorial(105, 19, AQUA, WHITE, pBuffer, pColor);
}

void MiniGame::ShowMiniGame() {
	//Show scene
	ShowMiniGameScene();
	//Show mini game's objects
	ShowCoins();
	ShowMainCharacter();
	ShowTrafficLights();
	ShowCars();
	ShowTrucks();
	ShowMotorbikes();
	ShowDinosaurs();
	//Show Info
	ShowTimeRemain();
	ShowScore();
	ShowGameTutorial();
	BufferGraphic::PushPixelOnScreen(pBuffer, pColor);
}

void MiniGame::ExitMiniGame(thread* thr) {
	system("cls");
	ResumeThread(thr->native_handle());
	IS_RUNNING = false;
	thr->join();
}


void MiniGame::SubThreadForMiniGame() {
	while (IS_RUNNING) {
		if (!mainCharacter.IsDead() && !IS_COMPLETE) {

			key_locker.lock();
			UpdatePosPeople(MOVING);
			MOVING = ' ';
			key_locker.unlock();

			UpdateCoinList();
			UpdatePosVehicle();
			UpdatePosAnimal();
			UpdateCoinStatus();

			if (level < maxLevel)
				ShowMiniGame();

			Sleep(sleepAmount);

			if (level == maxLevel) {
				level--;
				ShowMiniGame();
				PlaySound(TEXT("Sound/reachGoalSound.wav"), NULL, SND_ASYNC);
				Sleep(2000);
				IS_COMPLETE = true;
			}

			ProcessImpact();

			//if (CheckCrossingRoad())
				//IncreaseScore();

			if (CheckEndMiniGame() && level < maxLevel) {
				level++;
				if (level < maxLevel)
					StartMiniGame();
			}
		}
	}
}

void MiniGame::PauseGame(HANDLE threadHandle) {
	SuspendThread(threadHandle);
}

void MiniGame::ResumeGame(HANDLE threadHandle) {
	ResumeThread(threadHandle);
}

void MiniGame::ResetMiniGame()
{
	IS_RUNNING = true;
	IS_COMPLETE = false;
	mainCharacter.Reset();
	roadYCoordinate.resize(0);
	grassYCoordinate.resize(0);
	visited.resize(0);
	visitedCoin.resize(0);
	lightArr.resize(0);
	truckArr.resize(0);
	carArr.resize(0);
	motorbikeArr.resize(0);
	dinoArr.resize(0);
	coinList.resize(0);
}

void MiniGame::ReadRoadYCoord(ifstream& fi)
{
	int numRoads;

	fi.read((char*)&numRoads, sizeof(int));
	roadYCoordinate.resize(numRoads);

	for (int i = 0; i < numRoads; i++)
		fi.read((char*)&roadYCoordinate[i], sizeof(int));
}

void MiniGame::ReadRoadState(ifstream& fi)
{
	bool isVisited;

	for (int i = 0; i < roadYCoordinate.size(); i++) {
		fi.read((char*)&isVisited, sizeof(bool));
		visited.push_back(isVisited);
	}
}

void MiniGame::ReadGrassYCoord(ifstream& fi)
{
	int numGrasses;

	fi.read((char*)&numGrasses, sizeof(int));
	grassYCoordinate.resize(numGrasses);
	for (int i = 0; i < numGrasses; i++)
		fi.read((char*)&grassYCoordinate[i], sizeof(int));
}

void MiniGame::ReadTrafficLight(ifstream& fi)
{
	int numLights, lightX = 2, lightY;
	bool lightStatus;

	fi.read((char*)&numLights, sizeof(int));
	for (int i = 0; i < numLights; i++) {
		fi.read((char*)&lightY, sizeof(int));
		fi.read((char*)&lightStatus, sizeof(bool));
		lightArr.push_back(CTRAFFICLIGHT(lightX, lightY, lightStatus));
	}
}

void MiniGame::ReadMainCharacterCoord(ifstream& fi)
{
	int mainX, mainY;

	fi.read((char*)&mainX, sizeof(int));
	fi.read((char*)&mainY, sizeof(int));
	mainCharacter.SetX(mainX);
	mainCharacter.SetY(mainY);
}

void MiniGame::ReadCars(ifstream& fi)
{
	int numCars;

	fi.read((char*)&numCars, sizeof(int));
	for (int i = 0; i < numCars; i++) {
		int carX, carY;
		fi.read((char*)&carX, sizeof(int));
		fi.read((char*)&carY, sizeof(int));
		carArr.push_back(CCAR(carX, carY));
	}
}

void MiniGame::ReadMotorbikes(ifstream& fi)
{
	int numMotorbikes;

	fi.read((char*)&numMotorbikes, sizeof(int));
	for (int i = 0; i < numMotorbikes; i++) {
		int motorbikeX, motorbikeY;
		fi.read((char*)&motorbikeX, sizeof(int));
		fi.read((char*)&motorbikeY, sizeof(int));
		motorbikeArr.push_back(CMOTORBIKE(motorbikeX, motorbikeY));
	}
}

void MiniGame::ReadTrucks(ifstream& fi)
{
	int numTrucks;

	fi.read((char*)&numTrucks, sizeof(int));
	for (int i = 0; i < numTrucks; i++) {
		int truckX, truckY;
		fi.read((char*)&truckX, sizeof(int));
		fi.read((char*)&truckY, sizeof(int));
		truckArr.push_back(CTRUCK(truckX, truckY));
	}
}

void MiniGame::ReadDino(ifstream& fi)
{
	int numDino;

	fi.read((char*)&numDino, sizeof(int));
	for (int i = 0; i < numDino; i++) {
		int dinoX, dinoY;
		fi.read((char*)&dinoX, sizeof(int));
		fi.read((char*)&dinoY, sizeof(int));
		dinoArr.push_back(CDINOSAUR(dinoX, dinoY));
	}
}

void MiniGame::ReadBird(ifstream& fi)
{
	int numBirds;

	fi.read((char*)&numBirds, sizeof(int));
}

void MiniGame::ReadSleepAmount(ifstream& fi)
{
	fi.read((char*)&sleepAmount, sizeof(int));
}

void MiniGame::ReadScore(ifstream& fi)
{
	fi.read((char*)&score, sizeof(int));
}

void MiniGame::ReadLevel(ifstream& fi)
{
	fi.read((char*)&level, sizeof(int));
}

void MiniGame::ReadLevelFile(const char* path)
{
	bool isVisited;
	int numGrasses, grassY;
	int numLights, lightY;
	bool lightStatus;
	int mainX, mainY;
	int numCars, numTrucks, numDino, numBirds;
	ifstream fi;
	fi.open(path, ios::binary | ios::in);

	ReadRoadYCoord(fi);
	ReadRoadState(fi);
	ReadGrassYCoord(fi);
	ReadTrafficLight(fi);
	ReadMainCharacterCoord(fi);
	ReadCars(fi);
	ReadTrucks(fi);
	ReadMotorbikes(fi);
	ReadDino(fi);
	//ReadBird(fi);
	ReadSleepAmount(fi);
	//ReadScore(fi);
	ReadLevel(fi);

	fi.close();
}

void MiniGame::StartMiniGame() {
	ResetMiniGame();
	ReadLevelFile((const char*)utility.GenerateMiniGameFileName(level).c_str());
	GenerateCoinList();
}

void MiniGame::IncreaseScore() {
	PlaySound(TEXT("Sound/increasePointSound.wav"), NULL, SND_ASYNC);
	coinRecv++;
	if (coinRecv==10) {
		score += (10 + remainingSeconds * 10);
	}
	else {
		score += 10;
	}
}

void MiniGame::ProcessImpact() {
	for (const auto& car : carArr)
		if (mainCharacter.IsImpact(car))
			mainCharacter.Die();

	for (const auto& truck : truckArr)
		if (mainCharacter.IsImpact(truck))
			mainCharacter.Die();

	for (const auto& motorbike : motorbikeArr)
		if (mainCharacter.IsImpact(motorbike))
			mainCharacter.Die();

	for (const auto& dino : dinoArr)
		if (mainCharacter.IsImpact(dino))
			mainCharacter.Die();
}

bool MiniGame::CheckCrossingRoad() {
	for (int i = 0; i < visited.size(); i++) {
		if (mainCharacter.GetY() < roadYCoordinate[i] && !visited[i]) {
			visited[i] = true;
			return true;
		}
	}
	return false;
}

void MiniGame::ChangeTrafficLightsStatus() {
	for (auto& light : lightArr)
		light.ChangeStatus();
}

bool MiniGame::InRoad() {
	for (auto roadY : roadYCoordinate)
		if (mainCharacter.GetY() == roadY)
			return true;
	return false;
}

bool MiniGame::CoinInRoad(const Coin& c)
{
	for (auto roadY : roadYCoordinate)
		if (c.GetY() - 1 == roadY)
			return true;
	return false;
}

bool MiniGame::CheckInRedLight(const CVEHICLE& v) {
	for (int i = 0; i < lightArr.size(); i++)
		if (v.GetY() == lightArr[i].GetY() && !lightArr[i].GetStatus())
			return true;
	return false;
}

void MiniGame::SubThreadForTrafficLights() {
	while (IS_RUNNING) {
		Sleep(2500);
		ChangeTrafficLightsStatus();
	}
}

void MiniGame::UpdatePosAnimal() {
	for (auto& dino : dinoArr)
		dino.Move(dino.GetX() + step, dino.GetY());
}

void MiniGame::UpdatePosPeople(char move) {
	switch (move) {
	case 'A':
		mainCharacter.Left();
		break;
	case 'W':
		mainCharacter.Up();
		break;
	case 'S':
		mainCharacter.Down();
		break;
	case 'D':
		mainCharacter.Right();
		break;
	}
}

void MiniGame::UpdatePosVehicle() {
	for (auto& car : carArr) {
		if (!CheckInRedLight(car))
			car.Move(car.GetX() - step, car.GetY());
	}

	for (auto& truck : truckArr) {
		if (!CheckInRedLight(truck))
			truck.Move(truck.GetX() - step, truck.GetY());
	}

	for (auto& motorbike : motorbikeArr) {
		if (!CheckInRedLight(motorbike))
			motorbike.Move(motorbike.GetX() - step, motorbike.GetY());
	}
}

void MiniGame::UpdateCoinStatus()
{
	for (auto& coin : coinList) {
		coin.SetStatus(!coin.GetStatus());
	}
}


void MiniGame::UpdateCoinList() {
	for (int i = 0; i < coinList.size(); i++) {
		if (mainCharacter.CollectCoin(coinList[i])) {
			coinList.erase(coinList.begin() + i);
			IncreaseScore();
		}
	}
}

void MiniGame::UpdateTime() {

}

void MiniGame::SubThreadForTimer() {
	Timer timer(remainingMinutes, remainingSeconds);

	while (!timer.HasExpired() && IS_RUNNING) {
		timer.GetRemainingTime(remainingMinutes, remainingSeconds);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

bool MiniGame::CheckEndMiniGame() {
	return ((coinList.size() == 0 && mainCharacter.IsFinish()) || mainCharacter.IsFinish());
}

MiniGame::MiniGame(int score) {
	this->score = score;
	level = 1;
	key = ' ';
	sleepAmount = 0;
	coinRecv = 0;
	remainingMinutes = defaultStartMinutes, remainingSeconds = defaultStartSeconds;
}

MiniGame::~MiniGame() {

}

bool MiniGame::PlayMiniGame() {
	system("cls");
	system("color 80");

	StartMiniGame();

	thread screenThread(&MiniGame::SubThreadForMiniGame, this);
	thread lightsThread(&MiniGame::SubThreadForTrafficLights, this);
	thread timerThread(&MiniGame::SubThreadForTimer, this);
	while (1) {
		if (_kbhit())
			key = toupper(_getch());
		if (remainingSeconds == 0 && remainingMinutes == 0)
			IS_COMPLETE = true;
		if (!mainCharacter.IsDead() && !IS_COMPLETE) {
			if (key != ' ') {
				key_locker.lock();
				MOVING = key;
				key_locker.unlock();
			}
			
			if (key == 27) {
				PauseGame(screenThread.native_handle());
				PauseGame(lightsThread.native_handle());
				PauseGame(timerThread.native_handle());
				if (utility.ShowExitDialog()) {
					ExitMiniGame(&screenThread);
					ExitMiniGame(&lightsThread);
					ExitMiniGame(&timerThread);
					key = ' ';
					return false;
				}
				ResumeGame(screenThread.native_handle());
				ResumeGame(lightsThread.native_handle());
				ResumeGame(timerThread.native_handle());
			}

			else if (key == 'P') {
				PauseGame(screenThread.native_handle());
				PauseGame(lightsThread.native_handle());
				PauseGame(timerThread.native_handle());
			}
			else if (key == 'R') {
				ResumeGame(screenThread.native_handle());
				ResumeGame(lightsThread.native_handle());
				ResumeGame(timerThread.native_handle());
			}
			
			key = ' ';
		}
		else if (!IS_COMPLETE) {
			//IS_RUNNING = false;
			bool choice = utility.ShowGameOverDialog(score);
			ExitMiniGame(&screenThread);
			ExitMiniGame(&lightsThread);
			ExitMiniGame(&timerThread);
			return choice;
		}		
		else {
			ExitMiniGame(&screenThread);
			ExitMiniGame(&lightsThread);
			ExitMiniGame(&timerThread);
			return utility.ShowCongratsDialog(score);
		}
	}
}