#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
	string username;
	int score;

public:
	Player(const string&, int);
	friend istream& operator >>(istream&, Player&);
	friend ostream& operator <<(ostream&, const Player&);
	bool operator < (const Player&) const;
	string GetUsername() const;
	int GetScore() const;
};

