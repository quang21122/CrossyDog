#include "CPEOPLE.h"

CPEOPLE::CPEOPLE() {
	mX = 50;
	mY = 25;
	mState = true;
}

void CPEOPLE::SetX(int x) {
	mX = x;
}
void CPEOPLE::SetY(int y) {
	mY = y;
}

int CPEOPLE::GetX() {
	return mX;
}

int CPEOPLE::GetY() {
	return mY;
}

void CPEOPLE::Up() {
	if (mY >= 5) {
		PlaySound(TEXT("Sound/characterMovingSound.wav"), NULL, SND_ASYNC);
		mY -= 5;
	}
	
}

void CPEOPLE::Left() {
	if (mX >= 15) {
		PlaySound(TEXT("Sound/characterMovingSound.wav"), NULL, SND_ASYNC);
		mX -= 5;
	}
}

void CPEOPLE::Right() {
	if (mX <= 85) {
		PlaySound(TEXT("Sound/characterMovingSound.wav"), NULL, SND_ASYNC);
		mX += 5;
	}
}

void CPEOPLE::Down() {
	if (mY <= 20) {
		PlaySound(TEXT("Sound/characterMovingSound.wav"), NULL, SND_ASYNC);
		mY += 5;
	}
}

bool CPEOPLE::IsImpact(const CVEHICLE& v) {
	int XCoords[] = { mX,mX + 9 };
	int YCoords[] = { mY,mY + 4 };
	int n = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((XCoords[i] > v.GetX() && XCoords[i] < v.GetX() + 10) && (YCoords[j] >= v.GetY() && YCoords[j] < v.GetY() + 5))
				return true;
		}
	}
	return false;
}

bool CPEOPLE::IsImpact(const CANIMAL& a) {
	int XCoords[] = { mX,mX + 9 };
	int YCoords[] = { mY,mY + 4 };
	int n = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((XCoords[i] > a.GetX() && XCoords[i] < a.GetX() + 10) && (YCoords[j] >= a.GetY() && YCoords[j] < a.GetY() + 5))
				return true;
		}
	}
	return false;
}

bool CPEOPLE::CollectCoin(const Coin& c)
{
	int XCoords[] = { mX,mX + 9 };
	int YCoords[] = { mY,mY + 4 };
	int n = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((XCoords[i] > c.GetX() && XCoords[i] < c.GetX() + 10) && (YCoords[j] > c.GetY() && YCoords[j] < c.GetY() + 4))
				return true;
		}
	}
	return false;
}

bool CPEOPLE::IsFinish() {
	return mY == 0;
}

void CPEOPLE::Reset() {
	mX = 50;
	mY = 25;
	mState = true;
}

void CPEOPLE::Die() {
	mState = false;
}

bool CPEOPLE::IsDead() {
	return mState == false;
}