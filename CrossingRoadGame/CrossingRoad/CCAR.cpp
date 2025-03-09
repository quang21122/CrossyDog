#include "CCAR.h"
CCAR::CCAR() {}

CCAR::CCAR(int x, int y): CVEHICLE(x,y) {

}

void CCAR::Move(int x, int y) {
	SetX(x);
	SetY(y);
}