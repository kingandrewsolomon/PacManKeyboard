#include "pch.h"
#include "Player.h"

Player::Player(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
	this->isDead = false;
	this->direction = 2;
}

void Player::died()
{
	for(int i = 0; i < 4; i++)
		LogiLedSetLightingForKeyWithKeyName(this->livesDisplay[i], 0, 0, 0);
	this->lives--;
}

void Player::move() 
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