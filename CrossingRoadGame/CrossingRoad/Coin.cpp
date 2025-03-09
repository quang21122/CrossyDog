#include "Coin.h"


Coin::Coin(int x, int y, bool status) {
	this->x = x;
	this->y = y;
	this->status = status;
}

Coin::Coin() {
	this->x = GenerateX();
	this->y = GenerateY();
	this->status = true;
}

int Coin::GenerateX() {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> dis(10, 94);

	int randomX = dis(gen);

	return randomX;
}

int Coin::GenerateY() {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> dis(5, 30);

	int randomY;
	do {
		randomY = dis(gen);
	} while (randomY % 5 != 1);

	return randomY;
}

void Coin::SetX(int x) {
	this->x = x;
}

void Coin::SetY(int y) {
	this->y = y;
}

void Coin::SetStatus(bool status)
{
	this->status = status;
}

int Coin::GetX() const {
	return this->x;
}

int Coin::GetY() const {
	return this->y;
}

bool Coin::GetStatus() const
{
	return this->status;
}
