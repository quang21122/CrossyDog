#include "Player.h"

Player::Player(const string& username, int score)
{
	this->username = username;
	this->score = score;
}

bool Player::operator < (const Player& other) const {
	return this->score < other.score;
}

string Player::GetUsername() const {
	return username;
}

int Player::GetScore() const {
	return score;
}

istream& operator>>(istream& inDev, Player& player) {
	inDev >> player.username;
	inDev >> player.score;
	return inDev;
}

ostream& operator<<(ostream& outDev, const Player& player) {
	outDev << player.username << " " << player.score;
	return outDev;
}
