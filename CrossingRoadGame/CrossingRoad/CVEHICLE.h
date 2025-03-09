#pragma once
#include <Windows.h>

class CVEHICLE
{
	int mX, mY;
public:
	CVEHICLE();
	CVEHICLE(int, int);

	void SetX(int);
	void SetY(int);
	int GetX() const;
	int GetY() const;
	virtual void Move(int, int);
	void CollisionSound();
};

