#pragma once
#include "CVEHICLE.h"
class CCAR: public CVEHICLE
{
public:
	CCAR();
	CCAR(int, int);
	virtual void Move(int, int) override;
};

