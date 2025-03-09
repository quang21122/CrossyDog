#pragma once
class CTRAFFICLIGHT
{
	int mX, mY;
	bool status;
public:
	CTRAFFICLIGHT();
	CTRAFFICLIGHT(int, int, bool);

	int GetX() const;
	int GetY() const;

	bool GetStatus()const;
	void ChangeStatus();

};

