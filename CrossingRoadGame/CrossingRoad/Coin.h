#pragma once
#include <iostream>
#include <random>

using namespace std;

class Coin
{
	int x;
	int y;
	bool status;
public:
	Coin(int, int, bool);
	Coin();
	int GenerateX(); 
	int GenerateY(); 
	void SetX(int);
	void SetY(int);
	void SetStatus(bool);
	int GetX() const;
	int GetY() const;
	bool GetStatus() const;
};

