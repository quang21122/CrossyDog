#include "CTRUCK.h"
CTRUCK::CTRUCK() {}

CTRUCK::CTRUCK(int x, int y): CVEHICLE(x,y) {

}

void CTRUCK::Move(int x, int y) {
	SetX(x);
	SetY(y);
}