#include "CTRAFFICLIGHT.h"

CTRAFFICLIGHT::CTRAFFICLIGHT() {
	
}

CTRAFFICLIGHT::CTRAFFICLIGHT(int x, int y, bool status) {
	this->mX = x;
	this->mY = y;
	this->status = status;
}

int CTRAFFICLIGHT::GetX() const{
	return mX;
}

int CTRAFFICLIGHT::GetY() const{
	return mY;
}

bool CTRAFFICLIGHT::GetStatus() const{
	return status;
}

void CTRAFFICLIGHT::ChangeStatus(){
	status = !status;
}
