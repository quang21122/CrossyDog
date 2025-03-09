#include "CGAME.h"

WORD pColor[SCREEN_WIDTH * SCREEN_HEIGHT];
wchar_t pBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

const int step = 1;
const int maxLevel = 9;
char MOVING = ' ';
mutex key_locker;
bool IS_RUNNING = true;
bool IS_COMPLETE = false;


void CGAME::SaveGameState(ofstream& fo) {
	SaveRoadYCoord(fo);
	SaveRoadState(fo);
	SaveGrassYCoord(fo);
	SaveTrafficLight(fo);
	SaveMainCharacterCoord(fo);
	SaveCars(fo);
	SaveTrucks(fo);
	SaveMotorbikes(fo);
	SaveDino(fo);
	SaveBird(fo);
	SaveSleepAmount(fo);
	SaveScore(fo);
	SaveLevel(fo);
}

void CGAME::SaveRoadYCoord(ofstream& fo) {
	int numRoads = roadYCoordinate.size();
	fo.write((char*)&numRoads, sizeof(int));
	for (int i = 0; i < numRoads; i++) {
		fo.write((char*)&roadYCoordinate[i], sizeof(int));
	}
}
void CGAME::SaveRoadState(ofstream& fo) {
	for (int i = 0; i < visited.size(); i++) {
		bool state = visited[i];
		fo.write((char*)&state, sizeof(bool));
	}
}
void CGAME::SaveGrassYCoord(ofstream& fo) {
	int numGrass = grassYCoordinate.size();
	fo.write((char*)&numGrass, sizeof(int));
	for (int i = 0; i < numGrass; i++) {
		fo.write((char*)&grassYCoordinate[i], sizeof(int));
	}
}
void CGAME::SaveTrafficLight(ofstream& fo) {
	int lightY;
	bool lightStatus;
	int numLights = lightArr.size();
	fo.write((char*)&numLights, sizeof(int));
	for (auto& light : lightArr) {
		lightY = light.GetY();
		lightStatus = light.GetStatus();
		fo.write((char*)&lightY, sizeof(int));
		fo.write((char*)&lightStatus, sizeof(bool));		
	}
}
void CGAME::SaveMainCharacterCoord(ofstream& fo) {
	int mainX = mainCharacter.GetX(), mainY = mainCharacter.GetY();

	fo.write((char*)&mainX, sizeof(int));
	fo.write((char*)&mainY, sizeof(int));
}
void CGAME::SaveCars(ofstream& fo) {
	int carX, carY;
	int numCars = carArr.size();
	fo.write((char*)&numCars, sizeof(int));
	for (auto& car : carArr) {
		carX = car.GetX();
		carY = car.GetY();
		fo.write((char*)&carX, sizeof(int));
		fo.write((char*)&carY, sizeof(int));
	}
}
void CGAME::SaveMotorbikes(ofstream& fo) {
	int motorbikeX, motorbikeY;
	int numMotorbikes = motorbikeArr.size();
	fo.write((char*)&numMotorbikes, sizeof(int));
	for (auto &motorbike : motorbikeArr) {
		motorbikeX = motorbike.GetX();
		motorbikeY = motorbike.GetY();
		fo.write((char*)&motorbikeX, sizeof(int));
		fo.write((char*)&motorbikeY, sizeof(int));
	}
}
void CGAME::SaveTrucks(ofstream& fo) {
	int truckX, truckY;
	int numTrucks = truckArr.size();
	fo.write((char*)&numTrucks, sizeof(int));
	for (auto& truck : truckArr) {
		truckX = truck.GetX();
		truckY = truck.GetY();
		fo.write((char*)&truckX, sizeof(int));
		fo.write((char*)&truckY, sizeof(int));
	}
}
void CGAME::SaveDino(ofstream& fo) {
	int dinoX, dinoY;
	int numDino = dinoArr.size();
	fo.write((char*)&numDino, sizeof(int));
	for (auto& dino : dinoArr) {
		dinoX = dino.GetX();
		dinoY = dino.GetY();
		fo.write((char*)&dinoX, sizeof(int));
		fo.write((char*)&dinoY, sizeof(int));
	}
}
void CGAME::SaveBird(ofstream& fo) {
	int birdX, birdY;
	int numBirds = birdArr.size();
	fo.write((char*)&numBirds, sizeof(int));
	for (auto& bird : birdArr) {
		birdX = bird.GetX();
		birdY = bird.GetY();
		fo.write((char*)&birdX, sizeof(int));
		fo.write((char*)&birdY, sizeof(int));
	}
}
void CGAME::SaveSleepAmount(ofstream& fo) {
	fo.write((char*)&sleepAmount, sizeof(int));
}
void CGAME::SaveScore(ofstream& fo) {
	fo.write((char*)&score, sizeof(int));
}
void CGAME::SaveLevel(ofstream& fo) {
	fo.write((char*)&level, sizeof(int));
}

void CGAME::ReadRoadYCoord(ifstream& fi) {
	int numRoads;

	fi.read((char*)&numRoads, sizeof(int));
	roadYCoordinate.resize(numRoads);

	for (int i = 0; i < numRoads; i++)
		fi.read((char*)&roadYCoordinate[i], sizeof(int));
}

void CGAME::ReadRoadState(ifstream& fi) {
	bool isVisited;

	for (int i = 0; i < roadYCoordinate.size(); i++) {
		fi.read((char*)&isVisited, sizeof(bool));
		visited.push_back(isVisited);
	}
}

void CGAME::ReadGrassYCoord(ifstream& fi) {
	int numGrasses;

	fi.read((char*)&numGrasses, sizeof(int));
	grassYCoordinate.resize(numGrasses);
	for (int i = 0; i < numGrasses; i++)
		fi.read((char*)&grassYCoordinate[i], sizeof(int));
}

void CGAME::ReadTrafficLight(ifstream& fi) {
	int numLights, lightX = 2, lightY;
	bool lightStatus;
	
	fi.read((char*)&numLights, sizeof(int));
	for (int i = 0; i < numLights; i++) {
		fi.read((char*)&lightY, sizeof(int));
		fi.read((char*)&lightStatus, sizeof(bool));
		lightArr.push_back(CTRAFFICLIGHT(lightX, lightY, lightStatus));
	}
}

void CGAME::ReadMainCharacterCoord(ifstream& fi) {
	int mainX, mainY;

	fi.read((char*)&mainX, sizeof(int));
	fi.read((char*)&mainY, sizeof(int));
	mainCharacter.SetX(mainX);
	mainCharacter.SetY(mainY);
}

void CGAME::ReadCars(ifstream& fi) {
	int numCars;

	fi.read((char*)&numCars, sizeof(int));
	for (int i = 0; i < numCars; i++) {
		int carX, carY;
		fi.read((char*)&carX, sizeof(int));
		fi.read((char*)&carY, sizeof(int));
		carArr.push_back(CCAR(carX, carY));
	}
}

void CGAME::ReadMotorbikes(ifstream& fi){
	int numMotorbikes;

	fi.read((char*)&numMotorbikes, sizeof(int));
	for (int i = 0; i < numMotorbikes; i++) {
		int motorbikeX, motorbikeY;
		fi.read((char*)&motorbikeX, sizeof(int));
		fi.read((char*)&motorbikeY, sizeof(int));
		motorbikeArr.push_back(CMOTORBIKE(motorbikeX, motorbikeY));
	}
}

void CGAME::ReadTrucks(ifstream& fi) {
	int numTrucks;

	fi.read((char*)&numTrucks, sizeof(int));
	for (int i = 0; i < numTrucks; i++) {
		int truckX, truckY;
		fi.read((char*)&truckX, sizeof(int));
		fi.read((char*)&truckY, sizeof(int));
		truckArr.push_back(CTRUCK(truckX, truckY));
	}
}

void CGAME::ReadDino(ifstream& fi) {
	int numDino;

	fi.read((char*)&numDino, sizeof(int));
	for (int i = 0; i < numDino; i++) {
		int dinoX, dinoY;
		fi.read((char*)&dinoX, sizeof(int));
		fi.read((char*)&dinoY, sizeof(int));
		dinoArr.push_back(CDINOSAUR(dinoX, dinoY));
	}
}

void CGAME::ReadBird(ifstream& fi) {
	int numBirds;

	fi.read((char*)&numBirds, sizeof(int));
	for (int i = 0; i < numBirds; i++) {
		int birdX, birdY;
		fi.read((char*)&birdX, sizeof(int));
		fi.read((char*)&birdY, sizeof(int));
		birdArr.push_back(CBIRD(birdX, birdY));
	}
}

void CGAME::ReadSleepAmount(ifstream& fi) {
	fi.read((char*)&sleepAmount, sizeof(int));
}

void CGAME::ReadScore(ifstream& fi) {
	fi.read((char*)&score, sizeof(int));
}

void CGAME::ReadLevel(ifstream& fi) {
	fi.read((char*)&level, sizeof(int));
}

void CGAME::ReadLevelFile(const char* path) {
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
	ReadBird(fi);
	ReadSleepAmount(fi);
	ReadScore(fi);
	ReadLevel(fi);
	
	fi.close();
}

void CGAME::ShowMainCharacter(){
	int color;
	if (InRoad())
		color = GRAY;
	else if (level == maxLevel - 1 && mainCharacter.GetY() == 0)
		color = BRIGHT_WHITE;
	else
		color = LIGHT_GREEN;
	BufferGraphic::DrawMainCharacter(mainCharacter.GetX(), mainCharacter.GetY(), color, pBuffer, pColor);
}

void CGAME::ShowCars() {
	for (const auto& car : carArr)
		BufferGraphic::DrawCarLeftFacing(car.GetX(), car.GetY(), GRAY, pBuffer, pColor);
}

void CGAME::ShowTrucks(){
	for (const auto& truck : truckArr)
		BufferGraphic::DrawTruckLeftFacing(truck.GetX(), truck.GetY(), GRAY, pBuffer, pColor);
}

void CGAME::ShowMotorbikes(){
	for (const auto& motorbike : motorbikeArr)
		BufferGraphic::DrawCatWithMotorbike(motorbike.GetX(), motorbike.GetY(), GRAY, pBuffer, pColor);
}

void CGAME::ShowDinosaurs(){
	for (const auto& dino : dinoArr) 
		BufferGraphic::DrawDinosaur(dino.GetX(), dino.GetY(), GRAY, pBuffer, pColor);
}

void CGAME::ShowBirds() {
	for (const auto& bird : birdArr)
		BufferGraphic::DrawBird(bird.GetX(), bird.GetY(), GRAY, pBuffer, pColor);
}

void CGAME::ShowTrafficLights() {
	for (const auto& l : lightArr) {
		if (l.GetStatus())
			BufferGraphic::DrawGreenTrafficLight(l.GetX(), l.GetY(), WHITE, pBuffer, pColor);
		else BufferGraphic::DrawRedTrafficLight(l.GetX(), l.GetY(), WHITE, pBuffer, pColor);
	}		
}

void CGAME::ShowScore(){
	BufferGraphic::DrawScoreTitle(102, 8, BLACK, WHITE, pBuffer, pColor);
	BufferGraphic::DrawNumber(110, 10, BLACK, WHITE, pBuffer, pColor,score);
}

void CGAME::ShowLevel(){
	BufferGraphic::DrawLevelTitle(102, 2, RED, WHITE, pBuffer, pColor);
	BufferGraphic::DrawNumber(110, 4, RED, WHITE, pBuffer, pColor, level);
}

void CGAME::ShowGameTutorial(){
	BufferGraphic::DrawGameTutorial(105, 19, AQUA, WHITE, pBuffer, pColor);
}

void CGAME::ShowGameScene() {
	BufferGraphic::DrawBackgroundScreen(pBuffer, pColor, WHITE);
	BufferGraphic::DrawGameFrame(pBuffer, pColor);
	for (int i = 0; i < roadYCoordinate.size(); i++)
		BufferGraphic::DrawRoad(10, 100, roadYCoordinate[i], pBuffer, pColor);
	for (int i = 0; i < grassYCoordinate.size(); i++)
		BufferGraphic::DrawGrass(10, 100, grassYCoordinate[i], pBuffer, pColor);
	for (int i = 0; i < lightArr.size(); i++) {
		if (lightArr[i].GetStatus())
			BufferGraphic::DrawGreenTrafficLight(lightArr[i].GetX(), lightArr[i].GetY(),WHITE,pBuffer,pColor);
		else
			BufferGraphic::DrawRedTrafficLight(lightArr[i].GetX(), lightArr[i].GetY(), WHITE, pBuffer, pColor);
	}

	if (level == maxLevel - 1 || level == maxLevel)
		BufferGraphic::DrawGoal(10, 99, 0, 4, 2, 1, pBuffer, pColor);
}

CGAME::CGAME() {
	level = 1;
	score = 0;
	key = ' ';
	sleepAmount = 0;
}

void CGAME::ShowGame() {
	//Show scene
	ShowGameScene();
	//Show game's objects
	ShowMainCharacter();
	ShowTrafficLights();
	ShowCars();
	ShowTrucks();
	ShowMotorbikes();
	ShowDinosaurs();
	ShowBirds();
	//Show Info
	ShowLevel();
	ShowScore();
	ShowGameTutorial();
	BufferGraphic::PushPixelOnScreen(pBuffer, pColor);
}

CGAME::~CGAME() {

}

void CGAME::ResetGame() {
	IS_RUNNING = true;
	IS_COMPLETE = false;
	mainCharacter.Reset();
	roadYCoordinate.resize(0);
	grassYCoordinate.resize(0);
	visited.resize(0);
	lightArr.resize(0);
	truckArr.resize(0);
	carArr.resize(0);
	motorbikeArr.resize(0);
	dinoArr.resize(0);
	birdArr.resize(0);
}

void CGAME::ExitGame(thread* thr) {
	system("cls");
	level = 1;
	ResumeThread(thr->native_handle());
	IS_RUNNING = false;
	thr->join();
}

void CGAME::StartGame(const char* saveFileName) {
	ResetGame();
	ReadLevelFile(saveFileName);
}

void CGAME::StartGame() {
	ResetGame();
	ReadLevelFile((const char*)utility.GenerateLevelFileName(level).c_str());
}

void CGAME::LoadGame(ifstream& fi) {

}

void CGAME::SaveGame(const string& file) {
	const string extension = ".bin";
	string fileName = UpdateFileList(file);
	if (fileName == "") return;
	
	string dir = "SaveFiles/";
	ofstream fo;
	fo.open(dir + fileName + extension, ios::binary | ios::out);
	SaveGameState(fo);
	fo.close();
}

string CGAME::UpdateFileList(const string& file) {
	const string extension = ".bin";
	vector<string> fileList = utility.ReadFileList();
	if (fileList.size() == 10) return "";

	//string fileName = utility.GenerateSaveFileName();
	fileList.push_back(file + extension);
	utility.WriteFileList(fileList);

	return file;
}



void CGAME::PauseGame(HANDLE threadHandle) {
	SuspendThread(threadHandle);
}

void CGAME::ResumeGame(HANDLE threadHandle) {
	ResumeThread(threadHandle);
}

void CGAME::ProcessImpact(){
	for (auto& car : carArr)
		if (mainCharacter.IsImpact(car)) {
			car.CollisionSound();
			Sleep(1000);
			mainCharacter.Die();
		}	

	for (auto& truck : truckArr)
		if (mainCharacter.IsImpact(truck)) {
			truck.CollisionSound();
			Sleep(1000);
			mainCharacter.Die();
		}
			
	for (auto& motorbike : motorbikeArr)
		if (mainCharacter.IsImpact(motorbike)) {
			motorbike.CollisionSound();
			Sleep(1000);
			mainCharacter.Die();
		}
			
	for (auto& dino : dinoArr)
		if (mainCharacter.IsImpact(dino)) {
			dino.Tell();
			Sleep(1000);
			mainCharacter.Die();
		}
		
	for (auto& bird : birdArr)
		if (mainCharacter.IsImpact(bird)) {
			bird.Tell();
			Sleep(1000);
			mainCharacter.Die();
		}
}

bool CGAME::CheckCrossingRoad()
{
	for (int i = 0; i < visited.size(); i++) {
		if (mainCharacter.GetY() < roadYCoordinate[i] && !visited[i]) {
			visited[i] = true;
			return true;
		}
	}
	return false;
}

void CGAME::IncreaseScore(){
	score += 10;
}

void CGAME::ChangeTrafficLightsStatus(){
	for (auto &light : lightArr)
		light.ChangeStatus();
}

void CGAME::UpdatePosPeople(char move) {
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

void CGAME::UpdatePosVehicle() {
	for (auto& car : carArr) {
		if(!CheckInRedLight(car))
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

bool CGAME::InRoad(){
	for (auto roadY : roadYCoordinate)
		if (mainCharacter.GetY() == roadY)
			return true;
	return false;
}

bool CGAME::CheckInRedLight(const CVEHICLE& v){
	for (int i = 0; i < lightArr.size(); i++)
		if (v.GetY() == lightArr[i].GetY() && !lightArr[i].GetStatus())
			return true;
	return false;
}

void CGAME::UpdatePosAnimal() {
	for (auto& dino : dinoArr)
		dino.Move(dino.GetX() + step, dino.GetY());	

	for (auto& bird : birdArr)
		bird.Move(bird.GetX() - step, bird.GetY());
}

void CGAME::SubThreadForGame() {
	
	while(IS_RUNNING){
		if (!mainCharacter.IsDead() && !IS_COMPLETE) {

			key_locker.lock();
			UpdatePosPeople(MOVING);
			MOVING = ' '; 
			key_locker.unlock();

			UpdatePosVehicle();
			UpdatePosAnimal();

			if(level < maxLevel)
				ShowGame();

			Sleep(sleepAmount);

			if (level == maxLevel) {
				level--;
				ShowGame();
				PlaySound(TEXT("Sound/reachGoalSound.wav"), NULL, SND_ASYNC);
				Sleep(2000);
				IS_COMPLETE = true;
			}
						
			ProcessImpact();
			
			if (CheckCrossingRoad())
				IncreaseScore();

			if (mainCharacter.IsFinish() && level < maxLevel) {
				level++;
				if(level < maxLevel)
					StartGame();
			}			
		}
	}	
}

void CGAME::SubThreadForTrafficLights(){
	while (IS_RUNNING) {
		Sleep(2500);
		ChangeTrafficLightsStatus();
	}
}

void CGAME::PlayGame(const string& saveFileName) {
	system("cls");
	system("color 80");

	string dir = "";
	if (saveFileName != "") {
		dir = "SaveFiles/" + saveFileName;
		const char* saveFileDir = (const char*)dir.c_str();
		StartGame(saveFileDir);
	}	
	else
		StartGame();	
	
	thread screenThread(&CGAME::SubThreadForGame,this);
	thread lightsThread(&CGAME::SubThreadForTrafficLights, this);
	while (1) {
		if(_kbhit())
			key = toupper(_getch());
		if (!mainCharacter.IsDead() && !IS_COMPLETE) {	
			if (key != ' ') {
				key_locker.lock();
				MOVING = key;
				key_locker.unlock();
			}

			if (key == 27) {
				PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
				PauseGame(screenThread.native_handle());
				PauseGame(lightsThread.native_handle());
				if (utility.ShowExitDialog()) {
					ExitGame(&screenThread);
					ExitGame(&lightsThread);
					key = ' ';
					break;
				}
				ResumeGame(screenThread.native_handle());
				ResumeGame(lightsThread.native_handle());
			}
			else if (key == 'P') {
				PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
				PauseGame(screenThread.native_handle());
				PauseGame(lightsThread.native_handle());
			}
			else if (key == 'R') {
				PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
				ResumeGame(screenThread.native_handle());
				ResumeGame(lightsThread.native_handle());
			}
			else if (key == 'L') {
				PlaySound(TEXT("Sound/menuMovingSound.wav"), NULL, SND_ASYNC);
				PauseGame(screenThread.native_handle());
				PauseGame(lightsThread.native_handle());

				const vector<string> fileList = utility.ReadFileList();
				if (fileList.size() < 10) {
					string fileName = utility.ShowSaveGameDialog();
					SaveGame(fileName);
				}	
				else
					utility.ShowFullFileContainerNotification();

				ShowGame();

				if (utility.ShowExitDialog()) {
					ExitGame(&screenThread);
					ExitGame(&lightsThread);
					key = ' ';
					break;
				}

				ResumeGame(screenThread.native_handle());
				ResumeGame(lightsThread.native_handle());
			}
			key = ' ';
		}
		else if (!IS_COMPLETE){
			bool choice = utility.ShowGameOverDialog(score);
			if (choice) {
				level = 1;
				StartGame();
			}
			else {
				ExitGame(&screenThread);
				ExitGame(&lightsThread);
				break;
			}
		}
		else {
			Graphic::DrawMiniGameWelcome();
			_getch();
			PlaySound(TEXT("Sound/selectSound.wav"), NULL, SND_ASYNC);
			MiniGame miniGame(score);
			bool choice = miniGame.PlayMiniGame();

			if (choice) {
				level = 1;
				StartGame();
			}
			else {
				ExitGame(&screenThread);
				ExitGame(&lightsThread);
				break;
			}
		}
	}
	system("cls");
	system("color 30");
}