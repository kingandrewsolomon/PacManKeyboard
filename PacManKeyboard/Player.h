#pragma once
#include <LogitechLEDLib.h>

class Player
{
public:
	int xpos;
	int ypos;
	bool isDead;
	int lives = 3;
	LogiLed::KeyName livesDisplay[3] = { LogiLed::F1, LogiLed::F2, LogiLed::F3 };

	void move(int);
	void died();
	Player(int, int);
	~Player();

private:
	
};
