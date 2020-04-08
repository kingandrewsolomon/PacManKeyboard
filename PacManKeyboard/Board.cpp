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
		points[i] = new int[this->lengths];
		for (int j = 0; j < lengths; j++)
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
		for (int j = 0; j < lengths; j++)
		{
			LogiLedSetLightingForKeyWithKeyName(this->GameBoard[i][j], 100, 100, 100);
		}
	}
}

void Board::clear()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < lengths; j++)
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
		for (int j = 0; j < lengths; j++)
		{
			if (points[i][j] == 1) return true;
		}
	}
	return false;
}

void Board::completed(int x, int y)
{
	int radX;
	int radY = radX = 1;
	LogiLedSetLightingForKeyWithKeyName(GameBoard[y][x], 100, 50, 0);
	while (y - radY > 0 || y + radY < 4 || x - radX > 0 || x + radX < lengths)
	{
		if (y - radY > 0 && x - radX > 0)
		{
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y - radY][x - radX], 100, 100, 100);
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y - radY][x], 100, 100, 100);
		}
		if (y - radY > 0 && x + radX < lengths)
		{
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y - radY][x + radX], 100, 100, 100);
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y][x + radX], 100, 100, 100);
		}
		if (y + radY < 4 && x + radX < lengths)
		{
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y + radY][x + radX], 100, 100, 100);
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y + radY][x], 100, 100, 100);
		}
		if (y + radY < 4 && x - radX > 0)
		{
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y + radY][x - radX], 100, 100, 100);
			LogiLedSetLightingForKeyWithKeyName(GameBoard[y][x - radX], 100, 100, 100);
		}
		radX++;
		radY++;
		Sleep(500);
	}
}

Board::~Board()
{
}