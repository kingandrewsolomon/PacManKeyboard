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
}

void Board::initializeBoard() {

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < lengths[i]; j++)
		{
			LogiLedSetLightingForKeyWithKeyName(this->GameBoard[i][j], 100, 100, 100);
		}
	}
}

Board::~Board()
{
	delete []GameBoard;
}