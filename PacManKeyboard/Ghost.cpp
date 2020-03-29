#include "pch.h"
#include "Ghost.h"
#include <LogitechLEDLib.h>

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

void Ghost::set_direction()
{
	//if (xpos + 1 < this->board->lengths[xpos])
		direction = 2;

	if (xpos - 1 >= 0)
		direction = 4;

	//if (ypos + 1 < this->board->rows)
		direction = 3;

	if (ypos - 1 >= 0)
		direction = 1;
}

Ghost::~Ghost()
{
}