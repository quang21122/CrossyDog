#pragma once
#include "CVEHICLE.h"

class CMOTORBIKE: public CVEHICLE
{
public:
	CMOTORBIKE();
	CMOTORBIKE(int, int);
	virtual void Move(int, int) override;
};

