#pragma once
#include <cstdlib>

class Ghost
{
public:
	int xpos;
	int ypos;
	int direction;

	void move();
	void set_direction(int, int);
	Ghost(int, int);
	~Ghost();

private:

};
