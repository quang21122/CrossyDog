#include "CANIMAL.h"


CANIMAL::CANIMAL(){
}

CANIMAL::CANIMAL(int x, int y){
	SetX(x);
	SetY(y);
}

void CANIMAL::SetX(int x) {
	if (x < 10)
		x = 90;
	else if (x > 90)
		x = 10;

	mX = x;
}
void CANIMAL::SetY(int y) {
	if (y < 5)
		y = 25;
	else if (y > 25)
		y = 5;

	mY = y;
}

int CANIMAL::GetX() const {
	return mX;
}

int CANIMAL::GetY() const {
	return mY;
}

void CANIMAL::Move(int, int){

}

void CANIMAL::Tell(){

}
