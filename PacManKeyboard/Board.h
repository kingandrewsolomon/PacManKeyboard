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
	int lengths[4] = { 14, 14, 13, 12 };
	Board();
	void initializeBoard(); 
	void clear();
	void flash(int, int, int, int);
	bool hasPoints();
	void completed(int, int);
	~Board();

private:
	LogiLed::KeyName row1[14] = { LogiLed::TILDE, LogiLed::ONE, LogiLed::TWO, LogiLed::THREE, LogiLed::FOUR, LogiLed::FIVE, LogiLed::SIX, LogiLed::SEVEN, LogiLed::EIGHT, LogiLed::NINE, LogiLed::ZERO, LogiLed::MINUS, LogiLed::EQUALS, LogiLed::BACKSPACE };
	LogiLed::KeyName row2[14] = { LogiLed::TAB, LogiLed::Q, LogiLed::W, LogiLed::E, LogiLed::R, LogiLed::T, LogiLed::Y, LogiLed::U, LogiLed::I, LogiLed::O, LogiLed::P, LogiLed::OPEN_BRACKET, LogiLed::CLOSE_BRACKET, LogiLed::BACKSLASH };
	LogiLed::KeyName row3[13] = { LogiLed::CAPS_LOCK, LogiLed::A, LogiLed::S, LogiLed::D, LogiLed::F, LogiLed::G, LogiLed::H, LogiLed::J, LogiLed::K, LogiLed::L, LogiLed::SEMICOLON, LogiLed::APOSTROPHE, LogiLed::ENTER };
	LogiLed::KeyName row4[12] = { LogiLed::LEFT_SHIFT, LogiLed::Z, LogiLed::X, LogiLed::C, LogiLed::V, LogiLed::B, LogiLed::N, LogiLed::M, LogiLed::COMMA, LogiLed::PERIOD, LogiLed::FORWARD_SLASH, LogiLed::RIGHT_SHIFT };
};