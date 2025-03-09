#include "CBIRD.h"

CBIRD::CBIRD() {

}

CBIRD::CBIRD(int x, int y): CANIMAL(x, y) {
}

void CBIRD::Move(int x, int y) {
	SetX(x);
	SetY(y);
}

void CBIRD::Tell() {
	PlaySound(TEXT("Sound/birdChirp.wav"), NULL, SND_ASYNC);
}
