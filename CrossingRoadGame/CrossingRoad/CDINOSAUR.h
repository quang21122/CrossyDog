#pragma once
#include "CANIMAL.h"

class CDINOSAUR: public CANIMAL
{
public:
	CDINOSAUR();
	CDINOSAUR(int, int);
	virtual void Move(int, int) override;
	virtual void Tell() override;
};

