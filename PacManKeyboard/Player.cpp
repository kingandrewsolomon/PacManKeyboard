#include "pch.h"
#include "Player.h"
#include <LogitechLEDLib.h>

Player::Player(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
	this->isDead = false;
}

void Player::died()
{
	this->lives--;
}

void Player::move(int direction) 
{
	if (direction == 1)
		this->ypos--;

	if (direction == 2)
		this->xpos++;

	if (direction == 3)
		this->ypos++;

	if (direction == 4)
		this->xpos--;
}


Player::~Player()
{
}