// PacManKeyboard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "GameController.h"
#include "windows.h"
#include <iostream>
#include <LogitechLEDLib.h>

GameController *gc;
Board * b;
Ghost * g;
Player * p;


void playPacMan() {
	gc = new GameController(b, p, g);
	gc->initializeBoard();
	gc->runGame();
}

int main()
{
	bool initialized = LogiLedInitWithName("Keyboard PacMan");

	if (!initialized)
	{
		std::cout << "LogiLedInit() failed." << std::endl;

		return 0;
	}

	std::cout << "LED SDK Initialized" << std::endl;

	LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

	
	playPacMan();
	Sleep(4000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
