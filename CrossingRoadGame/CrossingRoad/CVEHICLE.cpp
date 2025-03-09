#include "CVEHICLE.h"


CVEHICLE::CVEHICLE(){
}

CVEHICLE::CVEHICLE(int x, int y){
	SetX(x);
	SetY(y);
}


void CVEHICLE::SetX(int x) {
	if (x < 10)
		x = 90;
	else if (x > 90)
		x = 10;

	mX = x;
}
void CVEHICLE::SetY(int y) {
	if (y < 5)
		y = 25;
	else if (y > 25)
		y = 5;

	mY = y;
}

int CVEHICLE::GetX() const {
	return mX;
}

int CVEHICLE::GetY() const{
	return mY;
}

void CVEHICLE::Move(int, int)
{

}

void CVEHICLE::CollisionSound()
{
	PlaySound(TEXT("Sound/carCollisionSound.wav"), NULL, SND_ASYNC);
}

