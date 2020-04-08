#pragma once
#include "pch.h"
#include "windows.h"
#include <LogitechLEDLib.h>

class Board
{
public:
	LogiLed::KeyName* GameBoard[4];
	int* points[4];
	int rows = 4;
	int lengths = 10;
	Board();
	void initializeBoard(); 
	void clear();
	void flash(int, int, int, int);
	bool hasPoints();
	void completed(int, int);
	~Board();

private:
	LogiLed::KeyName row1[10] = { LogiLed::ONE, LogiLed::TWO, LogiLed::THREE, LogiLed::FOUR, LogiLed::FIVE, LogiLed::SIX, LogiLed::SEVEN, LogiLed::EIGHT, LogiLed::NINE, LogiLed::ZERO };
	LogiLed::KeyName row2[10] = { LogiLed::Q, LogiLed::W, LogiLed::E, LogiLed::R, LogiLed::T, LogiLed::Y, LogiLed::U, LogiLed::I, LogiLed::O, LogiLed::P };
	LogiLed::KeyName row3[10] = { LogiLed::A, LogiLed::S, LogiLed::D, LogiLed::F, LogiLed::G, LogiLed::H, LogiLed::J, LogiLed::K, LogiLed::L, LogiLed::SEMICOLON };
	LogiLed::KeyName row4[10] = { LogiLed::Z, LogiLed::X, LogiLed::C, LogiLed::V, LogiLed::B, LogiLed::N, LogiLed::M, LogiLed::COMMA, LogiLed::PERIOD, LogiLed::FORWARD_SLASH };
};