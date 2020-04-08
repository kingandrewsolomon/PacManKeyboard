#include "pch.h"
#include "Ghost.h"

Ghost::Ghost(int x, int y)
{
	this->xpos = x;
	this->ypos = y;
}

void Ghost::move()
{
	if(direction == 1)
		this->ypos--;

	if (direction == 2)
		this->xpos++;

	if (direction == 3)
		this->ypos++;

	if (direction == 4)
		this->xpos--;
}

void Ghost::set_direction(int playerX, int playerY)
{
	// ypos > playerY = move up
	// xpos < playerX = move left
	// ypos < playerY = move down
	// xpos > playerX = move right
	if (rand() / (RAND_MAX / 100) < 25 || ypos > playerY)
	{
		direction = 1;
	}
	else if (rand() / (RAND_MAX / 100) < 25 || xpos < playerX)
	{
		direction = 2;
	}
	else if (rand() / (RAND_MAX / 100) < 25 || ypos < playerY)
	{
		direction = 3;
	}
	else if (rand() / (RAND_MAX / 100) < 25 || xpos > playerX)
	{
		direction = 4;
	}
	else
		direction = direction;
}

Ghost::~Ghost()
{
}