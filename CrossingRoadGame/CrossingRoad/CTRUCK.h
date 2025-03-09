#pragma once
#include "CVEHICLE.h"
class CTRUCK: public CVEHICLE
{
public:
	CTRUCK();
	CTRUCK(int, int);
	virtual void Move(int, int) override;
};

