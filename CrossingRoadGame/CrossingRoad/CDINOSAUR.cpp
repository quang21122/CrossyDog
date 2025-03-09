#include "CDINOSAUR.h"

CDINOSAUR::CDINOSAUR() {}

CDINOSAUR::CDINOSAUR(int x, int y): CANIMAL(x,y) {

}

void CDINOSAUR::Move(int x, int y) {
	SetX(x);
	SetY(y);
}

void CDINOSAUR::Tell(){
	PlaySound(TEXT("Sound/dinosaurRoar.wav"), NULL, SND_ASYNC);
}

