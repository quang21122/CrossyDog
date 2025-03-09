#pragma once
#include "CVEHICLE.h"
#include "CANIMAL.h"
#include "Coin.h"
#include <vector>
#include <Windows.h>

class CPEOPLE
{
	int mX, mY;
	bool mState;
public:
	CPEOPLE();
	void SetX(int);
	void SetY(int);
	int GetX();
	int GetY();
	void Up();
	void Left();
	void Right();
	void Down();
	bool IsImpact(const CVEHICLE&);
	bool IsImpact(const CANIMAL&);
	bool CollectCoin(const Coin&);
	bool IsFinish();
	void Reset();
	void Die();
	bool IsDead();
};

