#pragma once
#include <Windows.h>
class CANIMAL
{
	int mX, mY;
public:

	CANIMAL();
	CANIMAL(int, int);

	void SetX(int);
	void SetY(int);
	int GetX() const;
	int GetY() const;
	virtual void Move(int, int);
	virtual void Tell();
};

