#include "pch.h"
#include "Board.h"

Board::Board()
{
	GameBoard[0] = Board::row1;
	GameBoard[1] = Board::row2;
	GameBoard[2] = Board::row3;
	GameBoard[3] = Board::row4;

	for (int i = 0; i < rows; i++)
	{
		points[i] = new int[this->lengths[i]];
		for (int j = 0; j < lengths[i]; j++)
		{
			points[i][j] = 1;
		}
	}

	initializeBoard();
}

void Board::initializeBoard()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < lengths[i]; j++)
		{
			LogiLedSetLightingForKeyWithKeyName(this->GameBoard[i][j], 100, 100, 100);
		}
	}
}

void Board::clear()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < lengths[i]; j++)
		{
			LogiLedSetLightingForKeyWithKeyName(this->GameBoard[i][j], 0, 0, 0);
		}
	}
}

void Board::flash(int x, int y, int duration, int interval)
{
	bool on = false;
	for (int i = 0; i < duration; i++)
	{
		if (i % interval == 0)
		{
			if (!on)
				LogiLedSetLightingForKeyWithKeyName(GameBoard[y][x], 0, 0, 0);
			else
				LogiLedSetLightingForKeyWithKeyName(GameBoard[y][x], 100, 50, 0);
			on = !on;
		}
		Sleep(1);
	}
	LogiLedSetLightingForKeyWithKeyName(GameBoard[y][x], 0, 0, 0);
}

bool Board::hasPoints()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < lengths[i]; j++)
		{
			if (points[i][j] == 1) return true;
		}
	}
	return false;
}

void Board::completed(int x, int y)
{

}

Board::~Board()
{
	delete []GameBoard;
}