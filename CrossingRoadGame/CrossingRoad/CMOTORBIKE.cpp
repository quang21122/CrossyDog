#include "CMOTORBIKE.h"

CMOTORBIKE::CMOTORBIKE() {}

CMOTORBIKE::CMOTORBIKE(int x, int y):CVEHICLE(x,y) {

}

void CMOTORBIKE::Move(int x, int y) {
	SetX(x);
	SetY(y);
}