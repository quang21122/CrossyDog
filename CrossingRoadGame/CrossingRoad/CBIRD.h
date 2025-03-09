#pragma once
#include "CANIMAL.h"

class CBIRD: public CANIMAL
{
public:
	CBIRD();
	CBIRD(int, int);
	virtual void Move(int, int) override;
	virtual void Tell() override;
};

